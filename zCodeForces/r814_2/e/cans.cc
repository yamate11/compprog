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

  vector<ll> fib{1,1};
  {
    ll i = 2;
    while (true) {
      ll t = fib[i - 2] + fib[i - 1];
      if (t > 1e10) break;
      fib.push_back(t);
      i++;
    }
  }
  ll sz = SIZE(fib);
  auto solve = [&]() -> bool {
    vector<bool> rem(sz, true);
    ll K; cin >> K;
    // @InpVec(K, C) [NGcjxpvG]
    auto C = vector(K, ll());
    for (int i = 0; i < K; i++) { ll v; cin >> v; C[i] = v; }
    // @End [NGcjxpvG]
    ll s = accumulate(ALL(C), 0LL);
    ll lim = EXFIND_D(i, 0, sz, s + 1 == fib[i], -1LL);
    if (lim < 0) return false;
    lim -= 2;
    priority_queue<pll> pque;
    REP(i, 0, K) pque.emplace(C[i], 1000);
    REPrev(i, lim, 0) {
      auto [c, p] = pque.top(); pque.pop();
      if (c < fib[i]) return false;
      if (p == i) return false;
      if (c == fib[i]) continue;
      pque.emplace(c - fib[i], i - 1);
    }
    return true;
  };
  

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << (solve() ? "YES" : "NO") << "\n";

  return 0;
}

