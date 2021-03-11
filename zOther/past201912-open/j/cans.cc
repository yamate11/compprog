#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

using Tuple = tuple<ll, int, int>;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  vector<vector<ll>> A(H, vector<ll>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> A.at(i).at(j);
  }
  
  auto getDist = [&](int y, int x) {
    vector<vector<ll>> ret(H, vector<ll>(W, -1));
    priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pque;
    pque.emplace(0, y, x);
    while (!pque.empty()) {
      ll d; int j; int i; tie(d, i, j) = pque.top(); pque.pop();
      if (ret.at(i).at(j) >= 0) continue;
      ret.at(i).at(j) = d;

      auto sub = [&](int ii, int jj) -> void {
	if (ii < 0 || ii >= H || jj < 0 || jj >= W) return;
	if (ret.at(ii).at(jj) >= 0) return ;
	pque.emplace(d + A.at(ii).at(jj), ii, jj);
      };

      sub(i-1, j);
      sub(i+1, j);
      sub(i, j-1);
      sub(i, j+1);
    }
    return ret;
  };

  auto dist1 = getDist(H-1, 0);
  auto dist2 = getDist(H-1, W-1);
  auto dist3 = getDist(0, W-1);

  ll dmin = LLONG_MAX;
  // ll i0 = -1, j0 = -1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ll d = dist1.at(i).at(j) + dist2.at(i).at(j) + dist3.at(i).at(j)
	- 2 * A.at(i).at(j);
      if (d < dmin) {
	dmin = d;
	// i0 = i;
	// j0 = j;
      }
    }
  }
  cout << dmin << endl;

  return 0;
}

