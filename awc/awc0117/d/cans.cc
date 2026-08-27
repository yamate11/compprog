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

// @@ !! LIM(sortedIndex)

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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<pll> DV;
  REP(i, 0, N) {
    ll d, v; cin >> d >> v;
    DV.emplace_back(d, v);
  }
  // @InpVec(M, L) [GbuYLQhD]
  ranges::sort(DV);
  auto L = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; L[i] = v; }
  // @End [GbuYLQhD]
  ranges::sort(L);
  ll ans = 0;
  ll j = 0;
  priority_queue<ll> pque;
  REP(i, 0, M) {
    for (; j < N and DV[j].first <= L[i]; j++) pque.push(DV[j].second);
    if (not pque.empty()) {
      ll v = pque.top(); pque.pop();
      ans += v;
    }
  }
  cout << ans << endl;

  return 0;
}

