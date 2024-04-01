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
    ll N, K; cin >> N >> K;
    vector A(N, vector(N, 0LL));
    REP(i, 0, N) {
      REP(j, i, N) cin >> A[i][j];
    }
    vector V(N + 1, vector<ll>());
    V[0] = vector<ll>{0};
    using sta = tuple<ll, ll, ll>;
    REP(i, 1, N + 1) {
      priority_queue<sta> pque;
      pque.emplace(A[0][i - 1], -1, -1);
      REP(j, 0, i - 1) {
        pque.emplace(A[j + 1][i - 1] + V[j][0], j, 0);
      }
      pque.emplace(0 + V[i - 1][0], i - 1, 0);
      while (not pque.empty()) {
        auto [v, j, idx] = pque.top(); pque.pop();
        V[i].push_back(v);
        if (ssize(V[i]) == K) break;
        if (j >= 0) {
          if (idx + 1 < ssize(V[j])) {
            ll a = (j < i - 1) ? A[j + 1][i - 1] : 0;
            pque.emplace(a + V[j][idx + 1], j, idx + 1);
          }
        }
      }
    }
    REPOUT(i, 0, ssize(V[N]), V[N][i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

