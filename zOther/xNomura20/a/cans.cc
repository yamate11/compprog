#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H1, M1, H2, M2, K; cin >> H1 >> M1 >> H2 >> M2 >> K;
  ll x1 = H1 * 60 + M1;
  ll x2 = H2 * 60 + M2;
  ll ans = x2 - x1 - K;
  cout << ans << endl;

  return 0;
}

