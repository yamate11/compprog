#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(board)
// --> board
// ---- inserted library file board.cc

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
ostream& operator <<(ostream& os, const BrdIdx& i) {
  os << "(" << i.r << "," << i.c << ")";
  return os;
}

template <typename T>
struct Board {
  void init(int nR_, int nC_, T def_) {
    nR = nR_;
    nC = nC_;
    def = def_;
    data.resize(nR*nC, def);
  }

  void readData(istream& is) {
    for (int i = 0; i < nR; i++) {
      for (int j = 0; j < nC; j++) is >> at(i, j);
    }
  }

  int nR;
  int nC;
  T def;
  vector<T> data;
  Board(int nR_, int nC_, T def_) { init(nR_, nC_, def_); }
  Board(istream& is, int nR_, int nC_, T def_) {
    init(nR_, nC_, def_);
    readData(is);
  }
  BrdIdx bIdx(int r = 0, int c = 0) { return BrdIdx(nR, nC, r, c); }
  int enc(int r, int c) const { return nC * r + c; }
  int enc(const BrdIdx& bi) const { return nC * bi.r + bi.c; }
  pair<int, int> dec(int i) const { return make_pair(i / nC, i % nC); }
  BrdIdx decIdx(int i) const { return BrdIdx(i / nC, i % nC); }
  bool in(int r, int c) const { return 0 <= r && r < nR && 0 <= c && c < nC; }
  bool in(const BrdIdx& bi) const { return in(bi.r, bi.c); }
  T& at(int r, int c) { return in(r, c) ? data.at(enc(r, c)) : def; }
  T& at(const BrdIdx& bi) { return at(bi.r, bi.c); }
};


// ---- end board.cc
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  Board<char> brd(cin, H, W, '@');
  vector<BrdIdx> dirs({{1,0}, {0,1}});
  
  Board<ll> eval(H, W, LLONG_MAX); // accumulator
  using Pair = pair<ll, BrdIdx>;
  deque<Pair> deq;
  ll e0 = brd.at(0,0) == '#' ? 1 : 0;
  eval.at(0, 0) = e0;
  deq.emplace_back(e0, BrdIdx(0,0));
  while (!deq.empty()) {
    Pair p = deq.front(); deq.pop_front();
    ll e = p.first;
    BrdIdx i = p.second;
    if (eval.at(i) < e) continue;
    for (BrdIdx d : dirs) {
      if (! brd.in(i + d)) continue;
      ll incE = (brd.at(i) == '.' && brd.at(i+d) == '#') ? 1 : 0;
      if (eval.at(i+d) <= e + incE) continue;
      eval.at(i+d) = e + incE;
      if (incE) deq.emplace_back(e + 1, i + d);
      else      deq.emplace_front(e,    i + d);
    }
  }
  cout << eval.at(H-1, W-1) << endl;

  return 0;
}

