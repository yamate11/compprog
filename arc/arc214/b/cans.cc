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

// @@ !! LIM(input digit UnionFind ftwo debug)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// ---- inserted library file digit.cc

struct digit_util {
  ll base;
  vector<ll> _pow;

  digit_util(ll base_ = 10) : base(base_), _pow() {
    ll t = 1;
    while (true) {
      _pow.push_back(t);
      if (__builtin_smulll_overflow(t, base, &t)) break;
    }
  }
    
  ll pow_size() { return _pow.size(); }
  ll pow(ll i) { return _pow[i]; }

  ll width(ll x) {
    if (x < 0) throw runtime_error("digit.width: x <= 0");
    if (x == 0) return 1;
    ll ret = 0;
    for (; x != 0; x /= base) ret++;
    return ret;
  }

  ll nd_min(ll i) { return pow(i - 1); }
  ll nd_max(ll i) { return nd_min(i + 1) - 1; }

  ll floor(ll x) { return (x == 0) ? 0 : _pow[width(x) - 1]; }

  ll ceil(ll x) {
    if (x == 0) return 0;
    ll p = _pow[width(x) - 1];
    return (x == p) ? p : (p * base);
  }

  ll d_at(ll x, ll i) { return (x / pow(i)) % base; }
  ll v_at(ll x, ll i) { return d_at(x, i) * pow(i); }

  vector<ll> to_vector(ll x) {
    if (x < 0) throw runtime_error("to_vector: x < 0");
    if (x == 0) return vector<ll>{0};
    vector<ll> ret;
    for ( ; x != 0; x /= base) { ret.push_back(x % base); }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  string to_string(ll x, bool upcase = false) {
    char ten = upcase ? 'A' : 'a';
    string ret;
    for (ll d : to_vector(x)) ret.push_back(d < 10 ? '0' + d : ten + (d - 10));
    return ret;
  }

  ll from_vector(const vector<ll>& vec) {
    ll ret = 0;
    for (ll x : vec) ret = ret * base + x;
    return ret;
  }

  ll from_string(string s) {
    vector<ll> vec;
    for (char c : s) {
      ll x;
      if ('0' <= c and c <= '9')      x = c - '0';
      else if ('a' <= c and c <= 'z') x = c - 'a' + 10;
      else if ('A' <= c and c <= 'Z') x = c - 'A' + 10;
      else throw runtime_error("str_to_ll: unknown letter");
      vec.push_back(x);
    }
    return from_vector(vec);
  }

};

// ---- end digit.cc

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

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

template <typename T1, typename T2, typename T3, typename T4, typename T5>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5>& t);

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t);

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

template <typename T, size_t N>
ostream& operator<< (ostream& os, const array<T, N>& v);

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

ostream& operator<< (ostream& os, const __int128& x);

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

template <typename T1, typename T2, typename T3, typename T4, typename T5>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ", " << get<4>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ", " << get<4>(t) << ", " << get<5>(t) << ")";
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

template <typename T, size_t N>
ostream& operator<< (ostream& os, const array<T, N>& v) {
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

// for Enum type; just displays ordinals.
template <typename E>
typename std::enable_if<std::is_enum<E>::value, std::ostream&>::type
operator<<(std::ostream& os, E e) {
    return os << static_cast<typename std::underlying_type<E>::type>(e);
}

// This is a very ad-hoc implementation...
// Known problem: "1 << 127" cannot be handled.
ostream& operator<<(ostream& os, const __int128& v) {
  unsigned __int128 a = v < 0 ? -v : v;
  ll i = 0;
  string s(64, ' ');
  if (v == 0) {
    s[i++] = '0';
  }else {
    while (a > 0) {
      s[i++] = '0' + (char)(a % 10);
      a /= 10;
    }
  }
  if (v < 0) {
    s[i++] = '-';
  }
  s.erase(s.begin() + i, s.end());
  reverse(s.begin(), s.end());
  os << s;
  return os;
}


// ---- end f:<<

// ---- inserted library file debug.cc
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

struct myexc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  digit_util du2(2);

  auto solve = [&]() -> ll {
    ll N, M; cin >> N >> M;
    // @InpMVec(M, ((A, dec=1), (B, dec=1), X)) [H8TJS2Ox]
    auto A = vector(M, ll());
    auto B = vector(M, ll());
    auto X = vector(M, ll());
    for (int i = 0; i < M; i++) {
      ll v1; cin >> v1; v1 -= 1; A[i] = v1;
      ll v2; cin >> v2; v2 -= 1; B[i] = v2;
      ll v3; cin >> v3; X[i] = v3;
    }
    // @End [H8TJS2Ox]

    if (N % 2 != 0) return -1;
    ll w0 = du2.width(N);

    vector cnt(w0, vector(2, 0LL));
    REP(i, 0, N + 1) REP(k, 0, w0) cnt[k][i >> k & 1]++;

    ll x = 0;
    REP(k, 0, w0) {
      UnionFind<Ftwo> uf(N);
      REP(i, 0, M) uf.merge(A[i], B[i], Ftwo(X[i] >> k & 1));
      vector gs(2, 0LL);
      REP(i, 0, N) gs[*uf.pot(i)]++;
      if (gs[0] < gs[1]) swap(gs[0], gs[1]);
      if      (gs[0] == cnt[k][0] - 1 and gs[1] == cnt[k][1]) ;
      else if (gs[1] == cnt[k][1] - 1 and gs[0] == cnt[k][0]) x |= (1LL << k);
      else assert(0);
    }
    return x;

  };

  ll T; cin >> T;
  REP(_t, 0, T) cout << solve() << "\n";

  return 0;
}

