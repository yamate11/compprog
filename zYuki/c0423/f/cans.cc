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

// @@ !! LIM(board UnionFind cmpNaive forall)

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

template <typename T>
class Board {

  bool tr_rc;
  bool tr_row;
  bool tr_col;
  const int nR;
  const int nC;
  const T def;
  vector<T> data;
  int dispWidth;

  int enc(int r, int c) const {
    if (tr_rc) swap(r, c);
    if (tr_row) r = nR - 1 - r;
    if (tr_col) c = nC - 1 - c;
    if (r < 0 || nR <= r || c < 0 || nC <= c) return nC * nR;
    return nC * r + c;
  }
  int enc(const BrdIdx& bi) const { return enc(bi.r, bi.c); }

  static const vector<int> rotate_tbl;

  void set_for_rotate() {
    int x = (tr_rc << 2) | (tr_row << 1) | tr_col;
    int y = rotate_tbl[x];
    tr_rc  = (y >> 2) & 1;
    tr_row = (y >> 1) & 1;
    tr_col = (y >> 0) & 1;
  }

public:

  Board(int nR_, int nC_, T def_)
    : tr_rc(false), tr_row(false), tr_col(false),
      nR(nR_), nC(nC_), def(def_), data(nR*nC + 1, def),
      dispWidth(0) {}

  int numRows() const { return tr_rc ? nC : nR; }
  int numCols() const { return tr_rc ? nR : nC; }

  bool in(int r, int c) const {
    if (tr_rc) return 0 <= r && r < nC && 0 <= c && c < nR;
    else       return 0 <= r && r < nR && 0 <= c && c < nC;
  }

  // Note: We cannot implemen T& at(r, c) in a perfect way.
  //   When (r,c) is out of bounds, brd.at(r,c) returns brd.data[nR*nC]
  //   and its value should equal to that of brd.def.  But once
  //   "brd.at(r,c) = val;" (with (r,c) out of bounds) is executed,
  //   this no longer holds.
  //   If you need this sequence, you must use "brd.set(r,c,val);".
  typename vector<T>::reference at(int r, int c) {
    if (in(r, c)) return data[enc(r, c)];
    if (data[nR*nC] == def) return data[nR*nC];
    string msg = "Error: boards' __dummy holds an incorrect value.  Perhaps you should use get/set instead of at.";
    throw runtime_error(msg);
  }
  typename vector<T>::const_reference at(int r, int c) const {
    return in(r,c) ? data[enc(r, c)] : def;
  }
  void set(int r, int c, T t) { if (in(r, c)) data[enc(r, c)] = t; }
  const T get(int r, int c) const { return in(r,c) ? data[enc(r, c)] : def; }

  bool in(const BrdIdx& bi) const { return in(bi.r, bi.c); }
  typename vector<T>::reference at(const BrdIdx& bi) { return at(bi.r, bi.c); }
  typename vector<T>::const_reference
      at(const BrdIdx& bi) const { return at(bi.r, bi.c); }
  const T get(const BrdIdx& bi) const { return get(bi.r, bi.c); }
  void set(const BrdIdx& bi, T t) { set(bi.r, bi.c, t); }

  void transpose_inp() { tr_rc = !tr_rc; }
  void reverse_row_inp() { tr_row = !tr_row; }
  void reverse_col_inp() { tr_col = !tr_col; }
  
  void rotate_inp(int r) {
    r = r % 4;
    if (r < 0) r += 4;
    for (; r > 0; r--) set_for_rotate();
  }
  Board transpose() const
  { Board ret(*this); ret.transpose_inp(); return ret; }
  Board reverse_row() const
  { Board ret(*this); ret.reverse_row_inp(); return ret; }
  Board reverse_col() const
  { Board ret(*this); ret.reverse_col_inp(); return ret; }
  Board rotate(int r) const
  { Board ret(*this); ret.rotate_inp(r); return ret; }

  void setDispWidth(int w) { dispWidth = w; }

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
        os << setw(brd.dispWidth) << brd.get(r, c);
      }
      if (r < brd.numRows() - 1) os << "\n";
    }
    return os;
  }

};
template<typename T>
const vector<int> Board<T>::rotate_tbl({5,4,7,6,2,3,0,1});

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

// ---- inserted library file UnionFind.cc

template<typename T = ll, typename oplus_t = decltype(plus<T>()), typename onegate_t = decltype(negate<T>())>
struct UnionFind {
  int size;
  T zero;
  oplus_t oplus;
  onegate_t onegate;
  vector<pair<int, optional<T>>> _leader;
  vector<int> _gsize;
  bool built_groups;
  int _num_groups;
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

  void build_groups() {
    if (not built_groups) {
      _num_groups = 0;
      for (int j = 0; j < size; j++) if (leader(j) == j) _num_groups++;
      _groups.resize(size);
      for (int j = 0; j < size; j++) _groups[j].resize(0);
      for (int j = 0; j < size; j++) _groups[leader(j)].push_back(j);
      built_groups = true;
    }
  }

  int numGroups() {
    build_groups();
    return _num_groups;
  }

  const vector<int>& group(int i) {
    build_groups();
    return _groups[leader(i)];
  }

};

template<typename T = ll>
auto makeUnionFind(int size, T zero, auto oplus, auto onegate) {
  return UnionFind<T, decltype(oplus), decltype(onegate)>(size, zero, oplus, onegate);
}

// ---- end UnionFind.cc

// ---- inserted library file cmpNaive.cc

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

// ---- inserted library file forall.cc

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

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  ll H, W, N, D; cin >> H >> W >> N >> D;
  // @InpMVec(N, (X, Y)) [rAE6TPNV]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [rAE6TPNV]

  X.push_back(-1);
  Y.push_back(-1);

  ll vmax = -1;
  ll vmin = 1e18;
  REP(x, 1, H + 1) REP(y, 1, W + 1) {
    if (FORALL(i, 0, N, X[i] != x or Y[i] != y)) {
      X[N] = x;
      Y[N] = y;
      UnionFind uf(N + 1);
      REP(i, 0, N + 1) REP(j, i + 1, N + 1) {
        if (abs(X[i] - X[j]) + abs(Y[i] - Y[j]) <= D) uf.merge(i, j);
      }
      ll num = 0;
      REP(i, 0, N + 1) if (uf.leader(i) == i and uf.groupSize(i) >= 2) num++;
      vmax = max(num, vmax);
      vmin = min(num, vmin);
    }
  }
  cout << vmin << " " << vmax << endl;

  return 0;
}

int body(istream& cin, ostream& cout) {
  ll H, W, N, D; cin >> H >> W >> N >> D;

  vector X(N, 0LL);
  vector Y(N, 0LL);

  // Board<bool> brd(H, W, false);
  Board<int> idx(H, W, -1);
  REP(i, 0, N) {
    ll x, y; cin >> x >> y; x--; y--;
    // brd.at(x, y) = true;
    idx.at(x, y) = i;
    X[i] = x;
    Y[i] = y;
  }
  
  UnionFind uf(N);
  REP(i, 0, N) {
    REP(x, -D, D + 1) REP(y, -(D - abs(x)), D - abs(x) + 1) {
      if (x == 0 and y == 0) continue;
      ll j = idx.at(X[i] + x, Y[i] + y);
      if (j >= 0) uf.merge(i, j);
    }
  }
  
  ll ng = 0;
  REP(i, 0, N) if (uf.leader(i) == i and ssize(uf.group(i)) >= 2) ng++;
  ll vmax = -1;
  ll vmin = 1e18;
  vector<ll> color(N);
  REP(x0, 0, H) REP(y0, 0, W) {
    vector<ll> this_color;
    bool single_conn = false;
    if (idx.at(x0, y0) == -1) {
      // ll cnt = 0;
      REP(x, -D, D + 1) REP(y, -(D - abs(x)), D - abs(x) + 1) {
        ll j = idx.at(x0 + x, y0 + y);
        if (j >= 0) {
          ll ld = uf.leader(j);
          if (ssize(uf.group(ld)) == 1) single_conn = true;
          else {
            if (not color[ld]) {
              color[ld] = true;
              this_color.push_back(ld);
            }
          }
        }
      }
      ll sz = ssize(this_color);
      ll num;
      if (sz >= 1) num = ng - (sz - 1);
      else if (single_conn) num = ng + 1;
      else num = ng;
      vmax = max(vmax, num);
      vmin = min(vmin, num);
      for (ll c : this_color) color[c] = false;
    }
  }
  cout << vmin << " " << vmax << endl;

  return 0;
}

