#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()



bool solve() {
  vector<vector<ll>> A(6, vector<ll>(6));
  for (ll i = 0; i < 4; i++) {
    for (ll j = 0; j < 4; j++) {
      cin >> A.at(i+1).at(j+1);
    }
  }
  for (ll i = 1; i <= 4; i++) {
    for (ll j = 1; j <= 4; j++) {
      for (ll k = -1; k <= 1; k+= 2) {
	if (A.at(i).at(j) == A.at(i+k).at(j)) return true;
	if (A.at(i).at(j) == A.at(i).at(j+k)) return true;
      }
    }
  }
  return false;
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << (solve() ? "CONTINUE" : "GAMEOVER") << endl;

  return 0;
}

