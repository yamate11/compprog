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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpNbrList(N, N - 1, nbr, dec=1) [LuUW5Ati]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [LuUW5Ati]
  vector op(N, 0LL);
  REP(i, 0, Q) {
    ll p, x; cin >> p >> x; p--;
    op[p] += x;
  }
  vector<ll> ans(N);
  ll cur = 0;
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    cur += op[nd];
    ans[nd] = cur;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
    }
    cur -= op[nd];
  };
  dfs(dfs, 0, -1);
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}

