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

  ll N, t, p; cin >> N >> t >> p;
  // @InpVec(N, A) [Aq2BCyjc]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Aq2BCyjc]

  vector<double> E(N + 2, 0.0);
  REPrev(n, N - 1, 0) {
    double e1 = (A[n] - (A[n] * t) / 100) + E[n + 1];
    double e2 = p / 100.0 * ((A[n] - (A[n] * t) / 100) + E[n + 2]);
    double e3 = (1.0 - p / 100.0) * (A[n] + E[n + 1]);
    E[n] = max(e1, e2 + e3);
  }
  cout << E[0] << endl;

  return 0;
}

