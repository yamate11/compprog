#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


void updMax(int& ref, int v) {
  ref = max(ref, v);
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, T; cin >> N >> T;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);
  vector<vector<int>> dp(T+1, vector<int>(2));
  for (int i = 0; i < N; i++) {
    for (int t = T; t > 0; t--) {
      for (int k = 0; k < 2; k++) {
	if (t - A.at(i) >= 0) updMax(dp.at(t).at(k),
				     dp.at(t - A.at(i)).at(k) + B.at(i));
	if (k == 1 && t - 1 >= 0) updMax(dp.at(t).at(1),
					 dp.at(t-1).at(0) + B.at(i));
      }
    }
  }
  cout << dp.at(T).at(1) << endl;

  return 0;
}

