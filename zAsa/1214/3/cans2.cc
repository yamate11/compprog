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

  auto dist = [&](ll x, ll y, ll a, ll b) -> double {
    double t = (x - a) * (x - a) + (y - b) * (y - b);
    return sqrt(t);
  };

  ll a, b, c, d, T, V; cin >> a >> b >> c >> d >> T >> V;
  ll N; cin >> N;
  // @InpMVec(N, (X, Y)) [y2oXovCP]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [y2oXovCP]

  double eps = 1e-6;
  REP(i, 0, N) {
    double len = dist(X[i], Y[i], a, b) + dist(X[i], Y[i], c, d);
    ll z = llround(len);
    if (abs((double)z - len) > eps) z = llround(ceil(len));
    if (z <= T * V) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}

