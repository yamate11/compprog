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
  // @InpVec(N, D) [jVfaUpZk]
  auto D = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; D[i] = v; }
  // @End [jVfaUpZk]
  // @InpVec(M, S) [qZGwktVu]
  auto S = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; S[i] = v; }
  // @End [qZGwktVu]

  ll ans = 0;
  ranges::sort(S);
  REP(i, 0, N) {
    ll j = ranges::lower_bound(S, D[i]) - S.begin();
    if (j == 0) ans += S[0] - D[i];
    else if (j == M) ans += D[i] - S[M - 1];
    else ans += min(S[j] - D[i], D[i] - S[j - 1]);
  }
  cout << ans << endl;
  return 0;
}

