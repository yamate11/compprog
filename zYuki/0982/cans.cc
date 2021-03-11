#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:gcd)
// --> f:gcd
// ---- inserted function gcd from util.cc
// g = eGCD(a, b, s, t)  --->  sa + tb = g
ll eGCD(ll a, ll b, ll& s, ll& t) {
  if (a == 0) {
    s = 0;
    t = 1;
    return b;
  }
  ll u = 0;
  ll g = eGCD(b % a, a, t, u);
  s = u - (b / a) * t;
  return g;
}

// gcd(0, x) = x, gcd(-x, y) = gcd(x, y)
ll gcd(ll a, ll b) {
  ll dummy1 = 0;
  ll dummy2 = 0;
  return eGCD(abs(a), abs(b), dummy1, dummy2);
}
// ---- end gcd
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B; cin >> A >> B;
  ll g = gcd(A, B);
  if (g > 1) {
    cout << "-1\n";
    return 0;
  }
  vector<bool> vec(A*B);
  ll cnt = A * B;
  for (ll i = 0; i <= B; i++) {
    for (ll j = 0; j <= A; j++) {
      ll x = A * i + B * j;
      if (x < A * B && !vec.at(x)) {
	vec.at(x) = true;
	cnt--;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}

