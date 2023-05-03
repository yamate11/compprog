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

  auto f = [&](ll x, ll y, char cx, char cy) -> void {
    ll t = x / (y + 1);
    ll s = x % (y + 1);
    REP(i, 0, s) {
      REP(j, 0, t + 1) cout << cx;
      cout << cy;
    }
    REP(i, 0, y - s) {
      REP(j, 0, t) cout << cx;
      cout << cy;
    }
    REP(j, 0, t) cout << cx;
    cout << endl;
  };

  auto solve = [&]() -> void {
    ll N, R, B; cin >> N >> R >> B;
    if (R >= B) f(R, B, 'R', 'B');
    else f(B, R, 'B', 'R');
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

