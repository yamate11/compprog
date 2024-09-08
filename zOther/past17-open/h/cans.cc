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

// @@ !! LIM(f:updMaxMin)

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
  // @InpMVec(N, (A, B, C)) [G4xD4orH]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [G4xD4orH]

  ll maxB = *max_element(ALL(B));
  vector AC(maxB + 1, vector<pll>());
  REP(i, 0, N) {
    AC[B[i]].emplace_back(A[i], C[i]);
  }
  ll big = 1e18;
  vector<ll> tbl_init(M + 1, big);
  auto tbl = tbl_init;
  tbl[0] = 0;
  for (auto& ac : AC) {
    auto prev = tbl;
    REP(m, 0, M) {
      if (prev[m] < big) {
        for (auto [a, c] : ac) {
          ll m0 = min(m + c, M);
          updMin(tbl[m0], prev[m] + a);
        }
      }
    }
  }
  cout << (tbl[M] == big ? -1 : tbl[M]) << endl;

  return 0;
}

