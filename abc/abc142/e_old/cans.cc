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
typedef pair<int, int> Pair;

int myInf = 1e9;

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

  int full = (1 << N) - 1;
  vector<int> v(full + 1, myInf);
  v.at(0) = 0;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    int x = 0;
    for (int j = 0; j < b; j++) {
      int c;
      cin >> c; c--;
      x |= (1 << c);
    }

    for (int y = 0; y <= full; y++) {
      int cup = y | x;
      v.at(cup) = min(v.at(cup), v.at(y) + a);
    }

  }


  if (v.at(full) == myInf) {
    cout << -1 << endl;
  }else {
    cout << v.at(full) << endl;
  }

  return 0;
}

