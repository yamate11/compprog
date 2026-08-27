#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto binom = [&](ll n, ll r) -> ll {
    ll ans = 1;
    REP(i, 0, r) ans *= n - i;
    REP(i, 0, r) ans /= r - i;
    return ans;
  };

  auto repr = [&](ll x) -> string {
    string ret;
    REP(i, 0, 5) {
      REP(j, 0, 5) {
        ll d = x >> (i * 5 + j) & 1;
        ret += (char)('0' + d);
      }
      ret += '\n';
    }
    return ret;
  };

  REP(x, 0, 1LL << 25) {
    vector<ll> cnt(2);
    REP(a, 0, 5) REP(b, 0, 5) REP(c, a, 5) REP(d, b, 5) {
      if (a == c and b == d) continue;
      ll e1 = a * 5 + b;
      ll e2 = c * 5 + d;
      ll v1 = x >> e1 & 1;
      ll v2 = x >> e2 & 1;
      if (v1 == v2) {
        cnt[v1] += binom(c - a + d - b, c - a);
      }
    }
    if (cnt[0] == cnt[1]) {
      cout << repr(x);
      cout << "\n";
    }
  }

  return 0;
}

