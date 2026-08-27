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

  auto f = [&](const auto& vec) -> vector<ll> {
    vector<ll> ret;
    deque<pll> deq;
    assert(ssize(vec) == N);
    REP(i, 0, N) {
      while (not deq.empty() and deq.back().first <= vec[i]) deq.pop_back();
      deq.emplace_back(vec[i], i);
      if (i >= K - 1) {
        if (deq.front().second == i - K) deq.pop_front();
        assert(not deq.empty());
        ret.push_back(deq.front().first);
      }
    }
    assert(ssize(ret) == N - K + 1);
    return ret;
  };

  // @InpGrid(N, N, A) [5MAB8nnX]
  auto A = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [5MAB8nnX]

  vector B(N - K + 1, vector(N, 0LL));
  REP(j, 0, N) {
    vector<ll> V(N);
    REP(i, 0, N) V[i] = A[i][j];
    auto W = f(V);
    REP(i, 0, N - K + 1) B[i][j] = W[i];
  }
  vector C(N - K + 1, vector<ll>());
  REP(i, 0, N - K + 1) C[i] = f(B[i]);

  vector D(N + 1, vector(N + 1, 0LL));
  REP(i, 0, N) REP(j, 0, N) D[i + 1][j + 1] = A[i][j];
  REP(i, 1, N + 1) REP(j, 1, N + 1) D[i][j] += D[i][j - 1];
  REP(i, 1, N + 1) REP(j, 1, N + 1) D[i][j] += D[i - 1][j];

  ll ans = 0;
  REP(i, 0, N - K + 1) REP(j, 0, N - K + 1) {
    ll x = D[i][j] + D[i + K][j + K] - D[i + K][j] - D[i][j + K];
    ll y = x - C[i][j];
    ans = max(ans, y);
  }
  cout << ans << "\n";
  return 0;
}

