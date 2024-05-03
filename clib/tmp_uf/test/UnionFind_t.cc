#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(UnionFind ftwo debug)

// ---- inserted library file UnionFind.cc
#line 35 "../UnionFind.cc"

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
#line 21 "../ftwo.cc"

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

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig);

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig);

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st);

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t);
#endif

ostream& operator<< (ostream& os, int8_t x);

// definitions

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ")";
  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig) {
  queue<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig) {
  deque<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop_front();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  bool first = true;
  os << '[';
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st) {
  stack<T> tmp(st);
  os << '[';
  bool first = true;
  while (!tmp.empty()) {
    T& t = tmp.top();
    if (first) first = false;
    else os << ", ";
    os << t;
    tmp.pop();
  }
  os << ']';
  return os;
}

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t) {
  if (t.has_value()) os << "v(" << t.value() << ")";
  else               os << "nullopt";
  return os;
}
#endif

ostream& operator<< (ostream& os, int8_t x) {
  os << (int32_t)x;
  return os;
}

// ---- end f:<<

// ---- inserted library file debug.cc
#line 42 "../debug.cc"
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(bool with_nl, Head&& head) {
  cerr << head;
  if (with_nl) cerr << endl;
}

template <class Head, class... Tail>
void dbgLog(bool with_nl, Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(with_nl, forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DLOGNNL(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

/*
#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL_LIB(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif
*/

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)
#define DUP9(E1,...)   DUP1(E1), DUP8(__VA_ARGS__)
#define DUP10(E1,...)   DUP1(E1), DUP9(__VA_ARGS__)
#define DUP11(E1,...)   DUP1(E1), DUP10(__VA_ARGS__)
#define DUP12(E1,...)   DUP1(E1), DUP11(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP12, DUP11, DUP10, DUP9, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

#if DEBUG_LIB
  #define DLOG_LIB   DLOG
  #define DLOGK_LIB  DLOGK
  #define DLOGKL_LIB DLOGKL
#endif

// ---- end debug.cc

// @@ !! LIM -- end mark --
#line 7 "UnionFind_skel.cc"

template<typename T = int>
struct NaiveUnionFind {
  int size;
  vector<int> _leader;
  vector<optional<T>> _pot;
  vector<vector<int>> _member;

  NaiveUnionFind(int size_) : size(size_), _leader(size), _pot(size), _member(size) {
    for (int i = 0; i < size; i++) {
      _leader[i] = i;
      _pot[i] = (T)0;
      _member[i].push_back(i);
    }
  }
  int merge(int i, int j, optional<T> p = nullopt) {
    DLOGK("naive merge", i, j, p);
    int new_leader = _leader[j];
    int old_leader = _leader[i];
    if (new_leader == old_leader and not _pot[i]) {
      if (not p or *_pot[i] != *_pot[j] + *p) {
        for (int x : _member[new_leader]) _pot[x] = nullopt;
      }
      return new_leader;
    }
    bool pot_consis = p and _pot[j] and _pot[i];
    T pdiff = pot_consis ? *p + *_pot[j] - *_pot[i] : (T)0;
    if (not pot_consis) {
      for (int x : _member[new_leader]) _pot[x] = nullopt;
    }
    for (int x : _member[old_leader]) {
      _leader[x] = new_leader;
      _member[new_leader].push_back(x);
      if (pot_consis) _pot[x] = *_pot[x] + pdiff;
      else _pot[x] = nullopt;
    }
    _member[old_leader].resize(0);
    DLOG("naive merge result");
    for (int x = 0; x < size; x++) {
      DLOGK(x, _leader[x], _pot[x], _member[x]);
    }
    return new_leader;
  }

  pair<int, optional<T>> leaderpot(int i) {
    return {_leader[i], _pot[i]};
  }

  int leader(int i) { return _leader[i]; }

  int groupSize(int i) { return _member[_leader[i]].size(); }

  int numGroups() {
    int ret = 0;
    for (int i = 0; i < size; i++) if (_leader[i] == i) ret++;
    return ret;
  }

  const vector<int>& group(int i) { return _member[_leader[i]]; }

};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  {
    UnionFind uf1(6);
    assert(uf1.leader(0) != uf1.leader(5));
    assert(uf1.group_size(5) == 1);
    uf1.merge(0, 5);
    assert(uf1.num_groups() == 5);
    assert(uf1.leader(0) == uf1.leader(5));
    assert(uf1.group_size(5) == 2);
    assert(uf1.group_size(0) == 2);
    uf1.merge(1, 3);
    uf1.merge(2, 5);
    assert(uf1.num_groups() == 3);
    assert(uf1.group_size(2) == 3);
    assert(uf1.leader(0) == uf1.leader(2));
    assert(uf1.leader(1) == uf1.leader(3));
    assert(uf1.leader(4) != uf1.leader(0));
    assert(uf1.leader(0) != uf1.leader(1));

    auto gi3 = uf1.group_info();
    assert(gi3.group(2) == vector<int>({0, 2, 5}));
    assert(gi3.group(3) == vector<int>({1, 3}));
  }

  {
    for (int _z = 0; _z < 10000; _z++) {
      DLOG("****");
      int n = randrange(1, 11);
      UnionFind<ll> uf(n);
      NaiveUnionFind nuf(n);
      for (int _rep = 0; _rep < 30; _rep++) {
        int a = randrange(0, n);
        int b = randrange(0, n);
        int la = uf.leader(a);
        auto pa = uf.pot(a);
        int lb = uf.leader(b);
        auto pb = uf.pot(b);
        auto [nla, npa] = nuf.leaderpot(a);
        auto [nlb, npb] = nuf.leaderpot(b);
        assert(la == uf.leader(a));
        assert(lb == uf.leader(b));
        DLOGK(a, b, la, lb, nla, nlb);
        assert ((la == lb) == (nla == nlb));
        if (la == lb) {
          DLOGKL("equiv", a, b, la, lb, pa, pb, npa, npb);
          assert(pa and pb and npa and npb and *pa - *pb == *npa - *npb);
        }else {
          int p = randrange(-10, 11);
          DLOGKL("merge", b, a, p);
          int i = uf.merge(b, a, p);
          int j = nuf.merge(b, a, p);
          DLOGK(i, j, nuf.leaderpot(b), nuf.leaderpot(a));
          DLOGKL("uf", uf._leader);
          assert(uf.leader(j) == uf.leader(a) and uf.leader(j) == uf.leader(b));
          assert(nuf.leader(i) == nuf.leader(a) and nuf.leader(i) == nuf.leader(b));
          for (int k = 0; k < n; k++) {
            if (uf.leader(k) == i) {
              if (*nuf._pot[k] - *nuf._pot[i] != *uf.pot(k) - *uf.pot(i)) {
                DLOGK(k, i, *nuf._pot[k], *nuf._pot[i], *uf.pot(k), *uf.pot(i));
                assert(false);
              }
            }
          }
        }
        if (_rep == n) {
          for (int i = 0; i < n; i++) {
            assert(uf.num_groups() == nuf.numGroups());
            assert(uf.group_size(i) == nuf.groupSize(i));
            auto gi = uf.group_info();
            auto v1 = gi.group(i);
            auto v2 = nuf.group(i);
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            assert(v1 == v2);
          }
        }
      }
    }
  }


  {
    UnionFind<ll> uf(6);
    uf.merge(3, 1, 20);
    int ld = uf.merge(0, 1, -10);
    assert(ld >= 0);
    int ld3 = uf.leader(3);
    auto p3 = uf.pot(3);
    int ld0 = uf.leader(0);
    auto p0 = uf.pot(0);
    assert(ld3 == ld0 and *p3 - *p0 == 30);
    uf.merge(3, 0, 40);
    assert(not uf.pot(0) and not uf.pot(3));
  }

  {
    UnionFind<ll> uf(13);
    uf.merge(0, 1, 3);
    uf.merge(1, 2, 1);
    uf.merge(4, 1, 2);
    uf.merge(3, 4, -4);
    int rc1 = uf.merge(2, 3, 1);
    assert(rc1 >= 0);
    uf.merge(5, 7, 0);
    uf.merge(9, 5, -2);
    uf.merge(7, 6, 3);
    int rc2 = uf.merge(9, 6, 1);
    assert(rc2 >= 0);
    uf.merge(8, 7, 1);
    uf.merge(10, 11, 2);
    uf.merge(10, 12, 3);
    int rc3 = uf.merge(12, 11, -1);
    assert(rc3 >= 0);
    assert(uf.leader(0) == uf.leader(1));
    assert(uf.leader(0) == uf.leader(2));
    assert(uf.leader(0) == uf.leader(3));
    assert(uf.leader(0) == uf.leader(4));
    assert(uf.leader(0) != uf.leader(5));
    assert(uf.leader(5) == uf.leader(6));
    assert(uf.leader(5) == uf.leader(7));
    assert(uf.leader(5) == uf.leader(8));
    assert(uf.leader(5) == uf.leader(9));
    assert(uf.leader(5) != uf.leader(10));
    assert(*uf.pot(0) - *uf.pot(3) == 5);
    assert(*uf.pot(8) - *uf.pot(6) == 4);
    assert(*uf.pot(4) - *uf.pot(0) == -1);
    auto gi = uf.group_info();
    vector<int> v1(gi.group(3));
    for (int i = 0; i < 13; i++) assert(uf.group_size(i) == (int)gi.group(i).size());
  }


  {
    UnionFind<Ftwo> uf(6);
    uf.merge(4, 3, 1);
    uf.merge(3, 2, 1);
    int rc = uf.merge(4, 2, 0);
    assert(rc >= 0);
    assert(uf.leader(4) == uf.leader(2));
    int ld4 = uf.leader(4);
    auto pot4 = uf.pot(4);
    int ld2 = uf.leader(2);
    auto pot2 = uf.pot(2);
    assert(uf.leader(4) == ld4 and uf.leader(2) == ld2);
    assert(pot4 == pot2);
    assert(uf.group_size(4) == 3);
    auto gi = uf.group_info();
    auto v = gi.group(3);
    sort(v.begin(), v.end());
    assert(v == (vector<int>{2, 3, 4}));
  }

  cout << "test done." << endl;
}
