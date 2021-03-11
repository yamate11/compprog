#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = []() -> ll {
    ll n, k; cin >> n >> k;
    vector<ll> A(n), W(k);
    for (ll i = 0; i < n; i++) cin >> A.at(i);
    for (ll i = 0; i < k; i++) cin >> W.at(i);
    sort(A.begin(), A.end());
    sort(W.begin(), W.end(), greater<ll>());
    ll ans = 0;
    ll cur = 0;
    for (ll i = 0; i < k; i++) {
      if (W.at(i) == 1) break;
      ans += A.at(cur);
      cur += W.at(i) - 1;
    }
    for (ll i = 0; i < k; i++) {
      if (W.at(k-1-i) == 1) ans += A.at(n-1-i);
      ans += A.at(n-1-i);
    }
    return ans;
  };

  ll t; cin >> t;
  for (ll i = 0; i < t; i++) {
    cout << solve() << "\n";
  }

  return 0;
}

