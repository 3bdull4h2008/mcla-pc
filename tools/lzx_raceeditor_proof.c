/* Offline libmspack LZX proof: raceeditor.xsf @ xarchive_cache.rpf+0x64CB0000.
 * Strategies: concat | perframe | shared
 * Goal: produced == 143069
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "mspack.h"
#include "lzx.h"
#include "system.h"

typedef struct mspack_file mspack_file;
typedef struct mspack_system mspack_system;

#define ARCHIVE "E:/mcla pc/build/game_data/xarchive_cache.rpf"
#define OFF 0x64CB0000ull
#define WANT 143069u
#define WINDOW_BITS 17
static int g_window_bits = WINDOW_BITS;
#define RSC5 0x05435352u
#define XCOMP 0x0FF512EFu

typedef struct {
  uint8_t *buf;
  size_t size;
  size_t pos;
} MemFile;

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

typedef struct {
  const uint8_t *pay;
  uint32_t payLen;
  uint32_t uncomp;
} Frame;

static void hex16(const uint8_t *b, int n) {
  int lim = n < 16 ? n : 16;
  for (int i = 0; i < lim; i++) printf("%02x%s", b[i], (i + 1 < lim) ? " " : "");
}

static uint32_t lzx_once(const uint8_t *src, uint32_t srcLen,
                         uint8_t *dst, uint32_t dstCap,
                         uint32_t outSz, int reset_interval) {
  MemFile in = { (uint8_t *)src, srcLen, 0 };
  MemFile out = { dst, dstCap, 0 };
  struct lzxd_stream *lzx = lzxd_init(&g_sys, (mspack_file *)&in, (mspack_file *)&out,
                                      g_window_bits, reset_interval, 0x8000,
                                      (off_t)outSz, 0);
  if (!lzx) return 0;
  int rc = lzxd_decompress(lzx, (off_t)outSz);
  uint32_t produced = (uint32_t)out.pos;
  printf("    lzxd rc=%d produced=%u inPos=%zu/%zu reset=%d\n",
         rc, produced, in.pos, in.size, reset_interval);
  lzxd_free(lzx);
  return produced;
}

/* Shared-state: one lzxd, feed frames via sequential lzxd_decompress of each
 * frame's uncompressed size, with input cursor advanced per frame by swapping
 * the input buffer pointer between calls. libmspack keeps bit state, so we
 * prepend each frame payload into a rolling input and only request that frame's
 * output length per call. Simpler and correct for XC: keep ONE input cursor
 * over the concatenated payload and request each frame's uncomp length. */
static uint32_t lzx_shared(const uint8_t *src, uint32_t srcLen,
                           const Frame *fr, int nfr,
                           uint8_t *dst, uint32_t dstCap) {
  MemFile in = { (uint8_t *)src, srcLen, 0 };
  MemFile out = { dst, dstCap, 0 };
  struct lzxd_stream *lzx = lzxd_init(&g_sys, (mspack_file *)&in, (mspack_file *)&out,
                                      WINDOW_BITS, 0, 0x8000,
                                      (off_t)dstCap, 0);
  if (!lzx) return 0;
  uint32_t total = 0;
  for (int i = 0; i < nfr; i++) {
    uint32_t want = fr[i].uncomp;
    if (total + want > dstCap) want = dstCap - total;
    if (!want) break;
    int rc = lzxd_decompress(lzx, (off_t)want);
    uint32_t produced = (uint32_t)out.pos - total;
    printf("    shared f%d rc=%d produced=%u want=%u\n", i, rc, produced, want);
    if (rc != MSPACK_ERR_OK && produced == 0) break;
    total = (uint32_t)out.pos;
  }
  lzxd_free(lzx);
  return total;
}

int main(int argc, char **argv) {
  const char *mode = (argc > 1) ? argv[1] : "all";
  setvbuf(stdout, NULL, _IONBF, 0);
  FILE *fp = fopen(ARCHIVE, "rb");
  if (!fp) { fprintf(stderr, "open archive failed\n"); return 2; }
  if (fseeko(fp, (off_t)OFF, SEEK_SET) != 0) {
    /* fallback 32-bit fseek */
    if (fseek(fp, (long)OFF, SEEK_SET) != 0) { fprintf(stderr, "seek failed\n"); return 2; }
  }
  size_t cap = 4u * 1024u * 1024u;
  uint8_t *pkg = (uint8_t *)malloc(cap);
  size_t pkgSz = fread(pkg, 1, cap, fp);
  fclose(fp);
  printf("read %zu bytes at 0x%llX\n", pkgSz, (unsigned long long)OFF);
  printf("head:");
  for (int i = 0; i < 32; i++) printf(" %02x", pkg[i]);
  printf("\nBE: %08X %08X %08X %08X %08X\n",
         be32(pkg), be32(pkg + 4), be32(pkg + 8), be32(pkg + 12), be32(pkg + 16));

  uint32_t payloadOff = 0, wantOut = 0;
  if (be32(pkg) == RSC5 && be32(pkg + 12) == XCOMP) {
    payloadOff = 20;
    wantOut = be32(pkg + 16);
  } else if (be32(pkg) == XCOMP) {
    payloadOff = 8;
    wantOut = be32(pkg + 4);
  } else {
    fprintf(stderr, "bad magic\n");
    return 2;
  }
  printf("wantOut=%u payloadOff=%u\n", wantOut, payloadOff);

  Frame frames[512];
  int nfr = 0;
  size_t src = payloadOff;
  uint32_t totalPay = 0, totalUn = 0;
  while (src + 2 <= pkgSz && nfr < 512) {
    const uint8_t *hb = pkg + src;
    uint32_t hdr, uncomp, pay;
    if (hb[0] == 0xFF) {
      if (src + 5 > pkgSz) break;
      hdr = 5;
      uncomp = ((uint32_t)hb[1] << 8) | hb[2];
      pay = ((uint32_t)hb[3] << 8) | hb[4];
    } else {
      hdr = 2;
      uncomp = 0x8000;
      pay = ((uint32_t)hb[0] << 8) | hb[1];
    }
    if (pay == 0 || src + hdr + pay > pkgSz) break;
    frames[nfr].pay = pkg + src + hdr;
    frames[nfr].payLen = pay;
    frames[nfr].uncomp = uncomp;
    totalPay += pay;
    totalUn += uncomp;
    src += hdr + pay;
    nfr++;
  }
  printf("frames=%d totalPay=%u totalUn=%u\n", nfr, totalPay, totalUn);
  for (int i = 0; i < nfr && i < 8; i++) {
    printf("  f%d: pay=%u uncomp=%u pay16=", i, frames[i].payLen, frames[i].uncomp);
    hex16(frames[i].pay, (int)frames[i].payLen);
    printf("\n");
  }

  uint8_t *concat = (uint8_t *)malloc(totalPay ? totalPay : 1);
  size_t cp = 0;
  for (int i = 0; i < nfr; i++) {
    memcpy(concat + cp, frames[i].pay, frames[i].payLen);
    cp += frames[i].payLen;
  }
  uint32_t outCap = wantOut ? wantOut : 0x200000;
  if (outCap < 256) outCap = 256;
  uint8_t *out = (uint8_t *)calloc(1, outCap + 64);

  if (!strcmp(mode, "concat") || !strcmp(mode, "all")) {
    printf("\n[1] concat+one-lzxd reset=0\n");
    memset(out, 0, outCap);
    uint32_t p = lzx_once(concat, (uint32_t)cp, out, outCap, outCap, 0);
    printf("RESULT concat produced=%u want=%u match=%d first16=", p, WANT, p == WANT);
    hex16(out, (int)p);
    printf("\n");
    if (!strcmp(mode, "concat")) return 0;
  }
  if (!strcmp(mode, "concat1") || !strcmp(mode, "all")) {
    printf("\n[1b] concat+one-lzxd reset=1\n");
    memset(out, 0, outCap);
    uint32_t p = lzx_once(concat, (uint32_t)cp, out, outCap, outCap, 1);
    printf("RESULT concat_r1 produced=%u want=%u match=%d first16=", p, WANT, p == WANT);
    hex16(out, (int)p);
    printf("\n");
    if (!strcmp(mode, "concat1")) return 0;
  }
  if (!strcmp(mode, "perframe") || !strcmp(mode, "all")) {
    printf("\n[2] per-frame fresh\n");
    memset(out, 0, outCap);
    uint32_t total = 0;
    int ok = 1;
    for (int i = 0; i < nfr; i++) {
      uint32_t want = frames[i].uncomp;
      if (total + want > outCap) want = outCap - total;
      MemFile in = { (uint8_t *)frames[i].pay, frames[i].payLen, 0 };
      MemFile of = { out + total, outCap - total, 0 };
      struct lzxd_stream *lzx = lzxd_init(&g_sys, (mspack_file *)&in, (mspack_file *)&of,
                                          WINDOW_BITS, 0, 0x8000, (off_t)want, 0);
      if (!lzx) { printf("    f%d init fail\n", i); ok = 0; break; }
      int rc = lzxd_decompress(lzx, (off_t)want);
      uint32_t p = (uint32_t)of.pos;
      printf("    f%d rc=%d produced=%u want=%u in=%zu/%u\n",
             i, rc, p, want, in.pos, frames[i].payLen);
      lzxd_free(lzx);
      if (p == 0) { ok = 0; break; }
      total += p;
    }
    printf("RESULT perframe produced=%u want=%u match=%d ok=%d first16=",
           total, WANT, total == WANT, ok);
    hex16(out, (int)total);
    printf("\n");
    if (!strcmp(mode, "perframe")) return 0;
  }
  if (!strcmp(mode, "shared") || !strcmp(mode, "all")) {
    printf("\n[3] shared-state one lzxd\n");
    memset(out, 0, outCap);
    uint32_t p = lzx_shared(concat, (uint32_t)cp, frames, nfr, out, outCap);
    printf("RESULT shared produced=%u want=%u match=%d first16=", p, WANT, p == WANT);
    hex16(out, (int)p);
    printf("\n");
    if (!strcmp(mode, "shared")) return 0;
  }
  if (!strcmp(mode, "concat8000")) {
    printf("\n[1c] concat+one-lzxd reset=0x8000 (XMem table refresh interval)\n");
    memset(out, 0, outCap);
    uint32_t p = lzx_once(concat, (uint32_t)cp, out, outCap, outCap, 0x8000);
    printf("RESULT concat_r8000 produced=%u want=%u match=%d first16=", p, WANT, p == WANT);
    hex16(out, (int)p);
    printf("\n");
    return 0;
  }
  if (!strcmp(mode, "sweep")) {
    printf("\n[SW] window_bits sweep, concat reset=0\n");
    for (int wb = 15; wb <= 21; wb++) {
      g_window_bits = wb;
      memset(out, 0, outCap);
      uint32_t p = lzx_once(concat, (uint32_t)cp, out, outCap, outCap, 0);
      printf("  wb=%d produced=%u match=%d head=", wb, p, p == WANT);
      hex16(out, 8);
      printf("\n");
    }
    return 0;
  }
  if (!strcmp(mode, "shared8000") || !strcmp(mode, "all")) {
    printf("\n[3b] shared-state one lzxd, per-frame want (implicit table refresh)\n");
    memset(out, 0, outCap);
    uint32_t p = lzx_shared(concat, (uint32_t)cp, frames, nfr, out, outCap);
    printf("RESULT shared produced=%u want=%u match=%d first16=", p, WANT, p == WANT);
    hex16(out, (int)p);
    printf("\n");
    if (!strcmp(mode, "shared8000")) return 0;
  }
  free(out);
  free(concat);
  free(pkg);
  return 0;
}
