#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mPrime = 1000 * 1000 * 1000 + 7;

ll mMul(ll x, ll y) {
  return (x * y) % mPrime;
}

ll fact(ll n) {
  ll ans = 1;
  for (ll i = 1; i <= n; i++) {
    ans = mMul(ans, i);
  }
  return ans;
}

ll f(ll n) {
  ll x = fact(n);
  return mMul(2, mMul(x, x));
}

ll g(ll n) {
  ll x = fact(n);
  return mMul(x, mMul(x, n+1));
}

int main() {
  ll n, m;
  cin >> n >> m;
  ll ans = n == m ? f(n) : n == m+1 ? g(m) : m == n+1 ? g(n) : 0;
  cout << ans << endl;
  return 0;
}
