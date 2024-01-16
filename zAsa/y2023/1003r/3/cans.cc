#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll b, c; cin >> b >> c;
  ll ans = 0;
  if (b == 0) {
    ll p = c / 2;
    ll q = (c - 1) / 2;
    ans = p + q + 1;
  }else if (b > 0) {
    ll r = c / 2;
    ll q = (c - 1) / 2;
    ll p = (c - 1) / 2;
    ll s = (c - 2) / 2;
    if (q + r < 2 * b) ans = p + q + 1 + r + s + 1;
    else               ans = p + 2 * b + s + 1;
  }else {
    ll p = c / 2;
    ll s = (c - 1) / 2;
    ll r = (c - 1) / 2;
    ll q = (c - 2) / 2;
    if (q + r < 2 * (-b)) ans = p + q + 1 + r + s + 1;
    else               ans = p + 2 * (-b) + s + 1;
  }
  cout << ans << endl;

  return 0;
}

