#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(board)

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

  static vector<BrdIdx> nbr4, nbr5, nbr8, nbr9;
};

vector<BrdIdx>
  BrdIdx::nbr4({      {1,0},      {0,1},       {-1,0},        {0,-1}       }),
  BrdIdx::nbr5({{0,0},{1,0},      {0,1},       {-1,0},        {0,-1}       }),
  BrdIdx::nbr8({      {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}}),
  BrdIdx::nbr9({{0,0},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}});

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

// @@ !! LIM -- end mark --

template<typename T>
bool same(const Board<T>& brdA, const Board<T>& brdB) {
  int nRA = brdA.numRows(), nRB = brdB.numRows(),
    nCA = brdA.numCols(), nCB = brdB.numCols();
  if (nRA != nRB || nCA != nCB
      || brdA.at(nRA, nCA) != brdB.at(nRB, nCB)) return false;
  for (ll r = 0; r < brdA.numRows(); r++) {
    for (ll c = 0; c < brdA.numCols(); c++) {
      if (brdA.at(r, c) != brdB.at(r, c)) return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  
  {
    stringstream ss1("..#..\n..#..\n....#\n.#...\n");
    /*
      ..#..
      ..#..
      ....#
      .#...
    */
    Board<char> brd1(4, 5, '#');
    ss1 >> brd1;
    assert(brd1.get(0,0) == '.');
    assert(brd1.get(0,2) == '#');
    assert(brd1.get(-1,0) == '#');
    assert(brd1.get(4,4) == '#');
    assert(brd1.get(3,4) == '.');
    brd1.set(BrdIdx(2, 0), 'X');
    BrdIdx i(1,0);
    string tmp1;
    for (auto d : BrdIdx::nbr4) tmp1 += brd1.get(i + d);
    assert(tmp1 == "X..#");
  }

  {
    ll H2 = 5, W2 = 3;
    Board<ll> brd2(H2, W2, -1);
    for (ll r = 0; r < H2; r++) {
      for (ll c = 0; c < W2; c++) brd2.set(r, c, r + c);
    }
    BrdIdx i2(0, 0);
    ll sum2 = 0;
    for (BrdIdx ii = i2; brd2.get(ii) >= 0; ii += BrdIdx(1, 0)) {
      for (BrdIdx jj = ii; brd2.get(jj) >= 0; jj += BrdIdx(0, 1)) {
	sum2 += brd2.get(jj);
      }
    }
    assert(sum2 == 45);
  }

  {
    ll H = 3, W = 3;
    Board<ll> brd(H, W, -1);
    brd.at(1, 1) = 10;
    brd.set(-10, -10, 1000);
    assert(brd.at(-10, -10) == -1);
    assert(brd.at(-1, -1) == -1);
    brd.at(-10, -10) = 1000;
    assert(brd.get(-1, -1) == -1);
    try {
      brd.at(-1, -1);
      assert(0);
    }catch(const runtime_error& e) {
    }
    assert(brd.at(1, 1) == 10);
  }

  for (ll i = 0; i < 4; i++) {
    assert(BrdIdx::nbr4.at((i+1)%4) == BrdIdx::nbr4.at(i).rotateQ());
  }

  {
    Board<char> brd1(3, 4, '.');
    brd1.at(0, 0) = '#';
    assert(brd1.at(0, 0) == '#');

    Board<bool> brd2(3, 4, false);
    brd2.at(0, 0) = true;
    assert(brd2.at(0, 0));

    auto func3 = [&](Board<char>& brd3) -> void {
      brd3.at(0, 1) = '#'; 
      assert(brd3.at(0, 0) == '#');
    };

    auto func4 = [&](Board<bool>& brd4) -> void {
      brd4.at(0, 1) = '#'; 
      assert(brd4.at(0, 0));
    };

    auto func5 = [&](const Board<char>& brd5) -> void {
      // brd5.at(0, 1) = '#'; // compilation error
      assert(brd5.at(0, 0) == '#');
    };

    auto func6 = [&](const Board<bool>& brd6) -> void {
      // brd6.at(0, 1) = '#'; // compilation error
      assert(brd6.at(0, 0));
    };

    func3(brd1);
    func4(brd2);
    func5(brd1);
    func6(brd2);

    Board<char> brd7(brd1);
    Board<bool> brd8(brd2);
    Board<char> brd9 = brd1;
    Board<bool> brd10 = brd2;
    assert(same(brd7,brd1));
    assert(same(brd8,brd2));
    assert(same(brd9,brd1));
    assert(same(brd10,brd2));
  }
  {
    Board<char> brd0(3, 4, '@');
    stringstream("##.#\n...#\n.#..") >> brd0;
    Board<char> brd1(4, 3, '@');
    stringstream("#..\n#.#\n...\n##.\n") >> brd1;
    assert(same(brd0.transpose(), brd1));
    assert(same(brd0.transpose().transpose(), brd0));
    Board<char> brd2(3, 4, '@');
    stringstream(".#..\n...#\n##.#\n") >> brd2;
    assert(same(brd0.reverse_row(), brd2));
    Board<char> brd3(3, 4, '@');
    stringstream("#.##\n#...\n..#.\n") >> brd3;
    assert(same(brd0.reverse_col(), brd3));

    assert(same(brd0.rotate(0), brd0));
    Board<char> brdR1(4, 3, '@');
    stringstream("##.\n...\n#.#\n#..\n") >> brdR1;
    assert(same(brd0.rotate(1), brdR1));
    Board<char> brdR2(3, 4, '@');
    stringstream("..#.\n#...\n#.##\n") >> brdR2;
    // DLOGK(brd0);
    // DLOGK(brdR2);
    // DLOGK(brd0.rotate(1));
    assert(same(brd0.rotate(2), brdR2));
    Board<char> brdR3(4, 3, '@');
    stringstream("..#\n#.#\n...\n.##\n") >> brdR3;
    assert(same(brd0.rotate(3), brdR3));
    assert(same(brd0.rotate(-1), brdR3));
    assert(same(brd0.rotate(-5), brdR3));
    assert(same(brd0.rotate(7), brdR3));

    assert(same(brd0.transpose().rotate(0), brd1));
    assert(same(brd0.transpose().rotate(1), brdR3.transpose()));
    assert(same(brd0.transpose().rotate(2), brdR1.reverse_col()));
    assert(same(brd0.transpose().rotate(3), brd0.reverse_col()));
  }
  {
    Board<char> brd0(3, 4, '@');
    stringstream("##.#\n...#\n.#..") >> brd0;
    for (BrdIdx& bi : BoardRange(brd0)) {
      if (brd0.at(bi) == '#') brd0.at(bi) = '?';
    }
    stringstream sout;
    sout << brd0;
    assert(sout.str() == "??.?\n...?\n.?..");

    Board<bool> brd1(3, 4, false);
    brd1.at(1, 2) = true;
    for (BrdIdx& bi : BoardRange(brd1)) {
      if (bi.r == 1 && bi.c == 2) assert(brd1.at(bi) == true);
      else assert(brd1.at(bi) == false);
    }
  }


  cout << "Test done." << endl;

}
