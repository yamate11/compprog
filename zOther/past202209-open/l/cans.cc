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
  // @InpVec(N, A) [2iutszXc]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [2iutszXc]

  // @InpMVec(M, (P, (Q, dec=1), L, R)) [LigmBl5C]
  auto P = vector(M, ll());
  auto Q = vector(M, ll());
  auto L = vector(M, ll());
  auto R = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; P[i] = v1;
    ll v2; cin >> v2; v2 -= 1; Q[i] = v2;
    ll v3; cin >> v3; L[i] = v3;
    ll v4; cin >> v4; R[i] = v4;
  }
  // @End [LigmBl5C]

  vector tbl_init(9, 0LL);
  auto tbl = tbl_init;
  REP(i, 0, N) {
    auto prev = tbl;
    REP(r, 0, 9) {
      
    }
  }

  return 0;
}

