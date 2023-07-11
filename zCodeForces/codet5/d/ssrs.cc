#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    int u, v, y;
    cin >> u >> v >> y;
    u--;
    v--;
    E[u].push_back(make_pair(y, v));
    E[v].push_back(make_pair(y, u));
  }
  vector<long long> d(n, -1);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  pq.push(make_pair(0, n - 1));
  while (!pq.empty()){
    long long c = pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if (d[v] == -1){
      d[v] = c;
      for (pair<int, int> e : E[v]){
        int w = e.second;
        if (d[w] == -1){
          pq.push(make_pair(c + e.first, w));
        }
      }
    }
  }
  if (d[0] == -1){
    cout << "inf" << endl;
  } else {
    vector<pair<long long, int>> D;
    for (int i = 0; i < n; i++){
      if (d[i] != -1){
        d[i] = min(d[i], d[0]);
        D.push_back(make_pair(d[i], -i));
      }
    }
    sort(D.begin(), D.end(), greater<pair<long long, int>>());
    int n2 = D.size();
    cout << d[0] << ' ' << n2 - 1 << endl;
    for (int i = 0; i < n2 - 1; i++){
      string s(n, '0');
      for (int j = 0; j <= i; j++){
        s[-D[j].second] = '1';
      }
      long long t = D[i].first - D[i + 1].first;
      cout << s << ' ' << t << endl;
    }
  }
}
