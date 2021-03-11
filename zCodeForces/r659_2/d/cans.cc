#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll n, const auto& a) -> string {
    ll x = 0;
    for (ll i = 0; i < n; i++) {
      x ^= a.at(i);
    }
    if (x == 0) return "DRAW";
    ll j = 63 - __builtin_clzll(x);
    ll cnt_one = 0;
    ll cnt_zero = 0;
    for (ll i = 0; i < n; i++) {
      if ((a.at(i) >> j) & 1) {
	cnt_one++;
      }else {
	cnt_zero++;
      }
    }
    if (((cnt_one - 1) / 2) % 2 == 0) return "WIN";
    if (cnt_zero % 2 == 0) return "LOSE";
    return "WIN";
  };

  ll t; cin >> t;
  for (ll t_ = 0; t_ < t; t_++) {
    ll n; cin >> n;
    vector a(n, 0LL);
    for (ll i = 0; i < n; i++) cin >> a.at(i);
    cout << solve(n, a) << "\n";
  }

  return 0;
}

