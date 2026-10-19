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

  auto solve = [&]() -> bool {
    ll a, b, c, d, e, f, g, h; cin >> a >> b >> c >> d >> e >> f >> g >> h;
    ll diff = 0;
    bool from_Alice = true;
    if (h % 2 != 0) {
      diff += 2;
      from_Alice = false;
    }
    if (f < g) {
      ll x = g - f;
      ll q = x / 2;
      ll r = x % 2;
      if (r == 0) diff += q;
      else {
        if (from_Alice) diff += q + 2;
        else diff += q - 1;
        from_Alice = not from_Alice;
      }
    }else if (f > g) {
      ll x = f - g;
      ll q = x / 2;
      ll r = x % 2;
      if (r == 0) diff -= q;
      else {
        if (from_Alice) diff -= q - 1;
        else diff -= q + 2;
        from_Alice = not from_Alice;
      }
    }
    if (e % 2 != 0) {
      if (from_Alice) diff += 1;
      else            diff -= 1;
      from_Alice = not from_Alice;
    }
    if (c < d) {
      ll x = d - c;
      ll q = x / 2;
      ll r = x % 2;
      if (r == 0) diff += q;
      else {
        if (from_Alice) diff += q + 1;
        else diff += q;
        from_Alice = not from_Alice;
      }
    }else if (c > d) {
      ll x = c - d;
      ll q = x / 2;
      ll r = x % 2;
      if (r == 0) diff -= q;
      else {
        if (from_Alice) diff -= q;
        else            diff -= q + 1;
        from_Alice = not from_Alice;
      }
    }
    diff += 2 * (b - a);


    if (diff > 0) return false;
    else return true;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << (solve() ? "Bob\n" : "Alice\n");

  return 0;
}

