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

  auto solve = [&]() -> void {
    ll R, G, B; cin >> R >> G >> B;
    ll big = 1e18;

    auto check = [&](ll a, ll b, ll c) -> ll {
      if (b < c) swap(b, c);
      if ((b - c) % 3 != 0) return big;
      if ((2 * b + c) % 3 != 0) return big;
      ll cc = (b - c) / 3;
      ll aa = (2 * b + c) / 3;
      return aa + cc;
    };


    ll ans = check(R, G, B);
    updMin(ans, check(B, R, G));
    updMin(ans, check(G, B, R));
    if (ans == big) ans = -1;
    cout << ans << "\n";
  };

  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

