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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B, X; cin >> A >> B >> X;
  vector<ll> p10(11);
  p10[0] = 1;
  REP(i, 0, 10) p10[i + 1] = 10 * p10[i];
  ll lim = p10[9];
  if (A * lim + B * 10 <= X) {
    cout << lim << endl;
    return 0;
  }
  REPrev(d, 9, 1) {
    ll rem = X - B * d;
    if (rem < 0) continue;
    ll t = rem / A;
    if (p10[d - 1] <= t) {
      cout << min(t, p10[d] - 1) << endl;
      return 0;
    }
  }
  cout << 0 << endl;

  return 0;
}

