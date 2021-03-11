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
  set<int> fromOne;
  vector<int> toN;
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    if (a == 1) fromOne.insert(b);
    if (b == N) toN.push_back(a);
  }
  for (int x : toN) {
    if (fromOne.count(x) > 0) {
      cout << "POSSIBLE\n";
      return 0;
    }
  }
  cout << "IMPOSSIBLE\n";
  

  return 0;
}

