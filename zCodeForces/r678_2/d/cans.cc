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
  vector<ll> parent(n);
  vector<vector<ll>> child(n);
  for (ll i = 1; i < n; i++) {
    ll p; cin >> p; p--;
    parent[i] = p;
    child[p].push_back(i);
  }
  vector<ll> popul(n);
  for (ll i = 0; i < n; i++) cin >> popul[i];
  using sta = tuple<ll, ll, ll>;
  auto dfs = [&](auto rF, ll nd) -> sta {
    if (child[nd].empty()) return {popul[nd], 0, 1};
    vector<sta> rec;
    ll cmax = 0;
    for (ll c : child[nd]) {
      auto [cur, sp, num] = rF(rF, c);
      cmax = max(cmax, cur);
      rec.emplace_back(cur, sp, num);
    }
    ll thpop = popul[nd];
    ll newSp = 0;
    ll newNum = 0;
    for (auto [cur, sp, num] : rec) {
      newSp += sp + (cmax - cur) * num;
      newNum += num;
    }
    if (newSp >= thpop) return {cmax, newSp - thpop, newNum};
    thpop -= newSp;
    ll x = thpop / newNum;
    ll y = thpop % newNum;
    if (y == 0) return {cmax + x, 0, newNum};
    return {cmax + x + 1, newNum - y, newNum};
  };
  auto [cur, sp, num] = dfs(dfs, 0);
  cout << cur << endl;

  return 0;
}

