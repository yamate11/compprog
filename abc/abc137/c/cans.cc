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

  int N;
  cin >> N;
  vector<string> s(N);
  for (int i = 0; i < N; i++) {
    string t; cin >> t;
    char c[11];
    t.copy(c, 10, 0);
    c[10] = 0;
    sort(c, c+10);
    s.at(i) = string(c);
  }
  sort(s.begin(), s.end());
  string prev = "";
  ll cnt = -1;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if (s.at(i) == prev) cnt++;
    else {
      if (cnt > 1) ans += cnt * (cnt - 1) / 2;
      cnt = 1;
      prev = s.at(i);
    }
  }
  if (cnt > 1) ans += cnt * (cnt - 1) / 2;
  cout << ans << endl;

  return 0;
}

