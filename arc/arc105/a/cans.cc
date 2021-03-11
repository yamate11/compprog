#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll s = a + b + c + d;
    if (2 * a == s) return true;
    if (2 * b == s) return true;
    if (2 * c == s) return true;
    if (2 * d == s) return true;
    if (2 * (a + b) == s) return true;
    if (2 * (a + c) == s) return true;
    if (2 * (a + d) == s) return true;
    if (2 * (b + c) == s) return true;
    if (2 * (b + c) == s) return true;
    if (2 * (c + d) == s) return true;
    return false;
  };
  cout << (solve() ? "Yes\n" : "No\n");
  

  return 0;
}

