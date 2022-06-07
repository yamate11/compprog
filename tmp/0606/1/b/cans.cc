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

  ll H, W, X, Y; cin >> H >> W >> X >> Y; X--; Y--;
  vector<string> S(H);
  REP(i, H) cin >> S[i];
  ll cnt = 1;
  REP2(i, X + 1, H) {
    if (S[i][Y] == '#') break;
    cnt++;
  }
  REP2R(i, X - 1, 0) {
    if (S[i][Y] == '#') break;
    cnt++;
  }
  REP2(j, Y + 1, W) {
    if (S[X][j] == '#') break;
    cnt++;
  }
  REP2R(j, Y - 1, 0) {
    if (S[X][j] == '#') break;
    cnt++;
  }
  cout << cnt << endl;

  return 0;
}

