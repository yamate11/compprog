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

  ll N, K; cin >> N >> K;
  // @InpVec(N, X) [uYm1TFqR]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [uYm1TFqR]
  
  auto f = [&](const auto& vec) -> ll {
    ll i0 = lower_bound(ALL(vec), 0) - vec.begin();
    ll ans = 1e18;
    REP(i, i0, N) {
      ll t;
      if (i - i0 + 1 > K) break;
      else if (i - i0 + 1 == K) t = vec[i];
      else if (i - K + 1 < 0) continue;
      else t = vec[i] + (vec[i] - vec[i - K + 1]);
      ans = min(ans, t);
    }
    return ans;
  };
  ll ans = f(X);
  REP(i, 0, N) X[i] = -X[i];
  reverse(ALL(X));
  ans = min(ans, f(X));
  cout << ans << endl;
  return 0;
}

