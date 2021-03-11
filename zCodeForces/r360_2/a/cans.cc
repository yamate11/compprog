#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, d; cin >> n >> d;
  ll ans = 0;
  ll cnt = 0;
  for (ll i = 0; i <= d; i++) {
    string s; cin >> s;
    auto win = [&]() -> bool {
      for (ll j = 0; j < n; j++) {
	if (s[j] == '0') return true;
      }
      return false;
    };
    if (i < d && win()) {
      cnt++;
    }else {
      ans = max(ans, cnt);
      cnt = 0;
    }
  }
  cout << ans << endl;

  return 0;
}

