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

  auto solve = [&]() -> ll {
    ll N, M; cin >> N >> M;
    assert(M == 1);
    // @InpVec(N - 1, A) [BrSr0uax]
    auto A = vector(N - 1, ll());
    for (int i = 0; i < N - 1; i++) { ll v; cin >> v; A[i] = v; }
    // @End [BrSr0uax]
    A.push_back(1);
    // @InpVec(N, B) [l6Nty2qj]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [l6Nty2qj]
    sort(ALL(A));
    sort(ALL(B));
    ll j = 0;
    ll i = 0;
    for (; i < N; i++) {
      for ( ; j < N and B[j] <= A[i]; j++);
      if (j == N) return N - i;
      j++;
    }
    return 0;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

