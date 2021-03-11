#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  ll ua = 1234567, ub = 123456, uc = 1234;
  for (ll a = 0; a * ua <= n; a++) {
    for (ll b = 0; a * ua + b * ub <= n; b++) {
      if ((n - (a * ua + b * ub)) % uc == 0) {
	cout << "YES\n";
	return 0;
      }
    }
  }
  cout << "NO\n";


  return 0;
}

