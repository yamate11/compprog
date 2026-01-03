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

  ll N, M; cin >> N >> M;
  // @InpVec(M, A) [QnFqJ1pu]
  auto A = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; A[i] = v; }
  // @End [QnFqJ1pu]
  vector<ll> req{0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  
  ranges::sort(A, greater<>());
  ll rmin = req[A[0]];
  REP(i, 1, M) rmin = min(rmin, req[A[i]]);

  vector<pll> B;
  REP(i, 0, M) {
    if (EXISTS(j, 0, ssize(B), B[j].second == req[A[i]])) continue;
    B.emplace_back(A[i], req[A[i]]);
  }
  M = ssize(B);
  vector<ll> C(M);
  C[M - 1] = 10000;
  REPrev(i, M - 2, 0) C[i] = min(C[i + 1], B[i + 1].second);
  
  vector<ll> vec(M);
  auto f = [&](ll k0) -> bool {
    auto g = [&](auto rF, ll i, ll k, ll n) -> bool {
      ll r = B[i].second;
      if (i == M - 1) {
        if (k * r == n) {
          vec[i] = k;
          return true;
        }else return false;
      }
      if (r > C[i]) {
        if (n - C[i] * k < 0) return false;
        ll tmax = (n - C[i] * k) / (r - C[i]);
        REPrev(t, min(k, tmax), 0) {
          vec[i] = t;
          if (rF(rF, i + 1, k - t, n - r * t)) return true;
        }
        return false;
      }else {
        REPrev(t, k, 0) {
          vec[i] = t;
          if (rF(rF, i + 1, k - t, n - r * t)) return true;
        }
        return false;
      }
    };
    return g(g, 0, k0, N);
  };

  ll kmax = N / rmin;
  REPrev(k, kmax, 1) {
    if (f(k)) break;
  }
  REP(i, 0, M) {
    REP(j, 0, vec[i]) cout << B[i].first;
  }
  cout << endl;
  return 0;
}

