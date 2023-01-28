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

  ll N; cin >> N;
  // @InpGrid(N, N, D) [1YITyoXW]
  auto D = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; D[i][j] = v; }
  // @End [1YITyoXW]
  vector S(N + 1, vector(N + 1, 0LL));
  REP(i, 0, N) REP(j, 0, N) S[i + 1][j + 1] = D[i][j];
  REP(i, 1, N + 1) REP(j, 1, N + 1) S[i][j] += S[i - 1][j];
  REP(i, 1, N + 1) REP(j, 1, N + 1) S[i][j] += S[i][j - 1];
  vector<ll> vec(N * N + 1);
  REP(x0, 0, N) REP(y0, 0, N) REP(x1, x0 + 1, N + 1) REP(y1, y0 + 1, N + 1) {
    ll a = (x1 - x0) * (y1 - y0);
    ll t = S[x1][y1] + S[x0][y0] - (S[x1][y0] + S[x0][y1]);
    updMax(vec[a], t);
  }
  REP(i, 1, N * N + 1) vec[i] = max(vec[i], vec[i - 1]);
  ll Q; cin >> Q;
  REP(i, 0, Q) {
    ll x; cin >> x;
    cout << vec[x] << "\n";
  }

  return 0;
}

