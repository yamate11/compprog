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

  string s;
  cin >> s;
  ll n = s.size();
  auto tbl = vector(n, vector(n, -1LL));
  auto func = [&](auto rF, ll l, ll r) -> ll {
    ll& ret = tbl[l][r];
    if (ret < 0) {
      if (r - l + 1 < 3) ret = 0;
      else {
        ret = 0;
        for (ll j = l; j + 1 <= r; j++) {
          ret = max(ret, rF(rF, l, j) + rF(rF, j + 1, r));
        }
        if (s[l] == 'i' && s[r] == 'i') {
          for (ll j = l + 1; j < r; j++) {
            if (s[j] != 'w') continue;
            if (rF(rF, l + 1, j - 1) == j - 1 - (l + 1) + 1 &&
                rF(rF, j + 1, r - 1) == r - 1 - (j + 1) + 1) {
              ret = r - l + 1;
              break;
            }
          }
        }
      }
    }
    return ret;
  };
  cout << func(func, 0, n - 1) / 3 << endl;

  return 0;
}

