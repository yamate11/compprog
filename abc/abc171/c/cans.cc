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

string solve() {
  ll n; cin >> n; n--;

  ll k = 1;
  ll lim = 26;
  
  while (true) {
    if (n < lim) {
      string ans;
      for (ll i = 0; i < k; i++) ans += 'a';
      ll p = k-1;
      while (n > 0) {
	ll x = n % 26;
	ans.at(p) = 'a' + x;
	n /= 26;
	p--;
      }
      return ans;
    }
    n -= lim;
    k ++;
    lim *= 26;
  }
}




int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);


  cout << solve() << endl;

  return 0;
}

