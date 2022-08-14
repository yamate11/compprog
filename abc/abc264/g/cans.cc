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

using pll = pair<ll, ll>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector one(26, 0LL);
  vector two(26, vector(26, 0LL));
  vector three(26, vector(26, vector(26, 0LL)));
  REP(i, N) {
    string t; cin >> t;
    ll p; cin >> p;
    if (SIZE(t) == 1) one[t[0] - 'a'] = p;
    else if (SIZE(t) == 2) two[t[0] - 'a'][t[1] - 'a'] = p;
    else if (SIZE(t) == 3) three[t[0] - 'a'][t[1] - 'a'][t[2] - 'a'] = p;
  }
  const ll big = 1e18;
  /*
  auto enc = [&](ll a, ll b) -> ll { return 26 * a + b; };
  auto dec = [&](ll e) -> pll { return pll(e / 26, e % 26); };
  */
  ll sz = 26 * 26;
  vector tbl(26, vector(26, -big));
  REP(c1, 26) REP(c2, 26) tbl[c1][c2] = one[c1] + one[c2] + two[c1][c2];
  REP(_t, sz) {
    bool changed = false;
    REP(p, 26) REP(q, 26) REP(c, 26) {
      bool b = updMax(tbl[q][c], tbl[p][q] + one[c] + two[q][c] + three[p][q][c]);
      if (b) changed = true;
    }
    if (not changed) {
      ll vmax = -big;
      REP(p, 26) {
        vmax = max(vmax, one[p]);
        REP(q, 26) vmax = max(vmax, tbl[p][q]);
      }
      cout << vmax << endl;
      return 0;
    }
  }
  cout << "Infinity\n";

  return 0;
}

