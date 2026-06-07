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
  // @InpGrid(H, W, A) [EcvwfcOU]
  auto A = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [EcvwfcOU]
  using sta = tuple<ll, ll, ll, ll>;
  vector<sta> ans;
  REP(i, 0, H - 1) {
    REP(j, 0, W) {
      if (A[i][j] % 2 != 0) {
        A[i][j]--;
        A[i + 1][j]++;
        ans.emplace_back(i, j, i + 1, j);
      }
    }
  }
  REP(j, 0, W - 1) {
    if (A[H - 1][j] % 2 != 0) {
      A[H - 1][j]--;
      A[H - 1][j + 1]++;
      ans.emplace_back(H - 1, j, H - 1, j + 1);
    }
  }
  cout << ssize(ans) << endl;
  for (auto [a, b, c, d] : ans) {
    cout << format("{} {} {} {}\n", a + 1, b + 1, c + 1, d + 1);
  }
  return 0;
}

