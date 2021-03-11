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

  int A, B, X; cin >> A >> B >> X;
  double da = A;
  double db = B;
  double dx = (double)X / da;

  double th = 0.0;
  double pi = 4.0 * atan2(1,1);
  if (2 * dx <= da * db) {
    th = atan2(2*dx / db, db);
  }else {
    th = atan2(da, 2 * (da * db - dx) / da);
  }
  double ans = 90.0 - th / pi * 180.0;
  cout << ans << endl;

  return 0;
}

