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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    ll M = 1 << N;
    // @InpVec(M, P) [mb2KblWX]
    auto P = vector(M, ll());
    for (int i = 0; i < M; i++) { ll v; cin >> v; P[i] = v; }
    // @End [mb2KblWX]
    auto func = [&](auto rF, ll i, ll len) -> void {
      if (len == 1) return;
      ll k = len / 2;
      rF(rF, i, k);
      rF(rF, i + k, k);
      if (P[i] > P[i + k]) {
        REP(j, 0, k) swap(P[i + j], P[i + k + j]);
      }
    };
    func(func, 0, M);
    REPOUT(i, 0, M, P[i], " ");
  };


  ll T; cin >> T;
  REP(i, 0, T) solve();

  return 0;
}

