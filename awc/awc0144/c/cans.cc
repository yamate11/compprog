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

  ll N, M, K; cin >> N >> M >> K;
  // @InpMVec(N, (C, T, P)) [7vWFkjK1]
  auto C = vector(N, ll());
  auto T = vector(N, ll());
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; C[i] = v1;
    ll v2; cin >> v2; T[i] = v2;
    ll v3; cin >> v3; P[i] = v3;
  }
  // @End [7vWFkjK1]

  vector tbl(K + 1, -1LL);
  tbl[0] = 0;
  REP(i, 0, N) {
    ll prof = P[i] - C[i];
    if (prof <= 0) continue;
    REP(j, 0, K + 1) {
      if (tbl[j] < 0) continue;
      ll j0 = j + T[i];
      if (j0 >= K + 1) break;
      updMax(tbl[j0], tbl[j] + prof);
    }
  }
  ll ans = *ranges::max_element(tbl);
  ans *= M;
  cout << ans << endl;
  return 0;
}

