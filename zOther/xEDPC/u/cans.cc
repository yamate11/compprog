#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<vector<ll>> A(N, vector<ll>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cin >> A.at(i).at(j);
  }

  vector<ll> full(1<<N);
  vector<ll> val(1<<N);

  for (int k = 0; k < N; k++) {
    for (int x = 0; x < (1<<k); x++) {
      ll s = full.at(x);
      for (int m = 0; m < k; m++) if ((1<<m) & x) s += A.at(k).at(m);
      full.at((1<<k)|x) = s;
    }
  }
  for (int x = 0; x < 1<<N; x++) {
    ll s = full.at(x);
    int y = x;
    while ((y = x & (y-1)) != 0) {
      int z = x ^ y;
      s = max(s, val.at(y) + val.at(z));
    }
    val.at(x) = s;
  }

  cout << val.at((1<<N) - 1) << endl;
  return 0;
}

