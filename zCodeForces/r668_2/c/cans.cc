#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    ll tone = 0;
    ll tzero = 0;
    for (ll i = 0; i < k; i++) {
      bool one = false;
      bool zero = false;
      for (ll p = i; p < n; p += k) {
	if (s[p] == '1') one = true;
	if (s[p] == '0') zero = true;
      }
      if (one && zero) return false;
      if (one) tone++;
      if (zero) tzero++;
    }
    if (tone > k / 2 || tzero > k / 2) return false;
    return true;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    cout << (solve() ? "YES" : "NO") << "\n";
  }

  return 0;
}

