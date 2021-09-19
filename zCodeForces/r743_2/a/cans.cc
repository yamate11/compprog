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
    ll N; cin >> N;
    string s; cin >> s;
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
      ll d = s[i] - '0';
      ll add = (i < N-1) ? 1 : 0;
      if (d > 0) ans += add + d;
    }
    cout << ans << endl;

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

