#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define CONSTANT_MOD (1e9 + 7)

// @@ !! LIM(matrix mod debug)
// --> f:power matrix f:gcd f:intDiv mod f:<< debug
// ---- inserted function power from util.cc
/* *** WARNING ***  
      ll x = power(10, 12) 
   does not work since it is interpreted as 
      ll x = power<int>((int)10, 12)
   Use power<ll>(10, 12) or power(10LL, 12).
 */
template<typename T>
T power(T a, ll b) {
  T twoPow = a;
  T rv(1);
  while (b > 0) {
    if (b & 1LL) rv *= twoPow;
    twoPow *= twoPow;
    b >>= 1;
  }
  return rv;
}

// ad-hoc power function
template<typename T, typename Op>
T ah_power(T a, ll b, const T& unit_t, Op op) {
  T two_pow = a;
  T ret = unit_t;
  while (b > 0) {
    if (b & 1LL) ret = op(ret, two_pow);
    two_pow = op(two_pow, two_pow);
    b >>= 1;
  }
  return ret;
}
// ---- end power
// ---- inserted library file matrix.cc

struct MyExc : exception {};

template <typename T>
struct Matrix {
// private:
  size_t dimI;
  size_t dimJ;
  vector<T> mem;
  static size_t defDimIJ;

  void init_from_vv(const vector<vector<T>>& vec) {
    dimI = vec.size();
    dimJ = vec.at(0).size();
    if (dimI == dimJ) defDimIJ = dimI;
    mem.resize(dimI*dimJ);
    for (size_t i = 0; i < dimI; i++) {
      assert(vec.at(i).size() == dimJ);
      for (size_t j = 0; j < dimJ; j++) at(i,j) = vec.at(i).at(j);
    }
  }

// public:

  void precond(bool b, string msg) const {
    if (!b) {
      cerr << "**FATAL** " << msg << endl;
      exit(1);
    }
  }

  T&       at(size_t i, size_t j)       { return mem.at(i*dimJ + j); }
  const T& at(size_t i, size_t j) const { return mem.at(i*dimJ + j); }
  
  Matrix(size_t m, size_t n) : dimI(m), dimJ(n), mem(dimI*dimJ) {
    if (dimI == dimJ) defDimIJ = dimI;
  }

  Matrix(const vector<vector<T>>& vec) { init_from_vv(vec); }
  Matrix(initializer_list<vector<T>> il) {
    init_from_vv(vector<vector<T>>(il)); 
  }

  /*  They will be constructed as implicitly-defined constructors???
  Matrix(const Matrix<T>& mat)
    : dimI(mat.dimI), dimJ(mat.dimJ), mem(mat.mem) {}
  Matrix(Matrix<T>&& mat)
    : dimI(mat.dimI), dimJ(mat.dimJ), mem(move(mat.mem)) {}
  */

  Matrix(const T& t) {
    precond(defDimIJ != 0, "defDimIJ not set Matrix(T)");
    dimI = dimJ = defDimIJ;
    mem.resize(dimI*dimJ, (T)0);
    for (size_t i = 0; i < dimI; i++) at(i,i) = t;
  }

  /*
  Matrix<T>& operator =(const Matrix<T>& r) {
    dimI = r.dimI;
    dimJ = r.dimJ;
    mem = r.mem;
    return *this;
  }
  */

  void partial_subst(const Matrix<T>& r, size_t i0, size_t j0,
		     size_t i1, size_t j1, size_t i2, size_t j2) {
    for (size_t i = i1; i < i2; i++) {
      for (size_t j = j1; j < j2; j++) at(i0 + i, j0 + j) = r.at(i, j);
    }
  }

  void partial_subst(const Matrix<T>& r) {
    return partial_subst(r, 0, 0, 0, 0, r.dimI, r.dimJ);
  }

  void fill_row(const auto& vec, size_t i, size_t j0 = 0) {
    for (size_t j = 0; j < vec.size(); j++) at(i, j0 + j) = vec[j];
  }

  void fill_col(const auto& vec, size_t j, size_t i0 = 0) {
    for (size_t i = 0; i < vec.size(); i++) at(i0 + i, j) = vec[i];
  }

  Matrix<T>& operator +=(const Matrix<T>& r) {
    precond(dimI == r.dimI && dimJ == r.dimJ, "dimension mismatch");
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimJ; j++) at(i,j) += r.at(i,j);
    }
    return *this;
  }

  Matrix<T>& operator -=(const Matrix<T>& r) {
    precond(dimI == r.dimI && dimJ == r.dimJ, "dimension mismatch");
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimJ; j++) at(i,j) -= r.at(i,j);
    }
    return *this;
  }

  Matrix<T> operator +(const Matrix<T>& r) const {
    return Matrix<T>(*this) += r;
  }

  Matrix<T> operator -(const Matrix<T>& r) const {
    return Matrix<T>(*this) -= r;
  }

  // Unlike + and -, we anyway need a new object for multiplication.
  // Thus, we first define operator *, and then define operator *=
  // using operator *.
  Matrix<T> operator *(const Matrix<T>& r) const {
    precond(dimJ == r.dimI, "dimension mismatch");
    Matrix<T> result(dimI, r.dimJ);
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < r.dimJ; j++) {
	T s = 0;
	for (size_t k = 0; k < dimJ; k++)  s += at(i,k) * r.at(k,j);
	result.at(i,j) = s;
      }
    }
    return result;
  }

  Matrix<T>& operator *=(const Matrix<T>& r) {
    return *this = *this * r;
  }

  bool operator ==(const Matrix<T>& r) const {
    return dimI == r.dimI && dimJ == r.dimJ && mem == r.mem;
  }
  bool operator !=(const Matrix<T>& r) const { return !(*this == r); }

  ostream& ostr_out(ostream& os) const {
    vector<vector<T>> vec(dimI, vector<T>(dimJ));
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimJ; j++) vec.at(i).at(j) = at(i,j);
    }
    return os << vec;
  }

  Matrix<T> matpower(ll x) const {
    precond((defDimIJ = dimI) == dimJ, "only for square matrix");
    return power(*this, x);
  }

  Matrix<T> transpose() const {
    Matrix<T> res(dimJ, dimI);
    for (size_t i = 0; i < dimI; i++) for (size_t j = 0; j < dimJ; j++) {
	res.at(j,i) = at(i,j);
      }
    return res;
  }

  /* aux functions for sweepout */

  void basic_mult(int i, T t) {
    for (size_t j = 0; j < dimJ; j++) at(i, j) *= t;
  }

  void basic_xchg(int i1, int i2) {
    for (size_t j = 0; j < dimJ; j++) swap(at(i1, j), at(i2, j));
  }

  void basic_mult_add(int i1, T t, int i2) {
    for (size_t j = 0; j < dimJ; j++) at(i2, j) += at(i1, j) * t;
  }

  bool is_zero(T t) const { return t == (T)0; }

  pair<size_t, size_t> find_nz(size_t i0, size_t j0) {
    for ( ; j0 < dimJ; j0++) {
      size_t i = i0;
      for ( ; i < dimI && is_zero(at(i, j0)); i++);
      if (i < dimI) return {i, j0};
    }
    return {dimI, dimJ};
  }

  /*
    Sweepout for the vertical direction.
    Returns a pair (rank, det)
      rank: the rank of the matrix
      det: internally used for determinant calculation
    WARNNIG: T should be a field.
   */
  pair<size_t, T> self_sweepout() {
    T det = (T)1;
    size_t j0 = 0;
    size_t i0 = 0;
    for ( ; i0 < dimI; i0++) {
      auto [i1, j1] = find_nz(i0, j0);
      if (i1 == dimI) break;
      j0 = j1;
      if (i1 != i0) {
	det = -det;
	basic_xchg(i0, i1);
      }
      det *= at(i0, j0);
      basic_mult(i0, (T)1 / at(i0, j0));
      for (size_t i = 0; i < dimI; i++) {
	if (i == i0) continue;
	basic_mult_add(i0, -at(i, j0), i);
      }
    }
    return {i0, det};
  }
  
  pair<size_t, T> sweepout() const { 
    Matrix<T> res1(*this);
    return res1.self_sweepout();
  }

  /* WARNING: T should be a field. */
  T determinant() const {
    precond((defDimIJ = dimI) == dimJ, "only for square matrix");
    auto [rank, det] = sweepout();
    return (rank == dimI) ? det : (T)0;
  }

  /* WARNING: T should be a field. */
  Matrix<T> inverse() const {
    precond((defDimIJ = dimI) == dimJ, "only for square matrix");
    Matrix<T> work(dimI, dimI * 2);
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimI; j++) {
	work.at(i, j) = at(i, j);
	work.at(i, j + dimI) = (i == j) ? (T)1 : (T)0;
      }
    }
    work.self_sweepout();
    if (!is_zero(work.at(dimI-1, dimI-1) - (T)1)) {
      cerr << "inverse() for non-regular matrix." << endl;
      throw MyExc();
    }
    Matrix<T> ret(dimI, dimI);
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimI; j++) ret.at(i, j) = work.at(i, j + dimI);
    }
    return ret;
  }

};

template<typename T> size_t Matrix<T>::defDimIJ = 0;

template<typename T>
ostream& operator<< (ostream& os, const Matrix<T>& mat) {
  return mat.ostr_out(os);
}

// ---- end matrix.cc
// ---- inserted function gcd from util.cc
// g = eGCD(a, b, s, t)  --->  sa + tb = g
ll eGCD(ll a, ll b, ll& s, ll& t) {
  if (a == 0) {
    s = 0;
    t = 1;
    return b;
  }
  ll u = 0;
  ll g = eGCD(b % a, a, t, u);
  s = u - (b / a) * t;
  return g;
}

// gcd(0, x) = x, gcd(-x, y) = gcd(x, y)
ll gcd(ll a, ll b) {
  ll dummy1 = 0;
  ll dummy2 = 0;
  return eGCD(abs(a), abs(b), dummy1, dummy2);
}

// Chinese Remainder Theorem
//    auto [r, z] = crt(x1, a1, x2, a2)
//    ==>   r = a1 (mod x1);  r = a2 (mod x2);  z = lcm(x1, x2);  0 <= r < z
//    If no such r exists, returns [-1, -1]
//    Note: x1 and x2 should be >= 1.  a1 and a2 can be negative or zero.
pair<ll, ll> crt(ll x1, ll a1, ll x2, ll a2) {
  ll s, t; ll g = eGCD(x1, x2, s, t);
  if (a1 % g != 0 || a2 % g != 0) return {-1, -1};
  ll z = x1 / g * x2;
  ll p = (a2 / g) * s * x1 + (a1 / g) * t * x2;
  ll r = p % z;
  if (r < 0) r += z;
  return {r, z};
};

// ---- end gcd
// ---- inserted function intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}

// ---- end intDiv
// ---- inserted library file mod.cc

/*
  You may want to put something like:
#define CONSTANT_MOD (1e9 + 7)
#define CONSTANT_MOD 998244353
  in the header part (outside of library paste area)
 */

struct Fp {
#if defined(CONSTANT_MOD)
  static const ll MOD = CONSTANT_MOD;
#else
  static ll MOD;
#endif

  ll val;

  /*
  ll _calc_from_ll(ll t = 0) {
    if      (t >= MOD)  return t % MOD;
    else if (t >= 0)    return t;
    else if (t >= -MOD) return t + MOD;
    else {
      ll v = t % MOD;
      if (v == 0) return 0;
      else        return v + MOD;
    }
  }
  */

  Fp(ll t = 0) : val(imod(t, MOD)) {}
  Fp(const Fp& t) : val(t.val) {}
  Fp& operator =(const Fp& t) { val = t.val; return *this; }
  Fp& operator =(ll t) { val = imod(t, MOD); return *this; }
  Fp& operator =(int t) { val = imod(t, MOD); return *this; }

  Fp& operator +=(const Fp& t) {
    val += t.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  Fp& operator -=(const Fp& t) {
    val -= t.val;
    if (val < 0) val += MOD;
    return *this;
  }

  Fp& operator *=(const Fp& t) {
    val = (val * t.val) % MOD;
    return *this;
  }

  Fp inv() const {
    if (val == 0) {
      cerr << "inv() is called for zero." << endl;
      exit(1);
    }
    ll u = 0;
    ll v = 0;
    eGCD(val, MOD, u, v);
    return Fp(u);
  }

  Fp& operator /=(const Fp& t) {
    return (*this) *= t.inv();
  }

  Fp operator +(const Fp& t) const { return Fp(val) += t; }
  Fp operator -(const Fp& t) const { return Fp(val) -= t; }
  Fp operator *(const Fp& t) const { return Fp(val) *= t; }
  Fp operator /(const Fp& t) const { return Fp(val) /= t; }
  Fp operator -() const { return Fp(-val); }

  bool operator ==(const Fp& t) const { return val == t.val; }
  bool operator !=(const Fp& t) const { return val != t.val; }
  
  operator ll() const { return val; }

};

Fp operator +(int x, const Fp& y) { return Fp(x) + y; }
Fp operator -(int x, const Fp& y) { return Fp(x) - y; }
Fp operator *(int x, const Fp& y) { return Fp(x) * y; }
Fp operator /(int x, const Fp& y) { return Fp(x) / y; }
Fp operator +(ll x, const Fp& y) { return Fp(x) + y; }
Fp operator -(ll x, const Fp& y) { return Fp(x) - y; }
Fp operator *(ll x, const Fp& y) { return Fp(x) * y; }
Fp operator /(ll x, const Fp& y) { return Fp(x) / y; }
Fp operator +(const Fp& x, int y) { return x + Fp(y); }
Fp operator -(const Fp& x, int y) { return x - Fp(y); }
Fp operator *(const Fp& x, int y) { return x * Fp(y); }
Fp operator /(const Fp& x, int y) { return x / Fp(y); }
Fp operator +(const Fp& x, ll y) { return x + Fp(y); }
Fp operator -(const Fp& x, ll y) { return x - Fp(y); }
Fp operator *(const Fp& x, ll y) { return x * Fp(y); }
Fp operator /(const Fp& x, ll y) { return x / Fp(y); }

istream& operator>> (istream& is, Fp& t) {
  ll x; is >> x;
  t = x;
  return is;
}

ostream& operator<< (ostream& os, const Fp& t) {
  os << t.val;
  return os;
}

class Comb {
  int nMax;
  vector<Fp> vFact;
  vector<Fp> vInvFact;
public:
  Comb(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact.at(0) = 1;
    for (int i = 1; i <= nMax; i++) vFact.at(i) = i * vFact.at(i-1);
    vInvFact.at(nMax) = vFact.at(nMax).inv();
    for (int i = nMax; i >= 1; i--) vInvFact.at(i-1) = i * vInvFact.at(i);
  }
  Fp fact(int n) { return vFact.at(n); }
  Fp comb(int n, int r) {
    return vFact.at(n) * vInvFact.at(r) * vInvFact.at(n-r);
  }
  // The number of permutation extracting r from n.
  Fp perm(int n, int r) {
    return vFact.at(n) * vInvFact.at(n-r);
  }
};

#if !defined(CONSTANT_MOD)
ll Fp::MOD = 1e9 + 7;
// ll Fp::MOD = 998'244'353;
#endif

// ---- end mod.cc
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

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig) {
  deque<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop_front();
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

  ll k; cin >> k;
  Fp twop = 2;
  bool even = false;
  for (ll i = 0; i < k; i++) {
    ll a; cin >> a;
    if (a % 2 == 0) even = true;
    twop = power<Fp>(twop, a);
  }
  Fp p0;
  twop /= Fp(2);
  if (even) {
    p0 = (twop + 1) / Fp(3);
  }else {
    p0 = (twop - 1) / Fp(3);
  }
  cout << p0 << "/" << twop << endl;
  

  return 0;
}

