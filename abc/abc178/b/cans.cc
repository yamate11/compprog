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

  ll x = a * c;
  x = max(x, b * c);
  x = max(x, a * d);
  x = max(x, b * d);
  cout << x << endl;

  return 0;
}

