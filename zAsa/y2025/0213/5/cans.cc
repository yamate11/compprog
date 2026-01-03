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

  ll N, T; cin >> N >> T;
  vector AB(N, pll());
  REP(i, 0, N) {
    ll a, b; cin >> a >> b;
    AB[i] = pll(a, b);
  }
  sort(ALL(AB));
  vector tbl(T + 1, -1LL);
  tbl[0] = 0;
  REP(i, 0, N) {
    REPrev(t, T - 1, 0) {
      if (tbl[t] >= 0) {
        ll tt = min(T, t + AB[i].first);
        updMax(tbl[tt], tbl[t] + AB[i].second);
      }
    }
  }
  cout << *max_element(ALL(tbl)) << endl;

  return 0;
}

