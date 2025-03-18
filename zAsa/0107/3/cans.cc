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

vector<int> sortedIndex(const auto& vec, auto comp) {
  vector<int> ret(vec.size());
  iota(ret.begin(), ret.end(), 0);
  sort(ret.begin(), ret.end(), [&vec, &comp](int i, int j) { return comp(vec[i], vec[j]); });
  return ret;
}

template<typename Collection>
vector<int> sortedIndex(const Collection& vec) { return sortedIndex(vec, less<typename Collection::value_type>()); }

// ---- end sortedIndex.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpMVec(N, (A, C)) [AdFJe2bt]
  auto A = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; C[i] = v2;
  }
  // @End [AdFJe2bt]

  using tpA = tuple<ll, ll, ll>;
  vector<tpA> P;
  REP(i, 0, N) P.emplace_back(A[i], C[i], i);
  sort(ALL(P), [&](tpA i, tpA j) -> bool {
    auto [ai, ci, ii] = i;
    auto [aj, cj, ij] = j;
    if (ai != aj) return ai > aj;
    if (ci != cj) return ci < cj;
    return false;
  });
  ll cur = 1e18;
  vector<ll> ans;
  for (auto [a, c, i] : P) {
    if (c <= cur) {
      ans.push_back(i);
      cur = c;
    }
  }
  sort(ALL(ans));
  cout << ssize(ans) << "\n";
  REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");

  return 0;
}

