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
  // @InpNbrList(N, M, fwd, dir=True, bwd=bwd, dec=1, read=W) [EBJ1JTeD]
  struct fwd_t {
    int nd;
    ll W;
    fwd_t(int nd_ = int(), ll W_ = ll()) : nd(nd_), W(W_) {}
  };
  auto fwd = vector(N, vector(0, fwd_t()));
  auto bwd = vector(N, vector(0, fwd_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll W; cin >> W;
    fwd[u].emplace_back(v, W);
    bwd[v].emplace_back(u, W);
  }
  // @End [EBJ1JTeD]
  ll lim = 1LL << 10;
  vector vals(N, vector<ll>(lim, false));
  vector<pll> cands;
  vals[N - 1][0] = true;
  cands.emplace_back(N - 1, 0);
  while (not cands.empty()) {
    auto [i, v] = cands.back(); cands.pop_back();
    for (auto [j, w] : bwd[i]) {
      if (not vals[j][v ^ w]) {
        vals[j][v ^ w] = true;
        cands.emplace_back(j, v ^ w);
      }
    }
  }
  REP(v, 0, lim) {
    if (vals[0][v]) {
      cout << v << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}

