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

  ll N, K; cin >> N >> K;
  vector<ll> A(N), F(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < N; i++) cin >> F.at(i);
  sort(A.begin(), A.end(), greater<ll>());
  sort(F.begin(), F.end());
  
  ll lo = -1;
  ll hi = (ll)(1e12) + 10;
  while (lo + 1 < hi) {
    ll mid = (lo + hi) / 2;
    ll s = 0;
    for (int i = 0; i < N; i++) {
      ll g = mid / F.at(i);
      if (A.at(i) > g) s += A.at(i) - g;
    }
    if (s <= K) {
      hi = mid;
    }else {
      lo = mid;
    }
  }
  cout << hi << endl;
  return 0;
}

