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

  double a, b, x; cin >> a >> b >> x;
  double alpha;
  if (x > a * a * b / 2) {
    alpha = (a * a * b - x) /(a*a*a) * 2;
  }else {
    alpha = b * b * a / 2 / x;
  }
  double ans = atan2(alpha, 1) * 180 / M_PI;
  cout << ans << endl;

  return 0;
}

