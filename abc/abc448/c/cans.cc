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

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [9bCpUQsZ]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [9bCpUQsZ]
  set<pll> ss;
  REP(i, 0, N) {
    ss.emplace(A[i], i);
  }
  REP(q, 0, Q) {
    ll K; cin >> K;
    // @InpVec(K, B, dec=1) [jECDZPup]
    auto B = vector(K, ll());
    for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; B[i] = v; }
    // @End [jECDZPup]
    REP(i, 0, K) {
      ss.erase(pll(A[B[i]], B[i]));
    }
    cout << (*ss.begin()).first << "\n";
    REP(i, 0, K) {
      ss.emplace(A[B[i]], B[i]);
    }
  }


  return 0;
}

