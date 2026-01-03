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

  ll N, Q; cin >> N >> Q;
  // @InpMVec(N, (X, R, H)) [yJGI7Swj]
  auto X = vector(N, ll());
  auto R = vector(N, ll());
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
    ll v3; cin >> v3; H[i] = v3;
  }
  // @End [yJGI7Swj]

  auto f = [&](ll t) -> double {
    double ret = 0;
    REP(i, 0, N) {
      if (t < X[i]) ret += M_PI * R[i] * R[i] * H[i] / 3.0;
      else if (t < X[i] + H[i]) {
        double h = H[i] - (t - X[i]);
        double r = h * R[i] / (double)H[i];
        ret += M_PI * r * r * h / 3.0;
      }
    }
    return ret;
  };

  REP(_q, 0, Q) {
    ll a, b; cin >> a >> b;
    cout << f(a) - f(b) << "\n";
  }


  return 0;
}

