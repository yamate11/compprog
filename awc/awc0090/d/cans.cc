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
// published at https://github.com/yamate11/compprog-clib/blob/master/coordCompr.cc

template <class T = ll, class Compare = std::less<T>>
struct CoordCompr {
  mutable bool built = false;
  mutable vector<T> rev;
  Compare comp;

  CoordCompr() = default;
  explicit CoordCompr(Compare c) : built(false), rev(), comp(move(c)) {}
  explicit CoordCompr(vector<T> v, Compare c = Compare{}) : built(false), rev(std::move(v)), comp(move(c)) {}

  void add(const T& x) { rev.push_back(x); built = false; }

  void add(const vector<T>& v) {
    rev.insert(rev.end(), v.begin(), v.end());
    built = false;
  }

  bool equiv(const T& a, const T& b) const { return !comp(a, b) && !comp(b, a); }

  void build() const {
    if (built) return;
    sort(rev.begin(), rev.end(), comp);
    rev.erase(unique(rev.begin(), rev.end(), [this](const T& a, const T& b) { return equiv(a, b); }),
              rev.end());
    built = true;
  }

  int c(const T& x) const {
    build();
    auto it = lower_bound(rev.begin(), rev.end(), x, comp);
    assert(it != rev.end() && equiv(*it, x));
    return (int)(it - rev.begin());
  }

  const T& d(int i) const {
    build();
    assert(0 <= i and i < (int)rev.size());
    return rev[i];
  }

  int size() const {
    build();
    return (int)rev.size();
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

  ll N, B; cin >> N >> B;
  // @InpMVec(N, (L, R, C)) [bATlvW7g]
  auto L = vector(N, ll());
  auto R = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; L[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [bATlvW7g]

  CoordCompr cc;
  REP(i, 0, N) {
    cc.add(L[i]);
    cc.add(R[i]);
  }
  ll sz = cc.size();
  vector X(sz, 0LL);
  REP(i, 0, N) X[cc.c(L[i])] += C[i];
  vector SX(sz + 1, 0LL);
  REP(i, 0, sz) SX[i + 1] = SX[i] + X[i];
  using ev_tp = tuple<ll, ll, ll>;
  vector<ev_tp> ev;
  // ll END = 0;
  ll START = 1;
  REP(i, 0, N) {
    ev.emplace_back(cc.c(L[i]), START, i);
    // ev.emplace_back(cc.c(R[i]), END, i);
  }
  ranges::sort(ev);
  ll big = 1LL << 60;
  vector<ll> tbl(sz + 1, -big);
  tbl[0] = 0;
  ll eidx = 0;
  REP(t, 0, sz) {
    if (t > 0) updMax(tbl[t], tbl[t - 1]);
    while (eidx < ssize(ev) and get<0>(ev[eidx]) == t) {
      auto [_t, tp, i] = ev[eidx];
      if (tp == START) {
        ll pen = SX[cc.c(R[i])] - SX[t] - C[i];
        updMax(tbl[cc.c(R[i])], tbl[t] + B - pen);
      }
      eidx++;
    }
    tbl[t] -= X[t];
  }
  cout << tbl[sz - 1] << endl;
  return 0;
}

