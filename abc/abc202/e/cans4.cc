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
  vector<ll> parent(N + 1);
  vector<vector<ll>> child(N + 1);
  for (ll i = 2; i <= N; i++) {
    ll p; cin >> p;
    parent[i] = p;
    child[p].push_back(i);
  }
  vector<ll> e_in(N + 1), e_out(N + 1), etour(2*N);
  vector<vector<ll>> per_depth;
  ll idx = 0;
  auto dfs = [&](auto rF, ll nd, ll depth) -> void {
    if (depth >= (ll)per_depth.size()) per_depth.resize(depth + 1);
    per_depth[depth].push_back(idx);
    etour[idx] = nd;
    e_in[nd] = idx++;
    for (ll cld : child[nd]) rF(rF, cld, depth+1);
    etour[idx] = -nd;
    e_out[nd] = idx++;
  };
  dfs(dfs, 1, 0);

  ll Q; cin >> Q;
  for (ll _q = 0; _q < Q; _q++) {
    ll u, d; cin >> u >> d;
    if (d >= (ll)per_depth.size()) {
      cout << "0\n";
    }else {
      const vector<ll>& vec = per_depth[d];
      ll lo = lower_bound(vec.begin(), vec.end(), e_in[u]) - vec.begin();
      ll hi = lower_bound(vec.begin(), vec.end(), e_out[u]) - vec.begin();
      cout << hi - lo << "\n";
    }
  }

  return 0;
}

