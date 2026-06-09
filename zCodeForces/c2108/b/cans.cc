#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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

  auto solve = [&]() -> void {
    ll n, x; cin >> n >> x;
    ll ans;
    if (x == 0) {
      if (n == 1) ans = -1;
      else if (n % 2 == 0) ans = n;
      else ans = n - 1 + 4;
    }else if (x == 1) {
      if (n % 2 == 0) ans = n - 1 + 4;
      else ans = n;
    }else {
      ll k = n - popcount((u64)x);
      if (k <= 0) {
        ans = x;
      }else {
        if (k % 2 == 0) ans = x + k;
        else ans = x + k + 1;
      }
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

