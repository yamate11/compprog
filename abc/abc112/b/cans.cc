#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, T; cin >> N >> T;
  int cmin = 10000;
  for (int i = 0; i < N; i++) {
    int c, t; cin >> c >> t;
    if (t <= T) cmin = min(cmin, c);
  }
  if (cmin == 10000) {
    cout << "TLE\n";
  }else {
    cout << cmin << endl;
  }


  return 0;
}

