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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    auto U = vector(50, false);
    auto A = vector(N, vector(50, false));
    REP(i, 0, N) {
      ll k; cin >> k;
      REP(j, 0, k) {
        ll s; cin >> s; s--;
        A[i][s] = true;
        U[s] = true;
      }
    }
    ll ans = 0;
    REP(c, 0, 50) if (U[c]) {
      auto B = vector(50, false);
      REP(i, 0, N) if (not A[i][c]) {
        REP(j, 0, 50) B[j] = B[j] or A[i][j];
      }
      ll t = 0;
      REP(j, 0, 50) if (B[j]) t++;
      ans = max(ans, t);
    }
    cout << ans << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

