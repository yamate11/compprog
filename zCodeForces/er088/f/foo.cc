#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(40);

  double x1 = 1.0 / 3.0;
  long double x2 = (long double)1 / 3;
  __float128 x3 = (__float128)1 / 3;

  for (int i = 0; i < 40; i++) {
    double y = x1 * 10;
    int d = int(y);
    cout << d;
    x1 = y - d;
  }
  cout << endl;
  for (int i = 0; i < 40; i++) {
    long double y = x2 * 10;
    int d = int(y);
    cout << d;
    x2 = y - d;
  }
  cout << endl;
  for (int i = 0; i < 40; i++) {
    __float128 y = x3 * 10;
    int d = int(y);
    cout << d;
    x3 = y - d;
  }
  cout << endl;


  return 0;
}
