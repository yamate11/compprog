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

  ll N; cin >> N;
  // @InpVec(N, T) [5rJwIvMV]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [5rJwIvMV]
  ll M; cin >> M;
  // @InpMVec(M, ((P, dec=1), X)) [5cWCHaIe]
  auto P = vector(M, ll());
  auto X = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; P[i] = v1;
    ll v2; cin >> v2; X[i] = v2;
  }
  // @End [5cWCHaIe]

  ll tot = accumulate(ALL(T), 0LL);
  REP(i, 0, M) {
    cout << tot + X[i] - T[P[i]] << "\n";
  }

  return 0;
}

