#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll S, W; cin >> S >> W;
  if (W >= S) {
    cout << "unsafe\n";
  }else {
    cout << "safe\n";
  }

  return 0;
}

