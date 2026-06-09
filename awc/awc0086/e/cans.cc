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

  auto cble = [&](const string& s, ll p) -> bool {
    ll n = ssize(s);
    if (p == 0) {
      if (n >= 2 and s[p] != s[p + 1]) return false;
      return true;
    }else if (p == n - 1) {
      if (n >= 2 and s[p - 1] != s[p]) return false;
      return true;
    }else assert(0);
  };

  auto flip = [&](string& s, ll p) -> void {
    assert(0 <= p and p < ssize(s));
    if (s[p] == '0') s[p] = '1';
    else s[p] = '0';
  };

  auto f = [&](const string& s, const string& t) -> ll {
    ll ns = ssize(s);
    ll nt = ssize(t);
    vector tbl(ns + 1, vector(nt + 1, 0LL));
    REP(i, 0, ns) REP(j, 0, nt) {
      if (s[i] == t[j]) tbl[i + 1][j + 1] = tbl[i][j] + 1;
      else tbl[i + 1][j + 1] = max(tbl[i + 1][j], tbl[i][j + 1]);
    }
    return tbl[ns][nt];
  };


  string s, t; cin >> s >> t;
  ll ns = ssize(s);
  ll nt = ssize(t);
  ll K; cin >> K;
  ll ans = 0;
  REP(x, 0, 16) {
    if (popcount((u64)x) > K) continue;
    bool b1 = false;
    bool b2 = false;
    bool b3 = false;
    bool b4 = false;
    if (x >> 0 & 1 and cble(s, 0)) {
      flip(s, 0);
      b1 = true;
    }
    if (x >> 1 & 1 and ns >= 2 and cble(s, ns - 1)) {
      flip(s, ns - 1);
      b2 = true;
    }
    if (x >> 2 & 1 and cble(t, 0)) {
      flip(t, 0);
      b3 = true;
    }
    if (x >> 3 & 1 and nt >= 2 and cble(t, nt - 1)) {
      flip(t, nt - 1);
      b4 = true;
    }
    ll cur = f(s, t);
    ans = max(ans, cur);
    if (b1) flip(s, 0);
    if (b2) flip(s, ns - 1);
    if (b3) flip(t, 0);
    if (b4) flip(t, nt - 1);
  }
  cout << ans << endl;

  return 0;
}

