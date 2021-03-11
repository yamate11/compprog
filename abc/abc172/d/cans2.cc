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
  ll ans = 0;
  for (ll i = 1; i <= N; i++) {
    ll m = N / i;
    ll x = m * (m + 1) / 2;
    ans += x * i;
  }
  cout << ans << endl;

  return 0;
}

