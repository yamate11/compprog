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

  ll x1, y1, r, x2, y2, x3, y3; cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;

  auto out_rec = [&](ll x, ll y) -> bool {
    return not (x2 <= x and x <= x3 and y2 <= y and y <= y3);
  };
  auto out_circ = [&](ll x, ll y) -> bool {
    return (x - x1) * (x - x1) + (y - y1) * (y - y1) > r * r;
  };

  bool b1 = out_rec(x1 + r, y1) or out_rec(x1 - r, y1) or out_rec(x1, y1 + r) or out_rec(x1, y1 - r);
  bool b2 = out_circ(x2, y2) or out_circ(x2, y3) or out_circ(x3, y2) or out_circ(x3, y3);
  cout << (b1 ? "YES\n" : "NO\n");
  cout << (b2 ? "YES\n" : "NO\n");

  return 0;
}

