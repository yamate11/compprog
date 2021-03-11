#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


bool solve() {
  int H, W; cin >> H >> W;
  vector<string> A(H);
  int cnt = 0;
  for (int y = 0; y < H; y++) {
    cin >> A.at(y);
    for (int x = 0; x < W; x++) if (A.at(y).at(x) == '#') cnt++;
  }
  if (cnt != H + W - 1) return false;
  int x = 0, y = 0;

  auto chk = [&](int yy, int xx) {
    if (yy >= H) return false;
    if (xx >= W) return false;
    return A.at(yy).at(xx) == '#';
  };

  while (y != H-1 || x != W-1) {
    bool okD = chk(y+1, x);
    bool okR = chk(y, x+1);
    if (okD == okR) return false;
    if (okD) y++;
    else x++;
  }
  return true;
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << (solve() ? "Possible" : "Impossible") << endl;
  return 0;
}

