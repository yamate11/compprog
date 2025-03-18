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

  double A, B; cin >> A >> B;
  double c = A / (2 * B);
  auto func = [&](double y) -> double { return B * y + A / sqrt(1 + y); };
  ll x0 = llround(pow(c, (double)2/3) - 1);
  double ans = 1e18;
  REP(x, x0 - 2, x0 + 3) {
    ans = min(ans, func(x));
  }
  cout << ans << endl;
  return 0;
}

