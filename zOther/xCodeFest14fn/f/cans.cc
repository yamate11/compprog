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

  ll N; cin >> N;
  vector<ll> B(N);
  for (ll i = 0; i < N; i++) cin >> B.at(i);
  vector<bool> ok(N+2);
  for (ll i = 0; i < N; i++) {
    ll g = gcd(B.at((i - 1 + N) % N), B.at((i + 1) % N));
    ok.at(i) = B.at(i) % g == 0;
  }
  ok.at(N) = ok.at(0);
  ok.at(N+1) = ok.at(1);
  ll ans = N + 10;
  for (ll j = 0; j < 3; j++) {
    ll i = j;
    ll fix = 0;
    while (i < N + j) {
      while (i < N + j && ok.at(i)) i++;
      if (i < N + j) {
	fix++;
	i += 3;
      }
    }
    ans = min(ans, fix);
  }
  cout << ans << endl;

  return 0;
}

