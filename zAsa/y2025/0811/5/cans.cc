#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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
  vector vec(H + 1, vector(W + 1, 0LL));
  REP(i, 0, H) REP(j, 0, W) {
    ll c; cin >> c;
    if ((i + j) % 2 != 0) c = -c;
    vec[i + 1][j + 1] = c;
  }
  REP(i, 0, H + 1) REP(j, 1, W + 1) vec[i][j] += vec[i][j - 1];
  REP(i, 1, H + 1) REP(j, 0, W + 1) vec[i][j] += vec[i - 1][j];
  ll ans = 0;
  REP(i0, 0, H) REP(i1, i0 + 1, H + 1) REP(j0, 0, W) REP(j1, j0 + 1, W + 1) {
    ll v = vec[i1][j1] + vec[i0][j0] - vec[i1][j0] - vec[i0][j1];
    if (v == 0) ans = max(ans, (i1 - i0) * (j1 - j0));
  }
  cout << ans << endl;
  return 0;
}

