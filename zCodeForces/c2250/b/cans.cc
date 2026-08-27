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

  auto f = [&](ll n, ll k) -> string {
    string ret;
    if (k % 2 == 0) {
      if (k <= n - 2) {
        REP(i, 0, k / 2 + 1) ret += '0';
        REP(i, 0, k / 2 + 1) ret += '1';
        REP(i, 0, n - (k + 2)) ret += (i % 2 == 0 ? '0' : '1');
        return ret;
      }else {
        return "-1";
      }
    }else {
      if (k <= n - 3) {
        ret = "1";
        REP(i, 0, (k + 1) / 2 + 1) ret += '0';
        REP(i, 0, (k + 1) / 2 + 0) ret += '1';
        REP(i, 0, n - (k + 3)) ret += (i % 2 == 0 ? '0' : '1');
        return ret;
      }else {
        return "-1";
      }
    }
  };

  auto solve = [&]() -> string {
    ll n, k; cin >> n >> k;
    if (n % 2 == 0) {
      return f(n, k);
    }
    else {
      if (k == 0) {
        string ret;
        REP(i, 0, n) ret += (i % 2 == 0 ? '0' : '1');
        return ret;
      }
      string s = f(n - 1, k - 1);
      if (s == "-1") return s;
      ll c = s.back();
      ll c1 = '0' + (1 - (c - '0'));
      if (k == 0) s.push_back(c1);
      else s.push_back(c);
      return s;
    }

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

