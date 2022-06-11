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

int main2(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, K; cin >> H >> W >> K;
  vector ans(H, vector(W, 0LL));
  ll seq = 0;
  REP(i, H) {
    string s; cin >> s;
    REP(j, W) ans[i][j] = s[j] == '#' ? ++seq : 0;
  }
  REP(i, H) {
    REP2(j, 1, W)      if (ans[i][j] == 0) ans[i][j] = ans[i][j - 1];
    REP2R(j, W - 2, 0) if (ans[i][j] == 0) ans[i][j] = ans[i][j + 1];
  }
  REP(j, W) {
    REP2(i, 1, H)      if (ans[i][j] == 0) ans[i][j] = ans[i][j - 1];
    REP2R(i, H - 2, 0) if (ans[i][j] == 0) ans[i][j] = ans[i][j + 1];
  }
  REP(i, H) {
    REP(j, W) cout << ans[i][j] << " ";
    cout << "\n";
  }

  return 0;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, K; cin >> H >> W >> K;
  vector ans(H, vector(W, 0LL));
  ll seq = 0;
  REP(i, H) {
    string s; cin >> s;
    REP(j, W) ans[i][j] = s[j] == '#' ? ++seq : j == 0 ? 0 : ans[i][j - 1];
    if (ans[i][W - 1] != 0) REP2R(j, W - 2, 0) { if (ans[i][j] == 0) ans[i][j] = ans[i][j + 1]; }
    else if (i > 0 and ans[i - 1][0] != 0) { ans[i] = ans[i - 1]; }
  }
  REP(j, W) {
    REP2(i, 1, H)      if (ans[i][j] == 0) ans[i][j] = ans[i][j - 1];
    REP2R(i, H - 2, 0) if (ans[i][j] == 0) ans[i][j] = ans[i][j + 1];
  }
  REP(i, H) {
    REP(j, W) cout << ans[i][j] << " ";
    cout << "\n";
  }

  return 0;
}

