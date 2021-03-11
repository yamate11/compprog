#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, C, K; cin >> N >> C >> K;
  vector<int> T(N);
  for (int i = 0; i < N; i++) cin >> T.at(i);
  sort(T.begin(), T.end());
  int cnt = 0;
  int i = 0;
  while (i < N) {
    int st = T.at(i);
    int j = 1;
    for ( ; j < C && i + j < N && T.at(i + j) <= st + K; j++);
    cnt++;
    i += j;
  }
  cout << cnt << endl;

  return 0;
}

