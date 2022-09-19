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
  ll x = 4 * a * b;
  if (c - (a + b) < 0) {
    cout << "No\n";
    return 0;
  }
  ll y = c * c + (a + b - 2 * c) * (a + b);
  cout << (x < y ? "Yes\n" : "No\n");

  return 0;
}

