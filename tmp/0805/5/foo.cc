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
  // Note: Board<bool> is supported and should work.

  // BrdIdx can be used for (r,c) pair:
  //     BrdIdx bi(r, c);
  //     val = brd.at(bi);  // equivallent to   val = brd.at(r, c);

  // An index can be checked whether it is on the board with
  // brd.in(r, c) or brd.in(bi) for BrdIdx bi.

  // An index can be encoded into an integer and vice versa:
  //      int e = brd.enc(bi);      // 0 <= e < brd.numRows() * brd.numCols() if brd.in(bi) is true.
  //      BrdIdx bi = brd.dec(e);

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

template <typename T> struct BoardRot;

template <typename T>
class Board {

  const int nR;
  const int nC;
  const T def;
  vector<T> data;
  int dispWidth;

public:

  // Note: These types are usually T& and const T&, but different in the case of vector<bool>
  using reference = typename vector<T>::reference;
  using const_reference = typename vector<T>::const_reference;

  Board(int nR_, int nC_, T def_) : nR(nR_), nC(nC_), def(def_), data(nR*nC + 1, def), dispWidth(0) {}

  int numRows() const { return nR; }
  int numCols() const { return nC; }

  bool in(int r, int c) const { return 0 <= r && r < nC && 0 <= c && c < nR; }
  // Note: We cannot implement T& at(r, c) in a perfect way.
  //   When (r,c) is out of bounds, brd.at(r,c) returns brd.data[nR*nC]
  //   and its value should equal to that of brd.def.  But once
  //   "brd.at(r,c) = val;" (with (r,c) out of bounds) is executed,
  //   this no longer holds.
  //   If you need this sequence, you must use "brd.set(r,c,val);".
  int at_sub(int r, int c) const {
    if (in(r, c)) return enc(r, c);
    if (data[nR*nC] == def) return nR*nC;
    string msg = "Error: boards' __dummy holds an incorrect value.  Perhaps you should use get/set instead of at.";
    throw runtime_error(msg);
  }
  reference at(int r, int c) { return data[at_sub(r, c)]; }
  const_reference at(int r, int c) const { return data[at_sub(r, c)]; }
  reference get(int r, int c) { return at(r, c); }
  void set(int r, int c, T t) { if (in(r, c)) data[enc(r, c)] = t; }

  bool in(const BrdIdx& bi) const { return in(bi.r, bi.c); }
  reference at(const BrdIdx& bi) { return at(bi.r, bi.c); }
  const_reference at(const BrdIdx& bi) const { return at(bi.r, bi.c); }
  reference get(const BrdIdx& bi) { return get(bi.r, bi.c); }
  void set(const BrdIdx& bi, T t) { set(bi.r, bi.c, t); }

  int enc(int r, int c) const { return in(r, c) ? nC * r + c : -1; }
  int enc(const BrdIdx& bi) const { return enc(bi.r, bi.c); }
  BrdIdx dec(int e) const { return 0 <= e and e < nR * nC ? BrdIdx(e / nC, e % nC) : BrdIdx(-1, -1); }

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

  friend struct BoardRot<T>;

};

template <typename T>
class BoardRot {

  vector<vector<int>> mat{{1, 0}, {0, 1}};
  vector<vector<int>> mat_inv{{1, 0}, {0, 1}};

  static vector<vector<vector<int>>> rotate_m;
  static vector<vector<int>> transpose_m, transpose_row_m, transpose_col_m;

  vector<vector<int>> mat_prod(auto& m1, auto& m2) {
    vector ret(2, vector(2, 0));
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
        ret[i][j] = 0;
        for (int k = 0; k < 2; k++) ret[i][j] += m1[i][k] + m2[k][j];
      }
    return ret;
  }

public:

  using reference = typename vector<T>::reference;
  using const_reference = typename vector<T>::const_reference;

  Board<T>& board;

  BoardRot(Board<T>& b) : board(b) {}
  BrdIdx co_trans(const BrdIdx& bi) {
  }
  
  bool in(const BrdIdx& bi) const { return board.in(co_trans(bi)); }
  reference at(const BrdIdx& bi) { return board.at(co_trans(bi)); }
  const_reference at(const BrdIdx& bi) const { return board.at(co_trans(bi)); }
  bool in(int r, int c) const { return in(BrdIdx(r, c)); }
  reference at(int r, int c) { return at(BrdIdx(r, c)); }
  const_reference at(int r, int c) const { return at(BrdIdx(r, c)); }

  int enc(const BrdIdx& bi) const { return board.enc(co_trans(bi)); }
  int enc(int r, int c) const { return enc(BrdIdx(r, c)); }
  BrdIdx dec(int e) const { return co_trans_inv(board.dec(e)); }

  void rotate(int r) {
    r = r % 4;
    if (r == 0) return;
    if (r < 0) r += 4;
    mat = mat_prod(mat, rotate_m[r]);
    mat_inv = mat_prod(mat_inv, rotate_m[4 - r]);
  }
  void transpose() {
    //    mat = mat_prod(mat, 
  }

};

vector<vector<vector<int>>> BoardRot::rotate_m{{{1,0},{0,1}},{{0,1},{-1,0}},{{-1,0},{0,-1}},{{0,-1},{1,0}}};
vector<vector<int>> BoardRot::transpose_m{{0,1},{1,0}};
vector<vector<int>> BoardRot::transpose_row{{
vector<vector<int>> BoardRot::transpose_m{{0,1},{1,0}};





// @@ !! END ---- board.cc

// @@ !! LIM()

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


  cout << "Test done." << endl;

}
