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

  ll N; cin >> N;
  // @InpGrid(N, N, D) [vcwkpONM]
  auto D = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; D[i][j] = v; }
  // @End [vcwkpONM]

  auto E = D;
  REP(i, 0, N) REP(j, 1, N) E[i][j] += E[i][j - 1];
  REP(i, 1, N) REP(j, 0, N) E[i][j] += E[i - 1][j];
  auto e = [&](ll x, ll y) -> ll { return x ? (y ? E[x - 1][y - 1] : 0) : 0; };
  vector<ll> vec(N * N + 1, 0LL);
  REP(x0, 0, N) REP(y0, 0, N) REP(x1, x0 + 1, N + 1) REP(y1, y0 + 1, N + 1) {
    ll s = (x1 - x0) * (y1 - y0);
    ll v = e(x0, y0) + e(x1, y1) - e(x0, y1) - e(x1, y0);
    updMax(vec[s], v);
  }
  REP(i, 1, N * N + 1) updMax(vec[i], vec[i - 1]);

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll p; cin >> p;
    cout << vec[p] << "\n";
  }

  return 0;
}

