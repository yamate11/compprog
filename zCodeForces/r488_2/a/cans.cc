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
  vector<ll> X(n);
  set<ll> Y;
  for (ll i = 0; i < n; i++) cin >> X[i];
  for (ll i = 0; i < m; i++) {
    ll y; cin >> y;
    Y.insert(y);
  }
  bool first = true;
  for (ll i = 0; i < n; i++) {
    if (Y.find(X[i]) != Y.end()) {
      if (first) first = false;
      else cout << " ";
      cout << X[i];
    }
  }
  cout << "\n";

  return 0;
}

