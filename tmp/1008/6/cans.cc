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

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [76QcmCky]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [76QcmCky]
  vector<bool> visited(N);

  auto func = [&](ll st) -> ll {

    vector<ll> mem;
    auto dfs = [&](auto rF, ll nd) -> void {
      if (visited[nd]) return;
      visited[nd] = true;
      mem.push_back(nd);
      for (ll cld : nbr[nd]) rF(rF, cld);
    };
    dfs(dfs, st);

    ll cnt = 0;
    vector<ll> assign(N, -1);
    assign[st] = 0;
    auto sch = [&](auto rF, ll i) -> void {
      if (i == SIZE(mem)) {
        cnt++;
        return;
      }
      ll nd = mem[i];
      vector<bool> col(3);
      for (ll p : nbr[nd]) {
        ll a = assign[p];
        if (a >= 0) col[a] = true;
      }
      REP(c, 0, 3) if (not col[c]) {
        assign[nd] = c;
        rF(rF, i + 1);
        assign[nd] = -1;
      }
    };
    sch(sch, 0);

    return cnt;
  };



  ll ans = 1;
  REP(i, 0, N) {
    if (visited[i]) continue;
    ans *= func(i);
  }
  cout << ans << endl;

  return 0;
}

