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
  vector<int> a(N+1);
  for (int i = 1; i <= N; i++)  cin >> a.at(i);
  vector<char> p(N+1);
  int k = 0;
  for (int i = N; i >= 1; i--) {
    char x = a.at(i);
    for (int j = i*2; j <= N; j += i) {
      if (p.at(j)) x = 1 - x;
    }
    p.at(i) = x;
    k += x;
  }
  cout << k << endl;
  bool first = true;
  for (int i = 1; i <= N; i++) {
    if (p.at(i)) {
      if (first) first = false;
      else       cout << " ";
      cout << i;
    }
  }
  if (k > 0)  cout << endl;

  return 0;
}

