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

  ll A, B, Q; cin >> A >> B >> Q;
  vector P(2, vector<ll>());
  ll big = 1e17;
  REP(k, 0, 2) P[k].push_back(-big);
  REP(i, 0, A) {
    ll s; cin >> s;
    P[0].push_back(s);
  }
  REP(i, 0, B) {
    ll t; cin >> t;
    P[1].push_back(t);
  }
  REP(k, 0, 2) P[k].push_back(big);

  REP(i, 0, Q) {
    ll x; cin >> x;
    vector<ll> j(2);
    REP(k, 0, 2) j[k] = lower_bound(ALL(P[k]), x) - P[k].begin();
    ll ans = big;
    REP(a, 0, 2) REP(b, 0, 2) REP(c, 0, 2) {
      updMin(ans, abs(P[a][j[a] - b] - x) + abs(P[a][j[a] - b] - P[1 - a][j[1 - a] - c]));
    }
    cout << ans << "\n";
  }

  return 0;
}

