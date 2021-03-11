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
void show(auto v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
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

  int N; cin >> N;
  vector <int> C(N), D(N+1), M(N+1);
  for (int i = 0; i < N; i++) {
    int a; cin >> a; a--;
    C.at(a)++;
  }
  sort(C.begin(), C.end(), greater<int>());
  int prevVal = 0;
  for (int i = N-1; i >= 0; i--) {
    if (C.at(i) == prevVal) continue;
    for (int j = prevVal + 1; j <= C.at(i); j++) D.at(j) = i + 1;
    prevVal = C.at(i);
  }

  int s = 0;
  M.at(0) = N;
  for (int i = 1; i <= N; i++) {
    s += D.at(i);
    M.at(i) = s / i;
  }
  
  int i = N;
  int j = 1;
  while (i >= 0 && j <= N) {
    if (M.at(i) >= j) {
      cout << i << "\n";
      j++;
    }else {
      i--;
    }
  }

  return 0;
}

