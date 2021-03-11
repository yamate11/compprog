#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll solve() {
  ll a, b; cin >> a >> b;
  if (a >= 2 * b) return b;
  if (b >= 2 * a) return a;
  return (a + b) / 3;
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll t; cin >> t;
  for (ll i = 0; i < t; i++) {
    cout << solve() << "\n";
  }

  return 0;
}

