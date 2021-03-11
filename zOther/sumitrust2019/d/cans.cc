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
  string S; cin >> S;

  int cnt = 0;
  for (int i = 0; i < 10; i++) {
    int t1 = 0;
    while (t1 < N && S.at(t1) - '0' != i) t1++;
    for (int j = 0; j < 10; j++) {
      int t2 = t1 + 1;
      while(t2 < N && S.at(t2) - '0' != j) t2++;
      for (int k = 0; k < 10; k++) {
	int t3 = t2 + 1;
	while (t3 < N && S.at(t3) - '0' != k) t3++;
	if (t3 < N) cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}

