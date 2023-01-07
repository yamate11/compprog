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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

struct myexc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1, read=C) [NaSfhyAu]
  struct nbr_t {
    int nd;
    ll C;
    nbr_t() {}
    nbr_t(int nd_, ll C_) : nd(nd_), C(C_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
  }
  // @End [NaSfhyAu]

  vector<ll> vec(N, 0LL);
  vector<ll> parity(N, -1LL);
  ll minOdd = 1e18;
  ll minEven = 1e18;
  ll rc = -1;
  auto dfs = [&](auto rF, ll nd, ll par, ll val) -> void {
    if (parity[nd] >= 0) {
      if (parity[nd] != par) {
        ll e;
        if (par == 1) e = val - vec[nd];
        else          e = vec[nd] - val;
        if (e < 0 or e % 2 != 0) rc = -1;
        else rc = e / 2;
        throw myexc();
      }else {
        if (val != vec[nd]) {
          rc = -1;
          throw myexc();
        }
      }
      return;
    }
    parity[nd] = par;
    vec[nd] = val;
    if (par) minOdd = min(minOdd, val);
    else minEven = min(minEven, val);
    for (auto [cld, w] : nbr[nd]) rF(rF, cld, 1 - par, w - val);
  };
  auto dfs2 = [&](auto rF, ll nd, ll val) -> void {
    if (parity[nd] >= 0) {
      if (val != vec[nd]) throw myexc(); 
      return;
    }
    parity[nd] = 0;
    vec[nd] = val;
    for (auto [cld, w] : nbr[nd]) {
      if (w - val < 0) throw myexc();
      rF(rF, cld, w - val);
    }
  };
  try {
    dfs(dfs, 0, 0, 0);
    if (minOdd >= 0 and minEven + minOdd >= 0) {
      REPOUT(i, 0, N, parity[i] ? vec[i] - minOdd : vec[i] + minOdd, "\n");
    }else {
      cout << -1 << endl;
    }
    return 0;
  }catch(myexc& ex) {
    if (rc < 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  vec = vector<ll>(N, 0LL);
  parity = vector<ll>(N, -1LL);
  try {
    dfs2(dfs2, 0, rc);
  }catch(myexc& ex) {
    cout << -1 << endl;
    return 0;
  }
  REPOUT(i, 0, N, vec[i], "\n");

  return 0;
}

