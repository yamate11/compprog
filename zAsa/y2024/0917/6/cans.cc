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

// @@ !! LIM(board debug UnionFind)

// ---- inserted library file board.cc

struct BrdIdx {
  int r;
  int c;
  BrdIdx(int r_, int c_) : r(r_), c(c_) {}
  BrdIdx() : r(0), c(0) {}

  BrdIdx& operator +=(const BrdIdx& o) { r += o.r; c += o.c; return *this; }
  BrdIdx& operator -=(const BrdIdx& o) { r -= o.r; c -= o.c; return *this; }
  BrdIdx& operator *=(int k) { r *= k; c *= k; return *this; }
  BrdIdx operator +(const BrdIdx& o) const { return BrdIdx(*this) += o; }
  BrdIdx operator -(const BrdIdx& o) const { return BrdIdx(*this) -= o; }
  BrdIdx operator *(int k) const { return BrdIdx(*this) *= k; }
  BrdIdx operator -() const { return (*this) * (-1); }

  bool operator ==(const BrdIdx& o) const { return r == o.r && c == o.c; }
  bool operator !=(const BrdIdx& o) const { return !((*this) == o); }
  bool operator <(const BrdIdx& o) const {
    return r < o.r || (r == o.r && c < o.c); }
  bool operator <=(const BrdIdx& o) const {
    return r < o.r || (r == o.r && c <= o.c); }
  bool operator >(const BrdIdx& o) const { return o < *this; }
  bool operator >=(const BrdIdx& o) const { return o <= *this; }

  BrdIdx rotateQ() { return BrdIdx(-c, r); } // counter-clockwise

  static vector<BrdIdx> nbr4, nbr4D, nbr5, nbr8, nbr9;
};

vector<BrdIdx>
  BrdIdx::nbr4 ({      {1,0},      {0,1},       {-1,0},        {0,-1}       }),
  BrdIdx::nbr4D({            {1,1},      {-1,1},       {-1,-1},       {1,-1}}),
  BrdIdx::nbr5 ({{0,0},{1,0},      {0,1},       {-1,0},        {0,-1}       }),
  BrdIdx::nbr8 ({      {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}}),
  BrdIdx::nbr9 ({{0,0},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}});

BrdIdx operator *(int k, const BrdIdx& o) { return o * k; }
ostream& operator <<(ostream& os, const BrdIdx& i) {
  os << "(" << i.r << "," << i.c << ")";
  return os;
}

template <typename T, int dispWidth = 0>
struct Board {

  struct BoardSubst {
    Board& brd;
    int r;
    int c;
    BoardSubst(Board& brd_, int r_, int c_) : brd(brd_), r(r_), c(c_) {}
    const T& operator=(const T& t) { return brd.set(r, c, t); }
  };

  T def;
  vector<vector<T>> data;

  Board() : def(T()), data(0) {}
  Board(int nR, int nC, const T& def_) : def(def_), data(nR, vector(nC, def)) {}
  // Board(const Board&), Board(Board&&), operator=(const Board&), operator=(Board&&) are automatically generated.

  bool operator==(const Board& o) const = default;
  bool operator!=(const Board& o) const = default;

  int numRows() const { return ssize(data); }
  int numCols() const { return data.empty() ? 0 : ssize(data[0]); }

  bool in(int r, int c) const { return 0 <= r and r < numRows() and 0 <= c and c < numCols(); }
  bool in(const BrdIdx& bi) const { return in(bi.r, bi.c); }

  using return_T = typename conditional<is_same_v<T, bool>, T, const T&>::type;
  // Due to the proxy object for vector<bool>, you need to return bool, instead of const bool&.
  return_T at(int r, int c) const { return in(r, c) ? data[r][c] : def; }
  return_T at(const BrdIdx& bi) const { return at(bi.r, bi.c); }

  // Reference for Substitution
  BoardSubst rs(int r, int c) { return BoardSubst(*this, r, c); }
  BoardSubst rs(const BrdIdx& bi) { return rs(bi.r, bi.c); }

  const T& set(int r, int c, const T& t) {
    if (in(r, c)) data[r][c] = t;
    return t;
  }
  const T& set(const BrdIdx& bi, const T& t) { return set(bi.r, bi.c, t); }

  long long enc(int r, int c) { return in(r, c) ? r * numCols() + c : -1; }
  long long enc(const BrdIdx& bi) { return enc(bi.r, bi.c); }
  BrdIdx dec(long long e) {
    if (e < 0) return BrdIdx(-1, -1);
    int r = e / numCols();
    int c = e % numCols();
    if (in(r, c)) return BrdIdx(r, c);
    else return BrdIdx(-1, -1);
  }

  Board transpose() const {
    Board ret(numCols(), numRows(), def);
    for (int i = 0; i < numRows(); i++) for (int j = 0; j < numCols(); j++) ret.set(j, i, at(i, j));
    return ret;
  }
  Board reverse_row() const {
    Board ret(numRows(), numCols(), def);
    for (int i = 0; i < numRows(); i++) for (int j = 0; j < numCols(); j++) ret.set(numRows() - 1 - i, j, at(i, j));
    return ret;
  }
  Board reverse_col() const {
    Board ret(numRows(), numCols(), def);
    for (int i = 0; i < numRows(); i++) for (int j = 0; j < numCols(); j++) ret.set(i, numCols() - 1 - j, at(i, j));
    return ret;
  }
  Board _single_rotate() const {
    Board ret(numCols(), numRows(), def);
    for (int i = 0; i < numRows(); i++) for (int j = 0; j < numCols(); j++) ret.data[-j + numCols()-1][i] = data[i][j];
    return ret;
  }
  Board rotate(int r = 1) const {
    ll nR = numRows();
    ll nC = numCols();
    auto f = [&](ll szH, ll szW, auto g, auto h) {
      Board ret(szH, szW, def);
      for (int i = 0; i < nR; i++) for (int j = 0; j < nC; j++) ret.set(g(i, j), h(i, j), at(i, j));
      return ret;
    };
    if (r % 4 == 0) return *this;
    if (r > 0) r = r % 4;
    else r = 4 + r % 4;
    if (r == 1) return f(nC, nR, [&](int i, int j) { return -j + nC - 1; }, [&](int i, int j) { return i; });
    if (r == 2) return f(nR, nC, [&](int i, int j) { return -i + nR - 1; }, [&](int i, int j) { return -j + nC - 1; });
    if (r == 3) return f(nC, nR, [&](int i, int j) { return j; }, [&](int i, int j) { return -i + nR - 1; });
    assert(0);
    
    return _single_rotate().rotate(r - 1);
  }


  void readData(istream& is) {
    for (int i = 0; i < numRows(); i++) {
      for (int j = 0; j < numCols(); j++) {
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
    for (int r = 0; r < brd.numRows(); r++) {
      for (int c = 0; c < brd.numCols(); c++) {
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

    int nC;
    BrdIdx bi;

    Itr(int nC_, int r = 0, int c = 0) : nC(nC_), bi(r, c) {}

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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  Board<ll> brd(4, 4, -1);
  cin >> brd;
  DLOGK(brd);
  ll u0 = 0;
  vector<BrdIdx> v0;
  REP(i, 0, 4) REP(j, 0, 4) if (brd.at(i, j) == 1) {
    u0 |= (1LL << brd.enc(i, j));
    v0.push_back(BrdIdx(i, j));
  }

  ll cnt = 0;
  REP(x, 0, 1LL << 16) {
    if (u0 & ~x) continue;
    UnionFind uf(17);
    REP(i, 0, 4) REP(j, 0, 4) {
      auto bi = BrdIdx(i, j);
      ll e = brd.enc(bi);
      if (x >> e & 1) {
        for (auto dir : BrdIdx::nbr4) {
          auto bj = bi + dir;
          ll f = brd.enc(bj);
          if (brd.in(bj) and x >> f & 1) uf.merge(e, f);
        }
      }else {
        for (auto dir : BrdIdx::nbr4) {
          BrdIdx bj = bi + dir;
          ll f = brd.enc(bj);
          if (not brd.in(bj)) uf.merge(e, 16);
          else if (not (x >> f & 1)) uf.merge(e, f);
        }
      }
    }
    if (uf.num_groups() == 2) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

