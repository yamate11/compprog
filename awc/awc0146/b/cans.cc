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
  // @InpGrid(H, W, G) [vx0qoWua]
  auto G = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; G[i][j] = v; }
  // @End [vx0qoWua]
  vector<ll> row(H);
  vector<ll> col(W);
  REP(i, 0, H) REP(j, 0, W) {
    row[i] += G[i][j];
    col[j] += G[i][j];
  }
  ll big = 1LL << 60;
  ll ans = -big;
  REP(i, 0, H) REP(j, 0, W) {
    ll s = row[i] + col[j] - G[i][j];
    ans = max(ans, s);
  }
  cout << ans << "\n";
  return 0;
}

