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

  ll H, W; cin >> H >> W;
  // @InpGrid(H, W, C) [uNM3mhuz]
  auto C = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; C[i][j] = v; }
  // @End [uNM3mhuz]
  REP(i, 0, H) REP(j, 0, W) if ((i + j) % 2 == 1) C[i][j] = -C[i][j];
  vector S(H + 1, vector(W + 1, 0LL));
  REP(i, 0, H) REP(j, 0, W) S[i + 1][j + 1] = C[i][j];
  REP(i, 1, H + 1) REP(j, 1, W + 1) S[i][j] += S[i][j - 1];
  REP(i, 1, H + 1) REP(j, 1, W + 1) S[i][j] += S[i - 1][j];
  ll ans = 0;
  REP(x1, 0, H) REP(x2, x1 + 1, H + 1) REP(y1, 0, W) REP(y2, y1 + 1, W + 1) {
    ll v = S[x2][y2] + S[x1][y1] - (S[x2][y1] + S[x1][y2]);
    if (v == 0) ans = max(ans, (x2 - x1) * (y2 - y1));
  }
  cout << ans << endl;

  return 0;
}

