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

  auto solve = [&]() -> void {
    ll a, b, c, m; cin >> a >> b >> c >> m;
    ll va = m / a * 6;
    ll vb = m / b * 6;
    ll vc = m / c * 6;
    ll lab = a * b / gcd(a, b);
    ll lbc = b * c / gcd(b, c);
    ll lca = c * a / gcd(c, a);
    va -= m / lab * 3;
    va -= m / lca * 3;
    vb -= m / lab * 3;
    vb -= m / lbc * 3;
    vc -= m / lbc * 3;
    vc -= m / lca * 3;
    ll labc = lab * c / gcd(lab, c);
    va += m / labc * 2;
    vb += m / labc * 2;
    vc += m / labc * 2;
    cout << va << " " << vb << " " << vc << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

