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
  // @InpMVec(N, (P, T)) [qqocxrKf]
  auto P = vector(N, ll());
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; P[i] = v1;
    ll v2; cin >> v2; T[i] = v2;
  }
  // @End [qqocxrKf]

  ll big = 1e18;
  REP(j, 0, M) {
    ll K; cin >> K;
    // @InpVec(K, S, dec=1) [ezjUkHMc]
    auto S = vector(K, ll());
    for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; S[i] = v; }
    // @End [ezjUkHMc]
    vector vec(2, big);
    REP(i, 0, K) {
      updMin(vec[T[S[i]]], P[S[i]]);
    }
    if (vec[0] == big or vec[1] == big) {
      cout << -1 << "\n";
    }else {
      cout << vec[0] + vec[1] << "\n";
    }

  }

  return 0;
}

