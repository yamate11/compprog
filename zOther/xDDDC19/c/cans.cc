#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int H, W, K; cin >> H >> W >> K;
  int k = 0;
  bool apY = false;
  int pending = 0;
  vector<int> row(W);

  auto putrow = [&]() -> void {
    for (int i = 0; i < W; i++) {
      if (i > 0) cout << " ";
      cout << row.at(i);
    }
    cout << "\n";
  };

  for (int h = 0; h < H; h++) {
    string s; cin >> s;
    if (s.find('#') == string::npos) {
      if (!apY) pending ++;
      else putrow();
    }else {
      k++;
      bool apX = false;
      for (int i = 0; i < W; i++) {
	if (s.at(i) == '#') {
	  if (!apX) {
	    apX = true;
	  }else {
	    k++;
	  }
	  row.at(i) = k;
	}else {
	  row.at(i) = k;
	}
      }
      apY = true;
      if (pending > 0) {
	for (int j = 0; j < pending; j++) putrow();
	pending = 0;
      }
      putrow();
    }
  }

  return 0;
}

