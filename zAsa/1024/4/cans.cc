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

// @@ !! LIM(UnionFind ipoint)

// ---- inserted library file UnionFind.cc

struct UFDummyAlg {
  static UFDummyAlg zero;
  UFDummyAlg(int x = 0) {}
  UFDummyAlg operator -() const { return *this; }
  UFDummyAlg operator +(const UFDummyAlg& o) const { return *this; }
};
UFDummyAlg UFDummyAlg::zero;

template<typename T = UFDummyAlg, typename oplus_t = decltype(plus<T>()), typename onegate_t = decltype(negate<T>())>
struct UnionFind {

  struct GroupInfo {
    UnionFind& uf;
    vector<vector<int>> _groups;
    GroupInfo(UnionFind& uf_) : uf(uf_), _groups(uf.size) {
      for (int j = 0; j < uf.size; j++) {
        if (uf.leader(j) == j) {
          _groups[j].resize(uf.group_size(j));
          _groups[j].resize(0);
        }
      }
      for (int j = 0; j < uf.size; j++) _groups[uf.leader(j)].push_back(j);
    }
    const vector<int>& group(int i) { return _groups[uf.leader(i)]; }
  };

  int size;
  T zero;
  oplus_t oplus;
  onegate_t onegate;
  vector<int> _leader;
  vector<optional<T>> _pot;
  vector<int> _gsize;
  int _num_groups;
  static constexpr bool _with_pot = not is_same_v<T, UFDummyAlg>;
  
  UnionFind() : size(0), zero((T)0), oplus(plus<T>()), onegate(negate<T>()),
                _leader(0), _pot(0), _gsize(0), _num_groups(0) {}

  UnionFind(int size_, T zero_ = (T)0, oplus_t oplus_ = plus<T>(), onegate_t onegate_ = negate<T>())
    : size(size_), zero(zero_), oplus(oplus_), onegate(onegate_),
      _leader(size, -1), _pot(0), _gsize(size, 1), _num_groups(size) {
    if constexpr (_with_pot) _pot.resize(size, zero);
  }

  void set_size(int size_) {
    size = size_;
    _leader.resize(size, -1);
    if constexpr (_with_pot) _pot.resize(size, zero);
    _gsize.resize(size, 1);
  }

  int merge(int i, int j, T p) {
    int li = leader(i);
    int lj = leader(j);
    optional<T> ld_p;
    if constexpr (_with_pot) {
      if (_pot[i] and _pot[j]) ld_p = oplus(p, oplus(*_pot[j], onegate(*_pot[i])));
      else                     ld_p = nullopt;
    }
    if (li == lj) {
      if constexpr (_with_pot) { if (not (ld_p and *ld_p == zero)) _pot[li] = nullopt; }
      return lj;
    }
    _num_groups--;
    if (_gsize[lj] < _gsize[li]) {
      swap(li, lj);
      if constexpr (_with_pot) if (ld_p) ld_p = onegate(*ld_p);
    }
    // lj is the newleader
    _gsize[lj] += _gsize[li];
    _leader[li] = lj;
    if constexpr (_with_pot) {
      if (_pot[lj] and _pot[li]) _pot[li] = ld_p;
      else _pot[lj] = nullopt;
    }
    return lj;
  }

  template<typename U = T>
  enable_if_t<is_same_v<U, UFDummyAlg>, int> merge(int i, int j) { return merge(i, j, zero); }

  void _leaderpot(int i) {
    int oj = _leader[i];
    if (oj < 0) return;
    int nj = _leader[i] = leader(oj);
    if constexpr (_with_pot) {
      if (_pot[nj]) _pot[i] = oplus(*_pot[i], *_pot[oj]);
      else _pot[i] = nullopt;
    }
  }
  int leader(int i) {
    _leaderpot(i);
    return _leader[i] < 0 ? i : _leader[i];
  }
  optional<T> pot(int i)  { _leaderpot(i); return _pot[i]; }

  int group_size(int i) { return _gsize[leader(i)]; }

  int num_groups() { return _num_groups; }

  GroupInfo group_info() { return GroupInfo(*this); }

};

template<typename T = UFDummyAlg>
auto makeUnionFind(int size, T zero, auto oplus, auto onegate) {
  return UnionFind<T, decltype(oplus), decltype(onegate)>(size, zero, oplus, onegate);
}

// ---- end UnionFind.cc

// ---- inserted library file ipoint.cc

struct IPoint {
  ll x;
  ll y;
  IPoint(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}

  IPoint rotate(int r = 1) const {
    ll rd = r % 4;
    ll rr = r >= 0 ? rd : rd == 0 ? 0 : rd + 4;
    if      (rr == 0) return IPoint( x,  y);
    else if (rr == 1) return IPoint(-y,  x);
    else if (rr == 2) return IPoint(-x, -y);
    else if (rr == 3) return IPoint( y, -x);
    assert(0);
  }

  IPoint mirror_x() const { return IPoint(x, -y); }
  IPoint mirror_y() const { return IPoint(-x, y); }

  auto operator<=>(const IPoint&) const = default;   // This generates ==, !=, <, >, <=, >=.

  IPoint& operator +=(const IPoint& o) {
    x += o.x;
    y += o.y;
    return *this;
  }

  IPoint& operator -=(const IPoint& o) {
    x -= o.x;
    y -= o.y;
    return *this;
  }

  IPoint& operator *=(ll k) {
    x *= k;
    y *= k;
    return *this;
  }

  IPoint operator +(const IPoint& o) const { return IPoint(x, y) += o; }
  IPoint operator -(const IPoint& o) const { return IPoint(x, y) -= o; }
  IPoint operator *(ll k) const { return IPoint(x, y) *= k; }
  IPoint operator -() const { return IPoint(-x, -y); }

  bool parallel(const IPoint o) const { return x * o.y == y * o.x; }

  // For "argument sort".  The origin is treated as the maximum.
  static bool lt_arg(const IPoint& p1, const IPoint& p2) {
    bool b1 = p1.y > 0 or (p1.y == 0 and p1.x > 0);
    bool b2 = p2.y > 0 or (p2.y == 0 and p2.x > 0);
    if (b1 != b2) return b1;
    else return p1.x * p2.y > p1.y * p2.x;
  }

};
    
IPoint operator *(ll k, const IPoint& p) { return p * k; }
istream& operator >>(istream& is, IPoint& p) {
  ll x_, y_; is >> x_ >> y_;
  p.x = x_;
  p.y = y_;
  return is;
}
ostream& operator <<(ostream& os, const IPoint& p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

namespace std {
  template<>
  struct hash<IPoint> {
    std::size_t operator()(const IPoint& p) const {
      static const uint64_t frand = chrono::steady_clock::now().time_since_epoch().count();
      static const uint64_t a = (frand ^ 0x9e3779b97f4a7c15) | 1;
      static const uint64_t b = (frand ^ 0xbf58476d1ce4e5b9) | 1;
      return a * (uint64_t)p.x + b * (uint64_t)p.y;
    }
  };
}


// ---- end ipoint.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  UnionFind<IPoint> uf(N);
  REP(i, 0, M) {
    ll a, b; cin >> a >> b; a--; b--;
    IPoint p; cin >> p;
    uf.merge(b, a, p);
  }
  REP(i, 0, N) {
    if (uf.leader(i) != uf.leader(0)) {
      cout << "undecidable\n";
    }else {
      auto p = *uf.pot(i) - *uf.pot(0);
      cout << p.x << " " << p.y << "\n";
    }
  }
  return 0;
}

