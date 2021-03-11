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
  vector<ll> T(n);
  for (ll i = 0; i < n; i++) cin >> T[i];
  sort(T.begin(), T.end());
  ll cnt = 0;
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    if (sum <= T[i]) {
      cnt++;
      sum += T[i];
    }
  }
  cout << cnt << endl;


  return 0;
}

