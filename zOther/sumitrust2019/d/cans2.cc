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
  vector<bool> v1(10);
  vector<vector<bool>> v2(10, vector<bool>(10));
  vector<vector<vector<bool>>>
    v3(10, vector<vector<bool>>(10, vector<bool>(10)));
  for (int i = 0; i < N; i++) {
    int k = S.at(i) - '0';
    for (int p = 0; p < 10; p++) {
      if (v1.at(p)) {
	for (int q = 0; q < 10; q++) {
	  if (v2.at(p).at(q)) v3.at(p).at(q).at(k) = true;
	}
	v2.at(p).at(k) = true;
      }
    }
    v1.at(k) = true;
  }

  int cnt = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
	if (v3.at(i).at(j).at(k)) cnt ++;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}

