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
  // @InpVec(M, A) [I5aR82zg]
  auto A = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; A[i] = v; }
  // @End [I5aR82zg]
  // @InpVec(N, S, type=string) [l6fWvOrt]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [l6fWvOrt]

  auto ord = sortedIndex(A, greater<ll>());
  ll vmax = 0;
  vector cur(N, 0LL);
  REP(i, 0, N) {
    cur[i] = i;
    REP(j, 0, M) if (S[i][j] == 'o') cur[i] += A[j];
    updMax(vmax, cur[i]);
  }
  REP(i, 0, N) {
    ll x = cur[i];
    if (x == vmax) {
      cout << 0 << "\n";
      continue;
    }
    ll cnt = 0;
    REP(jj, 0, M) {
      ll j = ord[jj];
      if (S[i][j] == 'x') {
        x += A[j];
        cnt++;
      }
      if (x > vmax) {
        cout << cnt << "\n";
        break;
      }
    }
  }

  return 0;
}

