#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug matrix ftwo)

// ---- inserted function f:<< from util.cc
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

// ---- end f:<<

// ---- inserted library file debug.cc
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(bool with_nl, Head&& head) {
  cerr << head;
  if (with_nl) cerr << endl;
}

template <class Head, class... Tail>
void dbgLog(bool with_nl, Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(with_nl, forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DLOGNNL(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

/*
#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL_LIB(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif
*/

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)
#define DUP9(E1,...)   DUP1(E1), DUP8(__VA_ARGS__)
#define DUP10(E1,...)   DUP1(E1), DUP9(__VA_ARGS__)
#define DUP11(E1,...)   DUP1(E1), DUP10(__VA_ARGS__)
#define DUP12(E1,...)   DUP1(E1), DUP11(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP12, DUP11, DUP10, DUP9, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

#if DEBUG_LIB
  #define DLOG_LIB   DLOG
  #define DLOGK_LIB  DLOGK
  #define DLOGKL_LIB DLOGKL
#endif

// ---- end debug.cc

// ---- inserted function f:power from util.cc
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
// ---- end f:power

// ---- inserted library file matrix.cc

#if ! defined(DLOG_LIB)
  #define DLOG_LIB(...)
  #define DLOGK_LIB(...)
  #define DLOGKL_LIB(lab, ...)
#endif

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

  static Matrix fromVec(const vector<T>& svec, bool isColVect = true) {
    vector<vector<T>> vec;
    vec.push_back(svec);
    Matrix ret = Matrix(vec);
    if (isColVect) return ret.transpose();
    else           return ret;
  }

  vector<T> rowVec(size_t row) const {
    vector<T> result(dimJ);
    for (size_t i = 0; i < dimJ; i++) result[i] = at(row, i);
    return result;
  }

  vector<T> colVec(size_t col) const {
    vector<T> result(dimI);
    for (size_t i = 0; i < dimI; i++) result[i] = at(i, col);
    return result;
  }

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
    // DLOGKL("  ", *this);
    for ( ; i0 < dimI; i0++, j0++) {
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
      // DLOGKL("  ", *this);
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

  /* WARNING: T should be a field. */
  // Solves linear euqation "(*this) x = bs".
  //        dimI and dimJ can be different.
  // arguments:
  //    bs ... vector<T>.  bs.size() == dimI should hold.
  //    ret_kernel ... if false, returned kernel is an empty vector.
  // return value: optional<pair<vector<T>, vector<vector<T>>>
  //    If there is no solution, nullopt is returned.
  //    Otherwise, ret.value() is a pair [sol, kernel].
  //      sol ... a solution.  sol.size() is dimJ.
  //      kernel ... A basis of the space { x | (*this) x = 0 }.
  // Typical usage:
  //    auto ret = mat.linSolution(bs);
  //    if (!ret.has_value()) cout << "No solution\n";
  //    else {
  //      [sol, _dummy] = ret.value();
  //      cout << "Solution is: " << sol << "\n";
  //    }
  optional<pair<vector<T>, vector<vector<T>>>>
  linSolution(const vector<T>& bs, bool ret_kernel = true) const {
    Matrix<T> work(dimI, dimJ + 1);
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimJ; j++) { work.at(i, j) = at(i, j); }
      work.at(i, dimJ) = bs[i];
    }
    auto [rank, _] = work.self_sweepout();
    // DLOGK(rank, work);
    if (rank > 0) {
      bool succ = false;
      for (size_t j = 0; j < dimJ; j++) {
        if (work.at(rank - 1, j) != (T)0) { succ = true; break; }
      }
      if (!succ) { return nullopt; }
    }
    vector<T> sol(dimJ, (T)0);
    {
      size_t j = 0;
      for (size_t i = 0; i < rank; i++, j++) {
        for ( ; work.at(i, j) == (T)0; j++);
        sol[j] = work.at(i, dimJ);
      }
    }
    vector<vector<T>> kernel;
    if (ret_kernel) {
      vector<bool> cor(dimJ, false);
      size_t i = 0;
      for (size_t j = 0 ; j < dimJ; j++) {
        if (i == dimI || work.at(i, j) == (T)0) {
          vector<T> kv(dimJ);
          kv[j] = (T)1;
          for (size_t p = 0, q = 0; p < i; p++, q++) {
            while (!cor[q]) q++;
            kv[q] = -work.at(p, j);
          }
          kernel.push_back(move(kv));
        }else {
          cor[j] = true;
          if (i < dimI) i++;
        }
      }
    }
    return make_optional(make_pair(move(sol), move(kernel)));
  }


};

template<typename T> size_t Matrix<T>::defDimIJ = 0;

template<typename T>
ostream& operator<< (ostream& os, const Matrix<T>& mat) {
  return mat.ostr_out(os);
}

// ---- end matrix.cc

// ---- inserted library file ftwo.cc

struct Ftwo {
  int8_t val;

  Ftwo(ll t = 0) { val = (t == 0) ? 0 : 1; }
  Ftwo(const Ftwo& t) : val(t.val) {}
  Ftwo& operator =(const Ftwo& t) { val = t.val; return *this; }
  Ftwo& operator =(ll t) { val = (t == 0) ? 0 : 1; return *this; }
  Ftwo& operator =(int t) { val = (t == 0) ? 0 : 1; return *this; }

  Ftwo& operator +=(const Ftwo& t) {
    val ^= t.val;
    return *this;
  }

  Ftwo& operator -=(const Ftwo& t) {
    val ^= t.val;
    return *this;
  }

  Ftwo& operator *=(const Ftwo& t) {
    val &= t.val;
    return *this;
  }

  Ftwo inv() const {
    if (val == 0) {
      cerr << "inv() is called for zero." << endl;
      exit(1);
    }
    return Ftwo(1);
  }

  Ftwo& operator /=(const Ftwo& t) {
    return (*this) *= t.inv();
  }

  Ftwo operator +(const Ftwo& t) const { return Ftwo(val) += t; }
  Ftwo operator -(const Ftwo& t) const { return Ftwo(val) -= t; }
  Ftwo operator *(const Ftwo& t) const { return Ftwo(val) *= t; }
  Ftwo operator /(const Ftwo& t) const { return Ftwo(val) /= t; }
  Ftwo operator -() const { return Ftwo(-val); }

  bool operator ==(const Ftwo& t) const { return val == t.val; }
  bool operator !=(const Ftwo& t) const { return val != t.val; }
  
  operator ll() const { return val; }

};

Ftwo operator +(int x, const Ftwo& y) { return Ftwo(x) + y; }
Ftwo operator -(int x, const Ftwo& y) { return Ftwo(x) - y; }
Ftwo operator *(int x, const Ftwo& y) { return Ftwo(x) * y; }
Ftwo operator /(int x, const Ftwo& y) { return Ftwo(x) / y; }
Ftwo operator +(ll x, const Ftwo& y) { return Ftwo(x) + y; }
Ftwo operator -(ll x, const Ftwo& y) { return Ftwo(x) - y; }
Ftwo operator *(ll x, const Ftwo& y) { return Ftwo(x) * y; }
Ftwo operator /(ll x, const Ftwo& y) { return Ftwo(x) / y; }
Ftwo operator +(const Ftwo& x, int y) { return x + Ftwo(y); }
Ftwo operator -(const Ftwo& x, int y) { return x - Ftwo(y); }
Ftwo operator *(const Ftwo& x, int y) { return x * Ftwo(y); }
Ftwo operator /(const Ftwo& x, int y) { return x / Ftwo(y); }
Ftwo operator +(const Ftwo& x, ll y) { return x + Ftwo(y); }
Ftwo operator -(const Ftwo& x, ll y) { return x - Ftwo(y); }
Ftwo operator *(const Ftwo& x, ll y) { return x * Ftwo(y); }
Ftwo operator /(const Ftwo& x, ll y) { return x / Ftwo(y); }

istream& operator>> (istream& is, Ftwo& t) {
  ll x; is >> x;
  t = x;
  return is;
}

ostream& operator<< (ostream& os, const Ftwo& t) {
  os << int(t.val);
  return os;
}

// From a tweet by Noshibukuro (@noshi91)
// https://twitter.com/noshi91/status/1200702280128856064
// 
vector<ll> getF2Basis(const vector<ll>& vs) {
  vector<ll> ret;    // original vectors
  vector<ll> aux;    // This set will also be a basis of the vector space.
  for (ll v : vs) {
    ll e = v;
    for (ll b : aux) { e = min(e, e ^ b); }
    if (e) {
      ret.push_back(v);
      aux.push_back(e);
    }
  }
  return ret;
}

// ---- end ftwo.cc

// @@ !! LIM -- end mark --

int main() {

  random_device rd;
  mt19937 rng(rd());

  {
    Ftwo zero(0);
    Ftwo one(1);

    assert(zero + zero == zero);
    assert(zero + one == one);
    assert(one + zero == one);
    assert(one + one == zero);
    assert(zero - zero == zero);
    assert(zero - one == one);
    assert(one - zero == one);
    assert(one - one == zero);
    assert(zero * zero == zero);
    assert(zero * one == zero);
    assert(one * zero == zero);
    assert(one * one == one);
    assert(zero / one == zero);
    assert(one / one == one);
  }

  if (1) {
    ll rep = 100;
    ll sz2 = 12;
    for (ll k = 0; k < rep; k++) {
      Matrix<Ftwo> mat1(sz2, sz2);
      uniform_int_distribution<ll> dist1(0, 1);
      while (true) {
        for (ll i = 0; i < sz2; i++) {
          for (ll j = 0; j < sz2; j++) {
            mat1.at(i, j) = dist1(rng);
          }
        }
        auto [rank, det] = mat1.self_sweepout();
        if ((ll)rank == sz2) break;
      }
      uniform_int_distribution<ll> dist2(3, sz2);
      ll sz1 = dist2(rng);
      DLOGK(sz1);
      vector<ll> seed(sz1);
      for (ll i = 0; i < sz1; i++) {
        ll e = 0;
        for (ll j = 0; j < sz2; j++) {
          if (mat1.at(i, j)) { e |= (1LL << j); }
        }
        seed[i] = e;
      }
      vector<ll> vs;
      for (ll m = 0; m < sz1; m++) {
        ll e = 0;
        for (ll j = 0; j < sz1; j++) {
          if (dist1(rng) == 0) { e ^= seed[j]; }
        }
        vs.push_back(e);
      }
      for (ll m = 0; m < sz1; m++) vs.push_back(seed[m]);
      auto basis = getF2Basis(vs);
      DLOGK(sz1);
      DLOGK(vs);
      DLOGK(basis);
      assert((ll)basis.size() == sz1);
      Matrix<Ftwo> mat2(sz1, sz2);
      for (ll i = 0; i < sz1; i++) {
        for (ll j = 0; j < sz2; j++) {
          mat2.at(i, j) = (((basis[i] >> j) & 1) != 0) ? 1 : 0;
        }
      }
      DLOGK(mat2);
      auto [rank2, det2] = mat2.self_sweepout();
      DLOGK(rank2);
      assert((ll)rank2 == sz1);
      Matrix<Ftwo> mat3(sz1 + 1, sz2);
      for (ll i = 0; i < sz1; i++) {
        for (ll j = 0; j < sz2; j++) {
          mat3.at(i, j) = mat1.at(i, j);
        }
      }
      for (ll m = 0; m < sz1; m++) {
        for (ll j = 0; j < sz2; j++) {
          mat3.at(sz1, j) = ((basis[m] >> j) != 0) ? 1 : 0;
        }
        DLOGK(mat3);
        auto [rank3, det3] = mat3.self_sweepout();
        DLOGK(rank3);
        assert((ll)rank3 == sz1);
      }
    }
  }

  cerr << "Test Done.\n";

}
