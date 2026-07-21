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

  ll N, W; cin >> N >> W;
  // @InpVec(N, A) [j8fcJqwq]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [j8fcJqwq]
  vector<bool> B(W + 1);
  REP(i, 0, N) {
    if (A[i] <= W) B[A[i]] = true;
  }
  REP(i, 0, N) REP(j, 0, N) {
    if (i != j and A[i] + A[j] <= W) B[A[i] + A[j]] = true;
  }
  REP(i, 0, N) REP(j, 0, N) REP(k, 0, N) {
    if (i != j and j != k and i != k and A[i] + A[j] + A[k] <= W) B[A[i] + A[j] + A[k]] = true;
  }
  ll ans = 0;
  REP(i, 0, W + 1) ans += B[i];
  cout << ans << endl;


  return 0;
}

