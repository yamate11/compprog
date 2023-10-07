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

  auto f = [&](ll z, ll e) -> ll {
    ll ret = 0;
    while (z > 0) {
      ret += z % e;
      z /= e;
    }
    return ret;
  };

  ll N; cin >> N;
  ll ans = 1e18;
  for (ll x = 0; x <= N; x += 6) {
    ll y = N - x;
    ll a = f(x, 6) + f(y, 9);
    ans = min(ans, a);
  }
  cout << ans << endl;

  return 0;
}

