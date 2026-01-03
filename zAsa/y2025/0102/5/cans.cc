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

  ll R, C, K; cin >> R >> C >> K;
  map<pll, ll> mp;
  REP(i, 0, K) {
    ll r, c, v; cin >> r >> c >> v;
    mp[pll(r - 1, c - 1)] = v;
  }
  vector tbl(R + 1, vector(C, vector(4, -1LL)));
  tbl[0][0][0] = 0;
  REP(i, 0, R) {
    REP(j, 0, C) {
      auto it = mp.find(pll(i, j));
      if (it != mp.end()) {
        REPrev(k, 2, 0) {
          updMax(tbl[i][j][k + 1], tbl[i][j][k] + it->second);
        }
      }
      REP(k, 0, 4) {
        if (j < C - 1) updMax(tbl[i][j + 1][k], tbl[i][j][k]);
        updMax(tbl[i + 1][j][0], tbl[i][j][k]);
      }
    }
  }
  cout << tbl[R][C - 1][0] << endl;

  return 0;
}

