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
  vector<queue<int>> A(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int x; cin >> x; x--;
      A.at(i).push(x);
    }
  }
  int ans = N+1;
  vector<bool> done(M);
  for (int z = 0; z < M; z++) {
    vector<int> cnt(M);
    int nmax = 0;
    int narg = -1;
    for (int i = 0; i < N; i++) {
      int j = A.at(i).front();
      int num = ++cnt.at(j);
      if (num > nmax) {
	nmax = num;
	narg = j;
      }
    }
    ans = min(ans, nmax);
    done.at(narg) = true;
    for (int i = 0; i < N; i++) {
      while(!A.at(i).empty() && done.at(A.at(i).front())) A.at(i).pop();
    }
  }
  cout << ans << endl;

  return 0;
}

