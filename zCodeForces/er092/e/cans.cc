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

  auto solve = [&](ll m, ll d, ll w) -> ll {
    ll g = gcd(d - 1, w);
    ll wp = w / g;
    ll r = min(m, d);

    ll init = r - wp;
    ll diff = wp;
    ll rem = init % diff;
    ll dived = (init - rem) / diff;
    ll num = dived + 1;
    ll sump = dived * num / 2;
    ll sum = diff * sump + num * rem;

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll m, d, w; cin >> m >> d >> w;
    cout << solve(m, d, w) << "\n";
  }

  return 0;
}

