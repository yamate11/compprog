#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

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

  ll H, W, N; cin >> H >> W >> N;
  using sta = tuple<ll, ll, ll, ll>;
  vector<sta> ARCI;
  REP(i, N) {
    ll r, c, a; cin >> r >> c >> a; r--; c--;
    ARCI.emplace_back(a, r, c, i);
  }
  sort(ALL(ARCI), greater<sta>());
  vector<ll> recR(H, -1), recC(W, -1);
  vector<ll> ans(N);
  using stb = tuple<ll, ll, ll>;
  ll prev = 1e9;
  vector<stb> pending;
  for (auto [a, r, c, i] : ARCI) {
    if (a < prev) {
      for (auto [rr, cc, vv] : pending) {
        updMax(recR[rr], vv);
        updMax(recC[cc], vv);
      }
      pending.resize(0);
      prev = a;
    }
    ll v = max(recR[r], recC[c]) + 1;
    pending.emplace_back(r, c, v);
    ans[i] = v;
  }
  REP(i, N) cout << ans[i] << "\n";

  return 0;
}

