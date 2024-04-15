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

  ll A, B, M; cin >> A >> B >> M;
  // @InpVec(A, vecA) [KjBQOApC]
  auto vecA = vector(A, ll());
  for (int i = 0; i < A; i++) { ll v; cin >> v; vecA[i] = v; }
  // @End [KjBQOApC]
  // @InpVec(B, vecB) [VZVz42YB]
  auto vecB = vector(B, ll());
  for (int i = 0; i < B; i++) { ll v; cin >> v; vecB[i] = v; }
  // @End [VZVz42YB]
  // @InpMVec(M, ((X, dec=1), (Y, dec=1), C)) [ttiLxana]
  auto X = vector(M, ll());
  auto Y = vector(M, ll());
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; v2 -= 1; Y[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [ttiLxana]

  ll ans = *min_element(ALL(vecA)) + *min_element(ALL(vecB));
  REP(i, 0, M) {
    ans = min(ans, vecA[X[i]] + vecB[Y[i]] - C[i]);
  }
  cout << ans << endl;

  return 0;
}

