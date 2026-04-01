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

  ll N, M; cin >> N >> M;
  // @InpVec(N, V) [K53vYwhH]
  auto V = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; V[i] = v; }
  // @End [K53vYwhH]
  vector<pll> DT(M);
  REP(i, 0, M) {
    ll d, t; cin >> d >> t;
    DT[i] = pll(d, t);
  }

  ranges::sort(V);

  auto vec = sortedIndex(DT, [&](pll a, pll b) -> bool { return a.first * b.second < a.second * b.first; });
  ll j = 0;
  REP(ii, 0, M) {
    ll i = vec[ii];
    while (j < N and V[j] * DT[i].second < DT[i].first) j++;
    if (j == N) {
      cout << ii << endl;
      return 0;
    }
    j++;
  }
  cout << M << endl;
  return 0;
}

