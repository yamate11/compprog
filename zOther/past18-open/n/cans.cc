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

  ll tx, ty, vt, ax, ay, va; cin >> tx >> ty >> vt >> ax >> ay >> va;
  if (vt > va) {
    cout << "inf\n";
    return 0;
  }
  if (vt == va) {
    if (ty != ay) cout << "inf\n";
    else if (abs(tx) <= abs(ax)) cout << "inf\n";
    else cout << "0\n";
    return 0;
  }
  ay -= ty;
  ll a = vt * vt - va * va;
  ll b = vt * vt * (-2 * ay);
  ll c = vt * vt * (ay * ay + ax * ax) - va * va * tx * tx;
  ll D = b * b - 4 * a * c;
  if (D <= 0) {
    cout << 0 << endl;
    return 0;
  }else {
    long double sum = - (long double)b / a;
    long double prod = (long double)c / a;
    cout << sqrt(sum * sum - 4 * prod) << endl;
  }

  return 0;
}

