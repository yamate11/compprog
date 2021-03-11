#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(board)
// --> board
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

// ---- end board.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  Board<char> brd(H, W, '#');
  BrdIdx start, goal;
  vector<vector<BrdIdx>> telep(26);
  for (ll r = 0; r < H; r++) {
    string s; cin >> s;
    for (ll c = 0; c < W; c++) {
      brd.at(r, c) = s[c];
      if (s[c] == 'S') start = BrdIdx(r, c);
      if (s[c] == 'G') goal = BrdIdx(r, c);
      /*
      if (s[c] != '.' && s[c] != '#') {
	x = s[c] - 'a';
	telep[x].push_back(BrdIdx(r, c));
      }
      */
    }
  }
  vector<vector<bool>> nbrTT(26, vector<bool>(26, false));
  vector<vector<BrdIdx>> nbrTN(26);
  for (ll r = 0; r < H; r++) {
    for (ll c = 0; c < W; c++) {
      if ('a' <= brd.at(r, c) && brd.at(r, c) <= 'z') {
	ll x = brd.at(r, c) - 'a';
	for (BrdIdx& bd : BrdIdx::nbr4) {
	  BrdIdx bi = BrdIdx(r, c) + bd;
	  if (brd.at(bi) == '.' || brd.at(bi) == 'G') nbrTN[x].push_back(bi);
	  if ('a' <= brd.at(bi) && brd.at(bi) <= 'z') {
	    ll y = brd.at(bi) - 'a';
	    nbrTT[x][y] = nbrTT[y][x] = true;
	  }
	}
      }
    }
  }

  using sta = tuple<ll, ll, ll>;  // (dist, r, c); but r = H, c = alph
  queue<sta> que;
  vector<vector<bool>> visited(H + 2, vector<bool>(max(26LL, W)));
  que.emplace(0, start.r, start.c);
  visited[start.r][start.c] = true;
  while (!que.empty()) {
    auto [d, r, c] = que.front(); que.pop();
    if (goal.r == r && goal.c == c) {
      cout << d << endl;
      return 0;
    }
    if (r == H + 1) {
      for (ll x = 0; x < 26; x++) {
	if (x == c) continue;
	if (!nbrTT[x][c]) continue;
	if (visited[H][x]) continue;
	visited[H][x] = true;
	que.emplace(d + 1, H, x);
      }
      for (BrdIdx bi : nbrTN[c]) {
	if (visited[bi.r][bi.c]) continue;
	visited[bi.r][bi.c] = true;
	que.emplace(d + 1, bi.r, bi.c);
      }
    }else if (r == H) {
      visited[H + 1][c] = true;
      que.emplace(d + 1, H+1, c);
    }else {
      for (BrdIdx& bd : BrdIdx::nbr4) {
	BrdIdx bi = BrdIdx(r, c) + bd;
	if (brd.at(bi) == '#') continue;
	else if (brd.at(bi) == 'S') continue;
	else if ('a' <= brd.at(bi) && brd.at(bi) <= 'z') {
	  ll y = brd.at(bi) - 'a';
	  if (!visited[H][y]) {
	    visited[H][y] = true;
	    que.emplace(d + 1, H, y);
	  }
	}
	if (visited[bi.r][bi.c]) continue;
	visited[bi.r][bi.c] = true;
	que.emplace(d + 1, bi.r, bi.c);
      }
    }
  }
  cout << -1 << endl;

  return 0;
}

