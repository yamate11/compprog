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
  // @InpVec(M, X) [GFEdmcWc]
  auto X = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; X[i] = v; }
  // @End [GFEdmcWc]
  sort(ALL(X));

  vector<ll> G(M - 1);
  REP(i, 0, M - 1) G[i] = X[i + 1] - X[i];
  sort(ALL(G), greater<ll>());
  ll ans = 0;
  REP(i, N - 1, M - 1) ans += G[i];
  cout << ans << endl;

  return 0;
}

