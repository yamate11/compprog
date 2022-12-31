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

  ll N; cin >> N;
  ll T, A; cin >> T >> A;
  // @InpVec(N, H) [K1N3o5CT]
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
  // @End [K1N3o5CT]
  double vmin = 1e18;
  ll ans = -1;
  REP(i, 0, N) {
    double d = abs(T - H[i] * 0.006 - A);
    if (d < vmin) {
      vmin = d;
      ans = i;
    }
  }
  cout << ans + 1 << endl;
  
  return 0;
}

