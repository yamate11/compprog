#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = []() -> void {
    ll L, R, M; cin >> L >> R >> M;
    ll D = R - L;
    auto report = [&](ll a, ll x) -> void {
      if (x >= 0) {
	cout << a << " " << L + x << " " << L << endl;
      }else {
	cout << a << " " << L << " " << L - x << endl;
      }
    };
    for (ll a = L; a <= R; a++) {
      ll n = M / a;
      if (n > 0) {
	ll x = M - n * a;
	if (x <= D) {
	  report(a, x);
	  return;
	}
      }
      ll x = M - (n + 1) * a;
      if (-D <= x) {
	report(a, x);
	return;
      }
    }
    assert(0);
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();
  

  return 0;
}

