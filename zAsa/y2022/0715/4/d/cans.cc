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

  ll N; cin >> N;
  ll X, Y; cin >> X >> Y;
  
  ll big = 1e9;
  vector tbl(X + 1, vector(Y + 1, big));
  tbl[0][0] = 0;
  REP(i, N) {
    ll a, b; cin >> a >> b;
    REP2R(x, X, 0) REP2R(y, Y, 0) {
      if (x == X and y == Y) continue;
      if (tbl[x][y] >= big) continue;
      ll xx = min(X, x + a);
      ll yy = min(Y, y + b);
      updMin(tbl[xx][yy], tbl[x][y] + 1);
    }
  }
  if (tbl[X][Y] >= big) cout << -1 << endl;
  else cout << tbl[X][Y] << endl;

  return 0;
}

