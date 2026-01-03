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
  // @InpVec(N, A) [bfO9QzMw]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [bfO9QzMw]
  sort(ALL(A));
  vector S(N + 1, 0LL);
  REP(i, 0, N) S[i + 1] = S[i] + A[i];
  double ans = S[N];
  REP(j, 0, N) {
    double cur = (S[N] - S[j + 1]) - (N - 1 - j) * A[j] + 0.5 * N * A[j];
    ans = min(ans, cur);
  }
  cout << (double)ans / N << endl;

  return 0;
}

