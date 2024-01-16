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

  auto f = [&](ll a, ll b) -> ll {
    if ((a % 3) == 0) return 0;
    ll ans = b;
    ll p = a / 3;
    ll q = b / 2;
    ll x = p * b;
    ll y = (a - p) * q;
    ll z = (a - p) * (b - q);
    updMin(ans, max(x, max(y, z)) - min(x, min(y, z)));
    p++;
    q = b / 2;
    x = p * b;
    y = (a - p) * q;
    z = (a - p) * (b - q);
    updMin(ans, max(x, max(y, z)) - min(x, min(y, z)));
    return ans;
  };

  ll H, W; cin >> H >> W;
  ll ans = min(f(H, W), f(W, H));
  cout << ans << endl;

  return 0;
}

