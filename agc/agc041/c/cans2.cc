#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  if (N == 2) {
    cout << "-1\n";
    return 0;
  }
  vector<vector<char>> B(N, vector<char>(N));

  auto fill = [&](int y, int x, string s) {
    B.at(2*y).at(2*x) = s.at(0);
    B.at(2*y).at(2*x + 1) = s.at(1);
    B.at(2*y + 1).at(2*x) = s.at(2);
    B.at(2*y + 1).at(2*x + 1) = s.at(3);
  };

  if (N % 4 == 0) {
    for (int y = 0; y < N/2; y++) {
      for (int x = 0; x < N/2; x++) {
	if ((x + y) % 2 == 0) fill(y, x, "aabb");
	else                  fill(y, x, "cdcd");
      }
    }
  }else if (N % 2 == 0) {
    for (int y = 0; y < N/2; y++) {
      for (int x = 0; x < N/2; x++) {
	if (x == y) {
	  fill (x, y, "....");
	}else {
	  bool b1 = x > y;
	  bool b2 = (x + y) % 2 == 0;
	  if (b1 == b2) fill(y, x, "aabb");
	  else          fill(y, x, "cdcd");
	}
      }
    }
  }else {
    for (int y = 0; y < (N-3)/2; y++) fill(y, y, "....");
    for (int y = 0; y < (N-3)/2; y++) {
      for (int i = 2*y + 2; i < N; i++) {
	if ((y + i) % 2 == 0) {
	  B.at(2*y).at(i) = B.at(2*y + 1).at(i) = 'a';
	}else {
	  B.at(2*y).at(i) = B.at(2*y + 1).at(i) = 'b';
	}
      }
    }
    for (int x = 0; x < (N-3)/2; x++) {
      for (int j = 2*x + 2; j < N; j++) {
	if ((x + j) % 2 == 0) {
	  B.at(j).at(2*x) = B.at(j).at(2*x + 1) = 'a';
	}else {
	  B.at(j).at(2*x) = B.at(j).at(2*x + 1) = 'b';
	}
      }
    }
    B.at(N-3).at(N-3) = 'c';
    B.at(N-3).at(N-2) = 'c';
    B.at(N-3).at(N-1) = 'd';
    B.at(N-2).at(N-3) = 'f';
    B.at(N-2).at(N-2) = '.';
    B.at(N-2).at(N-1) = 'd';
    B.at(N-1).at(N-3) = 'f';
    B.at(N-1).at(N-2) = 'e';
    B.at(N-1).at(N-1) = 'e';
  }

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      cout << B.at(j).at(i);
    }
    cout << "\n";
  }

}

