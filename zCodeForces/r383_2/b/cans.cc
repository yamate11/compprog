#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, x; cin >> n >> x;
  ll lim1 = 1e6;
  ll lim2 = 1e5;
  vector<ll> cnt(lim1 + 1);
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    cnt[a]++;
  }
  ll ans = 0;
  for (ll i = 0; i <= lim2; i++) {
    ll j = i ^ x;
    if (j < i) continue;
    else if (j == i) {
      ans += cnt[i] * (cnt[i] - 1) / 2;
    }else if (i < j) {
      ans += cnt[i] * cnt[j];
    }
  }
  cout << ans << endl;


  return 0;
}

