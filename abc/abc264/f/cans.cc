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
  vector<ll> R(H); REP(i, H) cin >> R[i];
  vector<ll> C(W); REP(i, W) cin >> C[i];
  vector<string> A(H); REP(i, H) cin >> A[i];
  vector tbl(2, vector(2, vector(H, vector(W, 0LL))));
  REP(r, H) REP(c, W) {
    REP(p, 2) REP(q, 2) {
      if (r == 0 and c == 0) {
        ll v = 0;
        if (p == 1) v += R[0];
        if (q == 1) v += C[0];
        tbl[p][q][r][c] = v;
        continue;
      }
      ll e = A[r][c] - '0';
      ll ee = e ^ p ^ q;
      ll x = 1e18;
      ll y = 1e18;
      if (r > 0) {
        ll f = A[r - 1][c] - '0';
        ll ff = f ^ q;
        ll pp;
        if (ff == ee) pp = 0;
        else pp = 1;
        x = tbl[pp][q][r - 1][c] + (p ? R[r] : 0);
      }
      if (c > 0) {
        ll g = A[r][c - 1] - '0';
        ll gg = g ^ p;
        ll qq;
        if (gg == ee) qq = 0;
        else qq = 1;
        y = tbl[p][qq][r][c - 1] + (q ? C[c] : 0);
      }
      ll z = min(x, y);
      tbl[p][q][r][c] = z;
    }
  }
  ll ans = 1e18;
  REP(p, 2) REP(q, 2) ans = min(ans, tbl[p][q][H - 1][W - 1]);

  cout << ans << endl;
  return 0;
}

