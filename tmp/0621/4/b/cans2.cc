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

  ll X, Y;
  string W;
  cin >> X >> Y >> W;
  vector<string> S(9);
  REP(i, 9) cin >> S[i];
  vector tbl(27, vector(27, ' '));
  REP(p, 3) REP(q, 3) {
    ll si, di, sj, dj;
    if (p % 2 == 1) { si = 0; di = 1; }
    else            { si = 8; di = -1; }
    if (q % 2 == 1) { sj = 0; dj = 1; }
    else            { sj = 8; dj = -1; }
    for (ll zi = si, i = 0; i < 9; zi += di, i++) {
      for (ll zj = sj, j = 0; j < 9; zj += dj, j++) {
        tbl[p * 9 + zi][q * 9 + zj] = S[i][j];
      }
    }
  }
#if DEBUG
  REP(i, 27) {
    REP(j, 27) {
      cerr << tbl[i][j];
    }
    cerr << endl;
  }
#endif  

  ll ddi = 0, ddj = 0;
  REP(i, SIZE(W)) {
    if (W[i] == 'R') ddj = 1;
    if (W[i] == 'L') ddj = -1;
    if (W[i] == 'U') ddi = -1;
    if (W[i] == 'D') ddi = 1;
  }
  REP(i, 4) cout << tbl[9 + (Y - 1) + i * ddi][9 + (X - 1) + i * ddj];
  cout << endl;

  

  return 0;
}

