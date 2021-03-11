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
  for (ll i = 0; i < m; i++) {
    ll k; cin >> k;
    vector<ll> store(n + 1);
    vector<ll> A(k);
    for (ll j = 0; j < k; j++) cin >> A[j];
    bool check = false;
    for (ll j = 0; j < k; j++) {
      ll x = A[j];
      ll y = abs(x);
      ll sign = y / x;
      if (store[y] == 0) {
	store[y] = sign;
      }else if (store[y] != sign) {
	check = true;
	break;
      }
    }
    if (!check) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";


  return 0;
}

