#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, R; cin >> N >> R;
  if (N >= 10) {
    cout << R << endl;
  }else {
    cout << 100 * (10 - N) + R << endl;
  }

  return 0;
}

