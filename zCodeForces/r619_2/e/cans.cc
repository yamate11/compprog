#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(board debug)
// --> board f:<< debug
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

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig) {
  queue<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
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

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st) {
  stack<T> tmp(st);
  os << '[';
  bool first = true;
  while (!tmp.empty()) {
    T& t = tmp.top();
    if (first) first = false;
    else os << ", ";
    os << t;
    tmp.pop();
  }
  os << ']';
  return os;
}

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t) {
  if (t.has_value()) os << "v(" << t.value() << ")";
  else               os << "nullopt";
  return os;
}
#endif

ostream& operator<< (ostream& os, int8_t x) {
  os << (int32_t)x;
  return os;
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

#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(__VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif

// ---- end debug.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, Q; cin >> N >> M >> Q;
  Board<char> brd(cin, N, M, '#');
  Board<ll> cent(N, M, 0);

  using sta = tuple<char, BrdIdx, BrdIdx>;
  vector<sta> sp({{'R', BrdIdx(0, 0), BrdIdx(-1, -1)},
	{'G', BrdIdx(0, 1), BrdIdx(-1, 1)},
	  {'Y', BrdIdx(1, 0), BrdIdx(1, -1)},
	    {'B', BrdIdx(1, 1), BrdIdx(1, 1)}});
  auto chks = [&](const auto& bi, ll k) -> bool {
#if DEBUG
    bool on = false;
    if (k == 2) on = true;
#endif
    for (auto [c, dbs, dbd] : sp) {
      auto bs = bi + dbs;
      auto bcor = bs + (k - 1) * dbd;
      BrdIdx d1(dbd.r, 0);
      BrdIdx d2(0, dbd.c);
#if DEBUG
      if (on) DLOG("bi=", bi, "c=", c, "dbs=", dbs, "dbd=", dbd, "bcor=", bcor, "bs=", bs, "d1=", d1, "d2=", d2);
#endif
      for (ll i = 0; i < k; i++) {
	if (brd.at(bcor - i * d1) != c) {
#if DEBUG
	  if (on) DLOG("1. i=", i, "stored=", brd.at(bcor - i * d1));
#endif
	  return false;
	}
	if (brd.at(bcor - i * d2) != c) {
#if DEBUG
	  if (on) DLOG("2. i=", i, "stored=", brd.at(bcor - i * d2));
#endif
	  return false;
	}
      }
    }
    return true;
  };
  auto chksize = [&](const auto& bi) -> ll {
    for (ll k = 0; true; k++) if (!chks(bi, k+1)) return k;
  };

  ll kmax = 0;
  for (ll r = 0; r < N; r++) {
    for (ll c = 0; c < M; c++) {
      BrdIdx bi(r, c);
      ll k = chksize(bi);
      cent.at(bi) = k;
      kmax = max(kmax, k);
    }
  }
  DLOG("cent");
  DLOG(cent);
  vector acc(kmax+1, vector(N+1, vector(M+1, 0LL)));
  for (ll k = 1; k <= kmax; k++) {
    for (ll i = 0; i < N; i++) {
      for (ll j = 0; j < M; j++) {
	acc[k][i+1][j+1] = acc[k][i+1][j] + acc[k][i][j+1] - acc[k][i][j]
	  + (cent.at(i, j) >= k ? 1 : 0);
      }
    }
  }

  auto cnt = [&](ll k, ll r1, ll c1, ll r2, ll c2) -> ll {
    return acc[k][r2 + 1][c2 + 1]
    - acc[k][r1][c2 + 1] - acc[k][r2 + 1][c1]
    + acc[k][r1][c1];
  };

  for (ll _q = 0; _q < Q; _q++) {
    ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; r1--; c1--; r2--; c2--;
    
    auto mycnt = [&]() -> ll {
      for (ll k = 1; k <= kmax; k++) {
	ll r1k = r1 + (k - 1);
	ll c1k = c1 + (k - 1);
	ll r2k = r2 - 1 - (k - 1);
	ll c2k = c2 - 1 - (k - 1);
	if (r1k > r2k || c1k > c2k) return k - 1;
	if (cnt(k, r1k, c1k, r2k, c2k) == 0) return k - 1;
      }
      return kmax;
    };
    
    ll k = mycnt();
    cout << 4 * k * k << "\n";
  }

  return 0;
}

