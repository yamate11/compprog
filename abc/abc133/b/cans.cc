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

ll N, D;
vector<vector<ll>> X;

bool sqn(ll x) {
  ll y = sqrt(x);
  return y*y == x;
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

  cin >> N >> D;
  X.resize(N);
  for (ll j = 0; j < N; j++) {
    X.at(j).resize(D);
    for (ll i = 0; i < D; i++) {
      cin >> X.at(j).at(i);
    }
  }
  ll ans = 0;
  for (ll j = 0; j < N; j++) {
    for (ll k = j+1; k < N; k++) {
      ll s = 0;
      for (ll i = 0; i < D; i++) {
	ll t = X.at(j).at(i) - X.at(k).at(i);
	s += t*t;
      }
      if (sqn(s)) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}

