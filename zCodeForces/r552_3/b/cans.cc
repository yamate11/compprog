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
  vector<ll> v(101);
  vector<ll> p;
  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    ll x; cin >> x;
    if (v[x] == 0) {
      cnt++;
      v[x] = 1;
      p.push_back(x);
    }
  }
  sort(p.begin(), p.end());
  if (cnt == 1) {
    cout << 0 << endl;
  }else if (cnt == 2) {
    ll d = p[1] - p[0];
    if (d % 2 == 0) {
      cout << d / 2 << endl;
    }else {
      cout << d << endl;
    }
  }else if (cnt == 3) {
    if (p[1] * 2 == p[0] + p[2]) {
      cout << p[1] - p[0] << endl;
    }else {
      cout << -1 << endl;
    }
  }else {
    cout << -1 << endl;
  }


  return 0;
}

