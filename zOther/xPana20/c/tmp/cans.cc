#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll lim = (ll)1e5;
  double sqLim = sqrt(lim);
  double err = 1e-6;
  for (ll a = 1; a < lim; a++) {
    double sa = sqrt(a);
    if (sa == floor(sa)) continue;
    for (ll b = a; b < lim; b++) {
      double sb = sqrt(b);
      if (sb == floor(sb)) continue;
      double x = sa + sb;
      double y = min(x - floor(x), ceil(x) - x);
      if (y < err) {
	cout << a << " " << b << " " << x << " " << y << endl;
      }
      if (x > sqLim) break;
    }
  }

  return 0;
}

