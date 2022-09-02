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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  auto SH = vector(H, vector(W, char()));
  auto SV = vector(W, vector(H, char()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
      char v; cin >> v;
      SH[i][j] = SV[j][i] = v;
    }
  auto func = [&](auto& vvec, ll N1, ll N2) {
    vector ret(N1, vector(N2, 0LL));
    REP(i, 0, N1) {
      vector<ll> upper(N2), lower(N2);
      ll t = 0;
      REP(j, 0, N2) {
        if (vvec[i][j] == '#') t = j + 1;
        else lower[j] = t;
      }
      t = N2;
      REPrev(j, N2 - 1, 0) {
        if (vvec[i][j] == '#') t = j;
        else upper[j] = t;
      }
      REP(j, 0, N2) ret[i][j] = upper[j] - lower[j];
    }
    return ret;
  };
  auto Horiz = func(SH, H, W);
  auto Vert = func(SV, W, H);
  ll ans = 0;
  REP(i, 0, H) REP(j, 0, W) {
    ans = max(ans, Horiz[i][j] + Vert[j][i] - 1);
  }
  cout << ans << endl;
  return 0;
}

  
