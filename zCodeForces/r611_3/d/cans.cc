#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  set<ll> occ;
  using sta = pair<ll, ll>;
  queue<sta> que;
  for (ll i = 0; i < n; i++) {
    ll x; cin >> x;
    occ.insert(x);
    que.emplace(x, 1);
    que.emplace(x, -1);
  }
  ll val = 0;
  vector<ll> ans;
  while (m > 0) {
    auto [x, d] = que.front(); que.pop();
    ll y = x + d;
    if (occ.find(y) != occ.end()) continue;
    m--;
    val += abs(d);
    occ.insert(y);
    ans.push_back(y);
    if (d < 0) d--;
    else d++;
    que.emplace(x, d);
  }
  cout << val << endl;
  for (ll i = 0; i < (ll)ans.size(); i++) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}

