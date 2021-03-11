#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;



// @@ !! LIM()


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- board.cc

struct BrdIdx {
  int r;
  int c;
  BrdIdx(int r_, int c_) : r(r_), c(c_) {}
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
    return r < o.r || (r == o.r && c < o.c);
  }
  bool operator <=(const BrdIdx& o) const {
    return r < o.r || (r == o.r && c <= o.c);
  }
  bool operator >(const BrdIdx& o) const { return o < *this; }
  bool operator >=(const BrdIdx& o) const { return o <= *this; }
};
BrdIdx operator *(int k, const BrdIdx& o) { return o * k; }


template <typename T>
struct Board {
  int nR;
  int nC;
  T def;
  vector<T> data;
  int width;
  Board(int nR_, int nC_, T def_, int w = 0)
    : nR(nR_), nC(nC_), def(def_), data(nR*nC, def), width(w) {}
  int enc(int r, int c) const { return nC * r + c; }
  BrdIdx dec(int i) const { return BrdIdx(i / nC, i % nC); }

  bool in(int r, int c) const { return 0 <= r && r < nR && 0 <= c && c < nC; }
  bool in(const BrdIdx& bi) const { return in(bi.r, bi.c); }
  T& at(int r, int c) { return in(r, c) ? data.at(enc(r, c)) : def; }
  T& at(const BrdIdx& bi) { return at(bi.r, bi.c); }
};

template<typename T>
ostream& operator <<(ostream& os, Board<T> brd) {
  for (int i = 0; i < brd.nR; i++) {
    for (int j = 0; j < brd.nC; j++) {
      os << setw(brd.width) << brd.at(i, j);
    }
    os << "\n";
  }
  return os;
}

// @@ !! END ---- board.cc

int main() {

  Board<char> brd(5, 10, '.');
  brd.at(0,0) = brd.at(1,1) = brd.at(2,2) = brd.at(3,3) = 'o';
  brd.at(2,7) = brd.at(3,7) = brd.at(4,7) = 'x';
  ll num_o = 0, num_x = 0;
  for (ll i = 0; i < 5*10; i++) {
    BrdIdx bi = brd.dec(i);
    if      (brd.at(bi) == 'o') num_o ++;
    else if (brd.at(bi) == 'x') num_x ++;
  }
  assert(num_o == 4);
  assert(num_x == 3);
  brd.at(0,1) = 'x';
  brd.at(3,6) = 'x';
  BrdIdx biE = BrdIdx(0, 1);
  BrdIdx biS = BrdIdx(1, 0);
  vector<BrdIdx> dirs = {biE, biS, -biE, -biS};
  BrdIdx bi2(0,2), bi3(4,6);
  ll cnt = 0;
  for (BrdIdx dir : dirs) if (brd.at(bi2 + dir) == 'x') cnt++;
  assert(cnt == 1);
  cnt = 0;
  for (BrdIdx dir : dirs) if (brd.at(bi3 + dir) == 'x') cnt++;
  assert(cnt == 2);
  
  assert(brd.at(5, 4) == '.' && brd.at(2, -7) == '.');
  BrdIdx bi4(2, 3);
  assert(bi4 + bi3 == BrdIdx(6, 9));
  assert(bi4 - bi3 == BrdIdx(-2, -3));
  assert(bi4 * 2 == bi3 && 2 * bi4 == bi3);
  assert(-bi4 == BrdIdx(-2, -3));
  assert(bi4 == bi4);
  assert(bi4 != bi3);
  assert(bi4 < bi3);
  assert(bi4 < BrdIdx(3,0));
  
  Board<ll> brd2(3, 3, 0, 5);
  brd2.at(0,1) = 100;
  brd2.at(1,2) = -43;
  brd2.at(2,0) = 57;
  stringstream ss; ss << brd2;
  assert(ss.str() == "    0  100    0\n    0    0  -43\n   57    0    0\n");

  cout << "Test done." << endl;
}
