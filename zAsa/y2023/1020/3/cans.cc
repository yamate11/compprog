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

  auto solve = [&]() -> ll {
    ll x1, x2, x3; cin >> x1 >> x2 >> x3;
    if ((x2 - x1) % 2 != 0) return -1;
    if ((x3 - x2) % 2 != 0) return -1;
    ll d = x2 - x1 + x3 - x1;
    if (d % 6 != 0) return -1;
    ll m = (x1 + x2 + x3) / 3;
    ll cnt = 0;
    if (x1 > m) cnt += (x1 - m) / 2;
    if (x2 > m) cnt += (x2 - m) / 2;
    if (x3 > m) cnt += (x3 - m) / 2;
    return cnt;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << endl;

  return 0;
}

