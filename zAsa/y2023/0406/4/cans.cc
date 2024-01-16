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

  double a, b, c; cin >> a >> b >> c;
  double x = a + b + c;
  double sm = x * x * M_PI;
  double y;
  if (a > b + c) y = a - (b + c);
  else if (b > a + c) y = b - (a + c);
  else if (c > a + b) y = c - (a + b);
  else y = 0;
  double ans = sm - y * y * M_PI;
  cout << ans << endl;

  return 0;
}

