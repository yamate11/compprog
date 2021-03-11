#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll lim = 1e6;
  ll shift = 2e5;
  vector<ll> s(lim);
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ll x; cin >> x;
    ll t = s[x - i + shift] += x;
    ans = max(ans, t);
  }
  cout << ans << "\n";


  return 0;
}

