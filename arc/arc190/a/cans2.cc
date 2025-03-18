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

vector<int> sortedIndex(const auto& vec, auto comp) {
  vector<int> ret(vec.size());
  iota(ret.begin(), ret.end(), 0);
  sort(ret.begin(), ret.end(), [&vec, &comp](int i, int j) { return comp(vec[i], vec[j]); });
  return ret;
}

template<typename Collection>
vector<int> sortedIndex(const Collection& vec) { return sortedIndex(vec, less<typename Collection::value_type>()); }

// ---- end sortedIndex.cc

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
  // @InpMVec(M, ((L, dec=1), (R, dec=0))) [LPXHkXkC]
  auto L = vector(M, ll());
  auto R = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; v2 -= 0; R[i] = v2;
  }
  // @End [LPXHkXkC]

  vector<ll> ord(M);
  REP(i, 0, M) ord[i] = i;
  sort(ALL(ord), [&](ll a, ll b) -> bool {
    if (L[a] != L[b]) return L[a] < L[b];
    return R[a] < R[b];
  });
  ll i0 = EXFIND_D(j, 0, M, L[j] == 0 and R[j] == N, M);
  vector<ll> ans(M, 0LL);
  if (i0 < M) {
    cout << 1 << endl;
    ans[i0] = 1;
    REPOUT(i, 0, M, ans[i], " ");
    return 0;
  }
  if (M == 1) {
    cout << -1 << endl;
    return 0;
  }
  if (M == 2) {
    ll p = ord[0], q = ord[1];
    if (L[p] == L[q]) {
      ans[p] = 2; ans[q] = 1;
    }else if (R[p] <= L[q]) {
      ans[p] = 2; ans[q] = 2;
    }else if (R[q] <= R[p]) {
      ans[p] = 1; ans[q] = 2;
    }else if (0 == L[p] and R[q] == N) {
      ans[p] = 1; ans[q] = 1;
    }else {
      cout << -1 << endl;
      return 0;
    }
    cout << 2 << endl;
    REPOUT(i, 0, M, ans[i], " ");
    return 0;
  }
  
  auto f = [&]() -> bool {
    ll ii0 = EXFIND_D(ii, 0, M - 1, L[ord[ii]] == L[ord[ii + 1]], -1LL);
    if (ii0 >= 0) {
      ans[ord[ii0]] = 2; ans[ord[ii0 + 1]] = 1;
      return true;
    }
    ll ii1 = EXFIND_D(ii, 0, M - 1, R[ord[ii + 1]] <= R[ord[ii]], -1LL);
    if (ii1 >= 0) {
      ans[ord[ii1]] = 1; ans[ord[ii1 + 1]] = 2;
      return true;
    }
    ll p0 = ord[0], q0 = ord[M - 1];
    if (R[p0] <= L[q0]) {
      ans[p0] = 2; ans[q0] = 2;
      return true;
    }
    if (L[p0] == 0 and R[q0] == N) {
      ans[p0] = 1; ans[q0] = 1;
      return true;
    }
    return false;
  };
  if (f()) {
    cout << 2 << endl;
    REPOUT(i, 0, M, ans[i], " ");
    return 0;
  }
  map<ll, ll> mp;
  REP(i, 0, 3) {
    mp[L[i]] ^= (1LL << i);
    if (R[i] < N) mp[R[i]] ^= (1LL << i);
  }
  vector<bool> vecA(8, false);
  ll xx = mp.begin()->first;
  if (xx > 0) vecA[0] = true;
  ll cur = 0;
  for (auto [i, t] : mp) {
    cur ^= t;
    vecA[cur] = true;
  }
  ll x = EXFIND(i, 0, 8, vecA[i] == false);
  REP(i, 0, 3) {
    if (x >> i & 1) ans[i] = 2;
    else            ans[i] = 1;
  }
  cout << 3 << endl;
  REPOUT(i, 0, M, ans[i], " ");

  return 0;
}

