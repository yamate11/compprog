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

  ll N, M; cin >> N >> M;
  vector<ll> X(N, 0LL);
  REP(i, N) cin >> X[i];
  vector<ll> Y(N + 1, 0LL);
  REP(i, M) {
    ll c, y; cin >> c >> y;
    Y[c] = y;
  }
  auto tbl_init = vector(N + 1, -1LL);
  auto tbl = tbl_init;
  tbl[0] = 0;
  REP(i, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(c, N) {
      if (prev[c] < 0) continue;
      updMax(tbl[c + 1], prev[c] + X[i] + Y[c + 1]);
      updMax(tbl[0], prev[c]);
    }
  }
  cout << *max_element(ALL(tbl)) << endl;

  return 0;
}

