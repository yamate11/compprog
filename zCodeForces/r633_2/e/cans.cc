#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

vector<vector<ll>> cst({{0,0,0}, {1,2,3}, {2,3,1}, {3,1,2}});

ll solve(ll m) {
  ll q = (m - 1) / 3;
  ll r = (m - 1) % 3;
  ll n = 0;
  for (; q >= (((1LL << (2 * (n+1))) - 1) / 3); n++);
  ll qt = q - (((1LL << (2 * n)) - 1) / 3);
  ll res = cst.at(1).at(r);
  while (n > 0) {
    n--;
    ll p4 = 1LL << (2 * n);
    ll j = qt / p4;
    res = (res << 2) + cst.at(j).at(r);
    qt = qt % p4;
  }
  return res;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);


  /*
  for (ll i = 1; i <= 300; i++) {
    cout << i << " " << solve(i) << endl;
  }
  return 0;
  */

  ll t; cin >> t;
  for (ll z = 0; z < t; z++) {
    ll m; cin >> m;
    cout << solve(m) << "\n";
  }

  return 0;
}

