#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DLOG(...)
#endif

void debug(auto f) {
#if DEBUG
  f();
#endif
}

ll K;
vector<ll> ans;

ll colS(ll x) {
  ll s = 0;
  while (x > 0) {
    s += x % 10;
    x = x / 10;
  }
  return s;
}

ll seq9(ll k, ll n) {
  ll t = 1;
  for (ll i = 0; i < n; i++) {
    t *= 10;
  }
  return (k+1) * t - 1;
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> K;
  for (ll i = 1; i <= 9; i++)  ans.push_back(i);
  ll z = 9;
  ll n = 1;
  ll k = 1;
  while (z < K) {
    while (k - colS(k) <= 9 * n - 1) {
      ans.push_back(seq9(k, n));
      k++;
      z++;
    }
    n += 1;
    k /= 10;
  }
  for (ll w = 0; w < K; w++) {
    cout << ans.at(w) << "\n";
  }

  return 0;
}

