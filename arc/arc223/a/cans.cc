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

  auto solve = [&]() -> ll {
    ll N, W0; cin >> N >> W0;
    // @InpMVec(N, (W, V)) [7gsOkEiK]
    auto W = vector(N, ll());
    auto V = vector(N, ll());
    for (int i = 0; i < N; i++) {
      ll v1; cin >> v1; W[i] = v1;
      ll v2; cin >> v2; V[i] = v2;
    }
    // @End [7gsOkEiK]
    vector SV(N + 1, 0LL);
    REP(i, 0, N) SV[i + 1] = SV[i] + V[i];

    auto f = [&](auto rF, ll n, ll w) -> ll {
      if (n < 0) return 0;
      if (W[n] > w) return rF(rF, n - 1, w);
      ll c1 = SV[n];
      ll c2 = V[n] + rF(rF, n - 1, w - W[n]);
      return max(c1, c2);
    };
    return f(f, N - 1, W0);
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

