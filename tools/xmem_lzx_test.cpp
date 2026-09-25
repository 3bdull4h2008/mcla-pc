// Offline validator for src/xmem_lzx.h: decodes the 4 UI .xsf from the RPF and
// byte-compares against build/xmem_golden/*.bin. Build with cl (vcvars):
//   cl /EHsc /O2 /std:c++17 tools/xmem_lzx_test.cpp /Fe:build/xmem_lzx_test.exe
#include <cstdio>
#include <cstdint>
#include <vector>
#include "../src/xmem_lzx.h"

static const char* kArchive = "E:\\mcla pc\\build\\game_data\\xarchive_cache.rpf";
static const char* kGoldenDir = "E:\\mcla pc\\build\\xmem_golden\\";

struct Entry { const char* name; uint32_t off; };
static Entry kEntries[] = {
    {"raceeditor", 0x64CB0000u}, {"garage", 0x64980000u},
    {"policecam", 0x64CA3000u}, {"credits", 0x6496F000u},
};

int main() {
  FILE* a = nullptr;
  fopen_s(&a, kArchive, "rb");
  if (!a) { printf("cannot open archive\n"); return 2; }
  int fails = 0;
  for (auto& e : kEntries) {
    const size_t readlen = 0x400000;
    std::vector<uint8_t> pkg(readlen);
    fseek(a, (long)e.off, SEEK_SET);
    size_t got = fread(pkg.data(), 1, readlen, a);
    pkg.resize(got);
    std::vector<uint8_t> out;
    int path = mcla_lzx::host_decode_ui_xsf(pkg.data(), pkg.size(), out);
    char gpath[256];
    sprintf_s(gpath, "%s%s.bin", kGoldenDir, e.name);
    FILE* g = nullptr;
    fopen_s(&g, gpath, "rb");
    std::vector<uint8_t> gold;
    if (g) {
      fseek(g, 0, SEEK_END); long n = ftell(g); fseek(g, 0, SEEK_SET);
      gold.resize(n); fread(gold.data(), 1, n, g); fclose(g);
    }
    bool exact = path && !gold.empty() && out == gold;
    printf("[%-11s] path=%d produced=%zu golden=%zu head=%02x%02x%02x%02x %s\n",
           e.name, path, out.size(), gold.size(),
           out.size() > 0 ? out[0] : 0, out.size() > 1 ? out[1] : 0,
           out.size() > 2 ? out[2] : 0, out.size() > 3 ? out[3] : 0,
           exact ? "EXACT" : "MISMATCH");
    if (!exact) fails++;
  }
  fclose(a);
  printf("%s (%d failures)\n", fails ? "FAIL" : "PASS", fails);
  return fails ? 1 : 0;
}
