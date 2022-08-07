#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll n2, n3, n4; cin >> n2 >> n3 >> n4;
    ll n6 = n3 / 2;
    ll ans = min(n6, n4);
    n6 -= ans;
    n4 -= ans;
    if (n6 == 0) {
      ll n8 = n4 / 2;
      ll x = min(n8, n2);
      ans += x;
      n2 -= x;
      n2 += 2 * (n4 % 2);
      ans += n2 / 5;
    }else {
      assert(n4 == 0);
      if (n6 >= n2 / 2) {
        ans += n2 / 2;
      }else {
        ans += n6;
        n2 -= 2 * n6;
        ans += n2 / 5;
      }
    }
    return ans;
  };

  ll T; cin >> T;
  REP(t, T) cout << solve() << "\n";

  return 0;
}

