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
  // @InpVec(M, P) [Ju89QM9d]
  auto P = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; P[i] = v; }
  // @End [Ju89QM9d]

  REP(ii, 0, N) {
    ll K; cin >> K;
    // @InpVec(K, C, dec=1) [7G7BYglW]
    auto C = vector(K, ll());
    for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; C[i] = v; }
    // @End [7G7BYglW]
    if (K == 0) {
      cout << 0 << "\n";
    }else {
      ll cand = C[0];
      REP(i, 1, K) {
        ll t = C[i];
        if (P[cand] < P[t] or (P[cand] == P[t] and t < cand)) cand = t;
      }
      cout << cand + 1 << "\n";
    }


  }

  return 0;
}

