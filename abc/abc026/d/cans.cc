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

  ll a, b, c; cin >> a >> b >> c;
  auto f = [&](double t) -> double { return a * t + b * sin(c * t * M_PI) - 100.0; };
  double hi = 1.0;
  double lo = 0.0;
  double eps = 1e-7;
  while (f(hi) < eps) hi *= 2.0;
  while (true) {
    double mid = (lo + hi) / 2.0;
    if (-eps < f(mid) and f(mid) < eps) {
      cout << mid << endl;
      return 0;
    }
    if (f(mid) < 0) lo = mid;
    else hi = mid;
  }

  return 0;
}

