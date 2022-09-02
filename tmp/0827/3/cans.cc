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

  ll A, B, X; cin >> A >> B >> X;
  ll cur = 1e9;
  if (A * cur + B * 10 <= X) {
    cout << cur << endl;
    return 0;
  }
  REPrev(d, 9, 1) {
    cur /= 10;
    if (A * cur + B * d <= X) {
      ll ans = min((X - B * d) / A, 10 * cur - 1);
      cout << ans << endl;
      return 0;
    }
  }
  cout << 0 << endl;

  return 0;
}

