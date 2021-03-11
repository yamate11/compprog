#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k, m; cin >> n >> k >> m;
  vector<ll> O(n);
  vector<ll> A(m);
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    O[i] = a;
    ll x = a % m;
    A[x]++;
  }
  for (ll i = 0; i < m; i++) {
    if (A[i] >= k) {
      cout << "Yes\n";
      ll cnt = 0;
      bool first = true;
      for (ll j = 0; j < n; j++) {
        if (O[j] % m == i) {
          if (first) first = false;
          else cout << " ";
          cout << O[j];
          cnt++;
          if (cnt == k) break;
        }
      }
      cout << "\n";
      return 0;
    }
  }
  cout << "No\n";


  return 0;
}

