#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A.at(i);
    if (A.at(i) == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans = 1;
  for (ll i = 0; i < N; i++) {
    double x = (double)ans * (double)(A.at(i));
    if (x > 1e18) {
      cout << -1 << endl;
      return 0;
    }
    ans *= A.at(i);
    if (ans > (ll)(1e18)) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  

  return 0;
}

