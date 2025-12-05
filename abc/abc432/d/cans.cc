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

#if !defined(__TEMPLATE_SAFE_CUSTOM_HASH__)
#define __TEMPLATE_SAFE_CUSTOM_HASH__
template <typename T, typename Enable = void>
struct safe_custom_hash;
#endif

template<>
struct safe_custom_hash<IPoint, void> {
  std::size_t operator()(const IPoint& p) const {
    static const uint64_t frand = chrono::steady_clock::now().time_since_epoch().count();
    static const uint64_t a = (frand ^ 0x9e3779b97f4a7c15) | 1;
    static const uint64_t b = (frand ^ 0xbf58476d1ce4e5b9) | 1;
    return a * (uint64_t)p.x + b * (uint64_t)p.y;
  }
};

namespace std {
  template<>
  struct hash<IPoint> {
    std::size_t operator()(const IPoint& p) const { return safe_custom_hash<IPoint, void>()(p); }
  };
}


// ---- end ipoint.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X, Y; cin >> N >> X >> Y;
  // @InpMVec(N, ((C, type=char), A, B)) [34iLLgAm]
  auto C = vector(N, char());
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    char v1; cin >> v1; C[i] = v1;
    ll v2; cin >> v2; A[i] = v2;
    ll v3; cin >> v3; B[i] = v3;
  }
  // @End [34iLLgAm]

  vector<IPoint> vec1(1LL << N);
  vector<IPoint> vec2(1LL << N);
  vec1[0] = IPoint(0, 0);
  vec2[0] = IPoint(X, Y);
  REP(i, 0, N) {
    REP(j, 0, 1LL << i) {
      IPoint p1 = vec1[j];
      IPoint p2 = vec2[j];
      if (p1.x == p2.x) continue;
      ll a = 1LL << i;
      if (C[i] == 'X') {
        if (p2.x <= A[i]) {
          vec1[j] = IPoint(p1.x, p1.y - B[i]);
          vec2[j] = IPoint(p2.x, p2.y - B[i]);
        }else if (A[i] <= p1.x) {
          vec1[j] = IPoint(p1.x, p1.y + B[i]);
          vec2[j] = IPoint(p2.x, p2.y + B[i]);
        }else {
          vec1[j]     = IPoint(p1.x, p1.y - B[i]);
          vec2[j]     = IPoint(A[i], p2.y - B[i]);
          vec1[a | j] = IPoint(A[i], p1.y + B[i]);
          vec2[a | j] = IPoint(p2.x, p2.y + B[i]);
        }
      }else if (C[i] == 'Y') {
        if (p2.y <= A[i]) {
          vec1[j] = IPoint(p1.x - B[i], p1.y);
          vec2[j] = IPoint(p2.x - B[i], p2.y);
        }else if (A[i] <= p1.y) {
          vec1[j] = IPoint(p1.x + B[i], p1.y);
          vec2[j] = IPoint(p2.x + B[i], p2.y);
        }else {
          vec1[j]     = IPoint(p1.x - B[i], p1.y);
          vec2[j]     = IPoint(p2.x - B[i], A[i]);
          vec1[a | j] = IPoint(p1.x + B[i], A[i]);
          vec2[a | j] = IPoint(p2.x + B[i], p2.y);
        }
      }else assert(0);
    }
  }
  UnionFind uf(1LL << N);
  vector<ll> area(1LL << N, 0LL);
  REP(i, 0, 1LL << N) if (vec1[i].x < vec2[i].x) {
    area[i] = (vec2[i].x - vec1[i].x) * (vec2[i].y - vec1[i].y);
  }
  auto contact = [&](ll i, ll j) -> bool {
    auto sub2 = [&](ll IPoint::* p, ll IPoint::* q) -> bool {
      return (vec1[i].*p == vec2[j].*p)
        and  (not (vec2[j].*q <= vec1[i].*q or vec2[i].*q <= vec1[j].*q));
    };
    return sub2(&IPoint::x, &IPoint::y) or sub2(&IPoint::y, &IPoint::x);
  };
  REP(i, 0, 1LL << N) {
    if (vec1[i].x == vec2[i].x) continue;
    REP(j, i + 1, 1LL << N) {
      if (vec1[j].x == vec2[j].x) continue;
      if (contact(i, j) or contact(j, i)) {
        ll a = uf.leader(i);
        ll b = uf.leader(j);
        if (a != b) {
          ll c = uf.merge(a, b);
          area[c] = area[a] + area[b];
        }
      }
    }
  }
  vector<ll> ans;
  REP(i, 0, 1LL << N) {
    if (uf.leader(i) == i and vec1[i].x < vec2[i].x) ans.push_back(area[i]);
  }
  ranges::sort(ans);
  cout << ssize(ans) << endl;
  REPOUT(i, 0, ssize(ans), ans[i], " ");


  return 0;
}

