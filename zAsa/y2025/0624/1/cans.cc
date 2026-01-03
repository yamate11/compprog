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

  auto check = [&](ll h, ll m) {
    ll h1 = h / 10;
    ll h2 = h % 10;
    ll m1 = m / 10;
    ll m2 = m % 10;
    ll a = h1 * 10 + m1;
    ll b = h2 * 10 + m2;
    return (0 <= a and a < 24 and 0 <= b and b < 60);
  };

  ll h; cin >> h;
  ll m; cin >> m;
  while (true) {
    if (check(h, m)) {
      cout << h << " " << m << "\n";
      return 0;
    }
    m++;
    if (m == 60) {
      m = 0;
      h++;
      if (h == 24) h = 0;
    }
  }

  return 0;
}

