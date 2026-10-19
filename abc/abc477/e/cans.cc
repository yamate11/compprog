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

// @@ !! LIM(sortedIndex f:updMaxMin)

// ---- inserted library file sortedIndex.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/sortedIndex.cc

template<typename INT = long long int>
vector<INT> sortedIndexCFAI(const auto& vec, auto idx_comp) { // Comparison Function Arguments are Indices
  vector<INT> ret(vec.size());
  iota(ret.begin(), ret.end(), (INT)0);
  sort(ret.begin(), ret.end(), idx_comp);
  return ret;
}

template<typename INT = long long int, typename Collection, typename Comp = less<typename Collection::value_type>>
vector<INT> sortedIndex(const Collection& vec, Comp comp = Comp()) {
  return sortedIndexCFAI<INT>(vec, [&vec, &comp](INT i, INT j) { return comp(vec[i], vec[j]); });
}

template<typename INT = long long int>
pair<vector<INT>, vector<INT>> sortedIndex2CFAI(const auto& vec, auto idx_comp) {
  auto ord2idx = sortedIndexCFAI<INT>(vec, idx_comp);
  vector<INT> idx2ord(vec.size());
  for (size_t i = 0; i < vec.size(); i++) idx2ord[ord2idx[i]] = i;
  return {move(ord2idx), move(idx2ord)};
}

template<typename INT = long long int>
pair<vector<INT>, vector<INT>> sortedIndex2(const auto& vec, auto comp) {
  return sortedIndex2CFAI<INT>(vec, [&vec, &comp](INT i, INT j) { return comp(vec[i], vec[j]); });
}

template<typename INT = long long int, typename Collection>
pair<vector<INT>, vector<INT>> sortedIndex2(const Collection& vec) {
  return sortedIndex2<INT>(vec, less<typename Collection::value_type>());
}


// ---- end sortedIndex.cc

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [tdjpcE4j]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [tdjpcE4j]
  // @InpVec(N, B) [4DPcXNTb]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [4DPcXNTb]

  vector<ll> C(2*N + 1, 0LL);
  REP(i, 0, 2*N) C[i + 1] = C[i] + A[i % N];
  set<pll> sp;
  vector<ll> D(N);

  auto o2i = sortedIndex(B);
  REP(ii, 0, N) {
    ll i = o2i[ii];
    if (ii == 0) {
      sp.emplace(i, B[i]);
      sp.emplace(N + i, B[i]);
      D[i] = B[i];
    }else {
      auto it1 = sp.lower_bound(pll(i, 0));
      auto it2 = sp.lower_bound(pll(N + i, 0));
      auto [j1, d1] = *it1;
      auto [j2, d2] = *(std::prev(it2));
      ll d0 = B[i];
      updMin(d0, C[j1] - C[i] + d1);
      updMin(d0, C[N + i] - C[j2] + d2);
      sp.emplace(i, d0);
      sp.emplace(N + i, d0);
      D[i] = d0;
    }
  }

  REP(_q, 0, Q) {
    ll s, t; cin >> s >> t; s--; t--;
    if (t == N) {
      cout << D[s] << "\n";
    }else {
      ll ans = C[t] - C[s];
      updMin(ans, C[N + s] - C[t]);
      updMin(ans, D[s] + D[t]);
      cout << ans << "\n";
    }
  }
  

  return 0;
}

