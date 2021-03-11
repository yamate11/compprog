#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

void reduce(ll& a, ll& b) {
  ll g = gcd(a, b);
  a /= g;
  b /= g;
}

int main() {
  ll n, m, k; cin >> n >> m >> k;
  ll n_save = n;
  reduce(n, k);
  reduce(m, k);
  if (k >= 3) {
    cout << "NO\n";
  }else {
    if (k == 2) {
      if (2 * n <= n_save) n *= 2;
      else                 m *= 2;
    }
    cout << "YES\n0 0\n" << n << " 0\n0 " << m << "\n";
  }
  return 0;
}

