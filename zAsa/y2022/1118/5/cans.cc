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

// @@ !! LIM(coordCompr)

// ---- inserted library file coordCompr.cc

class CoordCompr {
  bool built;
  unordered_map<ll, int> mp;
                       // map from an original value to a compressed value
  vector<ll> rev;      // vector of original values

  void build() {
    built = true;
    sort(rev.begin(), rev.end());
    rev.erase(unique(rev.begin(), rev.end()), rev.end());
    mp = unordered_map<ll, int>();
    for (size_t i = 0; i < rev.size(); i++) mp[rev[i]] = i;
  }

public:

  CoordCompr() : built(false) {}
  CoordCompr(const vector<ll>& vec) : built(false), rev(vec) {}
  CoordCompr(vector<ll>&& vec) : built(false), rev(move(vec)) {}

  void add(ll x) {
    rev.push_back(x);
    built = false;
  }

  void add(const vector<ll>& vec) {
    for (ll x : vec) rev.push_back(x);
    built = false;
  }

  int c(ll x) {
    if (! built) build();
    return mp[x];
  }

  ll d(int i) {
    if (! built) build();
    return rev[i];
  }

  int size() {
    if (! built) build();
    return rev.size();
  }

};

// ---- end coordCompr.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpMVec(N, (X, Y)) [XpQ1TK4w]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [XpQ1TK4w]
  CoordCompr ccx, ccy;
  REP(i, 0, N) ccx.add(X[i]);
  REP(i, 0, N) ccy.add(Y[i]);
  ll szx = ccx.size();
  ll szy = ccy.size();
  vector S(szx + 1, vector(szy + 1, 0LL));
  REP(i, 0, N) S[ccx.c(X[i]) + 1][ccy.c(Y[i]) + 1] += 1;
  REP(x, 1, szx + 1) REP(y, 0, szy + 1) S[x][y] += S[x - 1][y];
  REP(y, 1, szy + 1) REP(x, 0, szx + 1) S[x][y] += S[x][y - 1];
  ll ans = LLONG_MAX;
  REP(x0, 0, szx) REP(x1, x0 + 1, szx + 1) REP(y0, 0, szy) REP(y1, y0 + 1, szy + 1) {
    ll t = S[x1][y1] + S[x0][y0] - S[x0][y1] - S[x1][y0];
    if (t >= K) ans = min(ans, (ccx.d(x1 - 1) - ccx.d(x0)) * (ccy.d(y1 - 1) - ccy.d(y0)));
  }
  cout << ans << endl;

  return 0;
}

