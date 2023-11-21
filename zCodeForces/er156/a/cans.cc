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

  auto solve = [&]() -> void {
    auto check = [&](ll p, ll q, ll r) -> bool {
      if (p <= 0 or q <= 0 or r <= 0 or p == q or q == r or p == r) return false;
      return true;
    };

    ll n; cin >> n;
    {
      ll p, q, r;
      if (n % 3 == 0) {
        ll k = n / 3;
        p = 1; q = 4; r = 3 * k - 5;
      }else if (n % 3 == 1) {
        ll k = (n - 1) % 3;
        p = 1; q = 2; r = 3 * k - 2;
      }else if (n % 3 == 2) {
        ll k = (n - 2) % 3;
        p = 1; q = 2; r = 3 * k - 1;
      }else assert(0);

      if (check(p, q, r)) {
        cout << "YES\n";
        cout << p << " " << q << " " << r << "\n";
        return;
      }
    }
    REP(p, 1, n) {
      if (p % 3 == 0) continue;
      REP(q, p + 1, n) {
        if (q % 3 == 0) continue;
        if (p >= q) continue;
        ll r = n - (p + q);
        if (r % 3 == 0) continue;
        if (q >= r) continue;
        cout << "YES\n";
        cout << p << " " << q << " " << r << "\n";
        return;
      }
    }
    cout << "NO\n";
    

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

