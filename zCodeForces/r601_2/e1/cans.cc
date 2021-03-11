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
  vector<ll> A(n);
  ll s = 0;
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
    s += A[i];
  }
  if (s == 1) {
    cout << -1 << endl;
    return 0;
  }
  ll d = 2;
  for ( ; d <= s; d++) if (s % d == 0) break;
  ll ans = 0;
  ll p = 0;
  for (ll i = 0; i < s / d; i++) {
    vector<ll> vec;
    for (ll j = 0; j < d; j++) {
      while (A[p] == 0) p++;
      vec.push_back(p);
      p++;
    }
    for (ll j = 0; j < d; j++) {
      ans += abs(vec[j] - vec[d / 2]);
    }
  }
  cout << ans << endl;

  return 0;
}

