#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;

  vector<bool> appear(26);
  if (S.size() < 26) {
    cout << S;
    for (char c : S) appear.at(c - 'a') = true;
    for (int i = 0; i < 26; i++) {
      if (appear.at(i)) continue;
      cout << (char)('a' + i) << endl;
      return 0;
    }
    assert(false);
  }else {
    for (int i = 24; i >= 0; i--) {
      if (S.at(i+1) < S.at(i)) continue;
      cout << S.substr(0, i);
      for (int j = 25; j > i; j--) {
	if (S.at(j) < S.at(i)) continue;
	cout << S.at(j) << endl;
	return 0;
      }
      assert(false);
    }
    cout << "-1\n";
    return 0;
  }
  return 0;
}

