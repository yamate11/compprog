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

// @@ !! LIM(coordCompr f:updMaxMin)

// ---- inserted library file coordCompr.cc

template<typename T = ll, typename MAP = unordered_map<T, int>>
class CoordCompr {
  bool built;
  MAP mp;
                       // map from an original value to a compressed value
  vector<T> rev;      // vector of original values

  void build() {
    built = true;
    sort(rev.begin(), rev.end());
    rev.erase(unique(rev.begin(), rev.end()), rev.end());
    mp = MAP();
    for (size_t i = 0; i < rev.size(); i++) mp[rev[i]] = i;
  }

public:

  CoordCompr() : built(false) {}
  CoordCompr(const vector<T>& vec) : built(false), rev(vec) {}
  CoordCompr(vector<T>&& vec) : built(false), rev(move(vec)) {}

  void add(const T& x) {
    rev.push_back(x);
    built = false;
  }

  void add(const vector<T>& vec) {
    for (const T& x : vec) rev.push_back(x);
    built = false;
  }

  int c(const T& x) {
    if (! built) build();
    return mp[x];
  }

  T d(int i) {
    if (! built) build();
    return rev[i];
  }

  int size() {
    if (! built) build();
    return rev.size();
  }

};

// ---- end coordCompr.cc

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

  ll N, K; cin >> N >> K;
  // @InpMVec(N, (X, Y)) [gj3nSGgC]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [gj3nSGgC]

  CoordCompr ccx, ccy;
  REP(i, 0, N) {
    ccx.add(X[i]);
    ccy.add(Y[i]);
  }
  ll szx = ccx.size();
  ll szy = ccy.size();
  vector P(szx, vector(szy, 0LL));
  REP(i, 0, N) P[ccx.c(X[i])][ccy.c(Y[i])] = 1;
  vector Q(szx + 1, vector(szy + 1, 0LL));
  REP(x, 1, szx + 1) REP(y, 1, szy + 1) Q[x][y] = P[x - 1][y - 1];
  REP(x, 1, szx + 1) REP(y, 1, szy + 1) Q[x][y] += Q[x - 1][y];
  REP(x, 1, szx + 1) REP(y, 1, szy + 1) Q[x][y] += Q[x][y - 1];

  ll big = 4e18;
  ll ans = big;
  REP(x0, 0, szx) REP(x1, x0 + 1, szx) REP(y0, 0, szy) REP(y1, y0 + 1, szy) {
    ll t = Q[x1 + 1][y1 + 1] + Q[x0][y0] - Q[x1 + 1][y0] - Q[x0][y1 + 1];
    if (t >= K) {
      ll lenx = ccx.d(x1) - ccx.d(x0);
      ll leny = ccy.d(y1) - ccy.d(y0);
      updMin(ans, lenx * leny);
    }
  }
  cout << ans << endl;

  return 0;
}

