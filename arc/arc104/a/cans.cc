#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll a, b; cin >> a >> b;
  ll x = (a + b) / 2;
  ll y = (a - b) / 2;
  cout << x << " " << y << endl;

  return 0;
}

