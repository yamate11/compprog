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

  ll H, W; cin >> H >> W;
  vector<string> S(H);
  REP(i, H) cin >> S[i];
  ll i0 = -1, j0 = -1, i1 = -1, j1 = -1;
  REP(i, H) REP(j, W) {
    if (S[i][j] == 'o') {
      if (i0 < 0) {
        i0 = i;
        j0 = j;
      }else {
        i1 = i;
        j1 = j;
      }
    }
  }
  cout << abs(i0 - i1) + abs(j0 - j1) << endl;

  return 0;
}

