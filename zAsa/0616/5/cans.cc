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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpNbrList(N, N - 1, nbr, dec=1, read=C) [TyAy5iKk]
  struct nbr_t {
    int nd;
    ll C;
    string show() const {
      return format("({}, {})", nd, C);
    }
    auto operator<=>(const nbr_t&) const = default;
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  ll tot = 0;
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
    tot += C;
  }
  // @End [TyAy5iKk]

  auto dfs = [&](auto rF, ll nd, ll pt) -> pll {
    ll p = nd;
    ll d = 0;
    for (auto [peer, len] : nbr[nd]) {
      if (peer == pt) continue;
      auto [p0, d0] = rF(rF, peer, nd);
      if (d < d0 + len) {
        d = d0 + len;
        p = p0;
      }
    }
    return pll(p, d);
  };
  auto [r1, d1] = dfs(dfs, 0, -1);
  auto [r2, d2] = dfs(dfs, r1, -1);
  cout << tot * 2 - d2 << endl;
  return 0;
}

