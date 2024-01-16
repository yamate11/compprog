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

  ll N, M, K; cin >> N >> M >> K;
  // @InpVec(N, A) [EDeG2FXM]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [EDeG2FXM]

  ll ans = 0;
  REPrev(k, 30, 0) {
    ll t = 1LL << k;
    vector<ll> B, C;
    REP(i, 0, SIZE(A)) {
      assert(A[i] < 2 * t);
      if (A[i] & t) {
        B.push_back(A[i] ^ t);
      }else {
        C.push_back(A[i]);
      }
    }
    if (SIZE(B) >= K) {
      ans |= t;
      A = move(B);
    }else {
      sort(ALL(C), greater<ll>());
      ll p = 0;
      ll lack = K - SIZE(B);
      REP(i, 0, lack) p += t - C[i];
      if (p <= M) {
        ans |= t;
        M -= p;
        A = move(B);
        REP(i, 0, lack) A.push_back(0);
      }else {
        A = move(B);
        REP(i, 0, SIZE(C)) A.push_back(C[i]);
      }
    }
  }
  cout << ans << endl;

  return 0;
}

