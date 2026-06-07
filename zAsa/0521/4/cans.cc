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

  ll N; cin >> N;
  // @InpMVec(N, (A, B)) [mv0ojrez]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [mv0ojrez]

  vector<ll> vec;
  REP(i, 0, N) {
    vec.push_back(A[i] + B[i]);
  }
  auto ord = sortedIndex(vec, greater<>());
  // auto ord = sortedIndex(vec);
  ll ans = 0;
  REP(ii, 0, N) {
    ll i = ord[ii];
    if (ii % 2 == 0) ans += A[i];
    else ans -= B[i];
  }
  cout << ans << endl;
  return 0;
}

