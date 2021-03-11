#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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

  ll K; cin >> K;
  string S, T; cin >> S >> T;
  vector<ll> tak(10), aok(10), rem(10, K);
  for (ll i = 0; i < 4; i++) {
    tak[S[i] - '0']++;
    rem[S[i] - '0']--;
    aok[T[i] - '0']++;
    rem[T[i] - '0']--;
  }
  double ans = 0.0;
  auto calc = [&](const auto& vec, ll t) {
    ll ret = 0;
    for (ll i = 1; i <= 9; i++) {
      ll v = vec[i];
      if (i == t) v++;
      ret += i * power<ll>(10, v);
    }
    return ret;
  };

  for (ll i = 1; i <= 9; i++) {
    if (rem[i] == 0) continue;
    for (ll j = 1; j <= 9; j++) {
      if (rem[j] == 0) continue;
      ll mark_tak = calc(tak, i);
      ll mark_aok = calc(aok, j);
      if (mark_tak > mark_aok) {
        double prob1, prob2;
        prob1 = double(rem[i]) / (9 * K - 8);
        if (i == j) {
          prob2 = double(rem[j] - 1) / (9 * K - 8 - 1);
        }else {
          prob2 = double(rem[j]) / (9 * K - 8 - 1);
        }
        ans += prob1 * prob2;
      }
    }
  }
  cout << ans << endl;

  return 0;
}

