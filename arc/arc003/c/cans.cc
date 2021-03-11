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

  ll N, M; cin >> N >> M;
  Board<double> brd(N, M, -1.0);
  BrdIdx start(0,0), goal(0,0);
  for (ll r = 0; r < N; r++) {
    string s; cin >> s;
    for (ll c = 0; c < M; c++) {
      if (s.at(c) == 's') {
	brd.at(r, c) = 10;
	start = BrdIdx(r, c);
      }else if (s.at(c) == 'g') {
	brd.at(r, c) = 10;
	goal = BrdIdx(r, c);
      }else if (s.at(c) == '#') {
	brd.at(r, c) = -1;
      }else {
	brd.at(r, c) = s.at(c) - '0';
      }
    }
  }

  vector<BrdIdx> dirs({ {-1,0}, {1,0}, {0,1}, {0,-1} });

  using Pair = pair<double, double>;
  vector<Pair> rec(N*M, {-1, -1});

  using TQ = pair<Pair, BrdIdx>;
  priority_queue<TQ> pque;

  pque.push(make_pair(make_pair(100.0, 1.0), start));
  while (!pque.empty()) {
    TQ q = pque.top(); pque.pop();
    Pair p = q.first; BrdIdx i = q.second;
    double br = p.first; double red = p.second;
    Pair cp = rec.at(brd.enc(i));
    double cbr = cp.first; double cred = cp.second;
    if (cbr >= br && cred >= red) continue;
    if (i == goal) {
      cout << br << endl;
      return 0;
    }
    rec.at(brd.enc(i)) = p;
    red *= 0.99;
    for (BrdIdx d : dirs) {
      double v = brd.at(i + d);
      if (v < 0) continue;
      double newBr = min(v * red, br);
      Pair zp = rec.at(brd.enc(i + d));
      double zbr = zp.first; double zred = zp.second;
      if (zbr >= newBr && zred >= red) continue;
      pque.push(make_pair(make_pair(newBr, red), i + d));
    }
  }
  cout << -1 << endl;


  return 0;
}

