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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [dFiCJ1CU]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [dFiCJ1CU]

  vector S(N + 1, 0LL);
  REP(i, 0, N) S[i + 1] = S[i] + A[i];

  ll s = 0;
  REP(i, 0, M) s += (i + 1) * A[i];
  ll ans = s;
  REP(i, 0, N - M) {
    s = s - (S[i + M] - S[i]) + M * A[i + M];
    ans = max(ans, s);
  }
  cout << ans << endl;
  return 0;
}

