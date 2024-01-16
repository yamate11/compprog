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

  ll x, y, a, b; cin >> x >> y >> a >> b;
  ll cnt = 0;
  while (true) {
    if ((x + b) / x <= a) {
      cnt += ((y - 1) - x) / b;
      cout << cnt << endl;
      return 0;
    }else {
      x *= a;
    }
    if (x >= y) break;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}

