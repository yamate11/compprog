#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int s; cin >> s;
  vector<bool> t(1000001);
  int i = 1;
  for ( ; !t.at(s); i++) {
    t.at(s) = true;
    if (s % 2 == 0) {
      s = s / 2;
    }else {
      s = s * 3 + 1;
    }
  }
  cout << i << endl;

  return 0;
}

