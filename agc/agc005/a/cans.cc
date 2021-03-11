#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string X; cin >> X;
  int t = 0;
  int s = 0;
  for (int i = 0; i < (int)X.size(); i++) {
    if (X.at(i) == 'S') {
      s++;
    }else if (X.at(i) == 'T') {
      if (s > 0) s--;
      else t++;
    }else {
      assert(false);
    }
  }
  cout << t + s << endl;

  return 0;
}

