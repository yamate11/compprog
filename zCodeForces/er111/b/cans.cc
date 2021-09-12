#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    if (b >= 0) return a * n + n * b;
    ll cnt = 0;
    for (ll i = 1; i < n; i++) if (s[i] != s[i-1]) cnt++;
    ll cc = 1 + (cnt + 1) / 2;
    return a * n + cc * b;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << "\n";

  return 0;
}

