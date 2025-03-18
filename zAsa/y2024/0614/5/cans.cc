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

  auto g = [&](ll a, ll b, ll c) -> ll {
    ll vmin = min(min(a, b), c);
    ll vmax = max(max(a, b), c);
    return vmax - vmin;
  };

  auto f = [&](ll h, ll w) -> ll {
    ll v = 1e18;
    REP(h0, 1, h) {
      ll ha = h - h0;
      ll ha0 = ha / 2;
      ll ha1 = ha - ha0;
      ll w0 = w / 2;
      ll w1 = w - w0;
      if (ha0 > 0 and ha1 > 0) {
        ll p = g(h0 * w, ha0 * w, ha1 * w);
        v = min(v, p);
      }
      ll q = g(h0 * w, ha * w0, ha * w1);
      v = min(v, q);
    }
    return v;
  };

  ll H, W; cin >> H >> W;
  ll x = f(H, W);
  ll y = f(W, H);
  cout << min(x, y) << endl;
  

  return 0;
}

