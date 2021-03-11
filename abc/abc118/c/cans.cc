#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// g = eGCD(a, b, s, t)  --->  sa + tb = g
constexpr ll eGCD(ll a, ll b, ll& s, ll& t) {
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

constexpr ll gcd(ll a, ll b) {
  ll dummy1 = 0;
  ll dummy2 = 0;
  return eGCD(a, b, dummy1, dummy2);
}


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  int g = 0;
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    if (i == 0) {
      g = a;
      continue;
    }
    g = gcd(g, a);
  }
  cout << g << endl;

  return 0;
}

