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

  ll Q, H, S, D, N; cin >> Q >> H >> S >> D >> N;
  N *= 4;
  ll v = Q * 8;
  updMin(v, H * 4);
  updMin(v, S * 2);
  updMin(v, D);
  ll x = N / 8;
  ll y = N % 8;
  ll w = 1e18;
  REP(iS, 0, y + 1) REP(iH, 0, y + 1) REP(iQ, 0, y + 1) {
    if (iS * 4 + iH * 2 + iQ == y) updMin(w, iS * S + iH * H + iQ * Q);
  }
  cout << v * x + w << endl;

  return 0;
}

