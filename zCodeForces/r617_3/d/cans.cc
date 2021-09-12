#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, A, B, K; cin >> N >> A >> B >> K;
  map<ll, ll> mp;
  vector<ll> H(N);
  for (ll i = 0; i < N; i++) cin >> H[i];
  for (ll i = 0; i < N; i++) {
    ll r = (H[i] - 1) % (A + B);
    ll t = r / A;
    mp[t]++;
  }
  ll ans = 0;
  for (auto [t, c] : mp) {
    if (t == 0) ans += c;
    else if (K >= t * c) {
      ans += c;
      K -= t * c;
    }else {
      ll cc = K / t;
      ans += cc;
    }
  }
  cout << ans << endl;

  return 0;
}

