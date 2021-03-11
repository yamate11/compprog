#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<bool> z(N);
  for (ll i = 0; i < N; i++) {
    ll x, y; cin >> x >> y;
    if (x == y) z[i] = true;
  }
  ll cnt = 0;
  for (ll i = 0; i < N; i++) {
    if (z[i]) {
      cnt++;
      if (cnt == 3) {
	cout << "Yes\n";
	return 0;
      }
    }else {
      cnt = 0;
    }
  }
  cout << "No\n";

  return 0;
}

