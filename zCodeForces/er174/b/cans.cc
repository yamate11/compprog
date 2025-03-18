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
    ll N, M; cin >> N >> M;
    // @InpGrid(N, M, A) [0Rdduvyd]
    auto A = vector(N, vector(M, ll()));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; A[i][j] = v; }
    // @End [0Rdduvyd]
    unordered_set<ll> ssA;
    unordered_set<ll> ssB;
    REP(i, 0, N) REP(j, 0, M) {
      ssA.insert(A[i][j]);
      if (j + 1 < M and A[i][j] == A[i][j + 1]) ssB.insert(A[i][j]);
      if (i + 1 < N and A[i][j] == A[i + 1][j]) ssB.insert(A[i][j]);
    }
    ll p1 = ssize(ssA) - ssize(ssB);
    ll p2 = ssize(ssB);
    ll ans;
    if (p2 > 0) {
      ans = 2 * (p2 - 1) + 1 * p1;
    }else {
      ans = p1 - 1;
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

