#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


void updMax(auto& x, auto y) { x = max(x, y); }

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, W, C; cin >> N >> W >> C;
  vector<int> w(N), v(N), c(N);
  for (int i = 0; i < N; i++) {
    cin >> w.at(i) >> v.at(i) >> c.at(i);
  }
  vector<int> ord(N);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(),
       [&](int p, int q) { return c.at(p) < c.at(q); });
  vector<vector<int>> dp(C+1, vector<int>(W+1)), tbl(C+1, vector<int>(W+1));
  for (int i = 0; i < N; i++) {
    int j = ord.at(i);
    for (int y = 0; y <= C-1; y++) {
      for (int x = W; x - w.at(j) >= 0; x--) {
	updMax(tbl.at(y).at(x), tbl.at(y).at(x - w.at(j)) + v.at(j));
      }
    }
    if (i == N-1 || c.at(j) != c.at(ord.at(i+1))) {
      for (int y = C; y >= 1; y--) {
	for (int x = 0; x <= W; x++) {
	  updMax(dp.at(y).at(x), tbl.at(y-1).at(x));
	}
      }
      for (int y = C-1; y >= 1; y--) tbl.at(y) = vector<int>(dp.at(y));
      tbl.at(0) = vector<int>(W+1);
    }
  }
  cout << dp.at(C).at(W) << endl;
  return 0;
}

