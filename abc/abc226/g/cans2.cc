#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    vector<ll> a(6), b(6);
    REP2(i, 1, 6) cin >> a[i];
    REP2(i, 1, 6) cin >> b[i];
    auto can = [&](ll i) -> void {
      ll m = min(a[i], b[i]);
      a[i] -= m;
      b[i] -= m;
    };
    can(5);
    if (a[5] > 0) return false;
    can(4);
    if (a[4] > b[5]) return false;
    b[5] -= a[4];
    can(3);
    if (a[3] > b[4] + b[5]) return false;
    {
      ll y = min(a[3], b[5]);
      b[5] -= y;
      b[2] += y;
      a[3] -= y;
      b[4] -= a[3];
      b[1] += a[3];
      a[3] = 0;
    }
    can(2);
    {
      if (a[2] <= 2 * b[5]) {
        if (a[2] % 2 == 0) {
          b[5] -= a[2] / 2;
          b[1] += a[2] / 2;
        }else {
          b[5] -= (a[2] / 2 + 1);
          b[1] += a[2] / 2;
          b[3] += 1;
        }
      }else {
        a[2] -= 2 * b[5];
        b[1] += 2 * b[5];
        b[5] = 0;
        if (a[2] <= 2 * b[4]) {
          if (a[2] % 2 == 0) {
            b[4] -= a[2] / 2;
          }else {
            b[4] -= (a[2] / 2 + 1);
            b[2] += 1;
          }
        }else {
          a[2] -= 2 * b[4];
          b[4] = 0;
          if (a[2] <= b[3]) {
            b[3] -= a[2];
            b[1] += a[2];
          }else {
            return false;
          }
        }
      }
    }
    return a[1] <= 2 * b[2] + 3 * b[3] + 4 * b[4] + 5 * b[5];
  };

  ll T; cin >> T;
  REP(_t, T) cout << (solve() ? "Yes\n" : "No\n");
  return 0;
}

