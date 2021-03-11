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
  ll base = 100;
  vector<ll> vec(2*base);
  ll cnt = 0;
  ll i = base;
  while (n > 0) {
    vec[i] = n % 2;
    cnt += vec[i];
    n /= 2;
    i++;
  }
  if (cnt > k) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes\n";
  i--;
  while (cnt + vec[i] <= k) {
    cnt += vec[i];
    vec[i - 1] += 2 * vec[i];
    vec[i] = 0;
    i--;
  }
  vec[i] -= k - cnt;
  vec[i-1] += 2 * (k - cnt);

  bool first = true;
  for (ll m = 2*base - 1; m >= 0; m--) {
    for (ll j = 0; j < vec[m]; j++) {
      if (first) first = false;
      else cout << " ";
      cout << m - base;
    }
  }
  cout << endl;

  return 0;
}

