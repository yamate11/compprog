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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto func = [&](ll x) -> ll {
    ll ret = 0;
    while (x > 0) {
      ret += x % 10;
      x /= 10;
    }
    return ret;
  };

  ll N; cin >> N;
  ll ans = LLONG_MAX;
  REP(a, 1, N) ans = min(ans, func(a) + func(N - a));
  cout << ans << endl;

  return 0;
}

