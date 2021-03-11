#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll solve() {
  ll N, M; cin >> N >> M;
  if (M == 1) {
    if (N == 1) return 0;
    return N * (N-1) / 2;
  }
  if (N == 1) {
    return M * (M-1) / 2;
  }
  return N * (N-1) / 2 + M * (M-1) / 2;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

