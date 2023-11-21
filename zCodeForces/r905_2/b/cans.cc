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
    ll N, K; cin >> N >> K;
    // @InpVec(N, A) [jPdCE8Ej]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [jPdCE8Ej]

    vector vec(K, 0LL);
    REP(i, 0, N) vec[A[i] % K]++;

    if (K == 4) {
      if (vec[0] > 0) return 0;
      if (vec[2] >= 2) return 0;
      if (vec[3] > 0) return 1;
      if (vec[2] == 1 and vec[1] > 0) return 1;
      if (vec[2] == 1 and vec[1] == 0) return 2;
      if (vec[2] == 0 and vec[1] == 1) return 3;
      return 2;
    }else {
      if (vec[0] > 0) return 0;
      REP(i, 1, K) if (vec[K - i] > 0) return i;
      assert(0);
    }

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

