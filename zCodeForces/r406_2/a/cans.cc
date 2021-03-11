#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll a, b, c, d; cin >> a >> b >> c >> d;
  if (b == d) {
    cout << b << endl;
    return 0;
  }
  ll g = gcd(a, c);
  if ((b - d) % g != 0) {
    cout << -1 << endl;
    return 0;
  }
  ll t = max(b, d);
  for ( ; 1 ; t++) {
    if ((t - b) % a == 0 && (t - d) % c == 0) {
      cout << t << endl;
      return 0;
    }
  }


  return 0;
}

