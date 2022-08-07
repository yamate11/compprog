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

  ll tot = 0;
  auto inp = [&](ll i0, ll j0) {
    vector vec(i0, vector(j0, 0LL));
    REP(i, i0) REP(j, j0) {
      ll x; cin >> x;
      vec[i][j] = x;
      tot += x;
    }
    return vec;
  };
  auto B = inp(2, 3);
  auto C = inp(3, 2);

  vector brd(3, vector(3, ' '));

  auto dfs = [&](auto rF, ll n) -> ll {
    if (n == 9) {
      ll ret = 0;
      REP(i, 2) REP(j, 3) if (brd[i][j] == brd[i + 1][j]) ret += B[i][j];
      REP(i, 3) REP(j, 2) if (brd[i][j] == brd[i][j + 1]) ret += C[i][j];
      return ret;
    }
    bool isFst = n % 2 == 0;
    auto op = isFst ? updMax<ll> : updMin<ll>;
    ll val = isFst ? LLONG_MIN : LLONG_MAX;
    REP(i, 3) REP(j, 3) {
      if (brd[i][j] != ' ') continue;
      brd[i][j] = isFst ? 'o' : 'x';
      op(val, rF(rF, n + 1));
      brd[i][j] = ' ';
    }
    return val;
  };
  
  ll fst = dfs(dfs, 0);
  ll snd = tot - fst;
  cout << fst << "\n" << snd << "\n";

  return 0;
}

