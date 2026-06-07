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

  ll N; cin >> N;
  // @InpVec(N, A) [OtA1AXOg]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [OtA1AXOg]
  // @InpVec(N, C) [pov1Ozlt]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [pov1Ozlt]
  vector<ll> tbl(N);
  REP(i, 0, N) {
    updMax(tbl[i], C[i]);
    REP(j, i + 1, N) if (A[i] < A[j]) updMax(tbl[j], tbl[i] + C[j]);
  }
  ll v = *ranges::max_element(tbl);
  ll tot = accumulate(ALL(C), 0LL);
  cout << tot - v << endl;

  return 0;
}

