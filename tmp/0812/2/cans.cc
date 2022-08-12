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

  auto f = [&](ll t) -> ll {
    ll ret = 0;
    while (t > 0) {
      ret += t % 10;
      t /= 10;
    }
    return ret;
  };

  ll N, A, B; cin >> N >> A >> B;
  ll ans = 0;
  REP2(i, 1, N + 1) {
    ll x = f(i);
    if (A <= x and x <= B) ans += i;
  }
  cout << ans << endl;

  return 0;
}

