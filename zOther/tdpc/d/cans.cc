#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, D; cin >> N >> D;
  int i2 = 0;
  while (D % 2 == 0) {
    i2++;
    D /= 2;
  }
  int i3 = 0;
  while (D % 3 == 0) {
    i3++;
    D /= 3;
  }
  int i5 = 0;
  while (D % 5 == 0) {
    i5++;
    D /= 5;
  }
  if (D != 1) {
    cout << "0.0\n";
    return 0;
  }
  vector<vector<vector<double>>>
    tbl(i2+1, vector<vector<double>>(i3+1, vector<double>(i5+1)));
  tbl.at(0).at(0).at(0) = 1.0;
  for (int i = 0; i < N; i++) {
    vector<vector<vector<double>>>
      newtbl(i2+1, vector<vector<double>>(i3+1, vector<double>(i5+1)));
    for (int j2 = 0; j2 <= i2; j2++) {
      for (int j3 = 0; j3 <= i3; j3++) {
	for (int j5 = 0; j5 <= i5; j5++) {
	  double p = tbl.at(j2).at(j3).at(j5);
	  newtbl.at(j2).at(j3).at(j5) += p/6;
	  newtbl.at(min(i2, j2+1)).at(j3).at(j5) += p/6;
	  newtbl.at(j2).at(min(i3, j3+1)).at(j5) += p/6;
	  newtbl.at(min(i2, j2+2)).at(j3).at(j5) += p/6;
	  newtbl.at(j2).at(j3).at(min(i5, j5+1)) += p/6;
	  newtbl.at(min(i2, j2+1)).at(min(i3, j3+1)).at(j5) += p/6;
	}
      }
    }
    tbl = move(newtbl);
  }
  cout << tbl.at(i2).at(i3).at(i5) << endl;

  return 0;
}

