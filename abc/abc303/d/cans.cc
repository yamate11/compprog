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

  ll X, Y, Z; cin >> X >> Y >> Z;
  string S; cin >> S;
  ll N = SIZE(S);
  ll big = 1e18;
  ll wL = 0;
  ll wU = big;
  REP(i, 0, N) {
    ll pL = wL;
    ll pU = wU;
    wL = wU = big;
    if (S[i] == 'A') {
      updMin(wU, pU + X);
      updMin(wL, pU + Z + Y);
      updMin(wL, pL + Y);
      updMin(wU, pL + Z + X);
      // updMin(wU, pU + X);
      // updMin(wL, pU + X + Z);
      // updMin(wL, pL + Y);
      // updMin(wU, pL + Y + Z);
      // updMin(wU, pL + Z + X);
    }else if (S[i] == 'a') {
      updMin(wL, pL + X);
      updMin(wU, pL + Z + Y);
      updMin(wU, pU + Y);
      updMin(wL, pU + Z + X);
      // updMin(wL, pL + X);
      // updMin(wU, pL + X + Z);
      // updMin(wU, pU + Y);
      // updMin(wL, pU + Y + Z);
      // updMin(wL, pU + Z + X);
    }else assert(0);
  }
  cout << min(wL, wU) << endl;

  return 0;
}

