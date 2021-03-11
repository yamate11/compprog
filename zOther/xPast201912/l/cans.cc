#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


using Pair = pair<double, int>;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, M; cin >> N >> M;
  vector<int> X(N+M), Y(N+M), C(N+M);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i) >> C.at(i);
  }
  for (int i = 0; i < M; i++) {
    cin >> X.at(N+i) >> Y.at(N+i) >> C.at(N+i);
  }
  double ans = DBL_MAX;
  for (int x = 0; x < (1<<M); x++) {
    vector<bool> done(N+M);
    for (int i = 0; i < M; i++) if (x & (1<<i)) { done.at(N+i) = true; }
    priority_queue<Pair, vector<Pair>, greater<Pair>> pque;
    pque.emplace(0.0, 0);
    double tot = 0.0;
    while (!pque.empty()) {
      Pair p = pque.top(); pque.pop();
      double d = p.first; int i = p.second;
      if (done.at(i)) continue;
      done.at(i) = true;
      tot += d;
      for (int j = 0; j < N+M; j++) {
	if (done.at(j)) continue;
	double dx = X.at(j) - X.at(i);
	double dy = Y.at(j) - Y.at(i);
	double z = sqrt(dx * dx + dy * dy);
	double t = C.at(i) == C.at(j) ? z : 10*z;
	pque.emplace(t, j);
      }
    }
    ans = min(ans, tot);
  }
  cout << ans << endl;

  return 0;
}

