#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    if (i-1 >= 0 && s.at(i-1) == s.at(i)) {
      cout << i << " " << i+1 << endl;
      return 0;
    }
    if (i-2 >= 0 && s.at(i-2) == s.at(i)) {
      cout << i-1 << " " << i+1 << endl;
      return 0;
    }
  }
  cout << "-1 -1\n";

  return 0;
}

