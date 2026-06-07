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

  ll N, D; cin >> N >> D;
  // @InpMVec(N, (C, F)) [fLNTkVN7]
  auto C = vector(N, ll());
  auto F = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; C[i] = v1;
    ll v2; cin >> v2; F[i] = v2;
  }
  // @End [fLNTkVN7]

  ll big = 1e18;
  vector<ll> tbl(D + 1, big);
  tbl[0] = 0;
  REP(i, 0, N) {
    REP(j, 0, D + 1) {
      if (tbl[j] < big) {
        ll k = min(j + F[i], D);
        updMin(tbl[k], tbl[j] + C[i]);
      }
    }
  }
  cout << tbl[D] << "\n";

  return 0;
}

