#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

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

  ll big = 1e18;

  ll H, W, C; cin >> H >> W >> C;
  auto f = [&](auto& A) -> ll {
    vector V(H, vector(W, big));
    vector T(H, vector(W, big));
    REP(i, H) REP(j, W) {
      V[i][j] = big;
      if (i > 0) updMin(V[i][j], T[i - 1][j] + C);
      if (j > 0) updMin(V[i][j], T[i][j - 1] + C);
      T[i][j] = min(V[i][j], A[i][j]);
    }
    ll ans = big;
    REP(i, H) REP(j, W) {
      ll w = V[i][j] + A[i][j];
      ans = min(ans, w);
    }
    return ans;
  };

  vector A(H, vector(W, 0LL));
  REP(i, H) REP(j, W) cin >> A[i][j];
  ll v1 = f(A);
  vector B(H, vector(W, 0LL));
  REP(i, H) REP(j, W) B[i][j] = A[i][W - 1 - j];
  ll v2 = f(B);
  ll ans = min(v1, v2);

  cout << ans << endl;


  return 0;
}

