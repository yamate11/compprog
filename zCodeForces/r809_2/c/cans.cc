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
    ll N; cin >> N;
    // @InpVec(N, H) [wulmNobL]
    auto H = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
    // @End [wulmNobL]
    if (N % 2 == 1) {
      ll s = 0;
      for (ll i = 1; i < N; i += 2) s += max(0LL, max(H[i - 1], H[i + 1]) + 1 - H[i]);
      cout << s << "\n";
      return;
    }
    vector<ll> v(N);
    REP(i, 1, N - 1) v[i] = max(0LL, max(H[i - 1], H[i + 1]) + 1 - H[i]);
    ll s = 0;
    for (ll i = 2; i < N - 1; i += 2) s += v[i];
    ll ans = s;
    for (ll i = 1; i < N - 2; i += 2) {
      s = s + v[i] - v[i + 1];
      ans = min(ans, s);
    }
    cout << ans << "\n";
    return;

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

