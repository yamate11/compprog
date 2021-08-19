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

  ll N, D, K; cin >> N >> D >> K;
  using sta = pair<ll, ll>;
  vector<sta> SP;
  for (ll i = 0; i < N; i++) {
    ll p, s; cin >> p >> s; p--;
    SP.emplace_back(s, p);
  }
  sort(SP.begin(), SP.end());
  using stb = pair<ll, ll>;
  vector<vector<stb>> PS(2);
  for (ll i = 0; i < N; i++) {
    auto [s, p] = SP[i];
    PS[p].emplace_back(s, i);
  }
  for (ll p = 0; p < 2; p++) PS[p].emplace_back(1e18, N);
  vector<ll> tbl(N + 1);
  auto nxtEv = [&](ll p, ll t) -> ll {
    auto [s, i] = *lower_bound(PS[p].begin(), PS[p].end(), stb(t, -1));
    return i;
  };
  for (ll i = 0; i < N; i++) {
    auto [s, p] = SP[i];
    ll newCnt = tbl[i] + 1;
    ll i2 = nxtEv(p, s + 1);
    updMax(tbl[i2], newCnt);
    ll i3 = nxtEv(1-p, s + 1 + D + K * newCnt);
    updMax(tbl[i3], newCnt);
  }
  cout << tbl[N] << endl;

  return 0;
}

