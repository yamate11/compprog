#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  vector<vector<char>> brd(H+2, vector<char>(W+2));
  for (ll i = 0; i < W+2; i++) brd.at(0).at(i) = brd.at(H+1).at(i) = 1;
  for (ll i = 0; i < H+2; i++) brd.at(i).at(0) = brd.at(i).at(W+1) = 1;
  for (ll i = 0; i < H; i++) {
    string s; cin >> s;
    for (ll j = 0; j < W; j++) {
      if (s.at(j) == '#') brd.at(i+1).at(j+1) = 1;
    }
  }

  auto chk = [&](const auto& recF, ll i, ll j) -> char {
    char& ret = brd.at(i).at(j);
    if (ret != 0) return ret;
    if (recF(recF, i+1, j) == 1 &&
	recF(recF, i, j+1) == 1 &&
	recF(recF, i+1, j+1) == 1) ret = 2;
    else                           ret = 1;
    return ret;
  };
  cout << (chk(chk, 1, 1) == 1 ? "First" : "Second") << endl;

  return 0;
}

