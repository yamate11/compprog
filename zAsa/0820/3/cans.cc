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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [E1uEikoF]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [E1uEikoF]

  vector<ll> S(N + 1);
  REP(i, 0, N) S[i + 1] = S[i] + A[i];

  ll x = 0;
  REP(i, 0, M) x += (i + 1) * A[i];
  ll ans = x;
  REP(i, 1, N - M + 1) {
    x -= S[M + i - 1] - S[0 + i - 1];
    x += M * A[M + i - 1];
    ans = max(ans, x);
  }
  cout << ans << endl;

  return 0;
}

