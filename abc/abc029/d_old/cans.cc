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

  string s; cin >> s;

  auto tbl_init = vector(2, vector(10, 0LL));
  auto tbl = tbl_init;
  tbl[0][0] = 1;
  for (ll i = 0; i < (ll)s.size(); i++) {
    auto prev = move(tbl);
    tbl = tbl_init;
    for (ll f = 0; f < 2; f++) {
      for (ll p = 0; p < 10; p++) {
        if (prev[f][p] == 0) continue;
        for (ll x = 0; x <= 9; x++) {
          ll f0 = f, p0 = p;
          if (f == 0) {
            ll d = s[i] - '0';
            if (x > d) continue;
            if (x < d) f0 = 1;
          }
          if (x == 1) p0 = p + 1;
          tbl[f0][p0] += prev[f][p];
        }
      }
    }
  }
  ll ans = 0;
  for (ll f = 0; f < 2; f++) {
    for (ll p = 0; p < 10; p++) ans += tbl[f][p] * p;
  }
  cout << ans << endl;

  return 0;
}

