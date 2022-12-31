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
#line 42 "/home/y-tanabe/proj/compprog/clib/debug.cc"
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

// ---- inserted library file algOp.cc
#line 105 "/home/y-tanabe/proj/compprog/clib/algOp.cc"

// Common definitions
//    zero, one, inverse

template<typename T>
constexpr T zero(const T& t) {
  if constexpr (is_integral_v<T> || is_floating_point_v<T>) { return (T)0; }
  else { return t.zero(); }
}

template<typename T>
constexpr T one(const T& t) {
  if constexpr (is_integral_v<T> || is_floating_point_v<T>) { return (T)1; }
  else { return t.one(); }
}

template<typename T>
constexpr T inverse(const T& t) {
  if constexpr (is_floating_point_v<T>) { return 1.0 / t; }
  else { return t.inverse(); }
}

// begin -- detection ideom
//    cf. https://blog.tartanllama.xyz/detection-idiom/

namespace detail {
  template <template <class...> class Trait, class Enabler, class... Args>
  struct is_detected : false_type{};

  template <template <class...> class Trait, class... Args>
  struct is_detected<Trait, void_t<Trait<Args...>>, Args...> : true_type{};
}

template <template <class...> class Trait, class... Args>
using is_detected = typename detail::is_detected<Trait, void, Args...>::type;

// end -- detection ideom


template<typename T>
// using subst_add_t = decltype(T::subst_add(declval<typename T::value_type &>(), declval<typename T::value_type>()));
using subst_add_t = decltype(T::subst_add);
template<typename T>
using has_subst_add = is_detected<subst_add_t, T>;

template<typename T>
using add_t = decltype(T::add);
template<typename T>
using has_add = is_detected<add_t, T>;

template<typename T>
using subst_mult_t = decltype(T::subst_mult);
template<typename T>
using has_subst_mult = is_detected<subst_mult_t, T>;

template<typename T>
using mult_t = decltype(T::mult);
template<typename T>
using has_mult = is_detected<mult_t, T>;

template<typename T>
using subst_subt_t = decltype(T::subst_subt);
template<typename T>
using has_subst_subt = is_detected<subst_subt_t, T>;

template<typename T>
using subt_t = decltype(T::subt);
template<typename T>
using has_subt = is_detected<subt_t, T>;

template <typename Opdef>
struct MyAlg {
  using T = typename Opdef::value_type;
  using value_type = T;
  T v;
  MyAlg() {}
  MyAlg(const T& v_) : v(v_) {}
  MyAlg(T&& v_) : v(move(v_)) {}
  bool operator==(MyAlg o) const { return v == o.v; }
  bool operator!=(MyAlg o) const { return v != o.v; }
  operator T() const { return v; }
  MyAlg zero() const { return MyAlg(Opdef::zero(v)); }
  MyAlg one() const { return MyAlg(Opdef::one(v)); }
  MyAlg inverse() const { return MyAlg(Opdef::inverse(v)); }
  MyAlg operator/=(const MyAlg& o) { return *this *= o.inverse(); }
  MyAlg operator/(const MyAlg& o) const { return (*this) * o.inverse(); }
  MyAlg operator-() const { return zero() - *this; }

  MyAlg& operator +=(const MyAlg& o) { 
    if constexpr (has_subst_add<Opdef>::value) {
      Opdef::subst_add(v, o.v);
      return *this;
    }else if constexpr (has_add<Opdef>::value) {
      v = Opdef::add(v, o.v);
      return *this;
    }else static_assert("either subst_add or add is needed.");

  }
  MyAlg operator +(const MyAlg& o) const { 
    if constexpr (has_add<Opdef>::value) {
      return MyAlg(Opdef::add(v, o.v));
    }else if constexpr (has_subst_add<Opdef>::value) {
      MyAlg ret(v);
      Opdef::subst_add(ret.v, o.v);
      return ret;
    }else static_assert("either subst_add or add is needed.");
  }
  MyAlg& operator *=(const MyAlg& o) { 
    if constexpr (has_subst_mult<Opdef>::value) {
      Opdef::subst_mult(v, o.v);
      return *this;
    }else if constexpr (has_mult<Opdef>::value) {
      v = Opdef::mult(v, o.v);
      return *this;
    }else static_assert("either subst_mult or mult is needed.");

  }
  MyAlg operator *(const MyAlg& o) const { 
    if constexpr (has_mult<Opdef>::value) {
      return MyAlg(Opdef::mult(v, o.v));
    }else if constexpr (has_subst_mult<Opdef>::value) {
      MyAlg ret(v);
      Opdef::subst_mult(ret.v, o.v);
      return ret;
    }else static_assert("either subst_mult or mult is needed.");
  }
  MyAlg& operator -=(const MyAlg& o) { 
    if constexpr (has_subst_subt<Opdef>::value) {
      Opdef::subst_subt(v, o.v);
      return *this;
    }else if constexpr (has_subt<Opdef>::value) {
      v = Opdef::subt(v, o.v);
      return *this;
    }else static_assert("either subst_subt or subt is needed.");

  }
  MyAlg operator -(const MyAlg& o) const { 
    if constexpr (has_subt<Opdef>::value) {
      return MyAlg(Opdef::subt(v, o.v));
    }else if constexpr (has_subst_subt<Opdef>::value) {
      MyAlg ret(v);
      Opdef::subst_subt(ret.v, o.v);
      return ret;
    }else static_assert("either subst_subt or subt is needed.");
  }
  friend istream& operator >>(istream& is, MyAlg& t)       { is >> t.v; return is; }
  friend ostream& operator <<(ostream& os, const MyAlg& t) { os << t.v; return os; }
};





// ---- end algOp.cc

// ---- inserted library file power.cc
#line 16 "/home/y-tanabe/proj/compprog/clib/power.cc"

template<typename T>
T power(const T& a, ll b) {
  auto two_pow = a;
  auto ret = one<T>(a);
  while (b > 0) {
    if (b & 1LL) ret *= two_pow;
    two_pow *= two_pow;
    b >>= 1;
  }
  return ret;
}

// ---- end power.cc

// ---- inserted library file matrix.cc
#line 73 "/home/y-tanabe/proj/compprog/clib/matrix.cc"

template <typename T>
struct Matrix {

  struct Part {
    const Matrix& mat;
    int i_size;
    int j_size;
    int i_0;
    int j_0;
    Part(const Matrix& mat_, int i_size_ = -1, int j_size_ = -1, int i_0_ = 0, int j_0_ = 0)
      : mat(mat_), i_size(i_size_ >= 0 ? i_size_ : mat.dimI),
        j_size(j_size_ >= 0 ? j_size_ : mat.dimJ), i_0(i_0_), j_0(j_0_) {
      if (i_0 + i_size > mat.dimI or j_0 + j_size > mat.dimJ) throw domain_error("part");
    }
  };

  int dimI;
  int dimJ;
  bool rev_rc = false; // if true, the order in mem is column->row
  vector<T> mem;

  T&       at(int i, int j)       { return rev_rc ? mem[j*dimI + i] : mem[i*dimJ + j]; }
  const T& at(int i, int j) const { return rev_rc ? mem[j*dimI + i] : mem[i*dimJ + j]; }
  
  Matrix() : dimI(1), dimJ(1), mem(1) {}
  Matrix(int dimI_, int dimJ_) : dimI(dimI_), dimJ(dimJ_), mem(dimI*dimJ) {}
  Matrix(int dimI_, int dimJ_, const T& t) : dimI(dimI_), dimJ(dimJ_), mem(dimI*dimJ, t) {}

  template<typename Z>
  void _from_vec(int dimI_, int dimJ_, Z&& vec) {
    int sz = vec.size();
    dimI = dimI_ <= 0 ? sz / dimJ_ : dimI_;
    dimJ = dimJ_ <= 0 ? sz / dimI_ : dimJ_;
    if (dimI * dimJ != sz) throw domain_error("_from_vec: inconsistent sizes");
    mem = forward<Z>(vec);
  }
  Matrix(int dimI_, int dimJ_, const vector<T>& vec) { _from_vec(dimI_, dimJ_, vec); }
  Matrix(int dimI_, int dimJ_, vector<T>&&      vec) { _from_vec(dimI_, dimJ_, move(vec)); }

  Matrix(initializer_list<initializer_list<T>> il) {
    dimI = il.size();
    if (dimI == 0) throw domain_error("from_il: zero rows");
    dimJ = (*il.begin()).size();
    if (dimJ == 0) throw domain_error("from_il: zero columns");
    mem.resize(dimI * dimJ);
    int i = 0;
    for (auto it : il) {
      if ((int)it.size() != dimJ) throw domain_error("from_il: not in rectangular shape");
      int j = 0;
      for (const T& t : it) mem[i * dimJ + (j++)] = t;
      i++;
    }
  }

  Matrix(const Part& cs) : dimI(cs.i_size), dimJ(cs.j_size), mem(dimI*dimJ) {
    for (int i = 0; i < dimI; i++) for (int j = 0; j < dimJ; j++) at(i, j) = cs.mat.at(cs.i_0 + i, cs.j_0 + j);
  }

  bool operator ==(const Matrix& r) const {
    if (dimI != r.dimI or dimJ != r.dimJ) return false;
    if (rev_rc == r.rev_rc) return mem == r.mem;
    for (int i = 0; i < dimI; i++) for (int j = 0; j < dimJ; j++) if (at(i, j) != r.at(i, j)) return false;
    return true;
  }
  bool operator !=(const Matrix& r) const { return !(*this == r); }

  T _zero_T() const { return ::zero<T>(at(0, 0)); }
  T _one_T() const { return ::one<T>(at(0, 0)); }

  template<int sign>
  Matrix& _add_subt(const Matrix& r) {
    if (dimI != r.dimI or dimJ != r.dimJ) throw domain_error("_add_subt: dimension mismatch");
    for (int i = 0; i < dimI; i++) for (int j = 0; j < dimJ; j++) {
        if constexpr (sign > 0) at(i, j) += r.at(i, j);
        else                    at(i, j) -= r.at(i, j);
      }
    return *this;
  }
  Matrix& operator +=(const Matrix& r) { return _add_subt<1>(r); }
  Matrix& operator -=(const Matrix& r) { return _add_subt<-1>(r); }
  Matrix operator +(const Matrix& r) const { return Matrix(*this) += r; }
  Matrix operator -(const Matrix& r) const { return Matrix(*this) -= r; }

  Matrix operator *(const Matrix& r) const {
    if (dimJ != r.dimI) throw domain_error("mult: dimension mismatch");
    Matrix result(dimI, r.dimJ, _zero_T());
    for (int i = 0; i < dimI; i++) for (int j = 0; j < r.dimJ; j++) {
	for (int k = 0; k < dimJ; k++) result.at(i, j) += at(i, k) * r.at(k, j);
      }
    return result;
  }
  Matrix& operator *=(const Matrix& r) { return *this = *this * r; }

  Matrix& operator *=(const T& t) {
    for (int p = 0; p < dimI * dimJ; p++) mem[p] *= t;
    return *this;
  }
  friend Matrix operator *(const Matrix& mat, const T& t) { return Matrix(mat) *= t; }
  friend Matrix operator *(const T& t, const Matrix& mat) { // Mult of T might be non-commutative
    Matrix ret(mat);
    for (int p = 0; p < mat.dimI * mat.dimJ; p++) ret.mem[p] = t * ret.mem[p];
    return ret;
  }

  static Matrix from_vvec(const vector<vector<T>>& vvec) {
    int dimI_ = vvec.size();
    if (dimI_ == 0) throw domain_error("from_vvec: zero rows");
    int dimJ_ = vvec[0].size();
    if (dimJ_ == 0) throw domain_error("from_vvec: zero columns");
    Matrix ret(dimI_, dimJ_);
    for (int i = 0; i < dimI_; i++) {
      if ((int)vvec[i].size() != dimJ_) throw domain_error("from_vvec: not in rectangular shape");
      for (int j = 0; j < dimJ_; j++) ret.mem[i*dimJ_ + j] = vvec[i][j];
    }
    return ret;
  }

  Matrix zero() const { return Matrix(dimI, dimJ, _zero_T()); }
  Matrix unit() const {
    if (dimI != dimJ) throw domain_error("unit: dimension mismatch");
    Matrix ret(dimI, dimI, _zero_T());
    for (int i = 0; i < dimI; i++) ret.at(i, i) = _one_T();
    return ret;
  }
  Matrix one() const { return unit(); }  // for general operation Ring

  Part part(int i_size_ = -1, int j_size_ = -1, int i_0_ = 0, int j_0_ = 0) const {
    return Part(*this, i_size_, j_size_, i_0_, j_0_);
  }

  Matrix rowVec(int i) const { return Matrix(part(1, -1, i, 0)); }
  Matrix colVec(int j) const { return Matrix(part(-1, 1, 0, j)); }

  void memcopy(const Part& cs, int i_1 = 0, int j_1 = 0) {
    for (int i = 0; i < cs.i_size; i++) for (int j = 0; j < cs.j_size; j++) {
        at(i_1 + i, j_1 + j) = cs.mat.at(cs.i_0 + i, cs.j_0 + j);
      }
  }

  Matrix matpower(ll x) const { return power<Matrix>(*this, x); }

  Matrix& self_transpose() {
    rev_rc = not rev_rc;
    swap(dimI, dimJ);
    return *this;
  }
  Matrix transpose() { return Matrix(*this).self_transpose(); }

  /* aux functions for sweepout */

  void basic_mult(int i, T t) {               // multiplies i-th row by t
    for (int j = 0; j < dimJ; j++) at(i, j) *= t;
  }
  void basic_xchg(int i1, int i2) {           // exchanges i1-th and i2-th rows
    for (int j = 0; j < dimJ; j++) swap(at(i1, j), at(i2, j));
  }
  void basic_mult_add(int i1, T t, int i2) {  // adds t times of i1-th row to i2-th row
    for (int j = 0; j < dimJ; j++) at(i2, j) += t * at(i1, j);
  }

  pair<int, int> _find_nz(int i0, int j0) const {
    for ( ; j0 < dimJ; j0++) {
      int i = i0;
      for ( ; i < dimI && at(i, j0) == _zero_T(); i++);
      if (i < dimI) return {i, j0};
    }
    return {dimI, dimJ};
  }

  pair<int, T> self_sweepout() {
    T det = _one_T();
    int j0 = 0;
    int i0 = 0;
    for ( ; i0 < dimI; i0++, j0++) {
      auto [i1, j1] = _find_nz(i0, j0);
      if (i1 == dimI) break;
      j0 = j1;
      if (i1 != i0) {
        det = -det;
	basic_xchg(i0, i1);
      }
      det *= at(i0, j0);
      basic_mult(i0, ::inverse<T>(at(i0, j0)));
      for (int i = 0; i < dimI; i++) {
	if (i == i0) continue;
        basic_mult_add(i0, -at(i, j0), i);
      }
    }
    return {i0, move(det)};
  }
  
  pair<int, T> sweepout() const { 
    Matrix res1(*this);
    return res1.self_sweepout();
  }

  T determinant() const {
    auto [rank, det] = sweepout();
    return (rank == dimI) ? det : _zero_T();
  }

  optional<Matrix> inv() const {
    if (dimI != dimJ) throw domain_error("inv: not square");
    Matrix work(dimI, dimI * 2);
    work.memcopy(part());
    work.memcopy(unit().part(), 0, dimI);
    work.self_sweepout();
    if (work.at(dimI - 1, dimI - 1) != _one_T()) return {};
    Matrix ret(dimI, dimI);
    ret.memcopy(work.part(dimI, dimI, 0, dimI));
    return ret;
  }

  Matrix inverse() const { return inv().value(); } // for general operation of Ring / Semi Ring

  template<bool ret_kernel = false>
  optional<pair<Matrix, vector<Matrix>>> linSolution(const Matrix& bs) const {
    if (dimI != bs.dimI or bs.dimJ != 1) throw domain_error("linSolution: invalid bs");
    Matrix work(dimI, dimJ + 1);
    work.memcopy(part());
    work.memcopy(bs.part(), 0, dimJ);
    auto [rank, _] = work.self_sweepout();
    Matrix sol(dimJ, 1);
    vector<Matrix> kernel;
    if (rank == 0) {
      if constexpr (not ret_kernel) return make_pair(move(sol), move(kernel));
      for (int j = 0; j < dimJ; j++) {
        Matrix m(dimJ, 1);
        m.at(j, 0) = _one_T();
        kernel.push_back(m);
      }
      return make_pair(move(sol), move(kernel));
    }
    if (not ([&]() -> bool {
      for (int j = 0; j < dimJ; j++) if (work.at(rank - 1, j) != _zero_T()) return true;
      return false;
    })()) return nullopt;
    for (int i = 0, j = 0; i < rank; i++, j++) {
      for ( ; work.at(i, j) == _zero_T(); j++);
      sol.at(j, 0) = work.at(i, dimJ);
    }
    if constexpr (not ret_kernel) return make_pair(move(sol), move(kernel));
    vector<bool> cor(dimJ, false);
    int i = 0;
    for (int j = 0 ; j < dimJ; j++) {
      if (i == dimI || work.at(i, j) == _zero_T()) {
        Matrix vec(dimJ, 1);
        vec.at(j, 0) = _one_T();
        for (int p = 0, q = 0; p < i; p++, q++) {
          while (!cor[q]) q++;
          vec.at(q, 0) = -work.at(p, j);
        }
        kernel.push_back(move(vec));
      }else {
        cor[j] = true;
        if (i < dimI) i++;
      }
    }
    return make_pair(move(sol), move(kernel));
  }

  friend istream& operator >>(istream& is, Matrix& mat) {
    is >> mat.dimI >> mat.dimJ;
    mat.rev_rc = false;
    mat.mem.resize(mat.dimI * mat.dimJ);
    for (int i = 0; i < mat.dimI; i++) for (int j = 0; j < mat.dimJ; j++) is >> mat.at(i, j);
    return is;
  }

  friend ostream& operator <<(ostream& os, const Matrix& mat) {
    for (int i = 0; i < mat.dimI; i++) {
      for (int j = 0; j < mat.dimJ; j++) {
        if (j > 0) os << ", ";
        os << mat.at(i, j);
      }
      os << "\n";
    }
    return os;
  }

};

// ---- end matrix.cc

// ---- inserted library file ftwo.cc
#line 21 "/home/y-tanabe/proj/compprog/clib/ftwo.cc"

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

  Ftwo zero() const { return (Ftwo)0; }
  Ftwo one() const { return (Ftwo)1; }
  Ftwo inverse() const { return inv(); }

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

/* 
  From a tweet by Noshibukuro (@noshi91)
  https://twitter.com/noshi91/status/1200702280128856064

  getF2Basis<mode>(vs)  ... Returns a basis of the vector space generated by vs
    mode == 0 ... Returning basis is a subset of vs
    mode == 1 ... Returning basis B is triangular.  I.e., B = {b1, b2, ... } with MSB(b_i) > MSB(b_j) if i < j.
*/
template<int mode>
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
  if constexpr (mode == 0) return ret;
  else if constexpr (mode == 1) {
    sort(aux.begin(), aux.end(), greater<ll>());
    return aux;
  }else static_assert([]{ return false; }(), "mode must be 0 or 1");
}

// ---- end ftwo.cc

// @@ !! LIM -- end mark --
#line 7 "ftwo_skel.cc"

int main() {

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

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
      // DLOGK(sz1);
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
      auto basis = getF2Basis<0>(vs);
      // DLOGK(sz1);
      // DLOGK(vs);
      // DLOGK(basis);
      assert((ll)basis.size() == sz1);
      Matrix<Ftwo> mat2(sz1, sz2);
      for (ll i = 0; i < sz1; i++) {
        for (ll j = 0; j < sz2; j++) {
          mat2.at(i, j) = (((basis[i] >> j) & 1) != 0) ? 1 : 0;
        }
      }
      // DLOGK(mat2);
      auto [rank2, det2] = mat2.self_sweepout();
      // DLOGK(rank2);
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
        // DLOGK(mat3);
        auto [rank3, det3] = mat3.self_sweepout();
        // DLOGK(rank3);
        assert((ll)rank3 == sz1);
      }
    }
  }

  {
    auto bs = getF2Basis<0>({5, 20, 8, 17, 31, 13, 6});
    assert((bs == vector<ll>{5, 20, 8, 31}));
    auto bs2 = getF2Basis<1>({5, 20, 8, 17, 31, 13, 6, 2});
    assert((bs2 == vector<ll>{17, 8, 5, 3, 1}));
  }

  {
    ll rep = 1000;
    ll lim = 1LL << 10;

    auto isBasis = [&](const vector<ll>& bs, const vector<ll>& vs) -> bool {
      DLOGKL("isBasis", bs, vs);
      ll n = bs.size();
      vector g(lim, false);
      for (ll x = 0; x < (1LL << n); x++) {
        ll t = 0; for (ll p = 0; p < n; p++) if (x >> p & 1) t ^= bs[p];
        if (g[t]) {
          DLOGKL("dup", t);
          return false;
        }
        g[t] = true;
      }
      for (ll v : vs) if (not g[v]) {
          DLOGKL("no", v);
          return false;
        }
      return true;
    };

    auto msb = [&](ll x) -> ll { return 63 - __builtin_clzll(x); };

    for (ll _i = 0; _i < rep; _i++) {
      auto sz = randrange(1, 9);
      auto wd = randrange(1, 9);
      vector<ll> vs;
      set<ll> ss;
      for (ll j = 0; j < sz; j++) {
        ll v = randrange(0, 1LL << wd);
        vs.push_back(v);
        ss.insert(v);
      }
      auto bs0 = getF2Basis<0>(vs);
      auto bs1 = getF2Basis<1>(vs);
      assert(isBasis(bs0, vs));
      assert(isBasis(bs1, vs));
      for (ll b : bs0) assert(ss.find(b) != ss.end());
      for (ll j = 0; j < (ll)bs1.size() - 1; j++) assert(msb(bs1[j]) > msb(bs1[j + 1]));
    }
  }

  cerr << "Test Done.\n";

}
