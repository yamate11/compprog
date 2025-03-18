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

// @@ !! LIM(board debug tree)

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

// ---- inserted library file tree.cc

struct function_error : runtime_error {
  function_error(const string& msg) : runtime_error(msg) {}
};

struct Tree {

  struct pe_t {
    int peer;
    int edge;
    pe_t(int peer_ = -1, int edge_ = -1) : peer(peer_), edge(edge_) {}
    static const pe_t end_object;
  };

  struct nbr_t {
    int parent_idx;                 // pe[parent_idx] is the parent
    vector<pe_t> pe;
    nbr_t() : parent_idx(-1), pe() {}
  };

  template<bool get_peer>
  struct nbr_iterator {
    const nbr_t& body;
    int pe_idx;
    explicit nbr_iterator(const nbr_t& body_, int pe_idx_) : body(body_), pe_idx(pe_idx_) {
      if (pe_idx == body.parent_idx) pe_idx++;
    }
    auto operator*() const -> typename conditional<get_peer, int, const pe_t&>::type {
      if constexpr (get_peer) return body.pe[pe_idx].peer;
      else                    return body.pe[pe_idx];
    }
    const nbr_iterator& operator++() {
      pe_idx++;
      if (pe_idx == body.parent_idx) pe_idx++;
      return *this;
    }
    bool operator !=(const nbr_iterator& o) const { return pe_idx != o.pe_idx; }
  };

  template<bool get_peer>
  struct children_view {
    const nbr_t& body;
    children_view(const nbr_t& body_) : body(body_) {}
    nbr_iterator<get_peer> begin() const { return nbr_iterator<get_peer>(body, 0); }
    nbr_iterator<get_peer> end() { return nbr_iterator<get_peer>(body, std::ssize(body.pe)); }
  };

  int numNodes;
  int root;
  vector<nbr_t> _nbr;
  vector<pair<int, int>> _edges;   // (x, y) in _edges => x < y
  vector<int> _parent;             // _parent[root] == -1
  vector<int> _stsize;
  vector<int> _depth;
  unordered_map<long long, int> _edge_idx;
  vector<vector<int>> _pPnt;   
          // _pPnt[0][n] == parent of n (or root if n is root)
          // _pPnt[t][n] == parent^{2^t}[n]
  vector<int> _euler_in;
  vector<int> _euler_out;
  vector<pair<int, bool>> _euler_edge;

  constexpr static bool use_depth = true;
  constexpr static bool use_stsize = true;
  constexpr static bool use_euler = true;

  Tree(int numNodes_, int root_ = 0) : numNodes(numNodes_), root(root_), _nbr(numNodes_) {
    if (numNodes == 1) _set_parent();
  }

  int add_edge(int x, int y) {
    int i = ssize(_edges);
    if (i >= numNodes - 1) throw range_error("add_edge");
    _nbr[x].pe.emplace_back(y, i);
    _nbr[y].pe.emplace_back(x, i);
    _edges.emplace_back(min(x, y), max(x, y));
    if (i + 1 == numNodes - 1) _set_parent();
    return i;
  }

  void _set_parent() {   // called from constructor, add_edge() and change_root()

    _nbr[root].parent_idx = ssize(_nbr[root].pe);

    if constexpr (use_depth) _depth.resize(numNodes);
    if constexpr (use_stsize) _stsize.resize(numNodes);
    if constexpr (use_euler) {
      _euler_in.resize(numNodes);
      _euler_out.resize(numNodes);
      _euler_edge.resize(2 * numNodes);
    }
    int euler_idx = 0;

    auto dfs = [&](auto rF, int nd, int pt, int edge) -> void {
      if constexpr (use_depth) _depth[nd] = pt == -1 ? 0 : _depth[pt] + 1;
      if constexpr (use_stsize) _stsize[nd] = 1;
      if constexpr (use_euler) {
        _euler_edge[euler_idx] = {edge, nd < pt};
        _euler_in[nd] = euler_idx;
        euler_idx++;
      }
      for (int i = 0; i < ssize(_nbr[nd].pe); i++) {
        auto [c_id, c_eg] = _nbr[nd].pe[i];
        if (c_id == pt) _nbr[nd].parent_idx = i;
        else {
          rF(rF, c_id, nd, c_eg);
          if constexpr (use_stsize) _stsize[nd] += _stsize[c_id];
        }
      }
      if constexpr (use_euler) {
        _euler_edge[euler_idx] = {edge, pt < nd};
        _euler_out[nd] = euler_idx;
        euler_idx++;
      }
    };

    dfs(dfs, root, -1, numNodes - 1);
  }

  pe_t parent_pe(int nd) { return _nbr[nd].pe[_nbr[nd].parent_idx]; }
  int parent(int nd) { return nd == root ? -1 : parent_pe(nd).peer; }
  int num_children(int nd) { return _nbr[nd].pe.size() - (_nbr[nd].parent_idx == (int)_nbr[nd].pe.size() ? 0 : 1); }
  pe_t child_pe(int nd, int idx) { return _nbr[nd].pe[idx < _nbr[nd].parent_idx ? idx : idx + 1]; }
  int child(int nd, int idx) { return child_pe(nd, idx).peer; }
  int child_edge(int nd, int idx) { return child_pe(nd, idx).edge; }
  auto children_pe(int nd) { return children_view<false>(_nbr[nd]); }
  auto children(int nd) { return children_view<true>(_nbr[nd]); }

  int stsize(int nd) {
    if constexpr (use_stsize) return _stsize[nd];
    else throw function_error("use_stsize should be set to call stsize.");
  }

  int depth(int nd) {
    if constexpr (use_depth) return _depth[nd];
    else throw function_error("use_depth should be set to call depth.");
  }

  long long _enc_node_pair(int x, int y) { return (x + 1) * (numNodes + 1) + (y + 1); }

  int edge_idx(int x, int y) {
    if (_edge_idx.empty()) {
      for (int i = 0; i < ssize(_edges); i++) {
        auto [xx, yy] = _edges[i];
        _edge_idx[_enc_node_pair(xx, yy)] = i;
        _edge_idx[_enc_node_pair(yy, xx)] = i;
      }
    }
    auto it = _edge_idx.find(_enc_node_pair(x, y));
    return it == _edge_idx.end() ? -1 : it->second;
  }

  pair<int, int> nodes_of_edge(int e) { return _edges[e]; }

  void _set_euler() {
    _euler_in.resize(numNodes);
    _euler_out.resize(numNodes);
    vector<pair<int, int>> stack{{root, -1}};
    int idx = 0;
    while (not stack.empty()) {
      auto& [nd, cidx] = stack.back();
      if (cidx == -1) _euler_in[nd] = idx++;
      cidx++;
      if (cidx < num_children(nd)) stack.emplace_back(child(nd, cidx), -1);
      else {
        _euler_out[nd] = idx++;
        stack.pop_back();
      }
    }
  }

  int euler_in(int nd) {
    if constexpr (use_euler) return _euler_in[nd];
    else throw function_error("use_euler should be set to call euler_in.");
  }

  int euler_out(int nd) {
    if constexpr (use_euler) return _euler_out[nd];
    else throw function_error("use_euler should be set to call euler_out.");
  }

  tuple<int, int, int> euler_edge(int idx) {
    if constexpr (use_euler) {
      if (idx == 0) return {numNodes - 1, -1, root};
      else if (idx == 2 * numNodes - 1) return {numNodes - 1, root, -1};
      else {
        auto [e, b] = _euler_edge[idx];
        auto [x, y] = nodes_of_edge(e);
        if (b) swap(x, y);
        return {e, x, y};
      }
    }
    else throw function_error("use_euler should be set to call euler_out.");
  }

  void preparePPnt() {
    if (not _pPnt.empty()) return;
    vector<int> vec_parent(numNodes);
    for (int i = 0; i < numNodes; i++) vec_parent[i] = i == root ? i : parent(i);
    _pPnt.push_back(move(vec_parent));
    for (int t = 0; true; t++) {
      bool done = true;
      vector<int> vec(numNodes);
      for (int n = 0; n < numNodes; n++) {
	int m = _pPnt[t][n];
	vec[n] = _pPnt[t][m];
	if (vec[n] != m) done = false;
      }
      _pPnt.push_back(move(vec));
      if (done) break;
    }
  }

  // Lowest Common Ancestor
  int lca(int x, int y) {
    if (depth(x) > depth(y)) swap(x, y);
    int dep = depth(x);
    int yy = ancestorDep(y, dep);
    if (x == yy) return x;
    int t = 0;
    for (int q = 1; q < dep; q *= 2) t++;
    for ( ; t >= 0; t--) {
      if (_pPnt[t][x] != _pPnt[t][yy]) {
	x = _pPnt[t][x];
	yy = _pPnt[t][yy];
      }
    }
    return parent(x);
  }

  // the path between two nodes (list of nodes, including x and y)
  vector<int> nnpath(int x, int y) {
    vector<int> ret;
    int c = lca(x, y);
    for ( ; x != c; x = parent(x)) ret.push_back(x);
    ret.push_back(c);
    int len = (int)ret.size();
    for ( ; y != c; y = parent(y)) ret.push_back(y);
    reverse(ret.begin() + len, ret.end());
    return ret;
  }

  // the ancestor of n whose depth is dep
  int ancestorDep(int x, int dep) {
    preparePPnt();
    int diff = depth(x) - dep;
    if (diff < 0) throw range_error("ancestorDep");
    for (int t = 0; diff >> t; t++) if (diff >> t & 1) x = _pPnt[t][x];
    return x;
  }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"    
  tuple<int, int, int, int, int> diameter() {
    if (numNodes == 1) return {0, 0, 0, 0, 0};
    if (numNodes == 2) return {1, 0, 1, 0, 1};
    depth(root);   // to ensure that _depth is correctly built
    int nd0 = max_element(_depth.begin(), _depth.end()) - _depth.begin();
    int nd1 = -1, ct0 = -1, ct1 = -1;
    int diam = 0;
    auto dfs2 = [&](auto rF, int nd, int dp, int pt) -> bool {
      // DFS from nd0, which is different from the root.
      bool ret = false;
      ll numChildren = 0;
      for (auto [cld, _e] : _nbr[nd].pe) {
        if (cld == pt) continue;
        numChildren++;
        bool bbb = rF(rF, cld, dp + 1, nd);
        ret = ret || bbb;
      }
      if (numChildren > 0) {
        if (ret) {
          if (diam % 2 == 0) {
            if (dp == diam / 2) ct0 = ct1 = nd;
          }else {
            if (dp == diam / 2) ct0 = nd;
            else if (dp == diam / 2 + 1) ct1 = nd;
          }
        }
      }else {
        if (dp > diam) {
          diam = dp;
          nd1 = nd;
          ret = true;
        }
      }
      return ret;
    };
    dfs2(dfs2, nd0, 0, -1);
    return {diam, nd0, nd1, ct0, ct1};
  }
#pragma GCC diagnostic pop

  pair<int, int> centroids() {
    auto dfs = [&](auto rF, int nd) -> pair<int, int> {
      for (int c : children(nd)) {
        int a = 2 * stsize(c);
        if (a > numNodes) return rF(rF, c);
        if (a == numNodes) return make_pair(nd, c);
      }
      return make_pair(nd, -1);
    };
    return dfs(dfs, root);
  }

  void change_root(int newRoot) {
    _stsize.clear();
    _depth.clear();
    _edge_idx.clear();
    _euler_in.clear();
    _euler_out.clear();
    _pPnt.clear();

    root = newRoot;
    _set_parent();
  }

};

const Tree::pe_t end_object{-1, -1};

template <typename M>
auto reroot(Tree& tree, const M& unit, auto add, auto mod1, auto mod2) {
  using A = decltype(mod2(M(), 0));
  vector<A> result(tree.numNodes);
  vector<vector<M>> sum_left(tree.numNodes);
  vector<vector<M>> sum_right(tree.numNodes);
  
  auto dfs1 = [&](const auto& recF, int nd) -> A {
    int k = tree.num_children(nd);
    vector<M> ws(k);
    for (int i = 0; i < k; i++) {
      int c = tree.child(nd, i);
      ws[i] = mod1(recF(recF, c), nd, c);
    }
    sum_left[nd].resize(k + 1, unit);
    sum_right[nd].resize(k + 1, unit);
    for (int i = 0; i < k; i++) sum_left[nd][i + 1] = add(sum_left[nd][i], ws[i]);
    for (int i = k - 1; i >= 0; i--) sum_right[nd][i] = add(sum_right[nd][i + 1], ws[i]);
    return mod2(sum_right[nd][0], nd);
  };
  dfs1(dfs1, tree.root);

  auto dfs2 = [&](const auto& recF, int nd, const M& t) -> void {
    result[nd] = mod2(add(sum_right[nd][0], t), nd);
    int k = tree.num_children(nd);
    for (int i = 0; i < k; i++) {
      int c = tree.child(nd, i);
      M excl_c = add(sum_left[nd][i], sum_right[nd][i + 1]);
      M m_for_c = add(excl_c, t);
      A v_for_c = mod2(m_for_c, nd);
      M pass_c = mod1(v_for_c, c, nd);
      recF(recF, c, pass_c);
    }
  };
  dfs2(dfs2, tree.root, unit);
  
  return result;
}

template <typename M>
vector<M> reroot(Tree& tree, const M& unit, auto add, auto mod1) {
  return reroot<M>(tree, unit, add, mod1, [](const M& m, int i) -> M { return m; });
}

// ---- end tree.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  Board<ll> F(H, W, 0LL);
  cin >> F;

  ll maxht = 0;
  REP(i, 0, H) REP(j, 0, W) maxht = max(maxht, F.at(i, j));
  vector Ht(maxht + 1, vector<BrdIdx>());
  REP(i, 0, H) REP(j, 0, W) Ht[F.at(i, j)].push_back(BrdIdx{(int)i, (int)j});
  
  ll big = 1e18;
  vector parent(H*W, -1LL);
  vector size(H*W, 1LL);
  vector rec(H*W, big);
  auto leader = [&](ll e) -> ll {
    // DLOGKL("in", e);
    while (parent[e] >= 0) e = parent[e];
    // DLOGKL("out", e);
    return e;
  };
  REPrev(ht, maxht, 1) {
    for (auto bi : Ht[ht]) {
      for (auto dir : BrdIdx::nbr4) {
        auto bj = bi + dir;
        if (F.at(bj) >= F.at(bi)) {
          ll ai = leader(F.enc(bi));
          ll aj = leader(F.enc(bj));
          if (ai != aj) {
            if (size[ai] > size[aj]) swap(ai, aj);
            parent[ai] = aj;
            DLOGKL("parent", ai, aj);
            size[aj] += size[ai];
            rec[ai] = ht;
          }
        }
      }
    }
  }
  DLOGK(rec);
  ll root = leader(0);
  Tree tr(H*W, root);
  REP(i, 0, H*W) if (i != root) tr.add_edge(parent[i], i);
  ll Q; cin >> Q;
  REP(q, 0, Q) {
    ll a, b, y, c, d, z; cin >> a >> b >> y >> c >> d >> z; a--; b--; c--; d--;
    ll lca = tr.lca(F.enc(a, b), F.enc(c, d));
    DLOGK(a, b, c, d, F.enc(a, b), F.enc(c, d), lca);
    auto f = [&](ll e) -> ll {
      ll ret = maxht;
      while (e != lca) {
        ret = min(ret, rec[e]);
        e = parent[e];
      }
      return ret;
    };
    ll h = min(f(F.enc(a, b)), f(F.enc(c, d)));
    DLOGK(h);
    if (y >= h and z >= h) cout << y + z - 2 * h << "\n";
    else cout << abs(y - z) << "\n";
  }
  

  return 0;
}

