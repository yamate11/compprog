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

  int N, M; cin >> N >> M;
  ll allsum = 0;

  vector<ll> reduce;
  for (int i = 0; i < N; i++) {
    ll a; cin >> a;
    allsum += a;
    while (a > 0) {
      ll nxtA = a / 2;
      ll red = a - nxtA;
      reduce.push_back(red);
      a = nxtA;
    }
  }
  sort(reduce.begin(), reduce.end(),
       [&](int x, int y) { return x > y; });
  ll redsum = 0;
  int rs = reduce.size();
  int lim = min(M, rs);
  for (int i = 0; i < lim; i++) {
    redsum += reduce.at(i);
  }
  cout << (allsum - redsum) << endl;

  return 0;
}

