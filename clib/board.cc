#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  // Board

  ll H, W; cin >> H >> W;

  // If Just reading is sufficient:
  Board<char> brd(cin, H, W, '#');
  // or, equivalently:
  Board<char> brd(H, W, '#');
  for (ll r = 0; r < H; r++) {
    string s; cin >> s;
    for (ll c = 0; c < W; c++) brd.set(r, c, s.at(c));
  }
  // The last param of the constructor ('#', in this case) is the
  // default value.  The value is used as an initial value.

  // The following two are the basic:
  //     brd.set(r, c, value);
  //     value = brd.get(r, c);
  // when (r,c) is out of range, brd.set() simply does nothing,
  // and brd.get() returns the default value.

  // at() is also available, though a bit dangeours and inefficient.
  //     brd.at(r, c) = value        // (1)
  //     value = brd.at(r, c)        // (2)
  // when (r,c) is out of range, (1) sets the value to some specific place
  // and successing call of (2) throws an exception.

  // BrdIdx can be used for (r,c) pair:
  //     BrdIdx bi(r, c);
  //     val = brd.get(bi);  // equivallent to   val = brd.get(r, c);

  // An index can be checked whether it is on the board with
  // brd.in(r, c) or brd.in(bi) for BrdIdx bi.

  // Internal store is 1-dimensional array.  enc/dec can be done with:
  //    enc(r, c), enc(BrdIdx(r, c)), dec(i), decIdx(i) 

  // operator "<<" is supported.  For width, use brd.setDispWidth(w).

  // BrdIdx is the object for indexing.  It is mostly the same as 
  // pair<int, int>, but has +, -, *, etc.
  // Thus, for example:
  vector<BrdIdx> dirs({{1,0}, {0,1}, {-1,0}, {0,-1}});
  for (BrdIdx p : dirs) { ... brd.at(i + p) ... }

  // Frequently used vector<BrdIdx> are defined:
    BrdIdx::nbr4   // the same as dirs above
    BrdIdx::nbr5
    BrdIdx::nbr8
    BrdIdx::nbr9

  // bi.rotateQ() returns a BrdIdx obtained by rotating bi 
  // by pi/2 counterclockwise.

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
struct Board {

  void readData(istream& is) {
    for (int i = 0; i < nR; i++) {
      for (int j = 0; j < nC; j++) {
	T t; is >> t;
	set(i, j, t);
      }
    }
  }

  const int nR;
  const int nC;
  const T def;
  vector<T> data;
  int dispWidth;
  T __dummy;

  Board(int nR_, int nC_, T def_)
    : nR(nR_), nC(nC_), def(def_), data(nR*nC, def),
      dispWidth(0), __dummy(def_) {}
  Board(istream& is, int nR_, int nC_, T def_)
    : nR(nR_), nC(nC_), def(def_), data(nR*nC, def),
      dispWidth(0), __dummy(def_) {
    readData(is);
  }
  BrdIdx bIdx(int r = 0, int c = 0) { return BrdIdx(r, c); }
  int enc(int r, int c) const { return nC * r + c; }
  int enc(const BrdIdx& bi) const { return nC * bi.r + bi.c; }
  pair<int, int> dec(int i) const { return make_pair(i / nC, i % nC); }
  BrdIdx decIdx(int i) const { return BrdIdx(i / nC, i % nC); }
  bool in(int r, int c) const { return 0 <= r && r < nR && 0 <= c && c < nC; }
  bool in(const BrdIdx& bi) const { return in(bi.r, bi.c); }

  // Note: implementing T& at(r, c) is problematic.
  //   When "brd.at(r,c) = value;" is executed, we need to provide some
  //   object even when (r,c) is out of bounds.  But after that if the
  //   user want the value at (r,c), there is no way to return the default
  //   value.  Thus, there is no better alternative than providing get/set.
  const T get(int r, int c) const {
    return in(r, c) ? data.at(enc(r, c)) : def;
  }
  const T get(const BrdIdx& bi) const { return get(bi.r, bi.c); }
  // Note: returning a reference (const T& get(...)) is problematic
  //       when T is bool.  (vector<bool> is implemented in a specific way)
  void set(int r, int c, T t) { if (in(r, c)) data.at(enc(r, c)) = t; }
  void set(const BrdIdx& bi, T t) { set(bi.r, bi.c, t); }

  T& at(int r, int c) {
    if (in(r, c)) return data.at(enc(r, c));
    if (__dummy == def) return __dummy;
    string msg = "Error: boards' __dummy holds an incorrect value.  Perhaps you should use get/set instead of at.";
    throw runtime_error(msg);
  }
  T& at(const BrdIdx& bi) { return at(bi.r, bi.c); }

  void setDispWidth(int w) { dispWidth = w; }
};

template<typename T>
ostream& operator <<(ostream& os, const Board<T>& brd) {
  for (int r = 0; r < brd.nR; r++) {
    for (int c = 0; c < brd.nC; c++) {
      os << setw(brd.dispWidth) << brd.get(r, c);
    }
    if (r < brd.nR - 1) os << "\n";
  }
  return os;
}

// @@ !! END ---- board.cc

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
    Board<char> brd1(ss1, 4, 5, '#');
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

  cout << "Test done." << endl;

}
