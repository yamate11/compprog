#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main() {
  ll N; cin >> N;
  vector<vector<pll>> nbr(N);
  REP(i, 0, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].emplace_back(b, i);
    nbr[b].emplace_back(a, i);
  }
  ll K = 1;
  vector<ll> ans(N - 1);
  auto dfs = [&](auto rF, ll nd, ll pt, ll pt_col) -> void {
    ll col = 0;
    for (auto [cld, idx] : nbr[nd]) {
      if (cld == pt) continue;
      if (++col == pt_col) ++col;
      ans[idx] = col;
      rF(rF, cld, nd, col);
    }
    K = max(K, col);
  };
  dfs(dfs, 0, -1, -1);
  cout << K << "\n";
  REP(idx, 0, N - 1) cout << ans[idx] << "\n";
  return 0;
}

