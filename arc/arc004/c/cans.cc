#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  char dummy;
  ll xx, yy;
  cin >> xx >> dummy >> yy;
  cpp_int X = xx;
  cpp_int Y = yy;
  cpp_int K = (2*X) / Y;
  bool found = false;
  for (cpp_int n = K; n <= K+1; n++) {
    cpp_int p = n * ( Y * (n+1) - 2 * X );
    cpp_int q = 2 * Y;
    if (p % q != 0) continue;
    cpp_int m = p / q;
    if (! ( 1 <= m && m <= n) ) continue;
    found = true;
    cout << n << " " << m << endl;
  }
  if (!found) {
    cout << "Impossible\n";
  }

  return 0;
}

