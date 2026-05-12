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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [4eNdXove]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [4eNdXove]
  // @InpVec(N, B) [ttD89S2O]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [ttD89S2O]
  // @InpVec(M, C) [9foq5I3I]
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; C[i] = v; }
  // @End [9foq5I3I]
  // @InpVec(M, D) [9a0CuO5w]
  auto D = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; D[i] = v; }
  // @End [9a0CuO5w]

  vector<pll> choco(N);
  REP(i, 0, N) choco[i] = pll(A[i], B[i]);
  vector<pll> box(M);
  REP(i, 0, M) box[i] = pll(C[i], D[i]);
  ranges::sort(choco);
  ranges::sort(box);

  ll cnt = 0;
  multiset<ll, greater<ll>> ms;
  ll i = 0;
  for (auto [c, d] : box) {
    for (; i < N and choco[i].first <= c; i++) ms.insert(choco[i].second);
    auto it = ms.lower_bound(d);
    if (it != ms.end()) {
      ms.erase(it);
      cnt++;
    }
  }
  cout << (cnt == N ? "Yes\n" : "No\n");

  return 0;
}

