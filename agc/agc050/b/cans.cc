#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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
  // @InpVec(N, A) [5kaqizsC]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [5kaqizsC]

  ll big = 1e18;
  vector tbl(N + 1, vector(N + 1, -big));
  auto f = [&](auto rF, ll a, ll b) -> ll {
    ll& ret = tbl[a][b];
    if (ret == -big) {
      ret = 0;
      for (ll i = a; i < b; i++) {
        for (ll j = i + 1; j < b; j += 3) {
          for (ll k = j + 1; k < b; k += 3) {
            ll v = rF(rF, a, i) + rF(rF, i + 1, j) + rF(rF, j + 1, k) + rF(rF, k + 1, b);
            ll w = A[i] + A[j] + A[k];
            updMax(ret, v + w);
          }
        }
      }
    }
    return ret;
  };

  cout << f(f, 0, N) << endl;
  return 0;

}

