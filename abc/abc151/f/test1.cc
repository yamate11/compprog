#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main() {
  complex<double> c(2, 5);
  cout << c << endl;
  complex<double> d(nan(""), nan(""));
  cout << d << endl;
  cout << isnan(c.real()) << " " << isnan(d.real()) << endl;
}
