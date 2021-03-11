#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<vector <int>> vec({{}, {6}, {6,12}, {6,3,9}, {2,4,3,9}
      , {2,4,6,3,9}, {2,4,6,12,3,9}, {2,4,6,8,10,3,9}, {2,4,6,8,10,12,3,9}});

  vector<int> ans;

  int N; cin >> N;
  if (N == 3) {
    ans = vector<int>({2, 3, 25});
  }else {
    int x = N % 8;
    int y = N / 8;
    if (x == 0) {
      for (int i = 0; i < y; i++) {
	for (int t : vec.at(8)) ans.push_back(i * 12 + t);
      }
    }else {
      ans = vec.at(x);
      for (int i = 1; i <= y; i++) {
	for (int t : vec.at(8)) ans.push_back(i * 12 + t);
      }
    }
  }
    
  bool first = true;
  for (int x : ans) {
    if (!first) cout << " ";
    cout << x;
    first = false;
  }
  cout << endl;

  return 0;
}

