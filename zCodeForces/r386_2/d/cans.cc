#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> string {
    ll n, k, a, b; cin >> n >> k >> a >> b;
    ll remG = a;
    ll remB = b;
    string ans;
    vector<ll> rem({remG, remB});
    vector<ll> lab({'G', 'B'});
    ll cur = (remG > remB) ? 0 : 1;
    while (true) {
      if (rem[cur] == 0) {
	return "NO";
      }else if (rem[cur] < rem[1 - cur]) {
	ans += lab[cur];
	rem[cur] -= 1;
      }else {
	ll t = min(rem[cur], k);
	for (ll i = 0; i < t; i++) ans += lab[cur];
	rem[cur] -= t;
      }
      if (rem[0] == 0 && rem[1] == 0) return ans;
      cur = 1 - cur;
    }
  };
  cout << solve() << endl;

  return 0;
}

