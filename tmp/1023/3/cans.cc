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

  ll N; cin >> N;
  // @InpGrid(N, N, C) [Go4tGtjz]
  auto C = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; C[i][j] = v; }
  // @End [Go4tGtjz]
  if (N == 1) {
    cout << "Yes\n0\n" << C[0][0] << endl;
    return 0;
  }
  vector horiz(N - 1, 0LL), vert(N - 1, 0LL);
  REP(i, 0, N - 1) horiz[i] = C[0][i + 1] - C[0][0];
  REP(i, 0, N - 1) vert[i]  = C[i + 1][0] - C[0][0];
  bool b1 = FORALL(i, 1, N, FORALL(j, 0, N - 1, C[i][j + 1] - C[i][0] == horiz[j]));
  bool b2 = FORALL(i, 1, N, FORALL(j, 0, N - 1, C[j + 1][i] - C[0][i] == vert[j]));
  ll mh = *min_element(ALL(horiz));
  ll mv = *min_element(ALL(vert));
  if (b1 and b2 and C[0][0] + mh + mv >= 0) {
    cout << "Yes\n";
    ll c = mh < 0 ? -mh : 0;
    cout << C[0][0] - c;
    REP(i, 0, N - 1) cout << " " << C[0][0] - c + vert[i];
    cout << "\n";
    cout << c;
    REP(i, 0, N - 1) cout << " " << c + horiz[i];
    cout << "\n";
  }else {
    cout << "No\n";
  }
  

  return 0;
}

