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
    string s; cin >> s;
    vector<ll> A(4);
    for (ll i = 0; i < (ll)s.size(); i++) {
      if (s[i] == 'U') A[0]++;
      if (s[i] == 'D') A[1]++;
      if (s[i] == 'L') A[2]++;
      if (s[i] == 'R') A[3]++;
    }
    ll vmin = min(A[0], A[1]);
    ll hmin = min(A[2], A[3]);
    if (vmin > 0 && hmin > 0) {
      cout << 2 * (hmin + vmin) << endl;
      for (ll i = 0; i < hmin; i++) cout << "R";
      for (ll i = 0; i < vmin; i++) cout << "U";
      for (ll i = 0; i < hmin; i++) cout << "L";
      for (ll i = 0; i < vmin; i++) cout << "D";
      cout << "\n";
    } else if (vmin == 0 && hmin == 0) {
      cout << 0 << "\n";
    } else if (hmin == 0) {
      cout << "2\nUD\n";
    } else if (vmin == 0) {
      cout << "2\nLR\n";
    } else assert(0);
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

