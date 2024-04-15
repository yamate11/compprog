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

  // vector<ll> A(3, vector<ll>(3));
  // REP(i, 0, 3) REP(j, 0, 3) cin >> A[i][j];
  vector<ll> A(9);
  REP(i, 0, 9) cin >> A[i];

  auto enc = [&](ll i, ll j) -> ll { return 3 * i + j; };

  auto get = [&](ll x, ll e) -> ll {
    ll a = (x >> (2 * e)) & 3;
    return a;
  };
  auto set = [&](ll x, ll e, ll val) -> ll {
    ll mask = (1LL << 18) - 1;
    mask ^= (3LL << (2 * e));
    ll y = (x & mask) | (val << (2 * e));
    return y;
  };

  vector<ll> tbl(1LL << 18, -1LL);
  auto f = [&](auto rF, ll x, ll turn) -> ll {
    ll me = turn % 2;
    ll& r = tbl[x];
    if (r == -1) {
      ll c = -1;
      REP(q, 0, 2) {
        bool b1 = EXISTS(i, 0, 3, FORALL(j, 0, 3, get(x, enc(i, j)) == q));
        bool b2 = EXISTS(i, 0, 3, FORALL(j, 0, 3, get(x, enc(j, i)) == q));
        bool b3 = FORALL(j, 0, 3, get(x, enc(j, j)) == q);
        bool b4 = FORALL(j, 0, 3, get(x, enc(j, 2 - j)) == q);
        if (b1 or b2 or b3 or b4) { c = q; break; }
      }
      if (c == 0 or c == 1) {
        r = c;
      }else if (turn == 9) {
        vector sum(2, 0LL);
        REP(e, 0, 9) {
          ll p = get(x, e);
          assert(p == 0 or p == 1);
          sum[p] += A[e];
        }
        if (sum[0] > sum[1]) r = 0;
        else r = 1;
      }else {
        REP(e, 0, 9) {
          ll p = get(x, e);
          if (p == 3) {
            ll y = set(x, e, me);
            ll b = rF(rF, y, turn + 1);
            if (b == me) {
              r = me;
              break;
            }
          }
        }
        if (r == -1) r = 1 - me;
      }
    }
    return r;
  };
  ll z = f(f, (1LL << 18) - 1, 0);
  cout << (z == 0 ? "Takahashi" : "Aoki") << endl;

  return 0;
}

