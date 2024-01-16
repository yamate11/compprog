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

  auto solve = [&]() -> bool {
    ll T; cin >> T;
    ll N; cin >> N;
    // @InpVec(N, A) [DVM0qK6m]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [DVM0qK6m]
    ll M; cin >> M;
    // @InpVec(M, B) [3puGK4dz]
    auto B = vector(M, ll());
    for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
    // @End [3puGK4dz]
    ll j = 0;
    REP(i, 0, M) {
      while (j < N and A[j] < B[i] - T) j++;
      if (j == N) return false;
      if (B[i] < A[j]) return false;
      j++;
    }
    return true;

  };
  cout << (solve() ? "yes\n" : "no\n");


  return 0;
}

