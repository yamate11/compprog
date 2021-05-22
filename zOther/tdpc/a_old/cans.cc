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
  vector<bool> tbl(N*100+1);
  tbl.at(0) = true;
  for (int i = 0; i < N; i++) {
    int p; cin >> p;
    for (int x = i*100; x >= 0; x--) {
      if (tbl.at(x)) tbl.at(x + p) = true;
    }
  }
  int ans = 0;
  for (int i = 0; i <= N*100; i++) {
    if (tbl.at(i)) ans++;
  }
  cout << ans << endl;

  return 0;
}

