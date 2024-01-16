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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, D; cin >> H >> W >> D;
  // @InpGrid(H, W, A, dec=1) [2605eZ5g]
  auto A = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; v -= 1; A[i][j] = v; }
  // @End [2605eZ5g]
  
  vector X(H * W, 0LL);
  vector Y(H * W, 0LL);
  REP(i, 0, H) REP(j, 0, W) {
    X[A[i][j]] = i;
    Y[A[i][j]] = j;
  }
  vector rec(D, vector<ll>{0});
  REP(i, 0, H * W) {
    if (i + D < H * W) {
      ll len = abs(X[i + D] - X[i]) + abs(Y[i + D] - Y[i]);
      rec[i % D].push_back(rec[i % D].back() + len);
    }
  }
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll l, r; cin >> l >> r; l--; r--;
    ll p = l % D;
    ll i = (l - p) / D;
    ll j = (r - p) / D;
    cout << rec[p][j] - rec[p][i] << "\n";

    
  }

  return 0;
}

