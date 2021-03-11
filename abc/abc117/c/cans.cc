#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int solve() {
  int N, M; cin >> N >> M;
  vector<int> X(M);
  if (N >= M) return 0;
  for (int i = 0; i < M; i++) cin >> X.at(i);
  sort(X.begin(), X.end());
  vector<int> D(M-1);
  for (int i = 0; i < M-1; i++) D.at(i) = X.at(i+1) - X.at(i);
  sort(D.begin(), D.end(), greater<int>());
  int y = 0;
  for (int i = 0; i < N-1; i++) y += D.at(i);
  return X.at(M-1) - X.at(0) - y;
}  

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cout << solve() << endl;

  return 0;
}

