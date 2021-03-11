#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> x(4);
  for (ll i = 0; i < 4; i++) cin >> x[i];
  sort(x.begin(), x.end());
  for (ll i = 0; i < 3; i++) {
    if (i > 0) cout << " ";
    cout << x[3] - x[i];
  }
  cout << endl;


  return 0;
}

