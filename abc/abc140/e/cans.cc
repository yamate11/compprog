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

  int N; cin >> N;
  vector<ll> P(N), od(N);
  for (int i = 0; i < N; i++) cin >> P.at(i);
  iota(od.begin(), od.end(), 0);
  sort(od.begin(), od.end(),
       [&](int i, int j) { return P.at(i) > P.at(j); });
  set<ll> indices;
  ll ans = 0;
  for (int i : od) {
    auto it = indices.insert(i).first;
    int x2 = -1, x1 = -1, y1 = N, y2 = N;
    auto it0 = it;
    if (it0 != indices.begin()) {
      x1 = *--it0;
      if (it0 != indices.begin()) x2 = *--it0;
    }
    it0 = it;
    if (++it0 != indices.end()) {
      y1 = *it0;
      if (++it0 != indices.end()) y2 = *it0;
    }
    DLOG("i=%d, x2=%d, x1=%d, i=%d, y1=%d, y2=%d, P.at(i)=%d",
	 i, x2, x1, i, y1, y2, P.at(i));
    ans += P.at(i) * ((x1 - x2) * (y1 - i) + (y2 - y1) * (i - x1));
  }
  cout << ans << endl;

  return 0;
}

