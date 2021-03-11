#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, k, s; cin >> n >> m >> k >> s;
  vector<int> A(n);
  rep(i, n) {
    cin >> A[i];
    A[i]--;
  }
  vector<vector<pair<int, int>>> G(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back({v, 1});
    G[v].push_back({u, 1});
  }
  vector<vector<int>> d(k, vector<int>(n, inf));
  auto bfs = [&](int k, int n, vector<vector<pair<int, int>>>& G) {
    vector<int> dist(n, inf);
    queue<pair<int, int>> q;
    rep(i, n) {
      if(A[i] == k) {
        q.push({i, 0});
        dist[i] = 0;
      }
    }
    vector<bool> vis(n);
    while(!q.empty()) {
      auto [cur, d] = q.front(); q.pop();
      if(vis[cur]) continue;
      if(dist[cur] < d) continue;
      vis[cur] = true;
      for(auto [ne, cost]: G[cur]) {
        if(dist[ne] > dist[cur] + cost) {
          dist[ne] = dist[cur] + cost;
          q.push({ne, dist[ne]});
        }
      }
    }
    return dist;
  };
  rep(i, k) d[i] = bfs(i, n, G);
  rep(i, n) {
    vector<int> v;
    rep(j, k) v.push_back(d[j][i]);
    sort(all(v));
    cout << accumulate(begin(v), begin(v)+s, 0) << ' ';
  }
  cout << endk;
  return 0;
}
