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

// @@ !! LIM(input sortedIndex)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

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

  ll N, T; cin >> N >> T;
  // @InpGrid(T, N, S) [x0lxodEo]
  auto S = vector(T, vector(N, ll()));
  for (int i = 0; i < T; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; S[i][j] = v; }
  // @End [x0lxodEo]

  ll cnt = 0;
  REP(t, 0, T) {
    auto vec = sortedIndex(S[t], greater<ll>());
    if (S[t][vec[0]] >= 2 * S[t][vec[1]]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

