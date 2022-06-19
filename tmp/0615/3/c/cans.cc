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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A; cin >> A;
  if (A <= 10) { cout << -1 << endl; return 0; }


  vector<ll> pow10(8);
  pow10[0] = 1;
  REP2(i, 1, 8) pow10[i] = pow10[i - 1] * 10;
  auto f = [&](ll x) -> ll {
    ll e = 0;
    ll p = 1;
    ll z = x;
    while (z > 0) {
      ll y = z % 10;
      e += y * p;
      p *= x;
      z /= 10;
    }
    return e;
  };

  REP(i, 10001) {
    ll x = f(i);
    if (A == x) {
      cout << i << endl;
      return 0;
    }
    if (A < x) {
      cout << -1 << endl;
      return 0;
    }
  }

  return 0;
}

