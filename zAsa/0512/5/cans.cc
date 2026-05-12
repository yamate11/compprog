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

  double P; cin >> P;
  auto f = [&](double t) -> double { return t + P / pow(2.0, t / 1.5); };
  double hi = max(10.0, P);
  double lo = 0.0;
  REP(i, 0, 200) {
    double mid1 = lo + (hi - lo) / 3.0;
    double mid2 = lo + (hi - lo) / 3.0 * 2.0;
    if (f(mid1) < f(mid2)) hi = mid2;
    else lo = mid1;
  }
  cout << f(lo) << endl;

  return 0;
}

