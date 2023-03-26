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

  ll H, W, A, B; cin >> H >> W >> A >> B;
  ll ans = 0;
  vector used(H, vector(W, false));
  auto dfs = [&](auto rF, ll i, ll j, ll a, ll b) -> void {
    if (i == H) {
      ans++;
    }else if (j == W) {
      rF(rF, i + 1, 0, a, b);
    }else if (used[i][j]) {
      rF(rF, i, j + 1, a, b);
    }else {
      if (b < B) {
        used[i][j] = true;
        rF(rF, i, j + 1, a, b + 1);
        used[i][j] = false;
      }
      if (a < A) {
        if (j + 1 < W and not used[i][j + 1]) {
          used[i][j] = true;
          used[i][j + 1] = true;
          rF(rF, i, j + 2, a + 1, b);
          used[i][j + 1] = false;
          used[i][j] = false;
        }
        if (i + 1 < H and not used[i + 1][j]) {
          used[i][j] = true;
          used[i + 1][j] = true;
          rF(rF, i, j + 1, a + 1, b);
          used[i + 1][j] = false;
          used[i][j] = false;
        }
      }
    }
  };
  dfs(dfs, 0, 0, 0, 0);
  cout << ans << endl;

  return 0;
}

