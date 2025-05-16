#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

using pll = pair<ll, ll>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> D(N); REP(i, N) {
    cin >> D[i];
  }
  vector nbr(N, vector<pll>());
  
  REP(i, N - 1) {
    ll u, v, w; cin >> u >> v >> w; u--; v--;
    if (w < 0) w = 0;
    nbr[u].emplace_back(v, w);
    nbr[v].emplace_back(u, w);
  }
  vector base(N, 0LL);
  vector bonus(N, 0LL);
  auto dfs = [&](auto rF, ll nd, ll pt, ll w) -> void {
    ll mbase = 0;
    vector<ll> mbonus;
    for (auto [cld, ww] : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd, ww);
      mbase += base[cld];
      mbonus.push_back(bonus[cld]);
    }
    sort(ALL(mbonus), greater<ll>());
    if (D[nd] == 0) {
      base[nd] = mbase;
      bonus[nd] = 0;
    }else {
      ll vbonus = 0;
      REP(i, D[nd] - 1) vbonus += mbonus[i];
      ll vbonusPlus = D[nd] - 1 < SIZE(mbonus) ? mbonus[D[nd] - 1] : 0;
      base[nd] = mbase + vbonus + vbonusPlus;
      bonus[nd] = max(w - vbonusPlus, 0LL);
    }
  };
  dfs(dfs, 0, -1, 0);
  cout << base[0] << endl;

  return 0;
}

