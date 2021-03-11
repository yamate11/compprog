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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];

  if (n == 1) {
    cout << "1 1\n" << -a[0] << "\n1 1\n0\n1 1\n0\n";
    return 0;
  }

  ll s, t;
  ll g = eGCD(n-1, n, s, t);
  assert(g == 1);
  cout << 1 << " " << n - 1 << "\n";
  vector fin(n, 0LL);
  for (ll i = 0; i < n - 1; i++) {
    if (i > 0) cout << " ";
    fin[i] = -s * (n - 1) * a[i];
    cout << fin[i];
    fin[i] += a[i];
  }
  cout << "\n";
  cout << n << " " << n << "\n";
  cout << -a[n-1] << "\n";
  cout << 1 << " " << n << "\n";
  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << -fin[i];
  }
  cout << "\n";

  return 0;
}

