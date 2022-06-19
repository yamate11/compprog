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

  ll N; cin >> N;
  vector<double> X(N), Y(N);
  REP(i, N) cin >> X[i] >> Y[i];

  auto f = [&](ll i, ll j) -> double {
    double px = X[i] - X[j];
    double py = Y[i] - Y[j];
    return sqrt(px * px + py * py);
  };

  double ans = 0;    
  REP(i, N) REP(j, N) ans = max(ans, f(i, j));
  cout << ans << endl;

  return 0;
}

