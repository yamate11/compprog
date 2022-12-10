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

  auto solve = [&]() -> void {
    ll n, k; cin >> n >> k;
    if (k % 4 == 0) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
    auto out = [&](ll p, ll q) {
      cout << p << " " << q << "\n";
    };
    ll m = (n + 1) / 4;
    if (k % 4 == 1) {
      REP(i, 0, m) {
        out(4 * i + 3, 4 * i + 1);
        out(4 * i + 2, 4 * i + 4);
      }
      if (m * 4 < n) out(n - 1, n);
    }else if (k % 4 == 2) {
      REP(i, 0, m) {
        out(4 * i + 1, 4 * i + 4);
        out(4 * i + 2, 4 * i + 3);
      }
      if (m * 4 < n) out(n, n - 1);
    }else if (k % 4 == 3) {
      REP(i, 0, m) {
        out(4 * i + 1, 4 * i + 2);
        out(4 * i + 3, 4 * i + 4);
      }
      if (m * 4 < n) out(n - 1, n);
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

