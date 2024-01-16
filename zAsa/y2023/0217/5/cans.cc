#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

enum f22 {ZERO, ONE, ID, NEG};

f22 composition(f22 x, f22 y) {
  if (x == ZERO or x == ONE) return x;
  else if (x == ID) return y;
  else if (x == NEG) {
    if (y == ZERO) return ONE;
    else if (y == ONE) return ZERO;
    else if (y == ID) return NEG;
    else if (y == NEG) return ID;
    else assert(0);
  }else assert(0);
 };

ll apply(f22 x, ll a) {
  if (x == ZERO) return 0;
  else if (x == ONE) return 1;
  else if (x == ID) return a;
  else if (x == NEG) return 1 - a;
  else assert(0);
 };

int main(/* int argc, char *argv[] */) {
  ll N, C; cin >> N >> C;
  ll K = 30;
  vector f(N, vector<f22>(K));
  REP(i, 0, N) {
    ll t, a; cin >> t >> a;
    auto fset = [&](f22 x0, f22 x1) -> void {
      REP(k, 0, K) f[i][k] = (a >> k & 1) ? x1 : x0;
    };
    if (t == 1)      fset(ZERO, ID);
    else if (t == 2) fset(ID, ONE);
    else if (t == 3) fset(ID, NEG);
    else assert(0);
  }
  vector<f22> v(K, ID);
  ll y = C;
  REP(i, 0, N) {
    ll x = 0;
    REP(k, 0, K) {
      v[k] = composition(f[i][k], v[k]);
      x |= apply(v[k], y >> k & 1) << k;
    }
    cout << x << "\n";
    y = x;
  }

  return 0;
}

