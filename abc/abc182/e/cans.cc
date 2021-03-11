#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, N, M; cin >> H >> W >> N >> M;

  const int BLOCK = 1;
  const int LIGHT = 2;
  const int CHECKED = 3;

  vector<vector<int>> brd(H, vector<int>(W, 0));
  /*
  using sta = pair<ll, ll>;
  vector<vector<sta>> row(H + 1), col(W + 1);
  for (ll i = 1; i <= H; i++) {
    row[i].emplace(0, BLOCK);
    row[i].emplace(W+1, BLOCK);
  }
  for (ll i = 1; i <= W; i++) {
    col[i].emplace(0, BLOCK);
    col[i].emplace(H+1, BLOCK);
  }
  */
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    brd[a][b] = LIGHT;
  }
  for (ll i = 0; i < M; i++) {
    ll c, d; cin >> c >> d; c--; d--;
    brd[c][d] = BLOCK;
  }
  ll cnt = 0;
  bool on = false;

  auto func1 = [&](ll i, ll j) -> void {
    if (brd[i][j] == BLOCK) {
      on = false;
    }else if (brd[i][j] == LIGHT) {
      on = true;
    }else if (on && brd[i][j] == 0) {
      cnt++;
      brd[i][j] = CHECKED;
    }
  };


  for (ll i = 0; i < H; i++) {
    on = false;
    for (ll j = 0; j < W; j++) func1(i, j);
    on = false;
    for (ll j = W - 1; j >= 0; j--) func1(i, j);
  }
  for (ll j = 0; j < W; j++) {
    on = false;
    for (ll i = 0; i < H; i++) func1(i, j);
    on = false;
    for (ll i = H - 1; i >= 0; i--) func1(i, j);
  }
  
  cout << N + cnt << endl;
  return 0;
}

