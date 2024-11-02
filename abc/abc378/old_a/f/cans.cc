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

  ll N; cin >> N;
  // @InpNbrList(N, N - 1, nbr, dec=1) [uoJFAUhO]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [uoJFAUhO]

  ll root;
  REP(i, 0, N) {
    if (ssize(nbr[i]) == 1) {
      root = i;
      break;
    }
  }
  ll ans = 0;
  auto dfs = [&](auto rF, ll nd, ll up, ll pt) -> ll {
    if (nd == root) {
      rF(rF, nbr[nd][0], -1, nd);
      return 0;
    }else {
      ll nc = ssize(nbr[nd]) - 1;
      if (nc == 0) {
        return 0;
      }else if (nc >= 3) {
        for (ll c : nbr[nd]) {
          if (c == pt) continue;
          rF(rF, c, -1, nd);
        }
        return 0;
      }else if (nc == 1) {
        for (ll c : nbr[nd]) {
          if (c == pt) continue;
          rF(rF, c, nd, nd);
        }
        if (up >= 0 and up != pt) ans++;
        return 1;
      }else if (nc == 2) {
        ll e = -1;
        ll f = -1;
        for (ll c : nbr[nd]) {
          if (c == pt) continue;
          ll p = rF(rF, c, up, nd);
          if (e < 0) e = p;
          else f = p;
        }
        ans += e * f;
        return e + f;
      }else {
        assert(0);
      }
    }
    
  };


  dfs(dfs, root, -1, -1);
  cout << ans << endl;


  return 0;
}

