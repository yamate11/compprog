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

  auto solve = [&]() -> bool {

    auto myread = [&]() {
      ll H, W; cin >> H >> W;
      // @InpVec(H, V, type=string) [Z4BSIGaI]
      auto V = vector(H, string());
      for (int i = 0; i < H; i++) { string v; cin >> v; V[i] = v; }
      // @End [Z4BSIGaI]
      ll x1 = 100, x2 = -100, y1 = 100, y2 = -100;
      REP(i, 0, H) REP(j, 0, W) if (V[i][j] == '#') {
        x1 = min(x1, i);
        x2 = max(x2, i);
        y1 = min(y1, j);
        y2 = max(y2, j);
      }
      auto VV = vector(x2 - x1 + 1, vector(y2 - y1 + 1, ' '));
      REP(i, x1, x2 + 1) REP(j, y1, y2 + 1) VV[i - x1][j - y1] = V[i][j];
      return tuple<ll, ll, vector<vector<char>>>{x2 - x1 + 1, y2 - y1 + 1, move(VV)};
    };

    auto [ha, wa, A] = myread();
    auto [hb, wb, B] = myread();
    auto [hx, wx, X] = myread();
  
    if (ha > hx or wa > wx or hb > hx or wb > wx) return false;
    REP(ax, 0, hx - ha + 1) REP(ay, 0, wx - wa + 1) REP(bx, 0, hx - hb + 1) REP(by, 0, wx - wb + 1) {
      auto C = vector(hx, vector(wx, '.'));
      REP(i, 0, ha) REP(j, 0, wa) if (A[i][j] == '#') C[ax + i][ay + j] = '#';
      REP(i, 0, hb) REP(j, 0, wb) if (B[i][j] == '#') C[bx + i][by + j] = '#';
      if (FORALL(i, 0, hx, FORALL(j, 0, wx, X[i][j] == C[i][j]))) return true;
    }
    return false;
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

