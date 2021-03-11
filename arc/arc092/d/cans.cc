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
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < N; i++) cin >> B.at(i);

  int ans = 0;
  for (int k = 0; k <= 30; k++) {
    vector<int> C(N), D(N);
    for (int i = 0; i < N; i++) {
      C.at(i) = A.at(i) & ((1 << (k+1)) - 1);
      D.at(i) = B.at(i) & ((1 << (k+1)) - 1);
    }
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());
    int p = 0; 
    int q = 0; 
    int r = 0; 
    for (int i = N-1; i >= 0; i--) {
      function<int(int,int)> upd = [&](int j0, int t) {
	for (int j = j0; j < N; j++) {
	  if (C.at(i) + D.at(j) >= (t << k)) return j;
	}
	return N;
      };
      p = upd(p, 1);
      q = upd(q, 2);
      r = upd(r, 3);
      int x = ((q - p) + (N - r)) % 2;
      ans = ans ^ (x << k);
    }
  }
  cout << ans << endl;

  return 0;
}

