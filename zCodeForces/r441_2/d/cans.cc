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
  vector<ll> P(n + 1);
  for (ll i = 1; i <= n; i++) cin >> P[i];
  ll r = n;
  ll cnt = 0;
  vector<bool> X(n + 1);
  cout << "1";
  for (ll i = 1; i <= n; i++) {
    X[P[i]] = true;
    if (P[i] < r) {
      cnt++;
    }else {
      assert(P[i] == r);
      cnt++;
      while(r >= 1 && X[r]) {
        cnt--;
        r--;
      }
    }
    cout << " " << cnt + 1;
  }
  cout << endl;

  return 0;
}

