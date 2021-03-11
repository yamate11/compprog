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
int fstDiff(string s) {
  int i = 1;
  while (i < (int) s.size()) {
    if (s.at(i-1) != s.at(i)) return i;
    i++;
  }
  return -1;
}

ll func(string s) {
  ll rv = 0;
  int i = 1;
  int cnt = 1;
  while (i < (int) s.size()) {
    if (s.at(i-1) == s.at(i)) {
      cnt ++;
    }else {
      rv += cnt / 2;
      cnt = 1;
    }
    i++;
  }
  rv += cnt / 2;
  return rv;
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

  string S;
  ll K;
  cin >> S >> K;
  ll ssize = S.size();

  int i = fstDiff(S);
  if (i == -1) {
    cout << ssize * K / 2 << endl;
    return 0;
  }
  string S1 = S.substr(0, i);
  string S2 = S.substr(i, ssize - i);
  string SS = S2 + S1;
  ll n1 = func(S1);
  ll n2 = func(S2);
  ll nn = func(SS);
  ll ans = n1 + n2 + nn * (K-1);
  cout << ans << endl;
  return 0;
}

