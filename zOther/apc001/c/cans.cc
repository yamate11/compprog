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
  cout << 0 << endl;
  string a;
  cin >> a;
  if (a == "Vacant") return 0;
  string sLo = a;
  string sHi = a;
  int iLo = 1;
  int iHi = N - 1;
  while (1) {
    DLOG("%s %d %d %s\n", sLo.c_str(), iLo, iHi, sHi.c_str());
    int i = (iLo + iHi) / 2;
    cout << i << endl;
    cin >> a;
    if (a == "Vacant") return 0;
    if (   ((i - iLo) % 2 == 0 && sLo != a) ||
	   ((i - iLo) % 2 == 1 && sLo == a) ) {
      sLo = a;
      iLo = i + 1;
    }else {
      sHi = a;
      iHi = i - 1;
    }
  }

  return 0;
}

