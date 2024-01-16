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

  ll H, W, N; cin >> H >> W >> N;
  // @InpMVec(N, ((X, dec=1), (Y, dec=1))) [q49P6geH]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; v2 -= 1; Y[i] = v2;
  }
  // @End [q49P6geH]
  vector<ll> init{H};
  vector vec(H, init);
  REP(i, 0, N) {
    ll d = X[i] - Y[i];
    if (d < 0) continue;
    vec[d].push_back(X[i]);
  }
  REP(i, 0, H) sort(ALL(vec[i]));
  ll c = 0;
  REP(i, 0, H) {
    ll j = lower_bound(ALL(vec[i]), c) - vec[i].begin();
    c = vec[i][j] + 1;
    if (c > H) break;
    vec[i].resize(j);
  }
  ll ans = H;
  REP(i, 0, H) if (not vec[i].empty()) ans = min(ans, vec[i][0]);
  cout << ans << endl;

  return 0;
}

