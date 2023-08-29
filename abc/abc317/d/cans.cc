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

  ll N; cin >> N;
  // @InpMVec(N, (X, Y, Z)) [ylitSaID]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  auto Z = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
    ll v3; cin >> v3; Z[i] = v3;
  }
  // @End [ylitSaID]
  ll totZ = 0;
  REP(i, 0, N) totZ += Z[i];
  ll big = 1e18;
  vector<ll> tbl_init(totZ + 1, big);
  auto tbl = tbl_init;
  tbl[0] = 0;
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(z, 0, totZ + 1) {
      if (prev[z] == big) continue;
      if (X[i] > Y[i]) {
        updMin(tbl[z + Z[i]], prev[z]);
      }else {
        updMin(tbl[z], prev[z]);
        updMin(tbl[z + Z[i]], prev[z] + (Y[i] - X[i]) / 2 + 1);
      }
    }
  }
  ll ans = big;
  REP(i, totZ / 2 + 1, totZ + 1) ans = min(ans, tbl[i]);
  cout << ans << endl;

  return 0;
}

