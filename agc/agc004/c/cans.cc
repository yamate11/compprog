#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int H, W; cin >> H >> W;
  vector<string> A(H);
  for (int i = 0; i < H; i++) {
    cin >> A.at(i);
  }

  auto func = [&](int z) {
    char v[W+1]; v[W] = 0;
    for (int j = 0; j < W; j++) v[j] = '.';
    cout << string(v) << "\n";
    for (int i = 1; i < H-1; i++) {
      if (i % 2 == z) {
	for (int j = 1; j < W-1; j++) v[j] = '#';
      }else {
	for (int j = 1; j < W-1; j++) v[j] = A.at(i).at(j);
      }
      if (z == 0) {
	v[0] = '#';
	v[W-1] = '.';
      }else {
	v[0] = '.';
	v[W-1] = '#';
      }
      cout << string(v) << "\n";
    }
    for (int j = 0; j < W; j++) v[j] = '.';
    cout << string(v) << "\n";
  };

  func(0);
  cout << "\n";
  func(1);

  return 0;
}

