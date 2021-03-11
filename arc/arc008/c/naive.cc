#include<bits/stdc++.h>

using namespace std;


int main()
{
  int N;
  int X[1000], Y[1000], T[1000], R[1000];
  double g[1000][1000], cost[1000];
  bool v[1000] = {};
  fill_n(cost, 1000, 1e9);


  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i] >> T[i] >> R[i];
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      g[i][j] = hypot(X[i] - X[j], Y[i] - Y[j]) / min(T[i], R[j]);
    }
  }

  cost[0] = 0;
  for(int i = 0; i < N; i++) {
    int idx = -1;
    for(int j = 0; j < N; j++) if((idx < 0 || cost[idx] >= cost[j]) && !v[j]) idx = j;
    for(int j = 1; j < N; j++) cost[j] = min(cost[j], cost[idx] + g[idx][j]);
    v[idx] = true;
  }
  sort(cost, cost + N);

  double ret = 0;
  for(int i = 1; i < N; i++) ret = max(ret, cost[i] + N - i - 1);
  cout << fixed << setprecision(10) << ret << endl;
}
