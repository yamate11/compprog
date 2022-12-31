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

/*
  2 <= base <= 10
 */

struct digitplace {
  int base;
  vector<ll> apow;

  digitplace(int base_ = 10) : base(base_), apow() { _mk_apow(); }
  ll str2ll(const string& s) { return stoll(s, 0, base); }
  string ll2str(ll x) {
    string ret;
    for ( ; x > 0; x /= 10) ret.push_back('0' + (x % base));
    reverse(ret.begin(), ret.end());
    return ret;
  }
  void _mk_apow() {
    if (not apow.empty()) return;
    for (ll t = 1; true; t *= base) {
      apow.push_back(t);
      if (t > LLONG_MAX / base) break;
    }
  }
  // Returns m such that base^{m - 1} <= x < base^{m} if x > 0, and 0 if x = 0.
  // Number of digits of x is m, except for x = 0
  int mag(ll x) {
    if (base == 2) {
      if (x == 0) return 0;
      return 64 - __builtin_clzll(x);
    }
    ll ret = 0;
    while (ret < SIZE(apow) and apow[ret] <= x) ret++;
    return ret;
  }
  
};


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K; cin >> K;
  string A, B; cin >> A >> B;
  auto f = [&](string x) -> ll {
    ll ret = 0;
    REP(i, SIZE(x)) ret = ret * K + (x[i] - '0');
    return ret;
  };
  cout << f(A) * f(B) << endl;

  return 0;
}

