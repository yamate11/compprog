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

  ll N; cin >> N;
  // @InpMVec(N, (X, Y)) [dqhReGXZ]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [dqhReGXZ]

  set<pll> ss;
  REP(i, 0, N) ss.emplace(X[i], Y[i]);

  ll ans = 0;
  REP(i, 0, N) REP(j, i + 1, N) {
    ll xi = X[i], yi = Y[i], xj = X[j], yj = Y[j];
    if (xi > xj) { swap(xi, xj); swap(yi, yj); }
    if (xi < xj and yi < yj) {
      auto it1 = ss.find(pll(xi, yj));
      auto it2 = ss.find(pll(xj, yi));
      if (it1 != ss.end() and it2 != ss.end()) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}

