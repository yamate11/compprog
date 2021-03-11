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

void solve(ll a, ll b, ll c) {
  ll s = 100 * a + 10 * b + c;
  if (s % 2 == 1) {
    cout << "No\n";
    return;
  }
  s /= 2;
  s -= min(100 * a, 100 * (s / 100));
  s -= min(10 * b, 10 * (s / 10));
  s -= min(c, s);
  if (s == 0) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

}

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

  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    ll a, b, c;  cin >> a >> b >> c;
    solve(a, b, c);
  }
  return 0;
}

