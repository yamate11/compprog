#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(40);

  ll n = 1 << stoi(argv[1]);
  ll t = stoi(argv[2]);
  if (t == 1) {
    double x1 = (double)1 / 3;
    for (int i = 0; i < n; i++) {
      x1 = x1 * x1;
      if (x1 > 1) x1 /= 10;
      if (x1 < 0.1) x1 *= 10;
    }
    cout << int(x1 * 10) << endl;
  }else if (t == 2) {
    long double x1 = (long double)1 / 3;
    for (int i = 0; i < n; i++) {
      x1 = x1 * x1;
      if (x1 > 1) x1 /= 10;
      if (x1 < 0.1) x1 *= 10;
    }
    cout << int(x1 * 10) << endl;
  }else if (t == 3) {
    __float128 x1 = (__float128)1 / 3;
    for (int i = 0; i < n; i++) {
      x1 = x1 * x1;
      if (x1 > 1) x1 /= 10;
      if (x1 < 0.1) x1 *= 10;
    }
    cout << int(x1 * 10) << endl;
  }


  return 0;
}
