#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

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

  void readData(const istream& is) {
    for (int i = 0; i < nR; i++) {
      for (int j = 0; j < nC; j++) is >> data.at(i).at(j);
    }
  }

  int nR;
  int nC;
  T def;
  vector<T> data;
  Board(int nR_, int nC_, T def_) { init(nR_, nC_, def_); }
  Board(const istream& is, int nR_, int nC_, T def_) {
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

struct MyException : exception {};

using Vec1 = vector<bool>;
using Vec2 = vector<Vec1>;
using Vec3 = vector<Vec2>;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;

  Board<char> brd(H, W, '@');
  vector<BrdIdx> dirs({{-1,0}, {1,0}, {0,-1}, {0,1}});
  BrdIdx start(0,0), goal(0,0);
  for (ll r = 0; r < H; r++) {
    string s; cin >> s;
    for (ll c = 0; c < W; c++) { 
      brd.at(r, c) = s.at(c);
      if (brd.at(r, c) == 's') {
	start = BrdIdx(r, c);
      }else if (brd.at(r, c) == 'g') {
	goal = BrdIdx(r, c);
      }
    }
  }
  Vec3 visited(H, Vec2(W, Vec1(3)));
  auto dfs = [&](const auto& recF, const BrdIdx& i, ll lev) -> void {
    if (i == goal) throw MyException();
    if (brd.at(i) == '@') return;
    if (brd.at(i) == '#' && lev == 2) return;
    if (visited.at(i.r).at(i.c).at(lev)) return;
    for (ll l = lev; l < 3; l++) {
      visited.at(i.r).at(i.c).at(l) = true;
    }
    ll newLev = brd.at(i) == '#' ? lev + 1 : lev;
    for (BrdIdx d : dirs) recF(recF, i + d, newLev);
  };
  
  try {
    dfs(dfs, start, 0);
    cout << "NO\n";
  }catch(const MyException& e) {
    cout << "YES\n";
  }

  return 0;
}

