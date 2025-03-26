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
    ll R, B; cin >> R >> B;
    if (R % 2 != 0) {
      cout << "No\n";
      return;
    }
    if (R == 0 and B % 2 != 0) {
      cout << "No\n";
      return;
    }
    cout << "Yes\n";
    ll x = R / 2 + B;
    ll usedB = 0;
    auto f = [&](ll r0, ll c0, ll dr1, ll dc1, ll dr2, ll dc2) -> void {
      /*
      ll dr = dr1 + dr2;
      ll dc = dc1 + dc2;
      */
      if (usedB < B) {
        cout << "B " << r0 << " " << c0 << "\n";
      }else {
        cout << "R " << r0 << " " << c0 << "\n";
        cout << "R " << r0 + dr1 << " " << c0 + dc1 << " " << "\n";
      }
      usedB++;
    };
    if (x % 2 == 0) {
      ll y = (x - 2) / 2;
      REP(i, 0, y) f(2 + i, 1 + i, 1, 0, 0, 1);
      f(2 + y, 1 + y, 0, 1, -1, 0);
      REP(i, 0, y) f(1 + y - i, 2 + y - i, -1, 0, 0, -1);
      f(1, 2, 0, -1, 1, 0);
    }else {
      assert(R >= 2);
      ll y = (x - 1) / 2;
      REP(i, 0, y) f(2 + i, 1 + i, 1, 0, 0, 1);
      cout << "R " << 2 + y << " " << 1 + y << "\n";
      REP(i, 0, y) f(1 + y - i, 1 + y - i, -1, 0, 0, -1);
      cout << "R 1 1\n";
    }
  };


  ll T; cin >> T;
  REP(t, 0, T) solve();


  return 0;
}

