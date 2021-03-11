#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<vector<ll>> P(n, vector<ll>(5));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < 5; j++) cin >> P[i][j];
  }

  if (n >= 100) {
    cout << 0 << endl;
    return 0;
  }
  vector<ll> ans;
  for (ll i = 0; i < n; i++) {
    bool succ = true;
    for (ll j = 0; j < n; j++) {
      if (i == j) continue;
      vector<ll> v(5);
      for (ll x = 0; x < 5; x++) v[x] = P[j][x] - P[i][x];
      for (ll k = j + 1; k < n; k++) {
        if (k == i) continue;
        vector<ll> w(5);
        for (ll x = 0; x < 5; x++) w[x] = P[k][x] - P[i][x];
        ll s = 0;
        for (ll x = 0; x < 5; x++) s += v[x] * w[x];
        if (s > 0) {
          succ = false;
          break;
        }
      }
      if (!succ) break;
    }
    if (succ) ans.push_back(i);
  }
  ll sz = ans.size();
  cout << sz << endl;
  for (ll i = 0; i < sz; i++) {
    cout << ans[i] + 1 << "\n";
  }
  return 0;
}

