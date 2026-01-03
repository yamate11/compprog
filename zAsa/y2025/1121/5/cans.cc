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
  // @InpNbrList(N, M, nbr, dec=1, read=C) [Xy64rBlO]
  struct nbr_t {
    int nd;
    ll C;
    nbr_t(int nd_ = int(), ll C_ = ll()) : nd(nd_), C(C_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
  }
  // @End [Xy64rBlO]
  vector<ll> ans(N);
  vector<bool> visited(N);
  auto f = [&](auto rF, ll nd, ll col) -> void {
    visited[nd] = true;
    ans[nd] = col;
    for (auto [peer, e_col] : nbr[nd]) {
      e_col--;
      if (not visited[peer]) {
        ll p_col;
        if (col != e_col) p_col = e_col;
        else p_col = (col + 1) % N;
        rF(rF, peer, p_col);
      }
    }
  };
  f(f, 0, 0);
  REPOUT(i, 0, N, ans[i] + 1, "\n");

  return 0;
}

