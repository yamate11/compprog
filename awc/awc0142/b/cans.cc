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

  ll N, M, K, Q; cin >> N >> M >> K >> Q;
  // @InpMVec(N, (V, C)) [QMZ0TdRL]
  auto V = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; V[i] = v1;
    ll v2; cin >> v2; C[i] = v2;
  }
  // @End [QMZ0TdRL]
  // @InpVec(Q, S) [86jI8bhh]
  auto S = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; S[i] = v; }
  // @End [86jI8bhh]
  ll lim = llround(1e5) + 1;
  vector<bool> av(lim);
  REP(i, 0, Q) av[S[i]] = true;
  vector<ll> A;
  REP(i, 0, N) {
    if (av[C[i]]) A.push_back(V[i]);
  }
  ranges::sort(A, greater<ll>());
  ll ans = 0;
  REP(i, 0, min((ll)ssize(A), K)) ans += A[i];
  cout << ans << "\n";

  return 0;
}

