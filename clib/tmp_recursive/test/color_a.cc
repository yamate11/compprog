#include <bits/stdc++.h>
#include <cassert>
using namespace std;

double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

void dfs(const std::vector<std::vector<int>>& graph, std::vector<int>& colors, int u, int c) {
    for(int v : graph[u]) {
        if(colors[v] != -1) continue;
        colors[v] = c;
        dfs(graph, colors, v, c);
    }
}

std::vector<int> color(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<int> colors(n, -1);
    int c = 0;
    for(int i = 0; i < n; ++i) {
        if(colors[i] != -1) continue;
        colors[i] = c;
        dfs(graph, colors, i, c++);
    }
    return colors;
}

int main() {
  int N, M; cin >> N >> M;
  vector<vector<int>> graph(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u--; v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  double t1 = get_time_sec();
  auto ans = color(graph);
  double t2 = get_time_sec();
  cout << t2 - t1 << endl;
  
  // for (int i = 0; i < N; i++) cout << ans[i] << " ";
  // cout << endl;

  // For preventing over-optimization
  int s = 0;
  for (int i = 0; i < N; i++) s ^= ans[i];
  cerr << s << endl;
}
