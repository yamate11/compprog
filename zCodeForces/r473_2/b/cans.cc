#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k, m; cin >> n >> k >> m;
  map<string, ll> mp;
  for (ll i = 0; i < n; i++) {
    string s; cin >> s;
    mp[s] = i;
  }
  vector<ll> cost(n);
  for (ll i = 0; i < n; i++) cin >> cost[i];
  vector<ll> belong(n);
  vector<vector<ll>> group(k);
  for (ll i = 0; i < k; i++) {
    ll x; cin >> x;
    for (ll j = 0; j < x; j++) {
      ll p; cin >> p; p--;
      group[i].push_back(p);
      belong[p] = i;
    }
  }
  vector<string> msg(m);
  for (ll i = 0; i < m; i++) cin >> msg[i];
  vector<ll> gcost(k);
  for (ll i = 0; i < k; i++) {
    ll c = LLONG_MAX;
    for (ll p : group[i]) c = min(c, cost[p]);
    gcost[i] = c;
  }
  ll ans = 0;
  for (ll i = 0; i < m; i++) {
    ans += gcost[belong[mp[msg[i]]]];
  }
  cout << ans << endl;

  return 0;
}

