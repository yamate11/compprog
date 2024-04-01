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
    ll ans = 0;
    REP(i, 0, X - 1) if (A[i] + 2 == A[i + 1]) ans++;
    if ((A[X - 1] + 2) % N == A[0]) ans++;
    ans += X - 2;
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

