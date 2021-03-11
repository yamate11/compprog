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

  int N, K; cin >> N >> K;
  vector<int> A(N);
  ll asum = 0;
  for (int i = 0; i < N; i++)  {
    cin >> A.at(i);
    asum += A.at(i);
  }
  sort(A.begin(), A.end());
  vector<bool> tbl(K);
  tbl.at(0) = true;
  int high = 0;
  int i = N-1;
  for ( ; i >= 0; i--) {
    if (high + asum < K) break;
    int a = A.at(i);
    asum -= a;
    for (int j = min(high + a, K-1); j-a >= 0; j--) {
      if (! tbl.at(j-a)) continue;
      tbl.at(j) = true;
      high = max(high, j);
    }
  }
  cout << (i+1) << endl;

  return 0;
}

