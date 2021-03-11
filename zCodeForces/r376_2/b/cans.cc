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
    ll n; cin >> n;
    ll state = 1;
    for (ll i = 0; i <= n; i++) {
      ll a;
      if (i < n) {
	cin >> a;
      }else {
	a = 0;
      }
      if (a >= 1) {
	if (a % 2 == 0) a = 2;
	else a = 1;
      }
      if (state == 1) {
	if (a == 0) {
	}else if (a == 1) {
	  state = 2;
	}else if (a == 2) {
	}
      }else if (state == 2) {
	if (a == 0) {
	  return false;
	}else if (a == 1) {
	  state = 1;
	}else if (a == 2) {
	}
      }
    }
    return true;
  };

  cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

