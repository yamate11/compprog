#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector<ll> A(K); REP(i, K) { cin >> A[i]; A[i]--; }
  vector<double> X(N), Y(N);
  REP(i, N) cin >> X[i] >> Y[i];
  auto dist = [&](ll i, ll j) -> double {
    double dx = X[i] - X[j];
    double dy = Y[i] - Y[j];
    return sqrt(dx * dx + dy * dy);
  };
  double ans = 0;
  REP(i, N) {
    double vmin = 1e18;
    REP(j, K) {
      ll k = A[j];
      vmin = min(vmin, dist(i, k));
    }
    ans = max(ans, vmin);
  }
  cout << ans << endl;

  return 0;
}

