#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  if (N == 1) {
    if (M == 0) {
      cout << "1 2\n";
    }else {
      cout << -1 << endl;
    }
    return 0;
  }

  if (M >= N - 1 || M < 0) {
    cout << -1 << endl;
    return 0;
  }
  for (ll i = 1; i < N; i++) {
    cout << 10 * i + 3 << " " << 10 * i + 5 << "\n";
  }
  cout << 12 << " " << 14 + 10 * M << "\n";

  return 0;
}

