#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  ll R, B;
  ll x, y;
  cin >> R >> B;
  cin >> x >> y;

  ll l, r;
  ll res = 0;
  l = 0, r = min(R/x, B);
  while(l <= r) {
    ll m0, m1;
    ll a, b;
    m0 = l + (r-l) / 3;
    m1 = l + (r-l) / 3 * 2;
    a = m0 + min((B-m0)/y, R-m0*x);
    b = m1 + min((B-m1)/y, R-m1*x);
    res = max(res, max(a,b));
    if(a > b) {
      r = m1-1;
    }
    else {
      l = m0+1;
    }
  }
  cout << res << endl;
}
