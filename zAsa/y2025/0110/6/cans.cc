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
  // @InpNbrList(N, M, fwd, dir=True, dec=1, read=W) [loZzJnB1]
  struct fwd_t {
    int nd;
    ll W;
    // fwd_t() {}
    fwd_t(int nd_ = int(), ll W_ = ll()) : nd(nd_), W(W_) {}
  };
  auto fwd = vector(N, vector(0, fwd_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll W; cin >> W;
    fwd[u].emplace_back(v, W);
  }
  // @End [loZzJnB1]

  ll big = 1e18;
  vector tbl(1LL << N, vector(N, big));
  vector<pll> cands;
  REP(nd, 0, N) {
    tbl[1LL << nd][nd] = 0;
    cands.emplace_back(1LL << nd, nd);
  }
  while (not cands.empty()) {
    auto prev = move(cands);
    cands = vector<pll>();
    for (auto [x, nd] : prev) {
      for (auto [peer, w] : fwd[nd]) {
        ll new_x = x | (1LL << peer);
        ll new_val = tbl[x][nd] + w;
        if (tbl[new_x][peer] > new_val) {
          tbl[new_x][peer] = new_val;
          cands.emplace_back(new_x, peer);
        }
      }
    }
  }
  ll ans = big;
  REP(i, 0, N) ans = min(ans, tbl[(1LL << N) - 1][i]);
  if (ans == big) {
    cout << "No\n";
  }else {
    cout << ans << endl;
  }

  return 0;
}

