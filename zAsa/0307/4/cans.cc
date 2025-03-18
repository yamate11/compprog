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

  ll N, M, K; cin >> N >> M >> K;
  // @InpVec(N, A) [y9OZ8uxH]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [y9OZ8uxH]
  // @InpVec(M, B) [1NUU244y]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [1NUU244y]

  ll sa = 0, sb = 0;
  ll i = 0, j = 0;
  while (i < N and sa + A[i] <= K) {
    sa += A[i];
    i++;
  }
  while (j < M and sa + sb + B[j] <= K) {
    sb += B[j];
    j++;
  }
  ll ans = i + j;
  while (i > 0) {
    sa -= A[--i];
    while (j < M and sa + sb + B[j] <= K) {
      sb += B[j];
      j++;
    }
    ans = max(ans, i + j);
  }
  cout << ans << endl;

  return 0;
}

