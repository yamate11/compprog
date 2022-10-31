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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, D; cin >> H >> W >> D;
  // @InpGrid(H, W, A) [XeBfRqo7]
  auto A = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [XeBfRqo7]
  ll N = H * W;
  vector<ll> X(N + 1), Y(N + 1);
  REP(i, 0, H) REP(j, 0, W) {
    X[A[i][j]] = i;
    Y[A[i][j]] = j;
  }
  vector<ll> Len(N + 1);
  for (ll i = 1; i + D <= N; i++) Len[i] = abs(X[i + D] - X[i]) + abs(Y[i + D] - Y[i]);
  vector<ll> Cum(N + 1);
  for (ll i = 1; i + D <= N; i++) {
    Cum[i + D] = Cum[i] + Len[i];
  }

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll l, r; cin >> l >> r;
    cout << Cum[r] - Cum[l] << "\n";
  }

  return 0;
}

