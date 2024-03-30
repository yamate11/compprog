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

  ll H, W, N; cin >> H >> W >> N;
  // @InpGrid(N, 4, X) [Yv5LuQmU]
  auto X = vector(N, vector(4, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < 4; j++) { ll v; cin >> v; X[i][j] = v; }
  // @End [Yv5LuQmU]

  auto cx = [&](ll i) -> ll {
    if (i < N) return X[i][0];
    if (i < 2*N) return X[i - N][2];
    if (i == 2*N) return 1;
    if (i == 2*N + 1) return H;
    assert(0);
  };
  auto cy = [&](ll i) -> ll {
    if (i < N) return X[i][1];
    if (i < 2*N) return X[i - N][3];
    if (i == 2*N) return 1;
    if (i == 2*N + 1) return W;
    assert(0);
  };

  ll big = 1e18;
  vector<ll> dist(2*N + 2, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[2*N] = 0;
  pque.emplace(0, 2*N);
  while (not pque.empty()) {
    auto [d, idx] = pque.top(); pque.pop();
    if (dist[idx] == d) {
      REP(j, 0, 2*N + 2) {
        if (idx == j) continue;
        ll newd;
        if (idx < N and j == idx + N) newd = d + 1;
        else newd = d + abs(cx(idx) - cx(j)) + abs(cy(idx) - cy(j));
        if (newd < dist[j]) {
          dist[j] = newd;
          pque.emplace(newd, j);
        }
      }
    }
  }
  cout << dist[2*N + 1] << endl;

  return 0;
}

