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
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
	int t = 0;
	while (t < N && S.at(t) - '0' != i) t++;
	t++;
	while (t < N && S.at(t) - '0' != j) t++;
	t++;
	while (t < N && S.at(t) - '0' != k) t++;
	if (t < N) cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}

