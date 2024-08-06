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

  ll N, Y; cin >> N >> Y;
  REP(x, 0, N + 1) {
    ll totX = x * 10000;
    if (totX > Y) break;
    REP(y, 0, (N - x) + 1) {
      ll totY = totX + y * 5000;
      if (totY > Y) break;
      ll z = N - (x + y);
      ll tot = totY + z * 1000;
      if (tot == Y) {
        cout << x << " " << y << " " << z << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}

