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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  /*
  auto solve = [&](ll a, ll b) -> ll {
    ll diffA = 0, diffB = 0;
    if (a < 900) diffA = (9 - (a / 100)) * 100;
    else if (a < 990) diffA = (9 - ((a - 900) / 10)) * 10;
    else if (a < 999) diffA = 999 - a;
    if (b >= 200) diffB = (b / 100 - 1) * 100;
    else if (b >= 110) diffB = ((b - 100) / 10 - 1) * 10;
    else if (b >= 101) diffB = b - 100;
    return a - b + max(diffA, diffB);
  };
  */


  auto f = [&](ll x, ll p, ll q) -> ll {
    vector<ll> z(3);
    REP(i, 0, 3) {
      z[i] = x % 10;
      x /= 10;
    }
    z[p] = q;
    ll t = 0;
    REP(i, 0, 3) t = t * 10 + z[2 - i];
    return t;
  };

  ll a, b; cin >> a >> b;
  ll ans = a - b;
  REP(i, 0, 3) REP(j, 0, 10) if (not (i == 2 and j == 0)) ans = max(ans, f(a, i, j) - b);
  REP(i, 0, 3) REP(j, 0, 10) if (not (i == 2 and j == 0)) ans = max(ans, a - f(b, i, j));
  cout << ans << endl;



  return 0;
}

