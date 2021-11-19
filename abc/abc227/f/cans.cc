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

  ll H, W, K; cin >> H >> W >> K;
  vector A(H, vector<ll>(W));
  vector<ll> vals;
  REP(i, H) REP(j, W) {
    ll a; cin >> a;
    A[i][j] = a;
    vals.push_back(a);
  }
  sort(ALL(vals));
  vals.erase(unique(ALL(vals)), vals.end());
  ll big = 1e18;
  ll ans = big;
  for (ll v : vals) {
    vector tbl(H, vector(W, vector(K+1, big)));
    REP(i, H) REP(j, W) REP(k, K + 1) {
      if (i == 0 and j == 0) {
        if (A[0][0] <= v) tbl[0][0][0] = 0;
        if (A[0][0] >= v) tbl[0][0][1] = A[0][0];
        continue;
      }
      if (A[i][j] <= v) {
        if (i > 0) updMin(tbl[i][j][k], tbl[i-1][j][k]);
        if (j > 0) updMin(tbl[i][j][k], tbl[i][j-1][k]);
      }
      if (A[i][j] >= v) {
        if (i > 0 and k > 0) updMin(tbl[i][j][k], tbl[i-1][j][k-1] + A[i][j]);
        if (j > 0 and k > 0) updMin(tbl[i][j][k], tbl[i][j-1][k-1] + A[i][j]);
      }
    }
    updMin(ans, tbl[H-1][W-1][K]);
  }
  cout << ans << endl;

  return 0;
}

