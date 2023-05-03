#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(UnionFind ftwo debug)

// ---- inserted library file UnionFind.cc
#line 34 "/home/y-tanabe/proj/compprog/clib/UnionFind.cc"

template<typename T = ll, typename oplus_t = decltype(plus<T>()), typename onegate_t = decltype(negate<T>())>
struct UnionFind {
  int size;
  T zero;
  oplus_t oplus;
  onegate_t onegate;
  vector<pair<int, optional<T>>> _leader;
  vector<int> _gsize;
  bool built_groups;
  vector<vector<int>> _groups;
  
  UnionFind(int size_, T zero_ = (T)0, oplus_t oplus_ = plus<T>(), onegate_t onegate_ = negate<T>())
    : size(size_), zero(zero_), oplus(oplus_), onegate(onegate_), _gsize(size, 1), built_groups(false) {
    for (int i = 0; i < size; i++) _leader.emplace_back(i, zero);
  }

  int merge(int i, int j, optional<T> p = nullopt) {
    built_groups = false;
    auto [li, pi] = leaderpot(i);
    auto [lj, pj] = leaderpot(j);
    if (li == lj) {
      if (not p.has_value()) _leader[li].second = nullopt;
      else if (pi.has_value() and oplus(*p, *pj) != *pi) _leader[li].second = nullopt;
      return li;
    }
    int new_leader, obs_leader; bool chg_sign;
    if (_gsize[li] < _gsize[lj]) {
      new_leader = lj;
      obs_leader = li;
      chg_sign = false;
    }else {
      new_leader = li;
      obs_leader = lj;
      chg_sign = true;
    }
    _gsize[new_leader] += _gsize[obs_leader];
    _leader[obs_leader].first = new_leader;
    if (p.has_value() and pi.has_value() and pj.has_value()) {
      T new_pot = oplus(*p, oplus(*pj, onegate(*pi)));
      if (chg_sign) new_pot = onegate(new_pot);
      _leader[obs_leader].second = new_pot;
    }else {
      _leader[new_leader].second = nullopt;  // Note this is for new_leader
    }
    return new_leader;
  }

  pair<int, optional<T>> leaderpot(int i) {
    int cur = i;
    vector<pair<int, optional<T>>> seen;
    optional<T> pp;
    {
      auto [nxt, p] = _leader[cur];
      while (cur != nxt) {
        seen.emplace_back(cur, p);
        cur = nxt;
        tie(nxt, p) = _leader[cur];
      }
      pp = p;
    }
    while (not seen.empty()) {
      auto [j, p] = seen.back(); seen.pop_back();
      if (pp.has_value()) pp = oplus(pp.value(), p.value());
      _leader[j] = {cur, pp};
    }
    return {cur, pp};
  }

  int leader(int i) { return leaderpot(i).first; }
  optional<T> pot(int i) { return leaderpot(i).second; }

  int groupSize(int i) { return _gsize[leader(i)]; }

  const vector<int>& group(int i) {
    if (not built_groups) {
      _groups.resize(size);
      for (int j = 0; j < size; j++) _groups[j].resize(0);
      for (int j = 0; j < size; j++) _groups[leader(j)].push_back(j);
      built_groups = true;
    }
    return _groups[leader(i)];
  }

};

template<typename T = ll>
auto makeUnionFind(int size, T zero, auto oplus, auto onegate) {
  return UnionFind<T, decltype(oplus), decltype(onegate)>(size, zero, oplus, onegate);
}

// ---- end UnionFind.cc

// ---- inserted library file ftwo.cc
#line 21 "/home/y-tanabe/proj/compprog/clib/ftwo.cc"

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
#line 42 "/home/y-tanabe/proj/compprog/clib/debug.cc"
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
    assert(uf1.groupSize(5) == 1);
    uf1.merge(0, 5);
    assert(uf1.leader(0) == uf1.leader(5));
    assert(uf1.groupSize(5) == 2);
    assert(uf1.groupSize(0) == 2);
    uf1.merge(1, 3);
    uf1.merge(2, 5);
    assert(uf1.groupSize(2) == 3);
    assert(uf1.leader(0) == uf1.leader(2));
    assert(uf1.leader(1) == uf1.leader(3));
    assert(uf1.leader(4) != uf1.leader(0));
    assert(uf1.leader(0) != uf1.leader(1));

    assert(uf1.group(2) == vector<int>({0, 2, 5}));
    assert(uf1.group(3) == vector<int>({1, 3}));

  }

  {
    for (int _z = 0; _z < 10000; _z++) {
      DLOG("****");
      int n = randrange(1, 11);
      UnionFind uf(n);
      NaiveUnionFind nuf(n);
      for (int _rep = 0; _rep < 30; _rep++) {
        int a = randrange(0, n);
        int b = randrange(0, n);
        auto [la, pa] = uf.leaderpot(a);
        auto [lb, pb] = uf.leaderpot(b);
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
          uf.merge(b, a, p);
          nuf.merge(b, a, p);
          DLOGK(nuf.leaderpot(b), nuf.leaderpot(a));
          DLOGKL("uf", uf._leader);
        }
        if (_rep == n) {
          for (int i = 0; i < n; i++) {
            assert(uf.groupSize(i) == nuf.groupSize(i));
            auto v1 = uf.group(i);
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
    UnionFind uf(6);
    uf.merge(3, 1, 20);
    int ld = uf.merge(0, 1, -10);
    assert(ld >= 0);
    auto [ld3, p3] = uf.leaderpot(3);
    auto [ld0, p0] = uf.leaderpot(0);
    assert(ld3 == ld0 and *p3 - *p0 == 30);
    uf.merge(3, 0, 40);
    assert(not uf.pot(0) and not uf.pot(3));
  }

  {
    UnionFind uf(13);
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
    vector<int> v1(uf.group(3));
    for (int i = 0; i < 13; i++) assert(uf.groupSize(i) == (int)uf.group(i).size());
  }


  {
    UnionFind<Ftwo> uf(6);
    uf.merge(4, 3, 1);
    uf.merge(3, 2, 1);
    int rc = uf.merge(4, 2, 0);
    assert(rc >= 0);
    assert(uf.leader(4) == uf.leader(2));
    auto [ld4, pot4] = uf.leaderpot(4);
    auto [ld2, pot2] = uf.leaderpot(2);
    assert(uf.leader(4) == ld4 and uf.leader(2) == ld2);
    assert(pot4 == pot2);
    assert(uf.groupSize(4) == 3);
    auto v = uf.group(3);
    sort(v.begin(), v.end());
    assert(v == (vector<int>{2, 3, 4}));
  }

  cout << "test done." << endl;
}
