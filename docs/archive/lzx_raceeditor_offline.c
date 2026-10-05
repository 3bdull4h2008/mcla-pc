/* Offline mirror of MclaHostLzxDecode / MclaHostXcDecodePackage (gpu_device.cpp).
 * Concat XC frame payloads after RSC5+0x14, one lzxd stream, wantOut=143069.
 * cl /O2 tools\lzx_raceeditor_offline.c /I.research\XenonRecomp\thirdparty\libmspack\libmspack\mspack
 *   .research\XenonRecomp\thirdparty\libmspack\libmspack\mspack\{lzxd,system,crc32,lzssd}.c
 *   /Fe:build\lzx_raceeditor_offline.exe
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "mspack.h"
#include "lzx.h"
#include "system.h"

#define ARCHIVE "E:/mcla pc/build/game_data/xarchive_cache.rpf"
#define OFF 0x64CB0000ull
#define WANT 143069u
#define WINDOW_BITS 17
#define RSC5 0x05435352u
#define XCOMP 0x0FF512EFu

typedef struct { uint8_t *buf; size_t size; size_t pos; } MemFile;

static int mf_read(mspack_file *f, void *buf, int n) {
  MemFile *mf = (MemFile *)f;
  size_t rem = mf->size - mf->pos;
  int got = (n < (int)rem) ? n : (int)rem;
  if (got > 0) memcpy(buf, mf->buf + mf->pos, (size_t)got);
  mf->pos += (size_t)got;
  return got;
}
static int mf_write(mspack_file *f, void *buf, int n) {
  MemFile *mf = (MemFile *)f;
  size_t rem = mf->size - mf->pos;
  int put = (n < (int)rem) ? n : (int)rem;
  if (put > 0) memcpy(mf->buf + mf->pos, buf, (size_t)put);
  mf->pos += (size_t)put;
  return put;
}
static void *mf_alloc(mspack_system *s, size_t n) { (void)s; return malloc(n); }
static void mf_free(void *p) { free(p); }
static void mf_copy(void *s, void *d, size_t n) { memcpy(d, s, n); }

static mspack_system g_sys = {
  NULL, NULL, mf_read, mf_write, NULL, NULL, NULL, mf_alloc, mf_free, mf_copy, NULL
};

static uint32_t be32(const uint8_t *p) {
  return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) | ((uint32_t)p[2] << 8) | p[3];
}

int main(void) {
  FILE *fp = fopen(ARCHIVE, "rb");
  if (!fp) { fprintf(stderr, "ERROR open archive\n"); return 2; }
  if (fseek(fp, (long)OFF, SEEK_SET) != 0) { fprintf(stderr, "ERROR seek\n"); return 2; }
  uint8_t *pkg = (uint8_t *)malloc(1 << 20);
  if (!pkg) return 2;
  size_t pkgSz = fread(pkg, 1, 1 << 20, fp);
  fclose(fp);
  printf("read %zu bytes @0x%llX head=%08X\n", pkgSz, (unsigned long long)OFF, be32(pkg));

  uint32_t wantOut = 0, payloadOff = 0;
  if (be32(pkg) == RSC5 && be32(pkg + 12) == XCOMP) {
    payloadOff = 20; /* RSC5(12)+XC(4)+size(4) */
    wantOut = be32(pkg + 16);
  } else if (be32(pkg) == XCOMP) {
    payloadOff = 8;
    wantOut = be32(pkg + 4);
  } else {
    fprintf(stderr, "ERROR bad magic %08X\n", be32(pkg));
    return 3;
  }
  printf("wantOut=%u payloadOff=%u\n", wantOut, payloadOff);
  if (wantOut != WANT) printf("WARN wantOut %u != %u\n", wantOut, WANT);

  /* Walk XC frames and concatenate compressed payloads (headers stripped). */
  uint8_t *payload = (uint8_t *)malloc(pkgSz);
  uint32_t payLen = 0, frameN = 0;
  size_t src = payloadOff;
  while (src + 2 <= pkgSz && frameN < 256) {
    uint32_t hdr = 2, uncomp = 0x8000, plen;
    if (pkg[src] == 0xFF) {
      if (src + 5 > pkgSz) break;
      hdr = 5;
      uncomp = ((uint32_t)pkg[src + 1] << 8) | pkg[src + 2];
      plen = ((uint32_t)pkg[src + 3] << 8) | pkg[src + 4];
    } else {
      plen = ((uint32_t)pkg[src] << 8) | pkg[src + 1];
    }
    if (plen == 0 || src + hdr + plen > pkgSz) break;
    memcpy(payload + payLen, pkg + src + hdr, plen);
    payLen += plen;
    src += hdr + plen;
    frameN++;
  }
  printf("frames=%u payLen=%u\n", frameN, payLen);
  if (!frameN || !payLen) { fprintf(stderr, "ERROR no XC frames\n"); return 4; }

  uint32_t outSz = wantOut ? wantOut : 0x100000;
  if (outSz > 0x400000) outSz = 0x400000;
  uint8_t *out = (uint8_t *)calloc(1, outSz);
  MemFile in = { payload, payLen, 0 };
  MemFile of = { out, outSz, 0 };
  /* MclaHostLzxDecode: windowBits=17, reset_interval=0, blockSize=0x8000 */
  struct lzxd_stream *lzx = lzxd_init(&g_sys, (mspack_file *)&in, (mspack_file *)&of,
                                      WINDOW_BITS, 0, 0x8000, (off_t)outSz, 0);
  if (!lzx) { fprintf(stderr, "ERROR lzxd_init\n"); return 5; }
  int rc = lzxd_decompress(lzx, (off_t)outSz);
  uint32_t produced = (uint32_t)of.pos;
  lzxd_free(lzx);
  printf("lzxd rc=%d produced=%u want=%u frames=%u payLen=%u match=%d\n",
         rc, produced, WANT, frameN, payLen, produced == WANT);
  if (produced) {
    printf("first16=");
    for (int i = 0; i < 16 && i < (int)produced; i++) printf("%02x ", out[i]);
    printf("\n");
  }
  if (produced == WANT) {
    FILE *o = fopen("E:/mcla pc/build/raceeditor_out.bin", "wb");
    if (o) { fwrite(out, 1, produced, o); fclose(o); printf("wrote build/raceeditor_out.bin\n"); }
    printf("SUCCESS\n");
    return 0;
  }
  printf("ERROR produced=%u want=%u rc=%d\n", produced, WANT, rc);
  return 1;
}
