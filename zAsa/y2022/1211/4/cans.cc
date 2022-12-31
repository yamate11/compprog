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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll T, N; cin >> T >> N;
  // @InpVec(N, A) [x7wufYH6]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [x7wufYH6]
  ll M; cin >> M;
  // @InpVec(M, B) [HsXdJeDR]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [HsXdJeDR]
  ll p = 0;
  REP(q, 0, M) {
    while (p < N and A[p] < B[q] - T) p++;
    if (p == N or A[p] > B[q]) {
      cout << "no\n";
      return 0;
    }
    p++;
  }
  cout << "yes\n";

  return 0;
}

