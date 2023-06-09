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

  ll A, B, C; cin >> A >> B >> C;
  ll lim = 1000;
  REP(i, 0, lim) {
    if (A % 2 == 1 or B % 2 == 1 or C % 2 == 1) {
      cout << i << endl;
      return 0;
    }
    ll a = A, b = B, c = C;
    A = b / 2 + c / 2;
    B = c / 2 + a / 2;
    C = a / 2 + b / 2;
  }
  cout << -1 << endl;

  return 0;
}

