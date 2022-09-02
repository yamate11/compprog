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
  // @InpGrid(H, W, G, type=char) [uUgauVlL]
  auto G = vector(H, vector(W, char()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { char v; cin >> v; G[i][j] = v; }
  // @End [uUgauVlL]
  vector visited(H, vector(W, false));
  ll r = 0, c = 0;
  while (true) {
    if (visited[r][c]) {
      cout << -1 << endl;
      return 0;
    }
    visited[r][c] = true;
    if (G[r][c] == 'U' and r != 0) r--;
    else if (G[r][c] == 'D' and r != H - 1) r++;
    else if (G[r][c] == 'L' and c != 0) c--;
    else if (G[r][c] == 'R' and c != W - 1) c++;
    else {
      cout << r + 1 << " " << c + 1 << endl;
      return 0;
    }
  }

  return 0;
}

