#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll inf = 1e18;

vector<ll> solve(vector<vector<pair<int, ll>>> g, vector<int> P,
                 vector<int> Q) {
  int N = g.size();
  using pa = pair<ll, int>;
  using ppa = pair<pa, int>;
  vector<pa> d1(N, {inf, -1});
  vector<pa> d2(N, {inf, -1});
  set<vector<ll>> vis;
  priority_queue<ppa, vector<ppa>, greater<>> que;

  auto add = [&](int i, ll d, int p) {
    if (d < d1[i].first) {
      if (d1[i].second == p) {
        d1[i] = {d, p};
      } else {
        d2[i] = d1[i];
        d1[i] = {d, p};
      }
      que.emplace(pa{d, p}, i);
    } else if (p != d1[i].second and d < d2[i].first) {
      // p != d1[i].second : ここバグらせポイント
      d2[i] = {d, p};
      que.emplace(pa{d, p}, i);
    }
  };

  for (auto& i : Q) add(i, 0, P[i]);
  while (que.size()) {
    auto [dp, i] = que.top();
    auto [d, p] = dp;
    que.pop();

    // ここ : サボると TLE ポイント
    if (d1[i] != pa{d, p} and d2[i] != pa{d, p}) continue;

    // ここ : サボると TLE ポイント
    if (vis.count(vector<ll>{d, p, i})) continue;
    vis.emplace(vector<ll>{d, p, i});

    for (auto& [dst, w] : g[i]) add(dst, d + w, p);
  }

  vector<ll> ans(N);
  for (int i = 0; i < N; i++) {
    ans[i] = (P[i] == d1[i].second ? d2 : d1)[i].first;
    if (ans[i] == inf) ans[i] = -1;
  }
  return ans;
}

int main() {
  int N, M, K, L;
  cin >> N >> M >> K >> L;

  vector<int> P(N), Q(L);
  for (auto& x : P) cin >> x;
  for (auto& x : Q) cin >> x, --x;

  vector<vector<pair<int, ll>>> g(N);
  for (int i = 0, u, v, w; i < M; i++) {
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  auto ans = solve(g, P, Q);
  for (int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
}
