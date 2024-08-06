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

  ll N, X; cin >> N >> X;
  // @InpMVec(N, (A, B, C)) [FjUssXIy]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [FjUssXIy]
  
  vector tbl(X + 1, pll(-1, -1));
  tbl[X] = pll(0, (ll)1e9);
  REP(i, 0, N) {
    REP(j, B[i], X + 1) {
      auto [g, s] = tbl[j];
      if (g >= 0) {
        updMax(tbl[j - B[i]], pll(g + C[i], s - A[i]));
      }
    }
  }
  ll j0 = -1;
  pll p0(-1, -1);
  REPrev(j, X, 0) {
    if (tbl[j] > p0) {
      p0 = tbl[j];
      j0 = j;
    }
  }
  cout << p0.first << " " << p0.second << " " << j0 << endl;

  return 0;
}

