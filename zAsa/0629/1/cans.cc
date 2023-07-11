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

  ll N, K, Q; cin >> N >> K >> Q;
  // @InpVec(K, A, dec=1) [RZ9HANqI]
  auto A = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [RZ9HANqI]
  // @InpVec(Q, L, dec=1) [B8zK2sUy]
  auto L = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; v -= 1; L[i] = v; }
  // @End [B8zK2sUy]
  
  vector<bool> B(N);
  REP(i, 0, K) B[A[i]] = true;
  vector<ll> pos(K);
  REP(i, 0, K) pos[i] = A[i];
  REP(q, 0, Q) {
    ll p = pos[L[q]];
    if (p != N - 1 and not B[p + 1]) {
      pos[L[q]]++;
      B[p] = false;
      B[p + 1] = true;
    }
  }
  REPOUT(i, 0, K, pos[i] + 1, " ");

  return 0;
}

