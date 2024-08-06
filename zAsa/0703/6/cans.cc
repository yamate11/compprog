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

  string s; cin >> s;
  ll n = ssize(s);
  bool b = true;
  if (s[n - 1] == '1') b = false;
  if (s[0] == '0') b = false;
  if (EXISTS(i, 0, n - 1, s[i] != s[n - 2 - i])) b = false;
  if (not b) {
    cout << -1 << endl;
    return 0;
  }
  vector<ll> rec;
  REP(i, 0, n / 2) {
    if (s[i] == '1') {
      rec.push_back(i + 1);
    }
  }
  ll m = rec.back();
  vector<pll> ans;

  auto f = [&](auto rF, ll i, ll j) -> void {
    if (i == 0) {
      // do nothing
    }else {
      ll x = rec[i] - rec[i - 1];
      rF(rF, i - 1, j - x);
      ans.emplace_back(j - x, j);
      REP(k, j - x + 1, j) ans.emplace_back(k, j);
    }
  };

  f(f, ssize(rec) - 1, m);
  f(f, ssize(rec) - 1, 2 * m);
  if (2 * m == n) {
    ans.emplace_back(m, 2 * m);
  }else {
    ans.emplace_back(m, n);
    ans.emplace_back(2 * m, n);
    REP(j, 2 * m + 1, n) ans.emplace_back(j, n);
  }
  for (auto [p, q] : ans) cout << p << " " << q << "\n";

  return 0;
}

