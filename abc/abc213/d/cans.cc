#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<vector<ll>> nbr(N);
  for (ll i = 0; i < N - 1; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  for (ll i = 0; i < N; i++) { sort(nbr[i].begin(), nbr[i].end()); }
  vector<ll> ans;
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    ans.push_back(nd);
    if (nd != 0 && nbr[nd].size() == 1) return;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
      ans.push_back(nd);
    }
  };
  dfs(dfs, 0, -1);

  for (ll x : ans) {
    cout << x + 1 << " ";
  }
  cout << "\n";

  return 0;
}

