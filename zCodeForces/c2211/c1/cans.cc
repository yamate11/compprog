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

// @@ !! LIM(sortedIndex forall)

// ---- inserted library file sortedIndex.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/sortedIndex.cc

template<typename INT = long long int>
vector<INT> sortedIndex(const auto& vec, auto comp) {
  vector<INT> ret(vec.size());
  iota(ret.begin(), ret.end(), (INT)0);
  sort(ret.begin(), ret.end(), [&vec, &comp](INT i, INT j) { return comp(vec[i], vec[j]); });
  return ret;
}

template<typename INT = long long int>
pair<vector<INT>, vector<INT>> sortedIndex2(const auto& vec, auto comp) {
  auto ord2idx = sortedIndex(vec, comp);
  vector<INT> idx2ord(vec.size());
  for (size_t i = 0; i < vec.size(); i++) idx2ord[ord2idx[i]] = i;
  return {move(ord2idx), move(idx2ord)};
}

template<typename INT = long long int, typename Collection>
vector<INT> sortedIndex(const Collection& vec) {
  return sortedIndex<INT>(vec, less<typename Collection::value_type>());
}

template<typename INT = long long int, typename Collection>
pair<vector<INT>, vector<INT>> sortedIndex2(const Collection& vec) {
  return sortedIndex2<INT>(vec, less<typename Collection::value_type>());
}


// ---- end sortedIndex.cc

// ---- inserted library file forall.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/forall.cc

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
    ll N, K; cin >> N >> K;
    // @InpVec(N, A, dec=1) [Beehtn7B]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
    // @End [Beehtn7B]
    // @InpVec(N, B, dec=1) [fw6LoQ9O]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; B[i] = v; }
    // @End [fw6LoQ9O]
    vector<ll> cnt(N);
    REP(i, 0, N) if (B[i] >= 0) cnt[B[i]]++;
    if (EXISTS(i, 0, N, cnt[i] >= 2)) return false;
    auto ord = sortedIndex(A);
    REP(i, 0, N) {
      if (B[i] >= 0 and B[i] != A[i]) {
        if (i >= K or (N - (i + 1) >= K)) return false;
        ll j = ord[B[i]];
        if (j >= K or (N - (j + 1) >= K)) return false;
      }
    }
    return true;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

