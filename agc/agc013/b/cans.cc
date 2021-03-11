#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, M; cin >> N >> M;
  vector<vector<int>> nbr(N);
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b; a--; b--;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
  }
  vector<bool> onPath(N);
  int x = 0;
  int y = nbr.at(x).at(0);
  onPath.at(x) = onPath.at(y) = true;

  auto sch = [&](int p, int n, auto& vec) {
    auto sub = [&](int t) -> int {
      for (int m : nbr.at(t)) {
	if (m == p) continue;
	if (onPath.at(m)) continue;
	return m;
      }
      return -1;
    };
    vec.push_back(n);
    while (true) {
      int m = sub(n);
      if (m == -1) return;
      vec.push_back(m);
      onPath.at(m) = true;
      p = n;
      n = m;
    }
  };

  vector<int> pXY, pYX;
  sch(x, y, pXY);
  sch(y, x, pYX);
  cout << pXY.size() + pYX.size() << endl;
  for (int i = pYX.size() - 1; i >= 0; i--) {
    cout << pYX.at(i) + 1;
    if (i > 0) cout << " ";
  }
  cout << " ";
  for (int i = 0; i < (int)pXY.size(); i++) {
    cout << pXY.at(i) + 1;
    if (i < (int)pXY.size() - 1) cout << " ";
  }
  cout << endl;

  return 0;
}

