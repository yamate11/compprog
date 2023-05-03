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

  ll N; cin >> N;
  // @InpNbrList(N, N - 1, nbr, dec=1) [og7DpnMC]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [og7DpnMC]

  vector<ll> dep1(N);
  auto dfs3 = [&](auto rF, ll nd, ll pt, ll d) -> void {
    dep1[nd] = d;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd, d + 1);
    }
  };
  dfs3(dfs3, 0, -1, 0);
  ll rt = max_element(ALL(dep1)) - dep1.begin();

  vector<ll> dep(N);
  vector<ll> md(N);
  vector<ll> arg(N);
  auto dfs1 = [&](auto rF, ll nd, ll pt, ll d) -> ll {
    dep[nd] = d;
    md[nd] = d;
    arg[nd] = -1;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      ll r = rF(rF, cld, nd, d + 1);
      if (r > md[nd]) {
        md[nd] = r;
        arg[nd] = cld;
      }
    }
    return md[nd];
  };
  dfs1(dfs1, rt, -1, 0);

  vector<ll> ans(N);
  ll seq = 1;
  auto dfs2 = [&](auto rF, ll nd, ll pt) -> void {
    ans[nd] = seq++;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      if (cld == arg[nd]) continue;
      rF(rF, cld, nd);
    }
    if (arg[nd] >= 0) {
      rF(rF, arg[nd], nd);
    }
    seq++;
  };
  dfs2(dfs2, rt, -1);
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}

