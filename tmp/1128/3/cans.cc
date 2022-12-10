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

  ll N; cin >> N;
  // @InpVec(N, A) [bqlDp3WV]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [bqlDp3WV]
  vector<ll> S(N + 1);
  REP(i, 0, N) S[i + 1] = S[i] + A[i];
  vector<ll> m(N + 1);
  REP(i, 1, N + 1) m[i] = max(m[i - 1], S[i]);
  ll c = 0;
  ll ans = 0;
  REP(i, 0, N) {
    ans = max(ans, c + m[i + 1]);
    c += S[i + 1];
  }
  cout << ans << endl;

  return 0;
}

