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
  // @InpGrid(H, W, A) [W7T2OdOB]
  auto A = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [W7T2OdOB]
  ll big = 1e18;
  ll ans = -big;
  REP(x, 0, 1LL << H) {
    ll s = 0;
    REP(i, 0, H) if (x >> i & 1) {
      REP(j, 0, W) s += A[i][j];
    }
    REP(j, 0, W) {
      ll cur = 0;
      REP(i, 0, H) if (not (x >> i & 1)) cur += A[i][j];
      if (cur > 0) s += cur;
    }
    ans = max(ans, s);
  }
  cout << ans << endl;
  return 0;
}

