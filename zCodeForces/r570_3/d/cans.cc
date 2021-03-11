#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll n; cin >> n;
    vector<ll> cnt(n + 1);
    for (ll i = 0; i < n; i++) {
      ll a; cin >> a;
      cnt[a]++;
    }
    sort(cnt.begin(), cnt.end(), greater<ll>());
    ll prev = 1e10;
    ll sum = 0;
    for (ll i = 0; i < n + 1; i++) {
      if (prev <= 1) break;
      if (cnt[i] >= prev) {
	sum += prev - 1;
	prev--;
      }else {
	sum += cnt[i];
	prev = cnt[i];
      }
    }
    cout << sum << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

