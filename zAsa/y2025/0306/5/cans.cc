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

  ll N, K; cin >> N >> K;
  // @InpVec(N, X, dec=1) [DP6LmL6A]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; X[i] = v; }
  // @End [DP6LmL6A]

  priority_queue<pll> pque;
  REP(i, 0, K) pque.emplace(X[i], i);
  auto [x0, i0] = pque.top();
  cout << i0 + 1 << "\n";
  REP(i, K, N) {
    auto [x, j] = pque.top();
    if (X[i] < x) {
      pque.pop();
      pque.emplace(X[i], i);
    }
    auto [y, k] = pque.top();
    cout << k + 1 << "\n";
  }


  return 0;
}

