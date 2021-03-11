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

  string S; cin >> S;
  int k = 0;
  int i = 0;
  int prevLen = 2;
  while (i < (int)S.size()) {
    if (i+2 == (int)S.size() && S.at(i) == S.at(i+1)) {
      k += 1;
      i += 2;
    } else if (prevLen > 1) {
      k += 1;
      i += 1;
      prevLen = 1;
    }else if (i+4 == (int)S.size() &&
	      S.at(i-1) == S.at(i) &&
	      S.at(i) == S.at(i+1) &&
	      S.at(i+1) == S.at(i+2) &&
	      S.at(i+2) == S.at(i+3)) {
      k += 2;
      i += 4;
    }else if (S.at(i-1) == S.at(i)) {
      k += 1;
      i += 2;
      prevLen = 2;
    }else {
      k += 1;
      i += 1;
      prevLen = 1;
    }
  }

  cout << k << endl;

  return 0;
}

