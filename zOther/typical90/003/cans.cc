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
  auto nbr = vector(N + 1, vector<ll>());
  for (ll i = 0; i < N-1; i++) {
    ll a, b; cin >> a >> b;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  using sta = pair<ll, ll>;
  auto dfs = [&](auto rF, ll nd, ll pt) -> sta {
    ll maxd = -1;
    ll arg = -1;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      auto [v, va] = rF(rF, cld, nd);
      if (v > maxd) {
        maxd = v;
        arg = va;
      }
    }
    if (maxd < 0) { return {1, nd}; }
    return {1 + maxd, arg};
  };
  auto [_d, fst] = dfs(dfs, 1, -1);
  auto [dist, snd] = dfs(dfs, fst, -1);
  cout << dist << endl;

  return 0;
}

