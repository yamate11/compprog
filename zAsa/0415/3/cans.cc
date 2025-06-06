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
  // @InpMVec(M, ((A, dec=1), (B, dec=1))) [4VxXXC96]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
  }
  // @End [4VxXXC96]
  ll K; cin >> K;
  // @InpMVec(K, ((C, dec=1), (D, dec=1))) [OdSyDdYv]
  auto C = vector(K, ll());
  auto D = vector(K, ll());
  for (int i = 0; i < K; i++) {
    ll v1; cin >> v1; v1 -= 1; C[i] = v1;
    ll v2; cin >> v2; v2 -= 1; D[i] = v2;
  }
  // @End [OdSyDdYv]

  ll ans = 0;
  REP(x, 0, 1LL << K) {
    vector<bool> P(N);
    REP(i, 0, K) {
      if (x >> i & 1) P[C[i]] = true;
      else            P[D[i]] = true;
    }
    ll cur = 0;
    REP(i, 0, M) {
      cur += (P[A[i]] and P[B[i]]);
    }
    ans = max(ans, cur);
  }
  cout << ans << endl;
  return 0;
}

