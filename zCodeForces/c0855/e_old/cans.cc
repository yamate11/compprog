#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
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

  auto solve = [&]() -> void {
    ll B, L, R; cin >> B >> L >> R;
    auto basetr = [&](ll t) -> vector<ll> {
      vector<ll> vec;
      while (t > 0) {
        vec.push_back(t % B);
        t /= B;
      }
      reverse(ALL(vec));
      return vec;
    };
    auto func = [&](ll t) -> ll {
      vector tbl_init(2, vector(2, vector(1LL << B, 0LL)));
      auto tbl = tbl_init;
      tbl[1][1][0] = 1;
      vector<ll> vt = basetr(t);
      for (ll d : vt) {
        auto prev = move(tbl);
        tbl = tbl_init;
        REP(eq, 2) REP(az, 2) REP(z, 1LL << B) {
          if (prev[eq][az][z] == 0) continue;
          REP(x, B) {
            if (eq && x > d) continue;
            bool new_eq = eq && x == d;
            bool new_az = az && x == 0;
            ll new_z = [&]() -> ll {
              if (new_az)  return 0;
              else if (az) return 1LL << x;
              else         return z ^ (1LL << x);
            }();
            tbl[new_eq][new_az][new_z] += prev[eq][az][z];
          }
        }
      }
      ll ret = 0;
      REP(eq, 2) REP(az, 2) ret += tbl[eq][az][0];
      return ret;
    };
    ll ans = func(R) - func(L - 1);
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

