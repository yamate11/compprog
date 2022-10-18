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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpNbrList(N, N - 1, nbr, dec=1, read=w) [kGp9Ggpt]
  struct nbr_t {
    int nd;
    ll w;
    nbr_t() {}
    nbr_t(int nd_, ll w_) : nd(nd_), w(w_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll w; cin >> w;
    nbr[u].emplace_back(v, w);
    nbr[v].emplace_back(u, w);
  }
  // @End [kGp9Ggpt]
  vector<ll> ans(N);
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    for (auto cld : nbr[nd]) {
      if (cld.nd == pt) continue;
      if (cld.w % 2 == 0) ans[cld.nd] = ans[nd];
      else ans[cld.nd] = 1 - ans[nd];
      rF(rF, cld.nd, nd);
    }
  };
  dfs(dfs, 0, -1);
  REPOUT(i, 0, N, ans[i], "\n");

  return 0;
}

