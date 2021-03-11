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
    string r, b;
    cin >> r >> b;
    ll cr = 0, cb = 0;
    for (ll i = 0; i < n; i++) {
      if (r[i] > b[i]) cr++;
      if (r[i] < b[i]) cb++;
    }
    if (cr == cb) cout << "EQUAL\n";
    else if (cr > cb) cout << "RED\n";
    else if (cr < cb) cout << "BLUE\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

