#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  // Board

  ll H, W; cin >> H >> W;

  Board<char> brd(H, W, '#');
  // The last param of the constructor ('#', in this case) is the
  // default value.  The value is also used as the initial value.

  cin >> brd;
  // or, equivalently,
  for (ll r = 0; r < H; r++) {
    string s; cin >> s;
    for (ll c = 0; c < W; c++) brd.at(r, c) = s[c];
  }

  // The following two are the basic:
  //     brd.set(r, c, value);
  //     value = brd.get(r, c);
  // when (r,c) is out of range, brd.set() simply does nothing,
  // and brd.get() returns the default value.

  // at() is also available, though a bit dangeours
  //     brd.at(r, c) = value        // (1)
  //     value = brd.at(r, c)        // (2)
  // when (r,c) is out of range, (1) sets the value to some specific place
  // and successing call of (2) throws an exception.

  // BrdIdx can be used for (r,c) pair:
  //     BrdIdx bi(r, c);
  //     val = brd.at(bi);  // equivallent to   val = brd.at(r, c);

  // An index can be checked whether it is on the board with
  // brd.in(r, c) or brd.in(bi) for BrdIdx bi.

  // 2dim -> 1dim encoding is supported.
  //   brd.enc(r, c) and brd.enc(bi) for encoding
  //   bi = brd.dec(e) for decoding

  // Operators ">>" and "<<" are supported.  
  // For width, use brd.setDispWidth(w).

  // A board can be transposed, reversed (both vertically and horizontally),
  // and rotated, using transpose(), reverse_row(), reverse_col(), and
  // rotate(r), where integer r denotes r * pi / 4 counter-clockwise.
  // In-place versions are available through transpose_inp() etc.

  // BrdIdx is the object for indexing.  It is mostly the same as 
  // pair<int, int>, but has +, -, *, etc.
  // Thus, for example:
  vector<BrdIdx> dirs({{1,0}, {0,1}, {-1,0}, {0,-1}});
  for (BrdIdx p : dirs) { ... brd.at(i + p) ... }

  // Frequently used vector<BrdIdx> are defined:
    BrdIdx::nbr4   //       DOWN,     RIGHT,     UP,     LEFT
    BrdIdx::nbr4D  //             DR,        UR,     UL,       DL
    BrdIdx::nbr5   // SELF, DOWN,     RIGHT,     UP,     LEFT
    BrdIdx::nbr8   //       DOWN, DR, RIGHT, UR, UP, UL, LEFT, DL
    BrdIdx::nbr9   // SELF, DOWN, DR, RIGHT, UR, UP, UL, LEFT, DL

  // bi.rotateQ() returns a BrdIdx obtained by rotating bi 
  // by pi/2 counterclockwise.  Thus, BrdIdx::nbr4 has the same elements as
  // {e1, e1.rotateQ(1), e1.rotateQ(2), e1.rotateQ(3)} where e1 = BrdIdx(1, 0).

 */


// @@ !! LIM()

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- board.cc

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
  // Board(const Board&), Board(Board&&), operator=(const Board&), operator=(Board&&) are automatically generated.

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

  long long enc(int r, int c) { return in(r, c) ? r * nC + c : -1; }
  long long enc(const BrdIdx& bi) { return enc(bi.r, bi.c); }
  BrdIdx dec(long long e) {
    if (e < 0) return BrdIdx(-1, -1);
    int r = e / nC;
    int c = e % nC;
    if (in(r, c)) return BrdIdx(r, c);
    else return BrdIdx(-1, -1);
  }

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


// @@ !! END ---- board.cc

