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

// @@ !! LIM(f:updMaxMin)

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto f = [&](ll h, ll w) -> ll {
    auto g = [&](ll a, ll b) -> ll {
      vector<ll> p(3);
      p[0] = a * w;
      p[1] = b * (w / 2);
      p[2] = b * (w - w / 2);
      sort(ALL(p));
      return p[2] - p[0];
    };
    ll ret = 1e18;
    if (h % 3 == 0) return 0;
    else ret = w;
    updMin(ret, g(h/3, h - h/3));
    updMin(ret, g(h/3 + 1, h - (h/3 + 1)));
    return ret;
  };


  ll H, W; cin >> H >> W;
  ll x = f(H, W);
  ll y = f(W, H);
  cout << min(x, y) << endl;

  return 0;
}

