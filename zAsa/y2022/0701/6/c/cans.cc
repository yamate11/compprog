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

double prod(double a, double b) { return a + b - 2 * a * b; };

double mypower(double a, ll b) {
  double two_pow = a;
  double ret = 0;
  for ( ; b > 0; b >>= 1) {
    if (b & 1LL) ret = prod(ret, two_pow);
    two_pow = prod(two_pow, two_pow);
  }
  return ret;
}

int main() {
  double p; cin >> p;
  ll n; cin >> n;
  cout << mypower(p, n) << endl;
  return 0;
}

