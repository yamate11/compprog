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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    if (N % 8 != 0) {
      cout << -1 << "\n";
    }else {
      N /= 8;
      if (N >= 12340) {
        ll base = N / 1234;
        ll rem = N % 1234;
        ll x4 = rem / 1111;
        rem = rem % 1111;
        ll x3 = rem / 111;
        rem = rem % 111;
        ll x2 = rem / 11;
        ll x1 = rem % 11;
        cout << base + x1 << " " << base + x2 << " " << base + x3 << " " << base + x4 << "\n";
      }else {

        auto f = [&]() -> bool {
          REP(x4, 0, N / 1111 + 1) {
            ll rem4 = N - 1111 * x4;
            REP(x3, 0, rem4 / 111 + 1) {
              ll rem3 = rem4 - 111 * x3;
              REP(x2, 0, rem3 / 11 + 1) {
                ll x1 = rem3 - 11 * x2;
                ll y = x1 + x2 + x3 + x4;
                if (2 * x1 < y and 2 * x2 < y and 2 * x3 < y and 2 * x4 < y) {
                  cout << x1 << " " << x2 << " " << x3 << " " << x4 << "\n";
                  return true;
                }
              }
            }
          }
          return false;
        };
        if (not f()) cout << -1 << "\n";

      }
    }
  };


  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

