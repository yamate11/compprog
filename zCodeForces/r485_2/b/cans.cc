#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

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
  T rv(1);
  while (b > 0) {
    if (b & 1LL) rv *= twoPow;
    twoPow *= twoPow;
    b >>= 1;
  }
  return rv;
}

// ad-hoc power function
template<typename T, typename Op>
T ah_power(T a, ll b, const T& unit_t, Op op) {
  T two_pow = a;
  T ret = unit_t;
  while (b > 0) {
    if (b & 1LL) ret = op(ret, two_pow);
    two_pow = op(two_pow, two_pow);
    b >>= 1;
  }
  return ret;
}
// ---- end power
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> char {
    ll x, y; cin >> x >> y;
    if (x == y) return '=';
    if (x == 1 && y > 1) return '<';
    if (x > 1 && y == 1) return '>';
    if (x < 10 && y < 10) {
      ll p = power<ll>(x, y);
      ll q = power<ll>(y, x);
      if (p < q) return '<';
      else if (p == q) return '=';
      else return '>';
    }
    if (x > y) return '<';
    else return '>';
  };

    
  cout << solve() << endl;

  return 0;
}

