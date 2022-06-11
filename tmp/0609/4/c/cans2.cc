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

  ll H, W, K; cin >> H >> W >> K;
  vector<string> S(H);
  REP(i, H) cin >> S[i];
  vector<ll> cutH;
  string blank(W, '.');
  bool firstH = true;
  cutH.push_back(0);
  REP(i, H) {
    if (S[i] == blank) continue;
    if (firstH) firstH = false;
    else cutH.push_back(i);
  }
  cutH.push_back(H);
  vector ans(H, vector(W, 0LL));
  ll seq = 1;
  REP(i, SIZE(cutH) - 1) {
    auto blankW = [&](ll j) -> bool {
      REP2(k, cutH[i], cutH[i + 1]) if (S[k][j] == '#') return false;
      return true;
    };
    vector<ll> cutV;
    bool firstV = true;
    cutV.push_back(0);
    REP(j, W) {
      if (blankW(j)) continue;
      if (firstV) firstV = false;
      else cutV.push_back(j);
    }
    cutV.push_back(W);
    REP(p, SIZE(cutV) - 1) {
      REP2(k, cutH[i], cutH[i + 1]) REP2(j, cutV[p], cutV[p + 1]) ans[k][j] = seq;
      seq++;
    }
  }

  REP(i, H) {
    REP(j, W) cout << ans[i][j] << " ";
    cout << "\n";
  }

  return 0;
}

