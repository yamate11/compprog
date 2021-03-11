#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
  ll n;
  cin >> n;
  vector<ll> a, b;
  if (n % 2 == 0) {
    for (ll i = 1; i <= n; i++) {
      for (ll j = i+1; j <= n; j++) {
	if (i + j != n + 1) {
	  a.push_back(i);
	  b.push_back(j);
	}
      }
    }
  }else {
    for (ll i = 1; i < n; i++) {
      for (ll j = i+1; j <= n; j++) {
	if (i + j != n) {
	  a.push_back(i);
	  b.push_back(j);
	}
      }
    }
  }
  cout << a.size() << endl;
  for (ll k = 0; k < (ll) a.size(); k++) {
    cout << a[k] << " " << b[k] << endl;
  }
  return 0;
}
