#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, b, a; cin >> n >> b >> a;
  vector<ll> s(n);
  for (ll i = 0; i < n; i++) cin >> s[i];
  ll a0 = a;
  for (ll i = 0; i < n; i++) {
    if (b > 0 && a < a0 && s[i]) {
      b--; a++;
    }else if (a > 0) {
      a--;
    }else if (b > 0) {
      b--;
    }else {
      cout << i << endl;
      return 0;
    }
  }
  cout << n << endl;

  return 0;
}

