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

  ll H, W; cin >> H >> W;
  vector<string> S(H);
  REP(i, 0, H) cin >> S[i];
  vector tbl(H, vector(W, 0LL));
  REPrev(r, H - 1, 0) REPrev(c, W - 1, 0) {
    if (r == H - 1 and c == W - 1) {
      tbl[r][c] = S[r][c] == '#' ? 1 : 0;
    }else {
      ll v = 1e18;
      if (r + 1 < H) {
        ll x = tbl[r + 1][c];
        if (S[r][c] != S[r + 1][c]) x++;
        v = min(v, x);
      }
      if (c + 1 < W) {
        ll x = tbl[r][c + 1];
        if (S[r][c] != S[r][c + 1]) x++;
        v = min(v, x);
      }
      tbl[r][c] = v;
    }
  }
  cout << (tbl[0][0] + 1) / 2 << endl;

  return 0;
}

