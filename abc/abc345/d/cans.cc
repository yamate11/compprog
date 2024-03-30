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

struct myexc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, H, W; cin >> N >> H >> W;
  // @InpMVec(N, (A, B)) [wCuKhZnv]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [wCuKhZnv]

  vector board(H, vector(W, false));
  vector<pll> stack;

  auto getopen = [&]() -> pll {
    REP(i, 0, H) REP(j, 0, W) if (not board[i][j]) return pll(i, j);
    return pll(-1, -1);
  };

  enum mode_t { CHECK, ON, OFF };
  auto put = [&](ll i, ll j, ll m, bool trans, mode_t mode) -> bool {
    ll a = A[m], b = B[m];
    if (trans) swap(a, b);
    REP(p, 0, a) REP(q, 0, b) {
      if (i + a > H or j + b > W) return false;
      if (mode == CHECK and not board[i + p][j + q]) return false;
      else board[i + p][j + q] = (mode == ON);
    }
    return true;
  };

  auto sch = [&](auto rF, ll used) -> void {
    auto [i, j] = getopen();
    if (i < 0) return true;
    if (popcount((u64)used) == N) return;
    REP(m, 0, N) {
      if (not (used >> m & 1)) {
        REP(b, 0, 2) {
          if (put(i, j, m, b, CHECK)) {
            put(i, j, m, b, ON);
            rF(rF, used | (1LL << m));
            put(i, j, m, b, OFF);
          }
        }
      }
    }
  };
  try {
    sch(sch, 0, 0);
    cout << "No\n";
  }catch (const myexc& e) {
    cout << "Yes\n";
  }

  return 0;
}

