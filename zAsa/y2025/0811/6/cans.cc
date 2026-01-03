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

vector<int> sortedIndex(const auto& vec, auto comp) {
  vector<int> ret(vec.size());
  iota(ret.begin(), ret.end(), 0);
  sort(ret.begin(), ret.end(), [&vec, &comp](int i, int j) { return comp(vec[i], vec[j]); });
  return ret;
}

template<typename Collection>
vector<int> sortedIndex(const Collection& vec) { return sortedIndex(vec, less<typename Collection::value_type>()); }

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

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [QLJlVdkf]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [QLJlVdkf]
  // @InpVec(N, W) [gD6wlPXt]
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; W[i] = v; }
  // @End [gD6wlPXt]
  // @InpVec(N, A) [I5qUbdFp]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [I5qUbdFp]

  vector<ll> ans(N, -1LL);
  auto ord = sortedIndex(W);
  REP(ii, 0, N) {
    ll i = ord[ii];
    vector<ll> tbl_init(W[i], -1LL);
    auto tbl = tbl_init;
    tbl[0] = 0;
    for (ll j : nbr[i]) {
      auto prev = tbl;
      if (W[j] >= W[i]) continue;
      REP(k, 0, W[i]) {
        if (prev[k] >= 0 and k + W[j] < W[i]) updMax(tbl[k + W[j]], prev[k] + ans[j]);
      }
    }
    ans[i] = 1 + *max_element(ALL(tbl));
  }
  ll tot = 0;
  REP(i, 0, N) tot += A[i] * ans[i];
  cout << tot << endl;

  return 0;
}

