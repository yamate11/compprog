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
  vector<vector<ll>> child(N + 1);
  for (ll i = 2; i <= N; i++) {
    ll p; cin >> p;
    child[p].push_back(i);
  }
  using sta = pair<ll, ll>;
  vector<vector<sta>> req(N + 1);
  ll Q; cin >> Q;
  for (ll idx = 0; idx < Q; idx++) {
    ll u, d; cin >> u >> d;
    req[u].emplace_back(d, idx);
  }
  vector<ll> ans(Q);
  auto dfs = [&](auto rF, ll nd, ll depth) -> deque<ll> {
    deque<ll> ret;
    ret.push_back(1);
    for (ll cld : child[nd]) {
      auto oth = rF(rF, cld, depth + 1);
      oth.push_front(0);
      if (ret.size() < oth.size()) { swap(ret, oth); }
      for (ll i = 0; i < (ll)oth.size(); i++) { ret[i] += oth[i]; }
    }
    for (auto [d, idx] : req[nd]) {
      ll dd = d - depth;
      if (0 <= dd && dd < (ll)ret.size()) { ans[idx] = ret[dd]; }
    }
    return ret;
  };
  dfs(dfs, 1, 0);
  for (ll i = 0; i < Q; i++) cout << ans[i] << "\n";

  return 0;
}

