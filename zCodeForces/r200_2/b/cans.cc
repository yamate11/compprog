#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll a, b, c; cin >> a >> b >> c;
  ll n = a + b + c;
  if (n % 2 != 0) {
    cout << "Impossible\n";
    return 0;
  }
  ll m = n / 2;
  ll x = m - c;
  ll y = m - a;
  ll z = m - b;
  if (x < 0 || y < 0 || z < 0) {
    cout << "Impossible\n";
    return 0;
  }
  cout << x << " " << y << " " << z << endl;

  return 0;
}

