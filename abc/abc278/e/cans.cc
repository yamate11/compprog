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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, N, h, w; cin >> H >> W >> N >> h >> w;
  // @InpGrid(H, W, A) [A4CMyHA1]
  auto A = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [A4CMyHA1]
  vector S(H + 1, vector(W + 1, vector(N + 1, 0LL)));
  REP(r, 0, H) REP(c, 0, W) S[r + 1][c + 1][A[r][c]] = 1;
  REP(r, 1, H + 1) REP(c, 1, W + 1) REP(i, 1, N + 1) S[r][c][i] += S[r][c - 1][i];
  REP(c, 1, W + 1) REP(r, 1, H + 1) REP(i, 1, N + 1) S[r][c][i] += S[r - 1][c][i];
  auto count = [&](ll i, ll r1, ll c1, ll r2, ll c2) -> ll {
    return S[r2][c2][i] + S[r1][c1][i] - S[r1][c2][i] - S[r2][c1][i];
  };
  vector ans(H - h + 1, vector(W - w + 1, 0LL));
  REP(k, 0, H - h + 1) REP(l, 0, W - w + 1) {
    REP(i, 1, N + 1) if (count(i, 0, 0, H, W) - count(i, k, l, k + h, l + w) > 0) ans[k][l]++;
  }
  REP(k, 0, H - h + 1) REPOUT(l, 0, W - w + 1, ans[k][l], " ");

  return 0;
}

