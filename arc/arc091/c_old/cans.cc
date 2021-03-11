#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll solve() {
  ll N, M; cin >> N >> M;
  if (!(N <= M)) swap(N, M);
  if (M == 1) return 1;
  if (N == 1) return M-2;
  return (N-2) * (M-2);
}  

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cout << solve() << endl;
  return 0;
}

