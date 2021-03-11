#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll lim = 100;
  ll A, B, C; cin >> A >> B >> C;
  vector tbl(lim + 1, vector(lim + 1, vector(lim + 1, 0.0)));
  /*
  for (ll i = 0; i < lim; i++) {
    for (ll j = 0; j < lim; j++) {
      tbl[i][j][100] = tbl[i][100][j] = tbl[100][i][j] = 0.0;
    }
  }
  */
  for (ll i = lim - 1; i >= A; i--) {
    for (ll j = lim - 1; j >= B; j--) {
      for (ll k = lim - 1; k >= C; k--) {
	if (i == 0 && j == 0 && k == 0) continue;
	tbl[i][j][k] = 
	  (i * (1 + tbl[i+1][j][k]) +
	   j * (1 + tbl[i][j+1][k]) +
	   k * (1 + tbl[i][j][k+1]))
	  / (i + j + k);
      }
    }
  }
  cout << tbl[A][B][C] << endl;

  return 0;
}

