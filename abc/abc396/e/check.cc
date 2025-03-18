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

// @@ !! LIM(UnionFind ftwo)

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

// ---- inserted library file ftwo.cc

struct Ftwo {
  int8_t val;

  Ftwo(ll t = 0) { val = t & 1; }
  Ftwo(const Ftwo& t) : val(t.val) {}
  Ftwo& operator =(const Ftwo& t) { val = t.val; return *this; }
  Ftwo& operator =(ll t) { val = (t == 0) ? 0 : 1; return *this; }
  Ftwo& operator =(int t) { val = (t == 0) ? 0 : 1; return *this; }

  Ftwo& operator +=(const Ftwo& t) {
    val ^= t.val;
    return *this;
  }

  Ftwo& operator -=(const Ftwo& t) {
    val ^= t.val;
    return *this;
  }

  Ftwo& operator *=(const Ftwo& t) {
    val &= t.val;
    return *this;
  }

  Ftwo inv() const {
    if (val == 0) {
      cerr << "inv() is called for zero." << endl;
      exit(1);
    }
    return Ftwo(1);
  }

  Ftwo zero() const { return (Ftwo)0; }
  Ftwo one() const { return (Ftwo)1; }
  Ftwo inverse() const { return inv(); }

  Ftwo& operator /=(const Ftwo& t) {
    return (*this) *= t.inv();
  }

  Ftwo operator +(const Ftwo& t) const { return Ftwo(val) += t; }
  Ftwo operator -(const Ftwo& t) const { return Ftwo(val) -= t; }
  Ftwo operator *(const Ftwo& t) const { return Ftwo(val) *= t; }
  Ftwo operator /(const Ftwo& t) const { return Ftwo(val) /= t; }
  Ftwo operator -() const { return Ftwo(-val); }

  bool operator ==(const Ftwo& t) const { return val == t.val; }
  bool operator !=(const Ftwo& t) const { return val != t.val; }
  
  operator ll() const { return val; }

};

Ftwo operator +(int x, const Ftwo& y) { return Ftwo(x) + y; }
Ftwo operator -(int x, const Ftwo& y) { return Ftwo(x) - y; }
Ftwo operator *(int x, const Ftwo& y) { return Ftwo(x) * y; }
Ftwo operator /(int x, const Ftwo& y) { return Ftwo(x) / y; }
Ftwo operator +(ll x, const Ftwo& y) { return Ftwo(x) + y; }
Ftwo operator -(ll x, const Ftwo& y) { return Ftwo(x) - y; }
Ftwo operator *(ll x, const Ftwo& y) { return Ftwo(x) * y; }
Ftwo operator /(ll x, const Ftwo& y) { return Ftwo(x) / y; }
Ftwo operator +(const Ftwo& x, int y) { return x + Ftwo(y); }
Ftwo operator -(const Ftwo& x, int y) { return x - Ftwo(y); }
Ftwo operator *(const Ftwo& x, int y) { return x * Ftwo(y); }
Ftwo operator /(const Ftwo& x, int y) { return x / Ftwo(y); }
Ftwo operator +(const Ftwo& x, ll y) { return x + Ftwo(y); }
Ftwo operator -(const Ftwo& x, ll y) { return x - Ftwo(y); }
Ftwo operator *(const Ftwo& x, ll y) { return x * Ftwo(y); }
Ftwo operator /(const Ftwo& x, ll y) { return x / Ftwo(y); }

istream& operator>> (istream& is, Ftwo& t) {
  ll x; is >> x;
  t = x;
  return is;
}

ostream& operator<< (ostream& os, const Ftwo& t) {
  os << int(t.val);
  return os;
}

/* 
  From a tweet by Noshibukuro (@noshi91)
  https://twitter.com/noshi91/status/1200702280128856064

  getF2Basis<mode>(vs)  ... Returns a basis of the vector space generated by vs
    mode == 0 ... Returning basis is a subset of vs
    mode == 1 ... Returning basis B is triangular.  I.e., B = {b1, b2, ... } with MSB(b_i) > MSB(b_j) if i < j.
*/
template<int mode>
vector<ll> getF2Basis(const vector<ll>& vs) {
  vector<ll> ret;    // original vectors
  vector<ll> aux;    // This set will also be a basis of the vector space.
  for (ll v : vs) {
    ll e = v;
    for (ll b : aux) { e = min(e, e ^ b); }
    if (e) {
      ret.push_back(v);
      aux.push_back(e);
    }
  }
  if constexpr (mode == 0) return ret;
  else if constexpr (mode == 1) {
    sort(aux.begin(), aux.end(), greater<ll>());
    return aux;
  }else static_assert([]{ return false; }(), "mode must be 0 or 1");
}

// ---- end ftwo.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto judge = [&]() -> vector<ll> {

    ll N, M; cin >> N >> M;
    // @InpMVec(M, ((X, dec=1), (Y, dec=1), Z)) [jWmDtZ3s]
    auto X = vector(M, ll());
    auto Y = vector(M, ll());
    auto Z = vector(M, ll());
    for (int i = 0; i < M; i++) {
      ll v1; cin >> v1; v1 -= 1; X[i] = v1;
      ll v2; cin >> v2; v2 -= 1; Y[i] = v2;
      ll v3; cin >> v3; Z[i] = v3;
    }
    // @End [jWmDtZ3s]

    auto op = [&](ll k) -> vector<ll> {
      vector<ll> ret(N);
      UnionFind<Ftwo> uf(N);
      REP(j, 0, M) {
        uf.merge(X[j], Y[j], Ftwo(Z[j] >> k & 1));
      }
      auto gi = uf.group_info();
      REP(a, 0, N) {
        if (uf.leader(a) == a) {
          if (not uf.pot(a)) return vector<ll>{};
          ll cnt0 = 0, cnt1 = 0;
          for (int i : gi.group(a)) {
            if (*uf.pot(i) == Ftwo(0)) cnt0++;
            else cnt1++;
          }
          if (cnt0 >= cnt1) {
            for (int i : gi.group(a)) ret[i] = *uf.pot(i);
          }else {
            for (int i : gi.group(a)) ret[i] = 1 - *uf.pot(i);
          }
        }
      }
      return ret;
    };

    ll K = 32;
    vector<ll> ans(N);
    REP(k, 0, K) {
      auto vec = op(k);
      if (vec.empty()) {
        return vec;
      }
      REP(i, 0, N) ans[i] |= (vec[i] << k);
    }
    return ans;
  };

  auto vec = judge();

  ll z; cin >> z;
  if (z == -1) {
    if (vec.empty()) {
      cout << "OK\n";
    }else {
      cout << "NG\n";
    }
  }else {
    if (vec.empty()) {
      cout << "NG\n";
    }else {
      ll N = ssize(vec);
      vector<ll> cmp(N);
      cmp[0] = z;
      REP(i, 1, N) cin >> cmp[i];
      if (accumulate(ALL(cmp), 0LL) == accumulate(ALL(vec), 0LL)) {
        cout << "OK\n";
      }else {
        cout << "NG\n";
      }
    }
  }
  

  

  return 0;
}

