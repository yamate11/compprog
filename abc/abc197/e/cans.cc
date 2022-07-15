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
  vector<ll> X(N), C(N);
  REP(i, N) cin >> X[i] >> C[i];
  ll lim = *max_element(ALL(C));
  const ll big = 1e18;
  vector E(2, vector(lim + 1, big));
  REP(i, N) {
    ll c = C[i];
    updMin(E[0][c], X[i]);
    updMax(E[1][c], X[i]);
  }
  E[0][0] = E[1][0] = 0;
  for (ll i = 1, j = 1, true; i++, j++) {
    while(j <= lim and E[0][j] == big) j++;
    if (j > lim) {
      REP(k, 2) E[k].resize(i);
      E[0].push_back(0);
      E[1].push_back(0);
      break;
    }
    E[0][i] = E[0][j];
    E[1][i] = E[1][j];
  }
  vector tbl_init(2, big);
  auto tbl = tbl_init;
  tbl[0] = tbl[1] = 0;
  REP(i, lim + 1) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(j, 2) {
      tbl[j] = min(prev[abs(p - E[1 - j][i]), abs(q - E[1 - j][i])
    }
    
  }
  

  return 0;
}

