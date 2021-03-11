#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;

  int ans = 1000;
  for (char c = 'a'; c <= 'z'; c++) {
    int des = 0;
    int l = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s.at(i) == c) {
	des = max(des, l);
	l = 0;
      }else {
	l++;
      }
    }
    des = max(des, l);
    ans = min(ans, des);
  }
  cout << ans << endl;

  return 0;
}

