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
    ll px, py; cin >> px >> py;
    string s; cin >> s;
    ll n = s.size();
    vector<ll> cnt(128);
    for (ll i = 0; i < n; i++) cnt[s[i]]++;
    if (px > 0 && cnt['R'] < px) {
      cout << "NO\n";
      return;
    }
    if (px < 0 && cnt['L'] < -px) {
      cout << "NO\n";
      return;
    }
    if (py > 0 && cnt['U'] < py) {
      cout << "NO\n";
      return;
    }
    if (py < 0 && cnt['D'] < -py) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
    return;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

