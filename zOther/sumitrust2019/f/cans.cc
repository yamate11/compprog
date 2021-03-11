#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll T1, T2, A1, A2, B1, B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

  ll v1 = (A1 - B1) * T1;
  ll v2 = (A2 - B2) * T2;
  if (v1 < 0) {
    v1 = -v1;
    v2 = -v2;
  }
  ll w = v1 + v2;
  if (w > 0) {
    cout << "0\n";
    return 0;
  }else if (w == 0) {
    cout << "infinity\n";
    return 0;
  }else {
    ll u = -w;
    if (v1 % u == 0) {
      cout << 2 * v1 / u << endl;
    }else {
      ll k = (v1 + u - 1) / u;
      cout << k * 2 - 1 << endl;
    }
    return 0;
  }
  

  

  return 0;
}

