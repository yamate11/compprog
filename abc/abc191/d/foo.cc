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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  // ll x = 12345, y = 67891;
  ll x = 0, y = 0;
  ll vmax = 0;
  for (ll rr = 100000; rr >= 99000; rr--) {
    for (ll ii = 0; ii <= 1000; ii++) {
      ll r = rr * 10000;
      ll i = ii * 10000;
      ll ub = ll(sqrt(r*r - (i-x)*(i-x)) + y) / 10000 * 10000;
      ll ub0 = ub;
      while((i-x)*(i-x) + (ub-y)*(ub-y) > r*r) ub -= 10000;
      while((i-x)*(i-x) + (ub+10000-y)*(ub+10000-y) <= r*r) ub += 10000;
      vmax = max(vmax, abs(ub0 - ub));
    }
  }
  cout << vmax << endl;
  // cout << ub0 << ", " << ub << ", " << ub0 - ub << endl;

}
