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
  ll r1 = (n + 1) / 2;
  ll r2 = (n + 1) - r1;
  cout << r1 * r2 << endl;
  

  return 0;
}

