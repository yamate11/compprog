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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpMVec(N, (X, Y)) [rKrsjX21]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [rKrsjX21]
  if (K == 1) {
    cout << "Infinity\n";
    return 0;
  }
  vector<ll> rec(N + 1);
  REP(i, 0, N) REP(j, i + 1, N) {
    ll cnt = 2;
    REP(k, 0, N) {
      if (k == i or k == j) continue;
      ll x1 = X[i] - X[k], y1 = Y[i] - Y[k], x2 = X[j] - X[k], y2 = Y[j] - Y[k];
      if (x1 * y2 == x2 * y1) cnt++;
    }
    rec[cnt]++;
  }
  ll ans = 0;
  REP(k, K, N + 1) {
    ll dup = k * (k - 1) / 2;
    assert(rec[k] % dup == 0);
    ans += rec[k] / dup;
  }
  cout << ans << endl;

  return 0;
}

