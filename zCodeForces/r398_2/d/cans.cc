#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m, k; cin >> n >> m >> k;
  ll lim = 1e7 + 10;
  vector<ll> af(lim);
  using sta = pair<ll, ll>;
  vector<sta> ss;
  for (ll i = 0; i < n; i++) {
    ll x; cin >> x;
    af[x]++;
  }
  for (ll i = 0; i < m; i++) {
    ll x; cin >> x;
    ss.emplace_back(x, i);
  }
  vector<ll> eb(lim);
  ll carry = 0;
  for (ll i = lim - 1; i >= 0; i--) {
    ll y = carry + af[i];
    if (y <= k) {
      eb[i] = y;
      carry = 0;
    }else {
      eb[i] = k;
      carry = y - k;
    }
  }
  if (carry > 0) {
    cout << -1 << endl;
    return 0;
  }
  sort(ss.begin(), ss.end(), greater<sta>());
  ll p = lim - 1;
  vector<ll> ans;
  for (auto [x, i] : ss) {
    p = min(p, x);
    while (p >= 0 && eb[p] == k) p--;
    if (p < 0) break;
    eb[p]++;
    ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (ll i = 0; i < (ll)ans.size(); i++) {
    if (i > 0) cout << " ";
    cout << ans[i] + 1;
  }
  cout << endl;


  return 0;
}

