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

  ll N, M, P; cin >> N >> M >> P;
  // @InpVec(N, A) [19tly9nr]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [19tly9nr]
  // @InpVec(M, B) [3ieNoeB7]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [3ieNoeB7]

  sort(ALL(A));

  auto S = vector<ll>(N + 1, 0LL);
  REP(i, 0, N) S[i + 1] = S[i] + A[i];
  ll ans = 0;
  REP(j, 0, M) {
    ll i0 = lower_bound(ALL(A), P - B[j]) - A.begin();
    ll x = (N - i0) * P;
    ll y = i0 * B[j] + S[i0];
    ans += x + y;
  }
  cout << ans << endl;

  return 0;
}

