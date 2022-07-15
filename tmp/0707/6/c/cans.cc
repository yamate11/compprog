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

// @@ !! LIM(forall)

// ---- inserted library file forall.cc

#define EX_REP_LL(i, from, to) for (ll i = from; i < to; i++)
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

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// @@ !! LIM -- end mark --

using pll = pair<ll, ll>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  const ll sz = 19, YES = 0, NO = 1, INCONSIS = 2;
  vector<string> S(sz);
  REP(i, sz) cin >> S[i];
  auto check = [&](ll x, ll y, char c, ll dx, ll dy) -> pair<ll, vector<pll>> {
    vector<pll> ret;
    ll k = 0;
    REP(i, 10) {
      if (not (0 <= x + i * dx and x + i * dx < sz and 0 <= y + i * dy and y + i * dy < sz)) break;
      if (S[x + i * dx][y + i * dy] != c) break;
      k++;
    }
    if (k == 10) return {INCONSIS, move(ret)};
    if (k <= 4) return {NO, move(ret)};
    REP2(i, k - 5, k) ret.emplace_back(x + i * dx, y + i * dy);
    return {YES, move(ret)};
  };
  auto f_count = [&](char c) -> ll {
    ll ret = 0;
    REP(x, sz) REP(y, sz) if (S[x][y] == c) ret++;
    return ret;
  };
  auto g = [&](char c1, char c2) -> bool {
    bool finished = false;
    vector<pll> cands;
    REP(x, 19) REP(y, 19) for (auto [dx, dy] : vector<pll>{{1, 0}, {0, 1}, {1, -1}, {1, 1}}) {
      auto [st2, vec2] = check(x, y, c2, dx, dy);
      if (st2 != NO) return false;
      auto [st1, vec1] = check(x, y, c1, dx, dy);
      if (st1 == INCONSIS) return false;
      if (st1 == YES) {
        if (finished) {
          auto old_cands = move(cands);
          cands = vector<pll>();
          for (pll p : old_cands) if (EXISTS(i, 0, SIZE(vec1), p == vec1[i])) cands.push_back(p);
        }else {
          finished = true;
          cands = move(vec1);
        }
        if (cands.empty()) return false;
      }
    }
    return true;
  };
  ll nb = f_count('o');
  ll nw = f_count('x');
  bool ans = (nb == nw and g('x', 'o')) or (nb == nw + 1 and g('o', 'x'));
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}

