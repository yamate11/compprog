#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug board)
// --> f:<< debug board
// ---- inserted function << from util.cc
template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ")";
  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const set<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const multiset<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const map<T1, T2>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  bool first = true;
  os << '[';
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}
// ---- end <<
// ---- inserted library file debug.cc
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(Head&& head) {
  cerr << head << endl;
}

template <class Head, class... Tail>
void dbgLog(Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(__VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

// ---- end debug.cc
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

  Board(int nR_, int nC_, T def_)
    : nR(nR_), nC(nC_), def(def_), data(nR*nC, def), dispWidth(0) {}
  Board(istream& is, int nR_, int nC_, T def_)
    : nR(nR_), nC(nC_), def(def_), data(nR*nC, def), dispWidth(0) {
    readData(is);
  }
  BrdIdx bIdx(int r = 0, int c = 0) { return BrdIdx(nR, nC, r, c); }
  int enc(int r, int c) const { return nC * r + c; }
  int enc(const BrdIdx& bi) const { return nC * bi.r + bi.c; }
  pair<int, int> dec(int i) const { return make_pair(i / nC, i % nC); }
  BrdIdx decIdx(int i) const { return BrdIdx(i / nC, i % nC); }
  bool in(int r, int c) const { return 0 <= r && r < nR && 0 <= c && c < nC; }
  bool in(const BrdIdx& bi) const { return in(bi.r, bi.c); }
  const T& get(int r, int c) const {
    return in(r, c) ? data.at(enc(r, c)) : def;
  }
  const T& get(const BrdIdx& bi) const { return get(bi.r, bi.c); }
  void set(int r, int c, T t) { if (in(r, c)) data.at(enc(r, c)) = t; }
  void set(const BrdIdx& bi, T t) { set(bi.r, bi.c, t); }
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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  Board<char> brd(cin, H, W, '@');
  Board<char> prev(H, W, '#');
  Board<char> back(H, W, '.');
  for (ll r = 0; r < H; r++) {
    for (ll c = 0; c < W; c++) {
      if (brd.get(r, c) == '.') {
	for (BrdIdx d : BrdIdx::nbr9) prev.set(BrdIdx(r, c) + d, '.');
      }
    }
  }
  DLOG(prev);
  for (ll r = 0; r < H; r++) {
    for (ll c = 0; c < W; c++) {
      if (prev.get(r, c) == '#') {
	for (BrdIdx d : BrdIdx::nbr9) back.set(BrdIdx(r, c) + d, '#');
      }
    }
  }
  for (ll r = 0; r < H; r++) {
    for (ll c = 0; c < W; c++) {
      if (brd.get(r,c) != back.get(r,c)) {
	cout << "impossible" << endl;
	return 0;
      }
    }
  }
  cout << "possible" << endl << prev << endl;

  return 0;
}

