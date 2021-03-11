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
    string s; cin >> s;
    // if (n == 1) return s[0] == '1';
    for (ll i = 0; i < n; i++) {
      if (s[i] == '0') {
        if ((i == 0 || s[i-1] == '0') &&
            (i+1 == n || s[i+1] == '0')) {
          return false;
        }
      }else if (s[i] == '1') {
        if (i+1 >= n) continue;
        if (s[i+1] == '1') return false;
      }
    }
    return true;
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

