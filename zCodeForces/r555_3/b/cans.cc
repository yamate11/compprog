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
  string a; cin >> a;
  vector<ll> f(10);
  for (ll i = 1; i <= 9; i++) cin >> f[i];
  ll stat = 0;
  for (ll i = 0; i < n; i++) {
    ll d = a[i] - '0';
    if (stat == 0 && f[d] > d) {
      stat = 1;
      a[i] = f[d] + '0';
    }else if (stat == 1 && f[d] >= d) {
      a[i] = f[d] + '0';
    }else if (stat == 1 && f[d] < d) {
      break;
    }
  }
  cout << a << endl;

  return 0;
}

