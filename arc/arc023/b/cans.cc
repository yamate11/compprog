#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll R, C, D; cin >> R >> C >> D;
  vector<vector<ll>> A(R, vector<ll>(C));
  for (ll i = 0; i < R; i++) {
    for (ll j = 0; j < C; j++) {
      cin >> A.at(i).at(j);
    }
  }
  ll vmax = 0;
  ll start = D % 2;
  for (ll p = start; p <= D; p += 2) {
    for (ll i = max(0LL, p - C + 1LL); i <= min(p, R - 1LL); i++) {
      ll j = p - i;
      vmax = max(vmax, A.at(i).at(j));
    }
  }
  cout << vmax << endl;

  return 0;
}

