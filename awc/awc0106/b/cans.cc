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

  ll N, M, K; cin >> N >> M >> K;
  // @InpVec(N, H) [iO5Hrxax]
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
  // @End [iO5Hrxax]
  // @InpVec(N, W, type=double) [mlYxTPG0]
  auto W = vector(N, double());
  for (int i = 0; i < N; i++) { double v; cin >> v; W[i] = v; }
  // @End [mlYxTPG0]
  // @InpNbrList(N, M, nbr, dec=1) [EXbRYobV]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [EXbRYobV]
  // @InpVec(K, S, dec=1) [tGJnzS7l]
  auto S = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; S[i] = v; }
  // @End [tGJnzS7l]
  vector<bool> hasDum(N, false);
  REP(i, 0, K) hasDum[S[i]] = true;

  auto ord = sortedIndex(H, greater<ll>());
  REP(ii, 0, N) {
    ll i = ord[ii];
    if (hasDum[i]) continue;
    vector<ll> under;
    for (ll peer: nbr[i]) if (H[peer] < H[i]) under.push_back(peer);
    ll d = ssize(under);
    if (d >= 1) {
      for (ll peer : under) W[peer] += W[i] / d;
      W[i] = 0;
    }
  }
  REPOUT(i, 0, N, W[i], " ");

  return 0;
}

