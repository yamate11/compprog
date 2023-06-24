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

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    if (N <= 6) return -1;
    vector<ll> vec;
    ll x = N;
    ll cnt = 0;
    while (x > 0) {
      ll y = x % 2;
      vec.push_back(y);
      if (y == 1) cnt++;
      x /= 2;
    }
    ll sz = SIZE(vec);
    reverse(ALL(vec));
    if (cnt >= 3) {
      ll t = 0;
      REP(i, 0, sz) {
        if (vec[i] == 1) {
          if (t < 3) t++;
          else vec[i] = 0;
        }
      }
    }else {
      bool done = false;
      if (cnt == 2) {
        ll t = 0;
        REP(i, 0, sz) {
          if (vec[i] == 1) {
            t++;
            if (t == 2) {
              if (i <= sz - 3) {
                vec[i] = 0;
                vec[i + 1] = 1;
                vec[i + 2] = 1;
                REP(j, i + 3, sz) vec[j] = 0;
                done = true;
                break;
              }
            }
          }
        }
      }
      if (not done) {
        REP(i, 0, sz) {
          if (vec[i] == 1) {
            assert(i <= sz - 4);
            vec[i] = 0;
            vec[i + 1] = vec[i + 2] = vec[i + 3] = 1;
            REP(j, i + 4, sz) vec[j] = 0;
            break;
          }
        }
      }
    }
    ll ans = 0;
    REP(i, 0, sz) {
      ans *= 2;
      if (vec[i] == 1) ans++;
    }
    return ans;

  };

  ll T; cin >> T;
  REP(i, 0, T) cout << solve() << "\n";

  return 0;
}

