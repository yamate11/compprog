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
  int nR;
  int nC;
  int r;
  int c;
  BrdIdx(int nR_, int nC_, int r_, int c_)
    : nR(nR_), nC(nC_), r(r_), c(c_) {}
  // BrdIdx(const BrdIdx& o) : nR(o.nR), nC(o.nC), r(o.r), c(o.c) {}
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
  BrdIdx bIdx(int r = 0, int c = 0) { return BrdIdx(nR, nC, r, c); }
  int enc(int r, int c) const { return nC * r + c; }
  pair<int, int> dec(int i) const { return make_pair(i / nC, i % nC); }

  bool in(int r, int c) const { return 0 <= r && r < nR && 0 <= c && c < nC; }
  bool in(const BrdIdx& bi) const { return in(bi.r, bi.c); }
  T& at(int r, int c) { return in(r, c) ? data.at(enc(r, c)) : def; }
  T& at(const BrdIdx& bi) { return at(bi.r, bi.c); }
};



using BI = BrdIdx;

struct MyException : exception {};

void solve() {
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
  auto solve2 = [&](char cLast, char cOther) -> void {
    auto solve3 = [&](BI s, BI dir, BI mv1, BI mv2) -> void {
      set<BI> cand;
      for (BI o(s); brd.in(o); ) {
	for (BI i(o); brd.in(i); ) {
	  if (brd.at(i) == '.') {
	    i += dir;
	  }else {
	    char c = brd.at(i);
	    ll k = 1;
	    for ( ; brd.at(i + k * dir) == c; k++);
	    if (k >= 10) throw MyException();
	    if (k >= 5) {
	      if (brd.at(i) == cOther) throw MyException();
	      if (cand.empty()) {
		for (ll p = k-5; p < 5; p++) cand.insert(i + p * dir);
	      }else {
		set<BI> newCand;
		for (ll p = k-5; p < 5; p++) {
		  BI ii = i + p * dir;
		  if (cand.find(ii) != cand.end()) newCand.insert(ii);
		}
		if (newCand.empty()) throw MyException();
		cand = move(newCand);
	      }
	    }
	    i += k * dir;
	  }
	}
	if (brd.in(o + mv1)) o += mv1;
	else                 o += mv2;
      }
    };
    BI orig = brd.bIdx(0, 0);
    BI dr = brd.bIdx(1, 0);
    BI dc = brd.bIdx(0, 1);
    solve3(orig, dc, dr, dr);
    solve3(orig, dr, dc, dc);
    solve3(orig, brd.bIdx(1,-1), dc, dr);
    solve3(brd.bIdx(brd.nR-1,0), brd.bIdx(1,1), -dr, dc);
  };
  DLOG("cntB=", cntB, "cntW=", cntW);
  if (cntB == cntW) solve2('x', 'o');
  else if (cntB == cntW + 1) solve2('o', 'x');
  else throw MyException();
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  try {
    solve();
    cout << "YES" << endl;
  }catch(const MyException& e) {
    cout << "NO" << endl;
  }
  return 0;
}

