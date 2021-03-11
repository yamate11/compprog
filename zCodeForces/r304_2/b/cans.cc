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
  for (ll i = 0; i < n; i++) cin >> A[i];
  sort(A.begin(), A.end());
  vector<ll> ex(10000);
  ll ans = 0;
  for (ll a : A) {
    while (ex[a]) {
      ans++;
      a++;
    }
    ex[a] = true;
  }
  cout << ans << endl;

  return 0;
}

