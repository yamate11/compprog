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

  auto solve = [&]() -> ll {
    ll N, M; cin >> N >> M;
    // @InpMVec(N, (X, Y)) [2CyJ0Ssp]
    auto X = vector(N, ll());
    auto Y = vector(N, ll());
    for (int i = 0; i < N; i++) {
      ll v1; cin >> v1; X[i] = v1;
      ll v2; cin >> v2; Y[i] = v2;
    }
    // @End [2CyJ0Ssp]

    REP(i, 0, N) X[i] *= 2;

    ll big = 1e18;
    ll ans = -big;
    
    ll b0 = 0, c0 = 0;
    REP(i, 0, N) {
      if (X[i] == 0) {
        ll new_c0 = c0 + b0 * Y[i];
        updMax(ans, c0 + b0);
        updMax(ans, new_c0);
        c0 = new_c0;
      }else {
        ll p = X[i] / 2;
        ll q = X[i] / 2 + b0;
        ll r = c0;
        auto f = [&](ll t) -> ll {
          return p * t * t + q * t + r;
        };
        updMax(ans, f(1));
        updMax(ans, f(Y[i]));
        double s = - double(X[i] / 2 + b0) / X[i];
        ll z1 = llround(floor(s));
        ll z2 = llround(ceil(s));
        if (1 <= z1 and z1 <= Y[i]) updMax(ans, f(z1));
        if (1 <= z2 and z2 <= Y[i]) updMax(ans, f(z2));
        b0 = b0 + X[i] * Y[i];
        c0 = f(Y[i]);
      }
    }
    return ans / 2;


  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

