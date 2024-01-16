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

  ll x, y; cin >> x >> y; x--; y--;
  string W; cin >> W;
  vector P(49, vector(49, ' '));
  REP(i, 0, 9) REP(j, 0, 9) {
    char c; cin >> c;
    P[i][j] = c;
  }
  REP(i, 0, 9) REP(j, 0, 8) P[i][16 - j] = P[i][j];
  REP(i, 0, 8) REP(j, 0, 9) P[16 - i][j] = P[i][j];
  REP(i, 0, 8) REP(j, 0, 8) P[16 - i][16 - j] = P[i][j];
  REP(i, 0, 49) REP(j, 0, 49) {
    if (i >= 17) P[i][j] = P[i - 16][j];
    else if (j >= 17) P[i][j] = P[i][j - 16];
  }

#if DEBUG
  REP(i, 0, 49) {
    REP(j, 0, 49) cerr << P[i][j];
    cerr << endl;
  }
#endif

  x += 16;
  y += 16;
  ll sz = SIZE(W);
  REP(i, 0, 4) {
    cout << P[y][x];
    if (W[0] == 'R' or (sz == 2 and W[1] == 'R')) x++;
    if (W[0] == 'L' or (sz == 2 and W[1] == 'L')) x--;
    if (W[0] == 'U' or (sz == 2 and W[1] == 'U')) y--;
    if (W[0] == 'D' or (sz == 2 and W[1] == 'D')) y++;
  }
  cout << endl;
  

  return 0;
}

