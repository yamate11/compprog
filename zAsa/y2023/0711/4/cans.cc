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

// @@ !! LIM(input f:updMaxMin)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

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

  ll R, C, D; cin >> R >> C >> D;
  // @InpGrid(R, C, A) [8oYj8ScA]
  auto A = vector(R, vector(C, ll()));
  for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [8oYj8ScA]
  vector<ll> B(R + C - 1);
  REP(i, 0, R) REP(j, 0, C) updMax(B[i + j], A[i][j]);
  ll ans = 0;
  for (ll d = D; d >= 0; d -= 2) {
    if (d >= R + C - 1) continue;
    ans = max(ans, B[d]);
  }
  cout << ans << endl;

  return 0;
}

