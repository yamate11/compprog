#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;



int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  auto take = [&](int i) -> int {
    int dir = 0;
    for (int j = i + 1; j < N; j++) {
      int diff = A.at(j) - A.at(j-1);
      int newDir = diff > 0 ? 1 : diff == 0 ? 0 : -1;
      if (newDir == 0) {
	// do nothing
      }else if (dir == 0) {
	dir = newDir;
      }else if (dir == newDir) {
	// do nothing
      }else {
	return j;
      }
    }
    return N;
  };

  int cnt = 0;
  for (int i = 0; i < N; i = take(i)) cnt++;
  cout << cnt << endl;
  return 0;
}

