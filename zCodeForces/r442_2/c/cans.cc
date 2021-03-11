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
  cout << n + (n / 2) << endl;
  for (ll i = 0; i < n / 2; i++) {
    if (i > 0) cout << " ";
    cout << 2 * (i + 1);
  }
  for (ll i = 0; i < (n + 1) / 2; i++) {
    cout << " ";
    cout << 2 * i + 1;
  }
  for (ll i = 0; i < n / 2; i++) {
    cout << " ";
    cout << 2 * (i + 1);
  }
  cout << endl;


  return 0;
}

