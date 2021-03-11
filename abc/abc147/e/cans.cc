#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int H, W; cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));
  vector<vector<int>> B(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> B.at(i).at(j);
    }
  }

  int lim = 161*81+10;
  vector<vector<vector<bool>>>
    cand(H, vector<vector<bool>>(W, vector<bool>(lim)));
  
  int xxx = abs(A.at(0).at(0) - B.at(0).at(0));
  cand.at(0).at(0).at(xxx) = true;
  for (int z = 0; z < W + H - 1; z++) {
    for (int x = 0; x < W; x++) {
      int y = z - x;
      if (y < 0) continue;
      if (y >= H) continue;
      for (int t = 0; t < lim; t++) {
	if (!cand.at(y).at(x).at(t)) continue;
	int y1 = y + 1;
	if (y1 < H) {
	  int w = abs(A.at(y1).at(x) - B.at(y1).at(x));
	  cand.at(y1).at(x).at(t + w) = true;
	  cand.at(y1).at(x).at(abs(t - w)) = true;
	}
	int x1 = x + 1;
	if (x1 < W) {
	  int w = abs(A.at(y).at(x1) - B.at(y).at(x1));
	  cand.at(y).at(x1).at(t + w) = true;
	  cand.at(y).at(x1).at(abs(t - w)) = true;
	}
      }
    }
  }
  for (int t = 0; t < lim; t++) {
    if (cand.at(H-1).at(W-1).at(t)) {
      cout << t << endl;
      return 0;
    }
  }

  return 0;
}

