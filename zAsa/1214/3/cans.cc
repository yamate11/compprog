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

  auto check = [&](ll u, ll v, ll a) -> bool {
    return 4 * u * v <= (a * a - (u + v)) * (a * a - (u + v));
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

  REP(i, 0, N) {
    ll dx1 = X[i] - a, dx2 = X[i] - c, dy1 = Y[i] - b, dy2 = Y[i] - d;
    if (check(dx1*dx1 + dy1*dy1, dx2*dx2 + dy2*dy2, T * V)) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}

