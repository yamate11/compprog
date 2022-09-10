#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM(board forall)

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

// ---- inserted library file forall.cc

#define EX_REP_LL(i, from, to) for (ll i = from; i < to; i++)
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

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// @@ !! LIM -- end mark --

void solve() {
  ll N, M; cin >> N >> M;
  Board<char> A(N, N, 'X'), B(M, M, 'X');
  cin >> A >> B;
  cout << (EXISTS(i, 0, N,
           EXISTS(j, 0, N,
           FORALL(k, 0, M,
           FORALL(l, 0, M,
           A.at(i + k, j + l) == B.at(k, l))))) ?
           "Yes\n" : "No\n");
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  solve();
  return 0;
}

