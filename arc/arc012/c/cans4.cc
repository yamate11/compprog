#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug)
// --> f:<< debug
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
// @@ !! LIM  -- end mark --

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
  Board(int nR_, int nC_, T def_)
    : nR(nR_), nC(nC_), def(def_), data(nR*nC, def) {}
  int enc(int r, int c) const { return nC * r + c; }
  BrdIdx dec(int i) const { return BrdIdx(i / nC, i % nC); }

  bool in(int r, int c) const { return 0 <= r && r < nR && 0 <= c && c < nC; }
  bool in(const BrdIdx& bi) const { return in(bi.r, bi.c); }
  T& at(int r, int c) { return in(r, c) ? data.at(enc(r, c)) : def; }
  T& at(const BrdIdx& bi) { return at(bi.r, bi.c); }
};

// struct MyException : exception {};

bool solve() {
  Board<char> brd(19, 19, '.');
  ll cntB = 0, cntW = 0;
  for (ll i = 0; i < 19; i++) {
    string s; cin >> s;
    for (ll j = 0; j < 19; j++) {
      brd.at(i, j) = s.at(j);
      if (s.at(j) == 'o') cntB++;
      else if (s.at(j) == 'x') cntW++;
    }
  }
  vector<BrdIdx>
    dirs {BrdIdx(1, 0), BrdIdx(0, 1), BrdIdx(1, 1), BrdIdx(1, -1)};
  auto allShort = [&](char c) -> bool {
    for (int i = 0; i < 19*19; i++) {
      BrdIdx bi = brd.dec(i);
      if (brd.at(bi) != c) continue;
      for (BrdIdx dir : dirs) {
	ll mp = 1;  for (; brd.at(bi + mp * dir) == c; mp++);
	ll mn = -1; for (; brd.at(bi + mn * dir) == c; mn--);
	if (mp - mn - 1 >= 5) return false;
      }
    }
    return true;
  };
  auto solve2 = [&](char cLast, char cOther) -> bool {
    if (!allShort(cOther)) return false;
    for (int i = 0; i < 19*19; i++) {
      BrdIdx bi = brd.dec(i);
      char cPre = brd.at(bi);
      if (cPre != cLast) continue;
      brd.at(bi) = '.';
      if (allShort(cLast)) return true;
      brd.at(bi) = cPre;
    }
    return false;
  };
  DLOG("cntB=", cntB, "cntW=", cntW);
  if (cntB == 0 && cntW == 0) return true;
  else if (cntB == cntW) return solve2('x', 'o');
  else if (cntB == cntW + 1) return solve2('o', 'x');
  else return false;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << (solve() ? "YES" : "NO") << endl;
  return 0;
}

