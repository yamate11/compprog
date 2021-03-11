#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  if (k == 1) {
    cout << "YES\n" << n << endl;
    return 0;
  }
  ll s = k * (k + 1) / 2;
  if ((n == 4 && k == 2) || (n == 8 && k == 3) || n < s) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  ll t = n - s;
  ll p = t / k;
  ll q = t % k;
  if (k == 2) {
    if (q == 0) {
      cout << p + 1 << " " << p + 2 << endl;
    }else {
      cout << p + 1 << " " << p + 3 << endl;
    }
    return 0;
  }

  if (q <= k - 2 || p >= 2) {
    for (ll i = 0; i < k; i++) {
      if (i > 0) cout << " ";
      if (i < k - q) cout << p + i + 1;
      else cout << p + i + 2;
    }
  }else {
    for (ll i = 0; i < k; i++) {
      if (i > 0) cout << " ";
      if (i <= 1) cout << p + i + 1;
      else if (i < k-1) cout << p + i + 2;
      else cout << p + i + 3;
    }
  }
  cout << endl;


  return 0;
}

