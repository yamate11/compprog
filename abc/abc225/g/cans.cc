#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, C; cin >> H >> W >> C;
  vector A(H, vector(W, 0LL)); REP(i, H) REP(j, W) cin >> A[i][j];

  ll NE = (H + W) % 2 == 0 ? (H-1 + W-1) / 2 + 1 : (H-1 + W-1 - 1) / 2 + 1;
  ll NO = (H + W) % 2 == 0 ? (H-1 + W-1 - 1) / 2 + 1 : (H-1 + W-1) / 2 + 1;
  ll shiftE = W % 2 == 0 ? (W-2) / 2 : (W-1) / 2;
  ll shiftO = W % 2 == 0 ? (W-1) / 2 : (W-2) / 2;
  ll ME = (H % 2 == 0 ? (H-2) / 2 : (H-1) / 2) + 1 + shiftE;
  ll MO = (H % 2 == 0 ? (H-1) / 2 : (H-2) / 2) + 1 + shiftO;
  vector vE(NE, vector(ME, 0LL));
  vector vO(NO, vector(MO, 0LL));

  REP(y, H) REP(x, W) {
    if ((x + y) % 2 == 0) vE[(x + y)     / 2][(x - y)     / 2 + shiftE] = A[y][x];
    else                  vO[(x + y - 1) / 2][(x - y - 1) / 2 + shiftO] = A[y][x];
  }
  auto func = [&](const auto& vec, ll n, ll m) {
    vector tbl(n + 1, vector(m + 1, 0LL));
    vector S(n + 1, vector(m + 1, 0LL));
    REP(i, n) REP(j, m) S[i][j+1] = S[i][j] + vec[i][j];
    REP(j, n) REP(i, m) S[i+1][j+1] = S[i][j+1] + vec[i][j+1];
    auto acc = [&](ll i0, ll j0, ll i1, ll j1) -> ll { return S[i1][j1] - S[i1][j0] - S[i0][j1] + S[i0][j0]; };
    REP(i, n) REP(j, m) {
      ll val = 0;
      REP(p, i) REP(q, j) {
        val = max(val, tbl[p][q] + acc(p, q, i, j));
      }
      tbl[i][j] = val;
    }
    return tbl[n][m];
  };

  ll score1 = func(vE, NE, ME);
  ll score2 = func(vO, NO, MO);
  cout << score1 + score2 << endl;
  return 0;
}

