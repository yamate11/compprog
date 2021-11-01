#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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

  ll N; cin >> N;
  using sta = pair<ll, ll>;
  vector<sta> XA;
  ll tot = 0;
  for (ll i = 0; i < N; i++) {
    ll x, a; cin >> x >> a;
    XA.emplace_back(x, a);
    tot += a;
  }
  XA.emplace_back(0, 0);
  sort(XA.begin(), XA.end());
  ll z = find(XA.begin(), XA.end(), sta(0, 0)) - XA.begin();
  const ll big = 1e15;
  auto tbl = vector(N + 1, vector(N + 1, vector(2, vector(N + 1, -big))));
  for (ll rem = 0; rem <= N; rem++) {
    for (ll isL = 0; isL <= 1; isL++) {
      tbl[z][z][isL][rem] = 0;
    }
  }
  for (ll l = z; l >= 0; l--) {
    auto [lx, la] = XA[l];
    for (ll r = z; r <= N; r++) {
      auto [rx, ra] = XA[r];
      for (ll isL = 0; isL <= 1; isL++) {
        ll orig = isL ? lx : rx;
        for (ll rem = 0; rem <= N; rem++) {
          for (ll newIsL = 0; newIsL <= 1; newIsL++) {
            for (ll take = 0; take <= 1; take++) {
              ll newL = l, newR = r, newRem = rem, newT;
              ll destIdx;
              if (newIsL) {
                if (l-1 < 0) continue;
                destIdx = newL = l - 1;
                newR = r;
              }else {
                if (r+1 > N) continue;
                newL = l;
                destIdx = newR = r + 1;
              }
              auto [dest, valA] = XA[destIdx];
              newT = tbl[l][r][isL][rem] - abs(orig - dest) * rem;
              if (take) {
                if (rem == 0) continue;
                newRem--;
                newT += valA;
              }
              updMax(tbl[newL][newR][newIsL][newRem], newT);
            }
          }
        }
      }
    }
  }
  ll ans = -big;
  for (ll l = 0; l <= N; l++) {
    for (ll r = l; r <= N; r++) {
      for (ll isL = 0; isL <= 1; isL++) {
        ans = max(ans, tbl[l][r][isL][0]);
      }
    }
  }
  cout << ans << endl;

  return 0;
}

