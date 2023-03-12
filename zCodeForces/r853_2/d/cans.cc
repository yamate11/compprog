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
    vector<int> AA(N), BB(N);
    {
      string A, B; cin >> A >> B;
      REP(i, 0, N) { AA[i] = A[i] - '0'; BB[i] = B[i] - '0'; }
    }
    ll al = EXFIND_D(i, 0, N, AA[i] == 1, N);
    ll bl = EXFIND_D(i, 0, N, BB[i] == 1, N);
    if ((al == N) != (bl == N)) {
      cout << -1 << "\n";
      return;
    }
    if (al == N) {
      cout << 0 << "\n";
      return;
    }
    vector<ll> ans;
    REP(i, bl, N) {
      if (AA[i] != BB[i]) {
        if (i < al) {
          REP(j, al, N) AA[i + (j - al)] = AA[i + (j - al)] ^ AA[j];
          ans.push_back(al - i);
          al = i;
        }else if (i > al) {
          ans.push_back(-(i - al));
          REPrev(j, N-1, i) AA[j] = AA[j] ^ AA[al + (j - i)];
        }else assert(0);
      }
    }
    ll br = N-1 - EXFIND(i, 0, N, AA[N-1 - i] == 1);
    REPrev(i, bl - 1, 0) {
      if (AA[i] == 1) {
        ans.push_back(br - i);
        REP(j, 0, i + 1) AA[j] = AA[j] ^ AA[j + br - i];
      }
    }
    cout << SIZE(ans) << "\n";
    if (SIZE(ans) > 0) {
      REPOUT(i, 0, SIZE(ans), ans[i], " ");
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

