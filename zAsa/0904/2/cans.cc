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

  ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  ll ans = LLONG_MAX;
  for (ll nc = 0; nc <= 2 * max(x, y); nc += 2) {
    ll na = max(0LL, x - nc / 2);
    ll nb = max(0LL, y - nc / 2);
    ll cost = a * na + b * nb + c * nc;
    ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}

