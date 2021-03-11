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
    vector<ll> P(N);

    auto chk = [&](ll d) -> bool {
      for (ll i = 0; i < N; i++) {
	if (!(P[(N + i + d) % N] == (P[i] + 1) % N)) return false;
      }
      return true;
    };


    for (ll i = 0; i < N; i++) {
      cin >> P[i];
      P[i]--;
    }

    if (chk(1) || chk(-1)) {
      cout << "YES" << endl;
    }else {
      cout << "NO" << endl;
    }

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

