#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  bool color = false;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      char c; cin >> c;
      if (c == 'C' || c == 'Y' || c == 'M') {
	color = true;
      }
    }
  }
  cout << (color ? "#Color" : "#Black&White") << endl;

  return 0;
}

