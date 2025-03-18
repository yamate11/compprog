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

  ll N; cin >> N;
  // @InpVec(N, Q) [dNlf5idx]
  auto Q = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; Q[i] = v; }
  // @End [dNlf5idx]
  // @InpVec(N, A) [dRBf7JFA]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [dRBf7JFA]
  // @InpVec(N, B) [1CaKidUE]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [1CaKidUE]

  ll nmax = 0;
  REP(a, 0, 10000000) {
    ll p = 1e18;
    REP(i, 0, N) {
      if (a * A[i] > Q[i]) {
        cout << nmax << endl;
        return 0;
      }
      ll r = Q[i] - a * A[i];
      if (B[i] > 0) {
        p = min(p, r / B[i]);
      }
    }
    nmax = max(nmax, a + p);
  }
  cout << nmax << endl;
  return 0;
}

