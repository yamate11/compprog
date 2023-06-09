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

  ll N, M, D; cin >> N >> M >> D;
  // @InpVec(N, A) [eE4KiDug]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [eE4KiDug]
  // @InpVec(M, B) [XR6A7Jz4]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [XR6A7Jz4]
  sort(ALL(A));
  sort(ALL(B));

  ll ans = -1;
  REP(i, 0, N) {
    ll j = upper_bound(ALL(B), A[i] + D) - B.begin();
    if (j == 0) continue;
    j--;
    if (abs(A[i] - B[j]) <= D) ans = max(ans, A[i] + B[j]);
  }
  cout << ans << endl;

  return 0;
}

