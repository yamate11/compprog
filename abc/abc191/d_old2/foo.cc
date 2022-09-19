#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

int main() {
  ll t = 9.223372036854775e18;
  ll lim = 1e6;
  vector<ll> v(lim);
  for (ll i = 0; i < lim; i++) {
    v[i] = (ll)((long double)t + (long double)i);
  }
  for (ll i = 0; i < lim - 1; i++) {
    if (v[i] != v[i + 1]) cout << (i + 1) << " " << v[i + 1] << "\n";
  }
}
