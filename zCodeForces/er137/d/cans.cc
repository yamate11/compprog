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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    string S; cin >> S;
    ll i0 = 0;
    while (i0 < N and S[i0] == '0') i0++;
    if (i0 == N) {
      cout << "0\n";
      return;
    }
    ll i1 = i0;
    while (i1 < N and S[i1] == '1') i1++;
    if (i1 == N) {
      cout << S.substr(i0) << "\n";
      return;
    }
    vector<bool> dead(i1 - i0 + 1, false);
    REP(i, i1, N) {
      vector<bool> drop(i1 - i0 + 1, false);
      bool exsafe = false;
      bool exdrop = false;
      REP(a, 1, i1 - i0 + 1) {
        if (dead[a]) continue;
        if (S[i] == '0' and S[i - a] == '0') {
          drop[a] = true;
          exdrop = true;
        }else {
          exsafe = true;
        }
      }
      if (exdrop and exsafe) {
        ll numLive = 0;
        REP(a, 1, i1 - i0 + 1) {
          dead[a] = dead[a] or drop[a];
          if (not dead[a]) numLive += 1;
        }
        if (numLive == 1) break;
      }
    }
    ll a0 = EXFIND(a, 1, i1 - i0 + 1, not dead[a]);
    string ans;
    for (ll i = i0; i < i1; i++) ans += '1';
    for (ll i = i1; i < N; i++) {
      if (S[i - a0] == '0' and S[i] == '0') ans += '0';
      else ans += '1';
    }
    cout << ans << endl;
    return;
  };

  solve();

  return 0;
}

