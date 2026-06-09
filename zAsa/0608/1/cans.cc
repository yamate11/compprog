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
  // @InpVec(N, A) [FwfR8EKX]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [FwfR8EKX]
  // @InpVec(K, B, dec=1) [Id535aN3]
  auto B = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; B[i] = v; }
  // @End [Id535aN3]

  ll m = *ranges::max_element(A);
  REP(i, 0, K) if (A[B[i]] == m) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";

  return 0;
}

