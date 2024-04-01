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
    ll N, X, Y; cin >> N >> X >> Y;
    // @InpVec(X, A, dec=1) [byCFGmZA]
    auto A = vector(X, ll());
    for (int i = 0; i < X; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
    // @End [byCFGmZA]
    sort(ALL(A));

    map<ll, ll> gap;
    REP(i, 0, X - 1) gap[A[i + 1] - A[i]]++;
    gap[A[0] + N - A[X - 1]]++;

    ll ans = X - 2;
    ll rem = 0;
    for (auto [g, v] : gap) {
      if (g == 1) ;
      else if (g == 2) ans += v;
      else if (g % 2 == 0) {
        ll t = (g - 2) / 2;
        if (t * v <= Y) {
          Y -= t * v;
          ans += (2 * t + 1) * v;
        }else {
          ll w = Y / t;
          Y -= t * w;
          ans += (2 * t + 1) * w;
          ans += 2 * Y;
          Y = 0;
          break;
        }
      }else {
        rem += v * (g / 2);
      }
    }
    ans += min(Y, rem) * 2;
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

