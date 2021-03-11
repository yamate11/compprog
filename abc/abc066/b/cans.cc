#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll n = S.size();
  for (ll k = n-2; k >= 2; k-= 2) {
    ll m = k / 2;
    bool success = true;
    for (ll i = 0; i < m; i++) {
      if (S.at(i) != S.at(m + i)) {
	success = false;
	break;
      }
    }
    if (success) {
      cout << k << endl;
      return 0;
    }
  }

  return 0;
}

