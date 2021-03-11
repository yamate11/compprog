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
    ll t, s, x; cin >> t >> s >> x;
    x -= t;
    if (x == 0) return true;
    x -= s;
    if (x < 0) return false;
    if (x % s == 0 || x % s == 1) return true;
    return false;
  };
  cout << (solve() ? "YES\n" : "NO\n");
  

  return 0;
}

