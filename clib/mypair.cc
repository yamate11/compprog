#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  // mypair

  Usage:
    * Constructor: mypair<A, B> p(a, b);
    * Elements:  p._1  and  p._2
    * Input/Output    cin >> p;    cout << p;

  Usage when A = B and it is an integral type:
    * addition etc.    p1 += p2, p = p1 + p2, p = -p1, p = i * p1, ...
    * rotation         p = p1.rotate(r);   default value for r is 1, which means 1*pi/2.
    * inner product    p1.inner_prod(p2)
    * parallel check   if (p1.parallel(p2)) ....

  using pll = mypair<ll, ll>;

*/

// @@ !! LIM()

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- mypair.cc

template<typename A, typename B>
struct mypair {
  A _1;
  B _2;
  mypair() : _1(), _2() {}
  mypair(const A& a, const B& b) : _1(a), _2(b) {}
  mypair(A&& a, B&& b) : _1(forward<A>(a)), _2(forward<B>(b)) {}
  mypair(const mypair& o) : _1(o._1), _2(o._2) {}
  mypair(mypair&& o) : _1(move(o._1)), _2(move(o._2)) {}

  mypair& operator =(const mypair& o) { _1 = o._1; _2 = o._2; return *this; }
  mypair& operator =(mypair&& o) { _1 = move(o._1); _2 = move(o._2); return *this; }

  bool operator ==(const mypair& o) const { return _1 == o._1 and _2 == o._2; }
  bool operator !=(const mypair& o) const { return not (*this == o); }
  bool operator  <(const mypair& o) const { return _1 < o._1 or (_1 == o._1 and _2 < o._2); }
  bool operator  >(const mypair& o) const { return o < *this; }
  bool operator <=(const mypair& o) const { return not (*this > o); }
  bool operator >=(const mypair& o) const { return o <= *this; }

  mypair(const pair<A, B>& p) : _1(p.first), _2(p.second) {}

  friend istream& operator >>(istream& is, mypair& p) { is >> p._1 >> p._2; return is; }
  friend ostream& operator <<(ostream& os, const mypair& p) { os << "(" << p._1 << ", " << p._2 << ")"; return os; }

  mypair& operator +=(const mypair& o) { _1 += o._1; _2 += o._2; return *this; }
  mypair& operator -=(const mypair& o) { _1 -= o._1; _2 -= o._2; return *this; }
  mypair& operator *=(const A& a) { _1 *= a; _2 *= a; return *this; }
  mypair& operator /=(const A& a) { _1 /= a; _2 /= a; return *this; }
  mypair operator +(const mypair& o) const { mypair ret(*this); ret += o; return ret; }
  mypair operator -() const { return mypair(-_1, -_2); }
  mypair operator -(const mypair& o) const { mypair ret(*this); ret -= o; return ret; }
  mypair operator *(const A& a) const { mypair ret(*this); ret *= a; return ret; }
  friend mypair operator*(const A& a, mypair& p) { return mypair(a * p._1, a * p._2); }
  mypair operator /(const A& a) const { mypair ret(*this); ret /= a; return ret; }
  
  int mod4(ll r) {
    ll t = r % 4;
    return t >= 0 ? t : 4 + t;
  }
  void self_rotate(ll r = 1) {
    ll t = mod4(r);
    if (t == 0) return;
    if (t == 1) { swap(_1, _2); _1 = -_1; }
    if (t == 2) { _1 = -_1; _2 = -_2; }
    if (t == 3) { swap(_1, _2); _2 = -_2; }
  }
  mypair rotate(ll r = 1) const {
    mypair ret(*this);
    ret.self_rotate(r);
    return ret;
  }

  A inner_prod(const mypair& o) const { return _1 * o._1 + _2 * o._2; }
  bool parallel(const mypair& o) const { return _1 * o._2 == _2 * o._1; }

};

using pll = mypair<ll, ll>;

// @@ !! END ---- mypair.cc
