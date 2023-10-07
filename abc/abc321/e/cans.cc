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

    auto sib = [&](ll x) -> ll {
      if (x % 2 == 0) return x + 1;
      else return x - 1;
    };
    auto f = [&](ll x, ll k) -> ll {
      ll l = x;
      ll r = x + 1;
      while (true) {
        if (N + 1 <= l) return 0;
        if (k == 0) {
          if (N + 1 >= r) return r - l;
          return N + 1 - l;
        }
        l *= 2;
        r *= 2;
        k--;
      }
    };

    ll X, K; cin >> X >> K;
    ll ans = f(X, K);
    ll y = X;
    ll k = K - 2;
    while (true) {
      if (y == 1) break;
      if (k == -1) {
        ans++;
        break;
      }
      ans += f(sib(y), k);
      y = y / 2;
      k--;
    }
    return ans;
  };

  ll T; cin >> T;
  REP(_t, 0, T) cout << solve() << endl;

  return 0;
}

