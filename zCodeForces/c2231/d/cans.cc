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

  using vector<ll> vll;
  auto solve = [&]() -> vll {
    ll N; cin >> N;
    string S; cin >> S;
    // @InpVec(N, A) [SW2sSNkM]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [SW2sSNkM]
    // @InpVec(N, C) [RW6ClQWp]
    auto C = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
    // @End [RW6ClQWp]

    if (EXISTS(i, 0, N - 1, C[i] > C[i + 1])) return vll();

    if (S[0] == '0') A[0] = C[0];
    else if (A[0] != C[0]) return vll();
    
    ll big = 1LL << 60;
    ll i0 = 0;
    while (?) {
      ll i = i0;
      for (; i < N and C[i] = C[i0]; i++);
      ll i1 = i;
      i1 can be N;
      ll up = i1 < N ? C[i1] - C[i0] : big;
      ll j0 = i0;
      ll t = 0;
      if (S[j0] == '1') {
        for (; j0 < i1 and S[j0] == '1'; j0++) {
          t += A[j0];
          if (t > 0) return vll();
        }
        if (j0 == i1) {
          if (i1 < N) {
            if (S[i1] == '0') A[i1] = C[i1] - t;
            else if (A[i1] != C[i1] - t) return vll();
          }
        }
        return local;
      }else {
        t = 0;
      }
      for (; j0 < i1 and S[j0] == '0'; j0++);
      if (j0 == j1) {
        return local;
      }else {
        for(; j0 < j1 and S[j0] == '1'; j0++)
      }
      



    }


  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) {
    auto A = solve();
    if (A.empty()) {
      cout << "No\n";
    }else {
      cout << "Yes\n";
      REPOUT(i, 0, ssize(A), A[i], " ");
    }
  }

  return 0;
}

