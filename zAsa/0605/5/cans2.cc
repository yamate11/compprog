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

// @@ !! LIM(input forall)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// ---- inserted library file forall.cc

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define COUNT_BASE(rep_part, cond) ([&](){ ll ret = 0; rep_part if (cond) ret++; return ret; }())
#define COUNT(i, from, to, cond) COUNT_BASE(EX_REP_LL(i, from, to), cond)
#define COUNT_C(x, coll, cond) COUNT_BASE(EX_REP_RB(x, coll), cond)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll M; cin >> M;
  // @InpNbrList(9, M, nbr, dec=1) [nXHmPVcm]
  auto nbr = vector(9, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [nXHmPVcm]
  // @InpVec(8, P, dec=1) [pjY5OMMd]
  auto P = vector(8, ll());
  for (int i = 0; i < 8; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [pjY5OMMd]
  
  vector<ll> B0(9, -1LL);
  REP(i, 0, 8) B0[P[i]] = i;
  ll vac0 = EXFIND(i, 0, 9, B0[i] == -1);

  vector<ll> goal(9, -1LL);
  REP(i, 0, 8) goal[i] = i;

  set<vector<ll>> visited;
  using sta = tuple<vector<ll>, ll, ll>;
  queue<sta> que;
  visited.insert(B0);
  que.emplace(B0, vac0, 0LL);
  if (B0 == goal) {
    cout << 0 << endl;
    return 0;
  }

  while (not que.empty()) {
    auto [B, vac, len] = que.front(); que.pop();
    for (ll peer : nbr[vac]) {
      vector newB = B;
      swap(newB[vac], newB[peer]);
      if (newB == goal) {
        cout << len + 1 << "\n";
        return 0;
      }
      if (not visited.contains(newB)) {
        visited.insert(newB);
        que.emplace(newB, peer, len + 1);
      }
    }
  }
  cout << -1 << endl;

  return 0;
}
