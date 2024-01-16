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

  ll N, Q; cin >> N >> Q;
  // @InpMVec(N, ((X, type=double), (R, type=double), (H, type=double))) [DNnMcZ14]
  auto X = vector(N, double());
  auto R = vector(N, double());
  auto H = vector(N, double());
  for (int i = 0; i < N; i++) {
    double v1; cin >> v1; X[i] = v1;
    double v2; cin >> v2; R[i] = v2;
    double v3; cin >> v3; H[i] = v3;
  }
  // @End [DNnMcZ14]

  auto f = [&](double z) -> double {
    double ret = 0.0;
    REP(i, 0, N) {
      if (z <= X[i]) ret += R[i] * R[i] * H[i];
      else if (z <= X[i] + H[i]) {
        double a = (X[i] + H[i] - z) / H[i];
        ret += a * a * a * R[i] * R[i] * H[i];
      }
      else ret += 0.0;
    }
    return ret;
  };

  double c = M_PI / 3.0;

  REP(_q, 0, Q) {
    double a, b; cin >> a >> b;
    cout << c * (f(a) - f(b)) << "\n";
  }

  return 0;
}

