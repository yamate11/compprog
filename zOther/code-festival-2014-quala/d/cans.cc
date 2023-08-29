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

// @@ !! LIM(binsearch forall)

// ---- inserted library file binsearch.cc

template<typename T>
T binsearch_i(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / 2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template<typename T>
T binsearch_r(auto check, T yes, T no, T err, bool rel = true) {
  while (abs(yes - no) > err &&
         (!rel || abs(yes - no) > abs(yes) * err)) {
    T mid = (yes + no) / 2.0;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

ll border_with_hint(ll t, auto pred, auto hint) {
  double y = hint(t);
  double d = floor(y);
  double e = ceil(y);
  bool rd = pred(d, t);
  bool re = pred(e, t);
  if (rd && !re) return d;
  if (!rd && re) return e;
  for (ll i = 1; true; i++) {
    bool rd_i = pred(d - i, t);
    if (rd_i && !rd) return d - i;
    if (!rd_i && rd) return d - (i - 1);
    bool re_i = pred(e + i, t);
    if (re_i && !re) return e + i;
    if (!re_i && re) return e + (i - 1);
  }
}

// ---- end binsearch.cc

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

  // For each a \subseteq [0..9), calcs #{t | 1 <= t <= n and appear(t) = a}, where appear(t) is the set of digits
  // that appears in t's base-10 representation
  auto f = [&](ll n) -> vector<ll> {
    vector<ll> ret(1LL << 10, 0LL);
    if (n <= 0) return ret;
    vector<ll> ds;
    for (ll m = n; m > 0; m /= 10) ds.push_back(m % 10);
    reverse(ALL(ds));

    vector tbl_init(2, vector(2, vector(1LL << 10, 0LL)));
    auto tbl = tbl_init;
    tbl[1][1][0] = 1;
    for (ll d : ds) {
      auto prev = move(tbl);
      tbl = tbl_init;
      REP(eq, 0, 2) REP(az, 0, 2) REP(x, 0, 1LL << 10) {
        ll p_v = prev[eq][az][x];
        if (p_v == 0) continue;
        REP(e, 0, 10) {
          if (eq and e > d) continue;
          ll new_eq = eq and e == d;
          ll new_az = az and e == 0;
          ll new_x = az ? (1LL << e) : (x | (1LL << e));
          tbl[new_eq][new_az][new_x] += p_v;
        }
      }
    }
    REP(eq, 0, 2) REP(x, 0, 1LL << 10) ret[x] += tbl[eq][0][x];
    return ret;
  };

  ll A, K; cin >> A >> K;
  
  auto check = [&](ll w) -> bool {
    auto vec1 = f(A + w);
    auto vec2 = f(A - w - 1);
    return EXISTS(x, 0, 1LL << 10, vec1[x] - vec2[x] > 0 and __builtin_popcountll(x) <= K);
  };
  ll w = binsearch_i<ll>(check, (ll)(1e16), -1);
  cout << w << endl;

  return 0;
}

