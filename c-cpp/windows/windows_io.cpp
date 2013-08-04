#include <Windows.h>
#include <cassert>
#include <cstdio>

template <typename F>
struct ScopeExit {
    ScopeExit(F f) : f(f) {}
    ~ScopeExit() { f(); }
    F f;
};

template <typename F>
ScopeExit<F> MakeScopeExit(F f) {
    return ScopeExit<F>(f);
};
#define STRING_JOIN2(arg1, arg2) DO_STRING_JOIN2(arg1, arg2)
#define DO_STRING_JOIN2(arg1, arg2) arg1 ## arg2
#define SCOPE_EXIT(code) \
    auto STRING_JOIN2(scope_exit_, __LINE__) = MakeScopeExit([&](){code;})


int main() {
  auto fn = L"C:\\Users\\skyshaw\\Desktop\\data.txt";
  auto f = CreateFile(fn, GENERIC_READ, FILE_SHARE_READ, nullptr,
    OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
  assert(fn);
  SCOPE_EXIT(CloseHandle(f));

  char b[64];
  DWORD c;
  ReadFile(f, b, sizeof(b), &c, nullptr);
  std::printf("> %.*s\n", c, b);
  return 0;
}