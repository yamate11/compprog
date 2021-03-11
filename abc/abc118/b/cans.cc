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
  vector<vector<bool>> fav(N, vector<bool>(M));
  for (int i = 0; i < N; i++) {
    int k; cin >> k;
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a; a--;
      fav.at(i).at(a) = true;
    }
  }
  int cnt = 0;
  for (int j = 0; j < M; j++) {
    bool all = true;
    for (int i = 0; i < N; i++) {
      if (!fav.at(i).at(j)) {
	all = false;
	break;
      }
    }
    if (all) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

