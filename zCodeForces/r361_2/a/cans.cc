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

    auto func = [&](ll n) -> pair<ll, ll> {
      if (n == 0) return {1, 3};
      return {(n - 1) % 3, (n - 1) / 3};
    };


    ll n; cin >> n;
    string s; cin >> s;
    ll xmin = 10, ymin = 10, xmax = -1, ymax = -1;
    for (ll i = 0; i < n; i++) {
      auto [x, y] = func(s[i] - '0');
      xmin = min(xmin, x);
      xmax = max(xmax, x);
      ymin = min(ymin, y);
      ymax = max(ymax, y);
    }
    if (ymax - ymin == 3) return true;
    auto case1 = [&]() -> bool {
      for (ll i = 0; i < n; i++) {
	if (s[i] == '1' || s[i] == '2' || s[i] == '3') return false;
      }
      return true;
    };
    auto case2 = [&]() -> bool {
      for (ll i = 0; i < n; i++) {
	if (s[i] == '7' || s[i] == '9') return false;
      }
      return true;
    };

    if (ymax - ymin == 2 && xmax - xmin == 2) {
      if (case1() || case2()) return false;
      return true;
    }
    return false;
  };
  
  cout << (solve() ? "YES" : "NO") << endl;
  return 0;
}

