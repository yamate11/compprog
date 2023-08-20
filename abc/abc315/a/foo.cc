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

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [0guFRdrH]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [0guFRdrH]

  ll ans = 0;
  ll q = 0;
  ll prod = 1;
  for (ll p = 0; p < N; p++) {
    while (q < N and prod * A[q] <= K) prod *= A[q++];
    ans = max(ans, q - p);
    prod /= A[p];
  }

  return 0;
}
