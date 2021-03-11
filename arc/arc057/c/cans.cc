#include <bits/stdc++.h>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>
typedef long long int ll;
using namespace std;
using namespace boost::multiprecision;

// @@ !! LIM(f:power)
// --> f:power
// ---- inserted function power from util.cc
/* *** WARNING ***  
      ll x = power(10, 12) 
   does not work since it is interpreted as 
      ll x = power<int>((int)10, 12)
   Use power<ll>(10, 12) or power(10LL, 12).
 */
template<typename T>
T power(T a, ll b) {
  T twoPow = a;
  T rv = 1;
  while (b > 0) {
    if (b & 1LL) rv *= twoPow;
    twoPow *= twoPow;
    b >>= 1;
  }
  return rv;
}
// ---- end power
// @@ !! LIM  -- end mark --

cpp_int solve() {
  string s; cin >> s;
  cpp_int lo(s);
  cpp_int lo2 = lo * lo;
  cpp_int hi2 = (lo + 1) * (lo + 1);
  cpp_int th = power(cpp_int(100), s.size());
  while (true) {
    cpp_int p = lo2 / th;
    cpp_int q1 = th * p;
    if (lo2 <= q1 && q1 < hi2)  return p;
    cpp_int q2 = th * (p+1);
    if (lo2 <= q2 && q2 < hi2)  return p+1;
    th /= 100;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

