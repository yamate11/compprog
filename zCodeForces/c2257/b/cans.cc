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

  auto solve = [&]() -> ll {
    ll N, M; cin >> N >> M;
    // @InpVec(N, A) [X3Hm5cgI]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [X3Hm5cgI]
    // @InpVec(M, B) [tinOv0MZ]
    auto B = vector(M, ll());
    for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
    // @End [tinOv0MZ]

    auto f = [&](const auto& X, ll k) -> ll {
      if (k == ssize(X) - 1) return X[k];
      return X[k] - (X[k + 1] - 1);
    };
    auto g = [&](ll t, auto& X, ll& k) -> void {
      X[k] -= t;
      if (k == ssize(X) - 1) {
        if (X[k] == 0) k++;
      }else {
        if (X[k] < X[k + 1]) k++;
      }
    };

    ll i = 0, j = 0;
    while (true) {
      ll t1 = f(A, i);
      ll t2 = f(B, j);
      ll t = min(t1, t2);
      g(t, A, i);
      g(t, B, j);
      if (j == M) return 1;
      if (i == N) return 2;
    }


  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

