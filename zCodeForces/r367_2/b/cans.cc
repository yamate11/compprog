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
  vector<ll> X(n);
  for (ll i = 0; i < n; i++) cin >> X[i];
  sort(X.begin(), X.end());
  X.push_back(1e10);
  ll q; cin >> q;
  for (ll i = 0; i < q; i++) {
    ll m; cin >> m;
    ll y = upper_bound(X.begin(), X.end(), m) - X.begin();
    cout << y << endl;
  }

  return 0;
}

