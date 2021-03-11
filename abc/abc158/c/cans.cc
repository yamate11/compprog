#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:nnDivCeil)
// --> f:nnDivCeil
// ---- inserted function nnDivCeil from util.cc
// Natural Number Division and Ceiling
ll nnDivCeil(ll x, ll y) {
  return (x + (y - 1)) / y;
}
// ---- end nnDivCeil
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B; cin >> A >> B;

  ll x = max(10*B, nnDivCeil(100*A, 8));
  if (x < 10 * B + 10 && 8 * x < 100 * (A + 1)) {
    cout << x << endl;
  }else {
    cout << -1 << endl;
  }

  return 0;
}

