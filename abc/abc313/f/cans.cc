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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(mapget coordCompr f:updMaxMin)

// ---- inserted library file mapget.cc

template<typename MP>
struct mgs : MP {
  using Key = typename MP::key_type;
  using T = typename MP::mapped_type;

  T def;

  mgs(const T& def_ = T()) : MP(), def(def_) {}
  mgs(const mgs& o) : MP(o), def(o.def) {}
  mgs(mgs&& o) : MP(move(o)), def(move(o.def)) {}
  mgs& operator =(const mgs& o) {
    MP::operator=(o);
    def = o.def;
    return *this;
  }
  mgs& operator =(mgs&& o) {
    MP::operator=(move(o));
    def = move(o.def);
    return *this;
  }

  const T& get(const Key& k) const {
    auto it = this->find(k);
    if (it == this->end()) return def;
    else return it->second;
  }

  template<typename T1>
  void set(const Key& k, T1&& t) {
    if (t == def) this->erase(k);
    else (*this)[k] = forward<T1>(t);
  }
};

// ---- end mapget.cc

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

  ll N, M; cin >> N >> M;
  // @InpMVec(N, (AA, BB)) [jIl0AjN4]
  auto AA = vector(N, ll());
  auto BB = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; AA[i] = v1;
    ll v2; cin >> v2; BB[i] = v2;
  }
  // @End [jIl0AjN4]
  // @InpMVec(M, ((X, dec=1), (Y, dec=1))) [SXZvnnbT]
  auto X = vector(M, ll());
  auto Y = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; v2 -= 1; Y[i] = v2;
  }
  // @End [SXZvnnbT]

  REP(i, 0, M) if (X[i] == Y[i]) {
    ll j = X[i];
    if (AA[j] < BB[j]) swap(AA[j], BB[j]);
  }
  ll base = 0;
  vector<ll> C(N);
  REP(i, 0, N) {
    base += AA[i];
    C[i] = BB[i] - AA[i];
  }
  vector<bool> SP(N, false);
  REP(i, 0, M) {
    if (X[i] == Y[i]) continue;
    if (C[X[i]] >= 0 and C[Y[i]] >= 0) { SP[X[i]] = SP[Y[i]] = true; }
  }
  ll pos = 0, neg = 0;
  ll spv = 0;
  REP(i, 0, N) {
    if (SP[i]) spv += C[i];
    else if (C[i] >= 0) pos++;
    else if (C[i] < 0) neg++;
    else assert(0);
  }
  vector peers(N, vector<ll>());
  REP(i, 0, M) {
    ll x = X[i], y = Y[i];
    if (x == y) continue;
    if (SP[x] or SP[y]) continue;
    if (C[x] < 0 and C[y] < 0) continue;
    peers[x].push_back(y);
    peers[y].push_back(x);
  }
  ll big = 1e18;
  // using mymp = mgs<unordered_map<ll, ll>>;
  if (pos <= neg) {
    CoordCompr cc;
    REP(i, 0, N) if (C[i] >= 0 and not SP[i]) cc.add(i);
    vector<ll> tbl(1LL << pos, -big);
    tbl[0] = 0;
    REP(i, 0, N) {
      if (C[i] < 0) {
        ll t = 0;
        for (ll p : peers[i]) t |= 1LL << cc.c(p);
        auto prev = tbl;
        REP(x, 0, 1LL << pos) {
          updMax(tbl[x | t], prev[x] + C[i]);
        }
      }
    }
    ll vmax = 0;
    REP(x, 0, 1LL << pos) {
      ll v = tbl[x];
      REP(i, 0, N) if (x >> i & 1) v += C[cc.d(i)];
      vmax = max(vmax, v);
    }
    double ans = (double)base + (spv + vmax) / 2.0;
    cout << ans << endl;
  }else {
    CoordCompr cc;
    REP(i, 0, N) if (C[i] < 0) cc.add(i);
    ll vmax = 0;
    REP(x, 0, 1LL << neg) {
      ll t = 0;
      ll v = 0;
      REP(i, 0, neg) if (x >> i & 1) {
        ll j = cc.d(i);
        v += C[j];
        for (ll q : peers[j]) t |= 1LL << q;
      }
      REP(i, 0, N) if (t >> i & 1) v += C[i];
      vmax = max(vmax, v);
    }
    double ans = (double)base + (spv + vmax) / 2.0;
    cout << ans << endl;
  }


  return 0;
}

