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

  auto solve = [&]() -> bool {
    ll N, M; cin >> N >> M;
    // @InpMVec(M, ((A, dec=1), (B, dec=1))) [jJaNqzZZ]
    auto A = vector(M, ll());
    auto B = vector(M, ll());
    for (int i = 0; i < M; i++) {
      ll v1; cin >> v1; v1 -= 1; A[i] = v1;
      ll v2; cin >> v2; v2 -= 1; B[i] = v2;
    }
    // @End [jJaNqzZZ]
    ll a = N / 2;
    ll b = N - a;
    if (a * (a - 1) / 2 + b * (b - 1) / 2 > M) return false;
    vector conn(N, vector(N, false));
    REP(i, 0, M) conn[A[i]][B[i]] = conn[B[i]][A[i]] = true;
    
    vector<ll> YA, YB, CandA, CandB;
    vector<bool> done(N, false);
    ll idx = 0;
    while (true) {
      if (not CandA.empty()) {
        ll i = CandA.back(); CandA.pop_back();
        if (EXISTS_C(j, YA, not conn[j][i])) return false;
        YA.push_back(i);
        REP(j, 0, N) if (not done[j] and not conn[i][j]) {
          done[j] = true;
          CandB.push_back(j);
        }
      }else if (not CandB.empty()) {
        ll i = CandB.back(); CandB.pop_back();
        if (EXISTS_C(j, YB, not conn[j][i])) return false;
        YB.push_back(i);
        REP(j, 0, N) if (not done[j] and not conn[i][j]) {
          done[j] = true;
          CandA.push_back(j);
        }
      }else if (idx == N) {
        return true;
      }else {
        if (not done[idx]) {
          done[idx] = true;
          if (EXISTS_C(j, YA, not conn[j][idx])) CandB.push_back(idx);
          else CandA.push_back(idx);
        }
        idx++;
      }
    }
    assert(0);
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

