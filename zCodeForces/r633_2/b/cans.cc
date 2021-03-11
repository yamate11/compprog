#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll _t; cin >> _t;
  for (ll _z = 0; _z < _t; _z++) {
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a.at(i);
    sort(a.begin(), a.end());
    vector<ll> r;
    {
      ll i = 0;
      ll j = n-1;
      while (i <= j) {
	r.push_back(a.at(i));
	if (i < j) r.push_back(a.at(j));
	i++;
	j--;
      }
    }
    reverse(r.begin(), r.end());
    for (ll i = 0; i < n; i++) {
      if (i > 0) cout << " ";
      cout << r.at(i);
    }
    cout << endl;
    
  }

  return 0;
}

