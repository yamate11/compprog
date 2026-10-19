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

  ll H, W, Q; cin >> H >> W >> Q;
  // @InpMVec(Q, ((R, dec=1), (C, dec=1), (X, type=char))) [pVULxN4i]
  auto R = vector(Q, ll());
  auto C = vector(Q, ll());
  auto X = vector(Q, char());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; v1 -= 1; R[i] = v1;
    ll v2; cin >> v2; v2 -= 1; C[i] = v2;
    char v3; cin >> v3; X[i] = v3;
  }
  // @End [pVULxN4i]
  vector tbl(H, vector(W, 0LL));
  REP(i, 0, Q) tbl[R[i]][C[i]] = i + 1;
  REPrev(i, H - 1, 0) REPrev(j, W - 2, 0) updMax(tbl[i][j], tbl[i][j + 1]);
  REPrev(i, H - 2, 0) REPrev(j, W - 1, 0) updMax(tbl[i][j], tbl[i + 1][j]);
  vector<string> ans(H, string(W, 'A'));
  REP(i, 0, H) REP(j, 0, W) {
    ll e = tbl[i][j];
    if (e > 0) ans[i][j] = X[e - 1];
  }
  REP(i, 0, H) cout << ans[i] << "\n";

  return 0;
}

