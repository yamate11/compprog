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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

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
  vector<ll> A(N + 1);
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  vector<ll> B(N + 1);
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }

  ll big = 1e18;

  auto f = [&](ll colCtr, ll colLast) -> ll {
    vector tbl(N, vector(2, big));
    tbl[0][colCtr] = A[0];
    tbl[0][1 - colCtr] = 0;
    tbl[0][colLast] += B[N - 1];
    REP(i, 1, N) REP(c, 0, 2) {
      tbl[i][c] = min(tbl[i - 1][c] + B[i - 1], tbl[i - 1][1 - c]);
      if (colCtr == c) tbl[i][c] += A[i];
    }
    return tbl[N - 1][colLast];
  };

  auto vec = vector<ll>{f(0, 0), f(0, 1), f(1, 0), f(1, 1)};
  ll ans = *min_element(ALL(vec));
  cout << ans << endl;

  return 0;
}

