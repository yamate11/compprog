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

using pll = pair<ll, ll>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  CoordCompr cc;
  ll N, M, Q; cin >> N >> M >> Q;
  vector<ll> A(M), B(M), C(M), QX(Q), QY(Q), QZ(Q), QW(Q);
  REP(i, M) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--; B[i]--; C[i]--;
    cc.add(B[i]);
    cc.add(C[i]);
  }
  REP(q, Q) {
    ll x, y, z, w; cin >> x >> y >> z >> w; x--; y--; z--; w--;
    if (y > w) { swap(x, z); swap(y, w); }
    QX[q] = x; QY[q] = y; QZ[q] = z; QW[q] = w;
    cc.add(x); cc.add(y); cc.add(z); cc.add(w);
  }
  REP(i, M) { B[i] = cc.c(B[i]); C[i] = cc.c(C[i]); }
  REP(q, Q) { QY[q] = cc.c(QY[q]), QW[q] = cc.c(QW[q]); }
  vector BC(N, vector<pll>({-1, -1}, {1e11, 1e11}));
  REP(i, M) BC[A[i]].emplace_back(B[i], C[i]);
  REP(m, N) {
    auto& vec = BC[m];
    if (vec.empty()) continue;
    sort(ALL(vec));
    vector<pll> newvec;
    for (ll i = 0; i < SIZE(vec); ) {
      auto [b, c] = vec[i];
      ll j = i + 1;
      for (; j < SIZE(vec) and vec[j].first <= c; j++) c = max(c, vec[j].second);
      newvec.emplace_back(b, c);
      i = j;
    }
    BC[m] = newvec;
  }
  vector<pll> LR = [&]() {
    vector<pll> tmp, ret;
    REP(m, N) for (auto& p : BC[m]) tmp.push_back(p);
    sort(ALL(tmp), [&](pll& p1, pll& p2) -> bool {
      if (p1.first != p2.first) return p1.first < p2.first;
      else                      return p1.second > p2.second;
    });
    ll rmax = -1;
    for (auto [l, r] : tmp) if (rmax < r) { ret.emplace(l, r); rmax = r; }
    return ret;
  }();
  ll sz = cc.size();
  vector tbl(1, vector<ll>(sz));
  for (ll p = 0, i = 0; i < sz; i++) {
    while (p + 1 < sz and LR[p + 1].first <= i) p++;
    if (LR[p].first <= i and i <= LR[p].second) tbl[0][i] = LR[p].second;
    else                                        tbl[0][i] = i;
  }
  for (ll k = 1; true; k++) {
    vector<ll> newlayer(sz);
    REP(i, sz) newlayer[i] = tbl[k - 1][tbl[k - 1][i]];
    if (newlayer == tbl[k - 1]) break;
    tbl.push_back(move(newlayer));
  }
  ll k0 = SIZE(tbl);
  
  auto func3 = [&](ll x, ll y, ll z, ll w) -> ll {
    ll dist = cc.d(w) - cc.d(y);
    auto func2 = [&](auto& vv, ll t, ll dir) -> ll {
      ll idx = lower_bound(vv, pll(t + 1, -1e18)) - vv.begin() - 1;
      auto [l, r] = vv[idx];
      if (l <= t and t <= r) return dir == 1 ? r : l;
      else return t;
    };
    y = func2(BC[x], y, 1);
    w = func2(BC[z], w, -1);
    if (w <= y) return dist + (x == z ? 0 : 1);
    if (tbl[k0 - 1][y] < w) return -1;
    ll num = 0;
    REP2R(k, k0 - 2, 0) {
      if (tbl[k][y] < w) y = tbl[k][y];
      num += (1LL << k);
    }
    return dist + num + 1;
  };
  REP(q, Q) cout << func3(QX[q], QY[q], QZ[q], QW[q]) << "\n";

  return 0;
}

