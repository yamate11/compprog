#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, fwd, dir=True, bwd=bwd, dec=1) [9Sf3tsCx]
  auto fwd = vector(N, vector(0, int()));
  auto bwd = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd[u].emplace_back(v);
    bwd[v].emplace_back(u);
  }
  // @End [9Sf3tsCx]

  vector<ll> color(N, 0LL);
  
  auto dfs = [&](auto rF, ll nd) -> void {
    if (color[nd] == 1) return;
    color[nd] = 1;
    for (ll a : bwd[nd]) rF(rF, a);
  };

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll v; cin >> v; v--;
      dfs(dfs, v);
    }else if (tp == 2) {
      ll v; cin >> v; v--;
      cout << (color[v] == 1 ? "Yes\n" : "No\n");
    }else assert(0);
  }
  

  return 0;
}

