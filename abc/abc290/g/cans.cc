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
    ll D, K, X; cin >> D >> K >> X;
    vector<ll> NN(D + 1);
    NN[0] = 1;
    REP(i, 0, D) NN[i + 1] = 1 + K * NN[i];

    auto func = [&](ll D0, ll off) -> ll {
      ll ans = 0;
      ll d = D0 - 1;
      while (true) {
        ll p = off / NN[d];
        ll q = off % NN[d];
        ans += p;
        if (q == 0) return ans;
        off = q;
        d--;
      }
      assert(0);
    };

    if (X == NN[D]) return 0;
    if (X == NN[D - 1]) return 1;
    if (NN[D - 1] < X) return func(D, NN[D] - X);
    ll d = D - 1;
    while (true) {
      if (X == NN[d]) return 1;
      if (NN[d - 1] < X) return 1 + func(d, NN[d] - X);
      d--;
    }
    assert(0);
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

