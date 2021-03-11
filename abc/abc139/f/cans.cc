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
  vector<ll> x(N), y(N);
  vector<double> arg(N);
  for (int i = 0; i < N; i++) {
    cin >> x.at(i) >> y.at(i);
    arg.at(i) = atan2(y.at(i), x.at(i));
  }
  vector<int> ordA(N);
  iota(ordA.begin(), ordA.end(), 0);
  sort(ordA.begin(), ordA.end(),
       [&](int a, int b) { return arg.at(a) < arg.at(b); });
  ll dsqr = 0;
  
  for (int i = 0; i < N; i++) {
    ll sx = 0;
    ll sy = 0;
    for (int j = i; j < i + N; j++) {
      int k = ordA.at(j % N);
      sx += x.at(k);
      sy += y.at(k);
      dsqr = max(dsqr, sx * sx + sy * sy);
    }
  }
  double ans = sqrt(dsqr);
  cout << ans << endl;

  return 0;
}

