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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(debug updMaxMin intDiv forall board ipoint cmpNaive perm)

// ---- inserted library file streamOut.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/streamOut.cc

// Declartion of g_show

// If T has member function show(), it is used:

template<typename T>
concept HasShow = requires(const T& t) {
  { t.show() } -> convertible_to<string>;
};

template<class T>
concept Streamable = requires(ostream& os, const T& x) {
  os << x;
};

//   The declaration must be put before calling it.

template<class T>
string g_show(const T& x);

// Definition of g_show_impl
//    The separation between g_show and g_show_impl is needed for order independence.

template<HasShow T> string g_show_impl(const T& t) { return t.show(); }

// basic types

inline string g_show_impl(char c) { return string(1, c); }
inline string g_show_impl(const char* s) { return s ? string(s) : string("(null)"); }
inline string g_show_impl(bool b) { return b ? "true" : "false"; }

// int, ll, ...; note that this also is applied to "sigend/unsigned char"
template<integral T>
  requires (not same_as<T, bool> and not same_as<T, char>)
string g_show_impl(T t) { return to_string(t); }

// double, long double, ...
template<floating_point T> string g_show_impl(T t) { return to_string(t); }

// containers in the standard library

//    pair
template <typename T1, typename T2>
string g_show_impl(const pair<T1,T2>& p) { return "(" + g_show(p.first) + ", " + g_show(p.second) + ")"; }

//    tuple
template<class... Ts>
string g_show_impl(const tuple<Ts...>& t) {
  string s = "(";
  bool first = true;
  apply([&](const auto&... xs) {
    ((s += (first ? "" : ", "), first = false, s += g_show(xs)),
     ...);
  }, t);
  s += ")";
  return s;
}

//   vector, array, deque, (un)ordered set, multiset, (un)ordered map, 

template<typename T, bool pair=false>
string g_show_with_iterator(const T& v) {
  string ret = "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) ret += ", ";
    if constexpr (pair) ret += "(" + g_show(it->first) + ": " + g_show(it->second) + ")";
    else                ret += g_show(*it);
  }
  ret += "]";
  return ret;
}

template<typename T>
string g_show_impl(const vector<T>& v) { return g_show_with_iterator(v); }

template <typename T, size_t N>
string g_show_impl(const array<T, N>& v) { return g_show_with_iterator(v); }

template <typename T, typename C>
string g_show_impl(const set<T, C>& v) { return g_show_with_iterator(v); }

template <typename T, typename C>
string g_show_impl(const unordered_set<T, C>& v) { return g_show_with_iterator(v); }

template <typename T, typename C>
string g_show_impl(const multiset<T, C>& v) { return g_show_with_iterator(v); }

template <typename T, typename T2>
string g_show_impl(const deque<T, T2>& v) { return g_show_with_iterator(v); }

template <typename T1, typename T2, typename C>
string g_show_impl(const map<T1, T2, C>& v) {
  return g_show_with_iterator<map<T1, T2, C>, true>(v);
}

template <typename T1, typename T2, typename C>
string g_show_impl(const unordered_map<T1, T2, C>& v) {
  return g_show_with_iterator<unordered_map<T1, T2, C>, true>(v);
}

//   queue, priority-queue

template<typename T>
string g_show_queue_and_like(const T& v0, auto front_like) {
  T v = v0;  // copy
  string ret = "[";
  bool first = true;
  while (not v.empty()) {
    if (not first) ret += ", ";
    first = false;
    const auto& x = front_like(v);
    ret += g_show(x);
    v.pop();
  }
  ret += "]";
  return ret;
}

template <typename T, typename T2>
string g_show_impl(const queue<T, T2>& v) {
  return g_show_queue_and_like(v, [](const queue<T, T2>& vv) { return vv.front(); });
}

template <typename T, typename T2, typename T3>
string g_show_impl(const priority_queue<T, T2, T3>& v) {
  return g_show_queue_and_like(v, [](const priority_queue<T, T2, T3>& vv) { return vv.top(); });
}

//    optional
template <typename T>
string g_show_impl(const optional<T>& t) { return t ? g_show(*t) : "(nullopt)"; }

//    (signed/unsigned) __int128

string g_show_impl(unsigned __int128 x) {
  if (x == 0) return "0";
  string s;
  while (x > 0) {
    int d = (int)(x % 10);
    s.push_back((char)('0' + d));
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}

string g_show_impl(__int128 x) {
  unsigned __int128 ux = (unsigned __int128)x;
  return x >= 0 ? g_show_impl(ux) : "-" + g_show_impl(~ux + 1);
}

// Both g_show_impl and operator<< are needed because of the implicit casting from __int128 to int etc.
ostream& operator<<(ostream& ostr, unsigned __int128 x) { return ostr << g_show(x); }
ostream& operator<<(ostream& ostr,          __int128 x) { return ostr << g_show(x); }


template<class T>
string g_show(const T& x) {
  if constexpr (requires { g_show_impl(x); }) {
    return g_show_impl(x);
  } else if constexpr (Streamable<T> && (not HasShow<T>)) {
    ostringstream oss;
    oss << x;
    return oss.str();
  }else {
    static_assert(sizeof(T) == 0, "g_show: unsupported type");
  }
}

// HasGShow
template<typename T>
concept HasGShow = requires(const T& t) {
  { g_show(t) } -> convertible_to<string>;
};

// ---- end streamOut.cc

// ---- inserted library file debug.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/debug.cc
// https://github.com/yamate11/compprog-clib/blob/master/debug.cc

template<class T>
void dbgPrintOne(const T& x) {
  if constexpr (HasGShow<T>) {
    cerr << g_show(x);
  } else {
    cerr << x;
  }
}

inline void dbgLog(bool with_nl) {
  if (with_nl) cerr << endl;
}

template <class Head, class... Tail>
void dbgLog(bool with_nl, Head&& head, Tail&&... tail) {
  dbgPrintOne(head);
  if constexpr (sizeof...(tail) > 0) {
    cerr << " ";
    dbgLog(with_nl, forward<Tail>(tail)...);
  } else {
    if (with_nl) cerr << endl;
  }
}

string dbgTrim(string s) {
  int l = 0, r = (int)s.size();
  while (l < r && isspace((unsigned char)s[l])) l++;
  while (l < r && isspace((unsigned char)s[r - 1])) r--;
  return s.substr(l, r - l);
}

vector<string> dbgSplitNames(const string& s) {
  vector<string> res;
  string cur;
  int depth = 0;

  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') depth++;
    if (c == ')' || c == ']' || c == '}') depth--;

    if (c == ',' && depth == 0) {
      res.push_back(dbgTrim(cur));
      cur.clear();
    } else {
      cur += c;
    }
  }

  res.push_back(dbgTrim(cur));
  return res;
}

template<class T>
void dbgLogKOne(const string& name, T&& value) {
  cerr << name << "=";
  dbgPrintOne(forward<T>(value));
}

template<class... Args>
void dbgLogK(const char* names_c, Args&&... args) {
  vector<string> names = dbgSplitNames(names_c);

  int idx = 0;
  auto print_one = [&](auto&& x) {
    if (idx > 0) cerr << " ";
    if (idx < (int)names.size()) {
      dbgLogKOne(names[idx], forward<decltype(x)>(x));
    } else {
      cerr << "?= ";
      dbgPrintOne(forward<decltype(x)>(x));
    }
    idx++;
  };

  (print_one(forward<Args>(args)), ...);
  cerr << endl;
}

template<class Label, class... Args>
void dbgLogKL(Label&& label, const char* names_c, Args&&... args) {
  dbgPrintOne(forward<Label>(label));
  if constexpr (sizeof...(Args) > 0) cerr << " ";

  vector<string> names = dbgSplitNames(names_c);

  int idx = 0;
  auto print_one = [&](auto&& x) {
    if (idx > 0) cerr << " ";
    if (idx < (int)names.size()) {
      dbgLogKOne(names[idx], forward<decltype(x)>(x));
    } else {
      cerr << "?=";
      dbgPrintOne(forward<decltype(x)>(x));
    }
    idx++;
  };

  (print_one(forward<Args>(args)), ...);
  cerr << endl;
}

#if DEBUG
  #define DLOG(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL(...)     dbgLog(false, __VA_ARGS__)
  #define DCALL(func, ...) func(__VA_ARGS__)
  #define DLOGK(...)       dbgLogK(#__VA_ARGS__, __VA_ARGS__)
  #define DLOGKL(lab, ...) dbgLogKL(lab, #__VA_ARGS__, __VA_ARGS__)
#else
  #define DLOG(...)
  #define DLOGNNL(...)
  #define DCALL(func, ...)
  #define DLOGK(...)
  #define DLOGKL(lab, ...)
#endif

#if DEBUG_LIB
  #define DLOG_LIB   DLOG
  #define DLOGK_LIB  DLOGK
  #define DLOGKL_LIB DLOGKL
#endif

// ---- end debug.cc

// ---- inserted library file updMaxMin.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/updMaxMin.cc

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

// ---- end updMaxMin.cc

// ---- inserted library file intDiv.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/intDiv.cc

// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}
//   Just a note.  For d \in Z and t \in R,
//       d < t <=> d < ceil(t),     d <= t <=> d <= floor(t),
//       d > t <=> d > floor(t),    d >= t <=> d >= ceil(t).

// ---- end intDiv.cc

// ---- inserted library file forall.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/forall.cc

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define COUNT_BASE(rep_part, cond) ([&](){ ll ret = 0; rep_part if (cond) ret++; return ret; }())
#define COUNT(i, from, to, cond) COUNT_BASE(EX_REP_LL(i, from, to), cond)
#define COUNT_C(x, coll, cond) COUNT_BASE(EX_REP_RB(x, coll), cond)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// ---- inserted library file board.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/board.cc

struct BrdIdx {
  ll r;
  ll c;
  constexpr BrdIdx(ll r_, ll c_) : r(r_), c(c_) {}
  constexpr BrdIdx() : r(0), c(0) {}

  BrdIdx& operator +=(const BrdIdx& o) { r += o.r; c += o.c; return *this; }
  BrdIdx& operator -=(const BrdIdx& o) { r -= o.r; c -= o.c; return *this; }
  BrdIdx& operator *=(ll k) { r *= k; c *= k; return *this; }
  BrdIdx operator +(const BrdIdx& o) const { return BrdIdx(*this) += o; }
  BrdIdx operator -(const BrdIdx& o) const { return BrdIdx(*this) -= o; }
  BrdIdx operator *(ll k) const { return BrdIdx(*this) *= k; }
  BrdIdx operator -() const { return (*this) * (-1); }

  bool operator ==(const BrdIdx& o) const { return r == o.r && c == o.c; }
  bool operator !=(const BrdIdx& o) const { return !((*this) == o); }
  bool operator <(const BrdIdx& o) const {
    return r < o.r || (r == o.r && c < o.c); }
  bool operator <=(const BrdIdx& o) const {
    return r < o.r || (r == o.r && c <= o.c); }
  bool operator >(const BrdIdx& o) const { return o < *this; }
  bool operator >=(const BrdIdx& o) const { return o <= *this; }

  BrdIdx rotateQ() const { return BrdIdx(-c, r); } // counter-clockwise

  static const array<BrdIdx,4> nbr4;
  static const array<BrdIdx,4> nbr4D;
  static const array<BrdIdx,5> nbr5;
  static const array<BrdIdx,8> nbr8;
  static const array<BrdIdx,9> nbr9;
};

inline const array<BrdIdx,4> BrdIdx::nbr4 {{      {1,0},      {0,1},       {-1,0},        {0,-1}       }};
inline const array<BrdIdx,4> BrdIdx::nbr4D{{            {1,1},      {-1,1},       {-1,-1},       {1,-1}}};
inline const array<BrdIdx,5> BrdIdx::nbr5 {{{0,0},{1,0},      {0,1},       {-1,0},        {0,-1}       }};
inline const array<BrdIdx,8> BrdIdx::nbr8 {{      {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}}};
inline const array<BrdIdx,9> BrdIdx::nbr9 {{{0,0},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}}};

BrdIdx operator *(ll k, const BrdIdx& o) { return o * k; }
ostream& operator <<(ostream& os, const BrdIdx& i) {
  os << "(" << i.r << "," << i.c << ")";
  return os;
}

template <typename T, ll dispWidth = 0>
struct Board {

  struct BoardSubst {
    Board& brd;
    ll r;
    ll c;
    BoardSubst(Board& brd_, ll r_, ll c_) : brd(brd_), r(r_), c(c_) {}
    const T& operator=(const T& t) { return brd.set(r, c, t); }
  };

  T def;
  vector<vector<T>> data;

  Board() : def(T()), data(0) {}
  Board(ll nR, ll nC, const T& def_) : def(def_), data(nR, vector(nC, def)) {}
  // Board(const Board&), Board(Board&&), operator=(const Board&), operator=(Board&&) are automatically generated.

  bool operator==(const Board& o) const = default;
  bool operator!=(const Board& o) const = default;

  int numRows() const { return (int)ssize(data); }
  int numCols() const { return data.empty() ? 0 : (int)ssize(data[0]); }

  bool in(ll r, ll c) const { return 0 <= r and r < numRows() and 0 <= c and c < numCols(); }
  bool in(const BrdIdx& bi) const { return in(bi.r, bi.c); }

  using return_T = typename conditional<is_same_v<T, bool>, T, const T&>::type;
  // Due to the proxy object for vector<bool>, you need to return bool, instead of const bool&.
  return_T at(ll r, ll c) const { return in(r, c) ? data[r][c] : def; }
  return_T at(const BrdIdx& bi) const { return at(bi.r, bi.c); }

  // Reference for Substitution
  BoardSubst rs(ll r, ll c) { return BoardSubst(*this, r, c); }
  BoardSubst rs(const BrdIdx& bi) { return rs(bi.r, bi.c); }

  const T& set(ll r, ll c, const T& t) {
    if (in(r, c)) data[r][c] = t;
    return t;
  }
  const T& set(const BrdIdx& bi, const T& t) { return set(bi.r, bi.c, t); }

  long long enc(ll r, ll c) { return in(r, c) ? r * numCols() + c : -1; }
  long long enc(const BrdIdx& bi) { return enc(bi.r, bi.c); }
  BrdIdx dec(long long e) {
    if (e < 0) return BrdIdx(-1, -1);
    ll r = e / numCols();
    ll c = e % numCols();
    if (in(r, c)) return BrdIdx(r, c);
    else return BrdIdx(-1, -1);
  }

  Board transpose() const {
    Board ret(numCols(), numRows(), def);
    for (ll i = 0; i < numRows(); i++) for (ll j = 0; j < numCols(); j++) ret.set(j, i, at(i, j));
    return ret;
  }
  Board reverse_row() const {
    Board ret(numRows(), numCols(), def);
    for (ll i = 0; i < numRows(); i++) for (ll j = 0; j < numCols(); j++) ret.set(numRows() - 1 - i, j, at(i, j));
    return ret;
  }
  Board reverse_col() const {
    Board ret(numRows(), numCols(), def);
    for (ll i = 0; i < numRows(); i++) for (ll j = 0; j < numCols(); j++) ret.set(i, numCols() - 1 - j, at(i, j));
    return ret;
  }
  Board _single_rotate() const {
    Board ret(numCols(), numRows(), def);
    for (ll i = 0; i < numRows(); i++) for (ll j = 0; j < numCols(); j++) ret.data[-j + numCols()-1][i] = data[i][j];
    return ret;
  }
  Board rotate(ll r = 1) const {
    ll nR = numRows();
    ll nC = numCols();
    auto f = [&](ll szH, ll szW, auto g, auto h) {
      Board ret(szH, szW, def);
      for (ll i = 0; i < nR; i++) for (ll j = 0; j < nC; j++) ret.set(g(i, j), h(i, j), at(i, j));
      return ret;
    };
    if (r % 4 == 0) return *this;
    if (r > 0) r = r % 4;
    else r = 4 + r % 4;
    if (r == 1) return f(nC, nR, [&](ll, ll j) { return -j + nC - 1; }, [&](ll i, ll) { return i; });
    if (r == 2) return f(nR, nC, [&](ll i, ll) { return -i + nR - 1; }, [&](ll, ll j) { return -j + nC - 1; });
    if (r == 3) return f(nC, nR, [&](ll, ll j) { return j; }, [&](ll i, ll) { return -i + nR - 1; });
    assert(0);
    
    return _single_rotate().rotate(r - 1);
  }


  void readData(istream& is) {
    for (ll i = 0; i < numRows(); i++) {
      for (ll j = 0; j < numCols(); j++) {
	T t; is >> t;
	set(i, j, t);
      }
    }
  }

  friend istream& operator >>(istream& is, Board& brd) {
    brd.readData(is);
    return is;
  }

  friend ostream& operator <<(ostream& os, const Board& brd) {
    for (ll r = 0; r < brd.numRows(); r++) {
      for (ll c = 0; c < brd.numCols(); c++) {
        os << setw(dispWidth) << brd.at(r, c);
      }
      if (r < brd.numRows() - 1) os << "\n";
    }
    return os;
  }

};

template<typename T>
struct BoardRange {
  const Board<T>& board;
  struct Itr {
    using iterator_category = input_iterator_tag;
    using value_type = BrdIdx;
    using difference_type = ptrdiff_t;
    using reference = value_type&;
    using pointer = value_type*;

    ll nC;
    BrdIdx bi;

    Itr(ll nC_, ll r = 0, ll c = 0) : nC(nC_), bi(r, c) {}

    bool operator ==(const Itr& o) const { return bi == o.bi; }
    bool operator !=(const Itr& o) const { return bi != o.bi; }

    reference operator *() { return bi; }
    pointer operator ->() { return &bi; }

    Itr& operator ++() {
      if (++bi.c == nC) {
        bi.c = 0;
        ++bi.r;
      }
      return *this;
    }
    Itr operator ++(int) {
      Itr const tmp(*this);
      ++*this;
      return tmp;
    }
  };

  BoardRange(const Board<T>& board_) : board(board_) {}
  Itr begin() { return Itr(board.numCols(), 0, 0); }
  Itr end() { return Itr(board.numCols(), board.numRows(), 0); }
};


// ---- end board.cc

// ---- inserted library file ipoint.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/ipoint.cc

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

// ---- inserted library file cmpNaive.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/cmpNaive.cc

const string end_mark("^__=end=__^");

int naive(istream& cin, ostream& cout);
int body(istream& cin, ostream& cout);

void cmpNaive() {
  while (true) {
    string s;
    getline(cin, s);
    bool run_body;
    if (s.at(0) == 'Q') {
      return;
    }else if (s.at(0) == 'B') {
      run_body = true;
    }else if (s.at(0) == 'N') {
      run_body = false;
    }else {
      cerr << "Unknown body/naive specifier.\n";
      exit(1);
    }
    string input_s;
    while (true) {
      getline(cin, s);
      if (s == end_mark) break;
      input_s += s;
      input_s += "\n";
    }
    stringstream ss_in(move(input_s));
    stringstream ss_out;
    ss_out << setprecision(20);
    if (run_body) {
      body(ss_in, ss_out);
    }else {
      naive(ss_in, ss_out);
    }
    cout << ss_out.str() << end_mark << endl;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if CMPNAIVE
  if (argc == 2) {
    if (strcmp(argv[1], "cmpNaive") == 0) {
      cmpNaive();
    }else if (strcmp(argv[1], "naive") == 0) {
      naive(cin, cout);
    }else if (strcmp(argv[1], "skip") == 0) {
      exit(0);
    }else {
      cerr << "Unknown argument.\n";
      exit(1);
    }
  }else {
#endif
    body(cin, cout);
#if CMPNAIVE
  }
#endif
  return 0;
}

/*
int naive(istream& cin, ostream& cout) {
  return 0;
}
int body(istream& cin, ostream& cout) {
  return 0;
}
*/

// ---- end cmpNaive.cc

// ---- inserted library file perm.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/perm.cc

template <bool dup, typename T>
struct IntPermBase {
  ll n;
  ll r;
  vector<ll> vec;
  bool started;
  vector<T> mapping;

  bool start_check() {
    if constexpr (dup) { if (not ((1 <= n and 0 <= r) or (n == 0 and r == 0))) return false; }
    else { if (not (0 <= n and 0 <= r and r <= n)) return false; }
    started = true;
    vec.resize(r, 0);
    return true;
  }

  bool finish() {
    vec.resize(0);
    started = false;
    return false;
  }

  IntPermBase(ll n_, ll r_) : n(n_), r(r_), started(false) {
    if (n >= 0) {
      mapping = vector<T>(n);
      for (ll i = 0; i < n; i++) {
        if constexpr (is_integral<T>::value) mapping[i] = (T)i;
        else mapping[i] = T();
      }
    }
  }
  IntPermBase(ll n_, ll r_, vector<T> mp) : n(n_), r(r_), started(false), mapping(move(mp)) {
    if (ssize(mapping) != n) throw runtime_error("IntPermBase: incorrect mapping length");
  }

  T at(ll i) const { return mapping[vec[i]]; }

  T operator[](ll i) const { return at(i); }

  void set_mapping(auto f) {
    for (ll i = 0; i < n; i++) mapping[i] = f(i);
  }

  vector<T> vec_view() const {
    vector<T> res;
    for (ll i = 0; i < r; i++) res.push_back(mapping[vec[i]]);
    return res;
  }
};

template<typename T = ll>
struct IntPerm : IntPermBase<false, T> {
  using Base = IntPermBase<false, T>;
  using Base::vec, Base::r, Base::n, Base::started;

  vector<vector<ll>> cands;
  vector<ll> cidx;

  bool start_check() {
    if (not IntPermBase<false, T>::start_check()) return false;
    iota(vec.begin(), vec.end(), 0);
    cands.resize(r);
    cidx.resize(r);
    for (ll i = 0; i < r; i++) {
      for (ll j = n - 1; j >= i; j--) cands[i].push_back(j);
      cidx[i] = n - i - 1;
    }
    return true;
  }

  bool finish() {
    cands.resize(0);
    cidx.resize(0);
    return IntPermBase<false, T>::finish();
  }

  IntPerm(ll n_, ll r_) : IntPermBase<false, T>(n_, r_) {}
  IntPerm(ll n_, ll r_, vector<T> mp) : IntPermBase<false, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    ll i = r - 1;
    for (; i >= 0 and cidx[i] == 0; i--);
    if (i < 0) return finish();
    vec[i] = cands[i][--cidx[i]];
    for (ll j = i + 1; j < r; j++) {
      if (j == i + 1) {
        cands[j].resize(0);
        for (ll k = 0; k < (ll)cands[i].size(); k++) {
          if (k == cidx[i]) continue;
          cands[j].push_back(cands[i][k]);
        }
      }else {
        cands[j] = cands[j - 1];
        cands[j].pop_back();
      }
      cidx[j] = n - j - 1;
      vec[j] = cands[j][cidx[j]];
    }
    return true;
  }
};

template<typename T = ll>
struct IntComb : IntPermBase<false, T> {
  using Base = IntPermBase<false, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish;

  bool start_check() {
    if (not IntPermBase<false, T>::start_check()) return false;
    iota(vec.begin(), vec.end(), 0);
    return true;
  }

  IntComb(ll n_, ll r_) : IntPermBase<false, T>(n_, r_) {}
  IntComb(ll n_, ll r_, vector<T> mp) : IntPermBase<false, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    ll i = r - 1;
    for (; i >= 0 and vec[i] == n - r + i; i--);
    if (i < 0) return finish();
    vec[i]++;
    for (ll j = i + 1; j < r; j++) vec[j] = vec[j - 1] + 1;
    return true;
  }
};

template<typename T = ll>
struct IntDupPerm : IntPermBase<true, T> {
  using Base = IntPermBase<true, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish, Base::start_check;

  IntDupPerm(ll n_, ll r_) : IntPermBase<true, T>(n_, r_) {}
  IntDupPerm(ll n_, ll r_, vector<T> mp) : IntPermBase<true, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    for (ll i = r - 1; i >= 0; vec[i--] = 0) if (++vec[i] < n) return true;
    return finish();
  }
};

template<typename T = ll>
struct IntDupComb : IntPermBase<true, T> {
  using Base = IntPermBase<true, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish, Base::start_check;

  IntDupComb(ll n_, ll r_) : IntPermBase<true, T>(n_, r_) {}
  IntDupComb(ll n_, ll r_, vector<T> mp) : IntPermBase<true, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    ll i = r - 1;
    for (; i >= 0 and vec[i] == n - 1; i--);
    if (i < 0) return finish();
    vec[i]++;
    for (ll j = i + 1; j < r; j++) vec[j] = vec[i];
    return true;
  }
};

struct IDCBoxBall {
  ll box;
  ll ball;
  IntDupComb<> idc;
  vector<ll> numBalls;
  IDCBoxBall(ll box_, ll ball_) : box(box_), ball(ball_), idc(box, ball) {}
  bool get() {
    bool b = idc.get();
    if (not b) return false;
    numBalls = vector<ll>(box);
    for (ll i = 0; i < ball; i++) numBalls[idc.at(i)]++;
    return true;
  }
  ll at(ll i) const { return numBalls[i]; }
  ll operator[](ll i) const { return at(i); }
  vector<ll> vec_view() const { return numBalls; }
};


template<typename INT>
struct IntDirProd {
  vector<INT> lim;
  ll r;
  vector<INT> vec;
  bool started;

  IntDirProd(const vector<INT>& lim_) : lim(lim_), r(lim.size()), started(false) {}

  ll at(ll i) const { return vec[i]; }
  ll operator[](ll i) const { return at(i); }

  const vector<INT>& vec_view() const { return vec; }

  bool start_check() {
    for (ll i = 0; i < r; i++) if (lim[i] == 0) return false;
    started = true;
    vec.resize(r, 0);
    return true;
  }

  bool finish() {
    vec.resize(0);
    started = false;
    return false;
  }

  bool get() {
    if (not started) return start_check();
    for (ll i = r - 1; i >= 0; vec[i--] = 0) if (++vec[i] < lim[i]) return true;
    return finish();
  }
};

template<typename INT>
struct IntPartition {
  INT n;
  vector<INT> vec;
  bool started = false;
  IntPartition(INT n_) : n(n_) {}
  
  bool get() {
    if (not started) {
      started = true;
      vec = vector<INT>(n, 1);
      return true;
    }else if (ssize(vec) == 1) {
      started = false;
      return false;
    }else {
      INT b = vec.back(); vec.pop_back();
      INT a = vec.back(); vec.pop_back();
      INT c = a + b;
      INT a1 = a + 1;
      while (c - a1 >= a1) {
        vec.push_back(a1);
        c -= a1;
      }
      vec.push_back(c);
      return true;
    }
  }

  INT at(ll i) const { return vec[i]; }
  const vector<INT>& vec_view() const { return vec; }
};

// ---- end perm.cc

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  ll N, K; cin >> N >> K;
  // @InpGrid(N, N, A) [U9XdcSU0]
  // This part (until atmark + "End") was generated by a script written by myself.
  // Source: https://github.com/yamate11/compprog-clib/blob/master/tool/inputExpand
  auto A = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [U9XdcSU0]

  auto fwd = [&](ll x, ll y) -> pll {
    return pll{y, N - 1 - x};
  };

  vector<pll> pos0;
  REP(i, 0, N) REP(j, 0, N) if (A[i][j] == 0) pos0.emplace_back(i, j);
  ll sz = ssize(pos0);
  if (sz <= K) {
    cout << N * N << endl;
    return 0;
  }
  IntComb ic(sz, K);
  ll ans = 0;
  while (ic.get()) {
    auto B = A;
    REP(i, 0, K) {
      auto [x, y] = pos0[ic[i]];
      B[x][y] = 1;
    }
    vector C(N, vector(N, 0LL));
    REP(p, 0, N) REP(q, 0, N) {
      auto [p1, q1] = fwd(p, q);
      C[p1][q1] = B[p][q];
    }
    ll cnt = 0;
    REP(p, 0, N) REP(q, 0, N) if (B[p][q] == 1 and C[p][q] == 1) cnt++;
    updMax(ans, cnt);
  }
  cout << ans << "\n";

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N, K; cin >> N >> K;
  // @InpGrid(N, N, A) [U9XdcSU0]
  // This part (until atmark + "End") was generated by a script written by myself.
  // Source: https://github.com/yamate11/compprog-clib/blob/master/tool/inputExpand
  auto A = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [U9XdcSU0]
  
  auto fwd = [&](ll x, ll y) -> pll {
    return pll{y, N - 1 - x};
  };

  ll H1 = divCeil(N, 2);
  ll H2 = divFloor(N, 2);
  ll orig = 0;
  ll typeA = 0;
  ll typeB = 0;
  ll typeC = 0;
  ll typeD = 0;
  ll typeE = 0;
  if (N % 2 != 0 and A[N / 2][N / 2] == 1) orig++;
  REP(i0, 0, H1) REP(j0, 0, H2) {
    vector<pll> v(4);
    v[0] = pll{i0, j0};
    REP(ii, 1, 4) {
      v[ii] = fwd(v[ii - 1].first, v[ii - 1].second);
    }
    vector<ll> w(4);
    REP(i, 0, 4) w[i] = A[v[i].first][v[i].second];
    ll cntB = 0;
    REP(i, 0, 4) cntB += w[i];
    if (cntB == 4) {
      orig += 4;
    }else if (cntB == 3) {
      orig += 2;
      typeA += 1;
    }else if (cntB == 2) {
      if (w[0] == w[1] or w[1] == w[2]) {
        orig += 1;
        typeC += 1;
      }else {
        orig += 0;
        typeB += 1;
      }
    }else if (cntB == 1) {
      orig += 0;
      typeD += 1;
    }else if (cntB == 0) {
      orig += 0;
      typeE += 1;
    }else assert(0);
  }
  DLOGK(orig);
  ll add = 0;
  while (true) {
    ll x = min(typeA, K);
    add += 2 * x;
    K -= x;
    DLOGKL("A", add, K);
    if (K == 0) break;
    x = min(typeB, K / 2);
    add += 4 * x;
    K -= 2 * x;
    typeB -= x;
    if (K == 0) break;
    if (typeB > 0) {
      assert(K == 1);
      add += 2;
      break;
    }
    DLOGKL("B", add, K);
    x = min(typeC, K / 2);
    add += 3 * x;
    K -= 2 * x;
    typeC -= x;
    if (K == 0) break;
    if (typeC > 0) {
      assert(K == 1);
      add += 1;
      break;
    }
    DLOGKL("C", add, K);
    x = min(typeD, K / 3);
    add += 4 * x;
    K -= 3 * x;
    typeD -= x;
    if (K == 0) break;
    if (typeD > 0) {
      if (K == 1) {
        add += 1;
        break;
      }else if (K == 2) {
        add += 2;
        break;
      }else assert(0);
    }
    DLOGKL("D", add, K);
    x = min(typeE, K / 4);
    add += 4 * x;
    K -= 4 * x;
    typeE -= x;
    if (K == 0) break;
    if (N % 2 != 0 and A[N / 2][N / 2] == 0) {
      add += 1;
      K -= 1;
      if (K == 0) break;
    }
    if (typeE > 0) {
      if (K == 1) {
        add += 0;
        break;
      }else if (K == 2) {
        add += 1;
        break;
      }else if (K == 3) {
        add += 2;
        break;
      }else assert(0);
    }
    break;
  }
  cout << orig + add << "\n";



  return 0;
}

