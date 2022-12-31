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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM(input f:updMaxMin)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

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

  ll N, M, K; cin >> N >> M >> K;
  using sta = tuple<ll, ll, ll>;
  vector<sta> edge(M);
  vector fwd(N, vector<pll>());
  REP(i, 0, M) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    edge[i] = sta(a, b, c);
    fwd[a].emplace_back(b, c);
  }
  ll big = 1e18;
  auto tbl = vector(N, big);
  tbl[0] = 0;
  REP(i, 0, K) {
    ll e; cin >> e; e--;
    auto [a, b, c] = edge[e];
    updMin(tbl[b], tbl[a] + c);
  }
  ll ans = tbl[N - 1];
  if (ans == big) ans = -1;
  cout << ans << endl;

  return 0;
}

