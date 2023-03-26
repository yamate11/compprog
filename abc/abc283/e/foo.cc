#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  if (long long ab; not __builtin_smulll_overflow(a, b, &ab) and ab <= c) {
    cout << "YES\n";
  }else {
    cout << "NO\n";
  }

}
