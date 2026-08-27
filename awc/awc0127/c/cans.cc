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

  auto solve = [&]() -> bool {

    ll N, M, K; cin >> N >> M >> K;
    // @InpVec(N, A) [5XnT2RuD]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [5XnT2RuD]

    ll idx = 0;
    REP(i, 0, M) {
      if (A[idx] > K) return false;
      ll S = A[idx++];
      while (idx < N and S + A[idx] <= K) {
        S += A[idx++];
      }
      if (idx == N) return true;
    }
    return false;
  };
  cout << (solve() ? "No\n" : "Yes\n");

  return 0;
}

