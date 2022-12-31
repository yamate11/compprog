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
  // @InpVec(N + 1, A) [lVlhnQEW]
  auto A = vector(N + 1, ll());
  for (int i = 0; i < N + 1; i++) { ll v; cin >> v; A[i] = v; }
  // @End [lVlhnQEW]
  // @InpVec(N, B) [rnnrSIxN]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [rnnrSIxN]
  ll ans = 0;
  REP(i, 0, N) {
    ll p = min(A[i], B[i]);
    ans += p;
    A[i] -= p;
    B[i] -= p;
    ll q = min(A[i + 1], B[i]);
    ans += q;
    A[i + 1] -= q;
    B[i] -= q;
  }
  cout << ans << endl;

  return 0;
}

