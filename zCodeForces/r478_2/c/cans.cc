#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, q; cin >> n >> q;
  vector<ll> A(n + 1), S(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> A[i];
    S[i] = S[i - 1] + A[i];
  }
  ll x = 0;
  for (ll t = 0; t < q; t++) {
    ll k; cin >> k;
    x += k;
    if (x >= S[n]) {
      cout << n << "\n";
      x = 0;
    }else {
      ll y = upper_bound(S.begin(), S.end(), x) - S.begin();
      cout << n - (y - 1) << "\n";
    }
  }

  return 0;
}

