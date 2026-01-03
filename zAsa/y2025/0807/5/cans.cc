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

  ll N, M; cin >> N >> M;
  vector<ll> cost(M);
  vector<ll> unlock(M);
  REP(i, 0, M) {
    ll a, b; cin >> a >> b;
    cost[i] = a;
    REP(j, 0, b) {
      ll c; cin >> c; c--;
      unlock[i] |= (1LL << c);
    }
  }
  ll big = 1e18;
  vector<ll> tbl(1LL << N, big);
  tbl[0] = 0;
  REP(i, 0, M) {
    REPrev(x, (1LL << N) - 1, 0) {
      if (tbl[x] < big) {
        updMin(tbl[x | unlock[i]], tbl[x] + cost[i]);
      }
    }
  }
  ll ans = tbl[(1LL << N) - 1];
  if (ans == big) ans = -1;
  cout << ans << endl;
  return 0;
}

