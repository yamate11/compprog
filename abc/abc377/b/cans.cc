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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  Board<char> brd(8, 8, '@');
  Board<char> res(8, 8, '.');
  cin >> brd;
  REP(i, 0, 8) REP(j, 0, 8) {
    if (brd.at(i, j) == '#') {
      REP(k, 0, 8) res.rs(i, k) = '#';
      REP(k, 0, 8) res.rs(k, j) = '#';
    }
  }
  ll cnt = 0;
  REP(i, 0, 8) REP(j, 0, 8) {
    if (res.at(i, j) == '.') cnt++;
  }
  cout << cnt << endl;
  
  return 0;
}

