#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#if defined(DEBUG)

#include <unistd.h>
#include <sys/fcntl.h>
#define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
#define DCALL(func, ...) func(__VA_ARGS__)

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#else  // defined(DEBUG)

#define DLOG(...)
#define DCALL(func, ...)

#endif // defined(DEBUG)
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
struct T {
  int xc;
  int yc;
  int idx;
  T(int xxc, int yyc, int iidx) : xc(xxc), yc(yyc), idx(iidx) {}
};

int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cout << setprecision(20);

  int R, C, N; cin >> R >> C >> N;

  auto edge = [&](int x, int y) -> bool {
    return x == 0 || x == R || y == 0 || y == C;
  };

  auto eord = [&](int x, int y) -> int {
    if (y == 0) return x;
    if (x == R) return R + y;
    if (y == C) return R + C + (R - x);
    if (x == 0) return R + C + R + (C - y);
    assert(false);
  };

  vector<T> P;
  int idx = 0;
  for (int i = 0; i < N; i++) {
    int p, q, r, s; cin >> p >> q >> r >> s;
    if (edge(p, q) && edge(r, s)) {
      P.emplace_back(p, q, idx);
      P.emplace_back(r, s, idx);
      idx++;
    }
  }
  sort(P.begin(), P.end(),
       [&](T u, T v) { return eord(u.xc, u.yc) < eord(v.xc, v.yc); });
  stack<T> st;
  for (auto u : P) {
    if (!st.empty() && st.top().idx == u.idx) {
      st.pop();
      DLOG("popped: (%d, %d, %d)", u.xc, u.yc, u.idx);
    }else {
      st.push(u);
      DLOG("popped: (%d, %d, %d)", u.xc, u.yc, u.idx);
    }
  }
  cout << (st.empty() ? "YES" : "NO") << endl;

  return 0;
}

