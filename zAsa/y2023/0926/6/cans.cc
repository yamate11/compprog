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
  // @InpVec(N, A) [EAMIrEPf]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [EAMIrEPf]
  // @InpVec(N, B) [YRxpdOgO]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [YRxpdOgO]

  ll big = 1e18;
  auto tbl_init = vector(2, big);
  ll ans = big;
  REP(st, 0, 2) {
    auto tbl = tbl_init;
    if (st == 0) {
      tbl[0] = A[0];
      tbl[1] = big;
    }else {
      tbl[0] = big;
      tbl[1] = 0;
    }
    REP(i, 1, N) {
      auto prev = move(tbl);
      tbl = tbl_init;
      REP(c, 0, 2) REP(d, 0, 2) {
        ll x = prev[c];
        if (c == d) x += B[i - 1];
        if (d == 0) x += A[i];
        updMin(tbl[d], x);
      }
    }
    ll v = min(tbl[st] + B[N - 1], tbl[1 - st]);
    ans = min(ans, v);
  }
  cout << ans << endl;
  return 0;
}

