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
  int first = 0;
  int second = 0;
  int firstarg, secondarg;
  for (int i = 1; i <= N; i++) {
    int a; cin >> a;
    if (a >= first) {
      second = first;
      secondarg = firstarg;
      first = a;
      firstarg = i;
    }else if (a >= second) {
      second = a;
      secondarg = i;
    }
  }
  for (int j = 1; j <= N; j++) {
    if (j == firstarg) cout << second << "\n";
    else               cout << first << "\n";
  }

  return 0;
}

