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

  auto solve = [&]() -> bool {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if (b > d) return false;
    if (a < b) return false;
    if (a % b > c) return false;
    if (c >= b) return true;
    ll g = gcd(b, d);
    ll x = (b - (a % b)) % g;
    if (x == 0) x = g;
    return g >= b - c;
    
  };

  ll T; cin >> T;
  REP(i, 0, T) cout << (solve() ? "Yes" : "No") << "\n";

  return 0;
}

