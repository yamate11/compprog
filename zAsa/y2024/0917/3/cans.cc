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

  ll X, Y, Z; cin >> X >> Y >> Z;
  string S; cin >> S;
  ll big = 1e18;
  ll toff = 0;
  ll ton = big;
  ll N = ssize(S);
  REP(i, 0, N) {
    ll poff = toff;
    ll pon = ton;
    toff = ton = big;
    if (poff < big) {
      if (S[i] == 'a') {
        updMin(toff, poff + X);
        updMin(ton, poff + Z + Y);
      }else if (S[i] == 'A') {
        updMin(toff, poff + Y);
        updMin(ton, poff + Z + X);
      }
    }
    if (pon < big) {
      if (S[i] == 'A') {
        updMin(ton, pon + X);
        updMin(toff, pon + Z + Y);
      }else if (S[i] == 'a') {
        updMin(ton, pon + Y);
        updMin(toff, pon + Z + X);
      }
    }
  }
  cout << min(ton, toff) << endl;

  return 0;
}

