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

// @@ !! LIM(forall)

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
  // @InpNbrList(9, M, nbr, dec=1) [3DONLFjl]
  auto nbr = vector(9, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [3DONLFjl]
  // @InpVec(8, P, dec=1) [Bnd335Q7]
  auto P = vector(8, ll());
  for (int i = 0; i < 8; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [Bnd335Q7]

  auto comp = [&](vector<ll>& pos) -> bool {
    return FORALL(i, 0, 8, pos[i] == i);
  };
  map<vector<ll>, ll> dist;
  using sta = tuple<ll, vector<ll>>;
  queue<sta> que;
  {
    vector<ll> pos(9, -1LL);
    REP(i, 0, 8) pos[P[i]] = i;
    if (comp(pos)) {
      cout << 0 << endl;
      return 0;
    }
    dist[pos] = 0;
    {
      ll emp = EXFIND(i, 0, 9, pos[i] == -1);
      que.emplace(emp, pos);
    }
  }
  while (not que.empty()) {
    auto [emp, pos] = que.front(); que.pop();
    ll len = dist[pos];
    for (ll j : nbr[emp]) {
      swap(pos[j], pos[emp]);
      if (comp(pos)) {
        cout << len + 1 << endl;
        return 0;
      }else {
        auto it = dist.find(pos);
        if (it == dist.end()) {
          dist[pos] = len + 1;
          que.emplace(j, pos);
        }
      }
      swap(pos[j], pos[emp]);
    }
  }
  cout << -1 << endl;

  return 0;
}

