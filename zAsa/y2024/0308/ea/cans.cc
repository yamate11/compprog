#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(matrix segTree mod cmpNaive)

// ---- inserted library file algOp.cc

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

namespace tartan_detail {
  template <template <class...> class Trait, class Enabler, class... Args>
  struct is_detected : false_type{};

  template <template <class...> class Trait, class... Args>
  struct is_detected<Trait, void_t<Trait<Args...>>, Args...> : true_type{};
}

template <template <class...> class Trait, class... Args>
using is_detected = typename tartan_detail::is_detected<Trait, void, Args...>::type;

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

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig);

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig);

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st);

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t);
#endif

ostream& operator<< (ostream& os, int8_t x);

// definitions

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

// ---- inserted library file segTree.cc

// It seems that we should keep the size power of two,
// considering the binary search.

pair<int, int> segtree_range_of_node(int ht, unsigned i) {
  unsigned m = bit_floor(i);
  unsigned w = ht + 1 - bit_width(i);
  int lo = (i ^ m) << w;
  int hi = lo + (1LL << w);
  return make_pair(lo, hi);
}

vector<int> segtree_nodes_for_range(int ht, unsigned lo, unsigned hi) {
  vector<int> left;
  vector<int> right;
  lo = (1 << ht) + lo;
  hi = (1 << ht) + hi - 1;
  while (lo <= hi) {
    if (lo == hi) {
      left.push_back(lo);
      break;
    }
    if (lo & 1) {
      left.push_back(lo);
      lo++;
    }
    if (not (hi & 1)) {
      right.push_back(hi);
      hi--;
    }
    lo >>= 1;
    hi >>= 1;
  }
  while (not right.empty()) {
    left.push_back(right.back());
    right.pop_back();
  }
  return left;
}

template <typename DAT, typename OP,
	  typename ADD_t, typename COMP_t, typename APPL_t, bool lazy> 
struct GenSegTree {
  using GST = GenSegTree<DAT, OP, ADD_t, COMP_t, APPL_t, lazy>;

  int orig_size;     // size of initdat
  int size;	     // power of two; >= 2
  int height;        // size = 1 << height;
  vector<DAT> node;  // vector of size 2*size.
                     // 0                 : unused
                     // 1    ... size-1   : interval
                     // size ... 2*size-1 : leaf
  vector<OP> susp;   // vector of size size.
                     // suspended operation FOR CHILDREN
                     // (already applied to this node)
  DAT unit_dat;
  OP unit_op;
  ADD_t add;
  COMP_t comp;
  APPL_t appl;
    
  GenSegTree() {}

  GenSegTree(DAT unit_dat_, OP unit_op_, ADD_t add_, COMP_t comp_, APPL_t appl_,
             const vector<DAT>& initdat = vector<DAT>())
    : unit_dat(unit_dat_), unit_op(unit_op_),
      add(add_), comp(comp_), appl(appl_) { set_data(initdat); }

  void set_data(const vector<DAT>& initdat) {
    orig_size = initdat.size();
    if (initdat.size() <= 1) height = 0;
    else   height = sizeof(int) * 8 - __builtin_clz(initdat.size() - 1);
    size = 1 << height;
    node.resize(2*size, unit_dat);
    for (int i = 0; i < (int)initdat.size(); i++) node[size + i] = initdat[i];
    for (int t = size - 1; t >= 1; t--) node[t] = add(node[t<<1|0], node[t<<1|1]);
    susp.resize(size, unit_op);
  }

  void child_updated_sub(int t) {
    node[t] = appl(susp[t], add(node[t<<1|0], node[t<<1|1]));
  }

  void child_updated(int l, int r) {
    r--;
    while (l > 1) {
      l >>= 1;
      r >>= 1;
      child_updated_sub(l);
      if (l < r) child_updated_sub(r);
    }
  }

  void node_op(int i, OP f) {
    node[i] = appl(f, node[i]);
    if (i < size) susp[i] = comp(f, susp[i]);
  }

  // Note that susp[i] HAS ALREADY BEEN APPLIED TO node[i].
  // When push_one(i) is called, susp[j] is updated (for j : i's child) and it is applied to node[j].
  void push_one(int i) {
    node_op(i<<1|0, susp[i]);
    node_op(i<<1|1, susp[i]);
    susp[i] = unit_op;
  }

  void push_upto(int l, int r) {
    for (int s = height; s >= 1; s--) {
      int lz = l >> s;
      int rz = (r-1) >> s;
      push_one(lz);
      if (lz < rz) push_one(rz);
    }
  }

  DAT query(int l, int r) {
    if (l >= r) return unit_dat;
    DAT ret_l = unit_dat;
    DAT ret_r = unit_dat;
    l += size;
    r += size;
    if constexpr(lazy) push_upto(l, r);
    while (l < r) {
      if (l & 1) {
	ret_l = add(ret_l, node[l]);
	l++;
      }
      if (r & 1) {
	ret_r = add(node[r-1], ret_r);
      }
      l >>= 1;
      r >>= 1;
    }
    DAT ret = add(ret_l, ret_r);
    return ret;
  }

  const DAT& get_single(int i) {
    if constexpr(lazy) push_upto(size + i, size + i + 1);
    return node[size + i];
  }

  void set_single(int i, const DAT& t) {
    ll x = size + i;
    if constexpr(lazy) push_upto(x, x + 1);
    node[x] = t;
    for (x >>= 1; x >= 1; x >>= 1) node[x] = add(node[x<<1|0], node[x<<1|1]);
  }

  // obsolete
  template<bool xx = lazy> enable_if_t<! xx> update(int i, DAT t) {
    ll x = size + i;
    node[x] = t;
    for (x >>= 1; x >= 1; x >>= 1) node[x] = add(node[x<<1|0], node[x<<1|1]);
  }

  template<bool xx = lazy> enable_if_t<xx> update(int l, int r, const OP& f) {
    if (l >= r) return;
    l += size;
    r += size;
    push_upto(l, r);
    int l0 = l, r0 = r;
    while (l < r) {
      if (l & 1) {
	node_op(l, f);
	l++;
      }
      if (r & 1) {
	node_op(r-1, f);
      }
      l >>= 1;
      r >>= 1;
    }
    child_updated(l0, r0);
  }

  pair<int, int> range_of_node(unsigned i) { return segtree_range_of_node(height, i); }

  vector<int> nodes_for_range(unsigned lo, unsigned hi) { return segtree_nodes_for_range(height, lo, hi); }

  friend ostream& operator<<(ostream& os, GenSegTree& st) {
    os << '[';
    for (int i = 0; i < st.orig_size; i++) {
      if (i > 0) os << ", ";
      os << st.get_single(i);
    }
    os << ']';
    return os;
  }

  int binsearch_r_until(const auto& check, int l) {
    // DLOGKL("in: binsearch_r_until", l);
    if (not check(unit_dat)) return l - 1;
    if (l == orig_size) return l;
    DAT val = unit_dat;
    int x = l + size;
    if constexpr(lazy) push_upto(x, x + 1);
    while (true) {
      if (x & 1) {
        DAT t = add(val, node[x]);
        if (not check(t)) break;
        val = t;
        x++;
        if (__builtin_popcountll(x) == 1) return orig_size;
      }
      x >>= 1;
      // DLOGKL("1: ", x, val);
    }
    while (x < size) {
      if constexpr(lazy) push_one(x);
      x <<= 1;
      DAT t = add(val, node[x]);
      if (check(t)) {
        x++;
        val = t;
      }
      // DLOGKL("2: ", x, val);
    }
    // DLOGKL("3: ", x - size, orig_size);
    return min(x - size, orig_size);
  }

  int binsearch_r_from(const auto& check, int l) {
    return binsearch_r_until([&](DAT x) { return not check(x); }, l) + 1;
  }

  int binsearch_l_until(const auto& check, int r) {
    if (not check(unit_dat)) return r + 1;
    if (r == 0) return 0;
    DAT val = unit_dat;
    int x = r + size;
    if (x == 2 * size) {
      if (check(node[1])) return 0;
      x = 1;
    }else {
      if constexpr(lazy) push_upto(x - 1, x);
      while (true) {
        if (x & 1) {
          x--;
          DAT t = add(node[x], val);
          if (not check(t)) break;
          val = t;
          if (__builtin_popcountll(x) == 1) return 0;
        }
        x >>= 1;
      }
    }
    while (x < size) {
      if constexpr(lazy) push_one(x);
      x = x << 1 | 1;
      DAT t = add(node[x], val);
      if (check(t)) {
        val = t;
        x--;
      }
    }
    return x + 1 - size;
  }

  int binsearch_l_from(const auto& check, int r) {
    return binsearch_l_until([&](DAT x) { return not check(x); }, r) - 1;
  }

};

template<typename DAT, typename OP>
auto make_seg_tree_lazy(DAT unit_dat, OP unit_op, auto add, auto comp, auto appl,
                        const vector<DAT>& initdat = vector<DAT>()) {
  using ret_t = GenSegTree<DAT, OP, decltype(add), decltype(comp), decltype(appl), true>;
  return ret_t(unit_dat, unit_op, add, comp, appl, initdat);
}

void* dummy_comp(void* x, void* y) { return nullptr; }
template<typename DAT>
DAT dummy_appl(void* x, const DAT& y) { return y; }

template<typename DAT>
auto make_seg_tree(DAT unit_dat, auto add, const vector<DAT>& initdat = vector<DAT>()) {
  using ret_t = GenSegTree<DAT, void*, decltype(add), void* (*)(void*, void*), DAT (*)(void*, const DAT&), false>;
  return ret_t(unit_dat, nullptr, add, dummy_comp, dummy_appl<DAT>, initdat);
}

// ---- end segTree.cc

// ---- inserted function f:gcd from util.cc

// auto [g, s, t] = eGCD(a, b)
//     g == gcd(|a|, |b|) and as + bt == g           
//     It guarantees that max(|s|, |t|) <= max(|a| / g, |b| / g)   (when g != 0)
//     Note that gcd(a, 0) == gcd(0, a) == a.
tuple<ll, ll, ll> eGCD(ll a, ll b) {
  ll sa = a < 0 ? -1 : 1;
  ll ta = 0;
  ll za = a * sa;
  ll sb = 0;
  ll tb = b < 0 ? -1 : 1;
  ll zb = b * tb;
  while (zb != 0) {
    ll q = za / zb;
    ll r = za % zb;
    za = zb;
    zb = r;
    ll new_sb = sa - q * sb;
    sa = sb;
    sb = new_sb;
    ll new_tb = ta - q * tb;
    ta = tb;
    tb = new_tb;
  }
  return {za, sa, ta};
}

pair<ll, ll> crt_sub(ll a1, ll x1, ll a2, ll x2) {
  // DLOGKL("crt_sub", a1, x1, a2, x2);
  a1 = a1 % x1;
  a2 = a2 % x2;
  auto [g, s, t] = eGCD(x1, -x2);
  ll gq = (a2 - a1) / g;
  ll gr = (a2 - a1) % g;
  if (gr != 0) return {-1, -1};
  s *= gq;
  t *= gq;
  ll z = x1 / g * x2;
  // DLOGK(z);
  s = s % (x2 / g);
  ll r = (x1 * s + a1) % z;
  // DLOGK(r);
  if (r < 0) r += z;
  // DLOGK(r);
  return {r, z};
};

// Chinese Remainder Theorem
//
//    r = crt(a1, x1, a2, x2)
//    ==>   r = a1 (mod x1);  r = a2 (mod x2);  0 <= r < lcm(x1, x2)
//    If no such r exists, returns -1
//    Note: x1 and x2 should >= 1.  a1 and a2 can be negative or zero.
//
//    r = crt(as, xs)
//    ==>   for all i. r = as[i] (mod xs[i]); 0 <= r < lcm(xs)
//    If no such r exists, returns -1
//    Note: xs[i] should >= 1.  as[i] can be negative or zero.
//          It should hold: len(xs) == len(as) > 0

ll crt(ll a1, ll x1, ll a2, ll x2) { return crt_sub(a1, x1, a2, x2).first; }

ll crt(vector<ll> as, vector<ll> xs) {
  // DLOGKL("crt", as, xs);
  assert(xs.size() == as.size() && xs.size() > 0);
  ll r = as[0];
  ll z = xs[0];
  for (size_t i = 1; i < xs.size(); i++) {
    // DLOGK(i, r, z, as[i], xs[i]);
    tie(r, z) = crt_sub(r, z, as[i], xs[i]);
    // DLOGK(r, z);
    if (r == -1) return -1;
  }
  return r;
}

// ---- end f:gcd

// ---- inserted library file mod.cc

template<int mod=0>
struct FpG {   // G for General
  static ll dyn_mod;

  static ll getMod() {
    if (mod == 0) return dyn_mod;
    else          return mod;
  }

  static void setMod(ll _mod) {  // effective only when mod == 0
    dyn_mod = _mod;
  }

  static ll _conv(ll x) {
    if (x >= getMod())  return x % getMod();
    if (x >= 0)         return x;
    if (x >= -getMod()) return x + getMod();
    ll y = x % getMod();
    if (y == 0) return 0;
    return y + getMod();
  }

  ll val;

  FpG(int t = 0) : val(_conv(t)) {}
  FpG(ll t) : val(_conv(t)) {}
  FpG(const FpG& t) : val(t.val) {}
  FpG& operator =(const FpG& t) { val = t.val; return *this; }
  FpG& operator =(ll t) { val = _conv(t); return *this; }
  FpG& operator =(int t) { val = _conv(t); return *this; }

  FpG& operator +=(const FpG& t) {
    val += t.val;
    if (val >= getMod()) val -= getMod();
    return *this;
  }

  FpG& operator -=(const FpG& t) {
    val -= t.val;
    if (val < 0) val += getMod();
    return *this;
  }

  FpG& operator *=(const FpG& t) {
    val = (val * t.val) % getMod();
    return *this;
  }

  FpG inv() const {
    if (val == 0) { throw runtime_error("FpG::inv(): called for zero."); }
    auto [g, u, v] = eGCD(val, getMod());
    if (g != 1) { throw runtime_error("FpG::inv(): not co-prime."); }
    return FpG(u);
  }

  FpG zero() const { return (FpG)0; }
  FpG one() const { return (FpG)1; }
  FpG inverse() const { return inv(); }

  FpG& operator /=(const FpG& t) {
    return (*this) *= t.inv();
  }

  FpG operator +(const FpG& t) const { return FpG(val) += t; }
  FpG operator -(const FpG& t) const { return FpG(val) -= t; }
  FpG operator *(const FpG& t) const { return FpG(val) *= t; }
  FpG operator /(const FpG& t) const { return FpG(val) /= t; }
  FpG operator -() const { return FpG(-val); }

  bool operator ==(const FpG& t) const { return val == t.val; }
  bool operator !=(const FpG& t) const { return val != t.val; }
  
  operator ll() const { return val; }

  friend FpG operator +(int x, const FpG& y) { return FpG(x) + y; }
  friend FpG operator -(int x, const FpG& y) { return FpG(x) - y; }
  friend FpG operator *(int x, const FpG& y) { return FpG(x) * y; }
  friend FpG operator /(int x, const FpG& y) { return FpG(x) / y; }
  friend bool operator ==(int x, const FpG& y) { return FpG(x) == y; }
  friend bool operator !=(int x, const FpG& y) { return FpG(x) != y; }
  friend FpG operator +(ll x, const FpG& y) { return FpG(x) + y; }
  friend FpG operator -(ll x, const FpG& y) { return FpG(x) - y; }
  friend FpG operator *(ll x, const FpG& y) { return FpG(x) * y; }
  friend FpG operator /(ll x, const FpG& y) { return FpG(x) / y; }
  friend bool operator ==(ll x, const FpG& y) { return FpG(x) == y; }
  friend bool operator !=(ll x, const FpG& y) { return FpG(x) != y; }
  friend FpG operator +(const FpG& x, int y) { return x + FpG(y); }
  friend FpG operator -(const FpG& x, int y) { return x - FpG(y); }
  friend FpG operator *(const FpG& x, int y) { return x * FpG(y); }
  friend FpG operator /(const FpG& x, int y) { return x / FpG(y); }
  friend bool operator ==(const FpG& x, int y) { return x == FpG(y); }
  friend bool operator !=(const FpG& x, int y) { return x != FpG(y); }
  friend FpG operator +(const FpG& x, ll y) { return x + FpG(y); }
  friend FpG operator -(const FpG& x, ll y) { return x - FpG(y); }
  friend FpG operator *(const FpG& x, ll y) { return x * FpG(y); }
  friend FpG operator /(const FpG& x, ll y) { return x / FpG(y); }
  friend bool operator ==(const FpG& x, ll y) { return x == FpG(y); }
  friend bool operator !=(const FpG& x, ll y) { return x != FpG(y); }

  friend istream& operator>> (istream& is, FpG& t) {
    ll x; is >> x;
    t = x;
    return is;
  }

  friend ostream& operator<< (ostream& os, const FpG& t) {
    os << t.val;
    return os;
  }

};
template<int mod>
ll FpG<mod>::dyn_mod;

template<typename T>
class Comb {
  int nMax;
  vector<T> vFact;
  vector<T> vInvFact;
public:
  Comb(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact[0] = 1;
    for (int i = 1; i <= nMax; i++) vFact[i] = i * vFact[i-1];
    vInvFact.at(nMax) = (T)1 / vFact[nMax];
    for (int i = nMax; i >= 1; i--) vInvFact[i-1] = i * vInvFact[i];
  }
  T fact(int n) { return vFact[n]; }
  T binom(int n, int r) {
    if (r < 0 || r > n) return (T)0;
    return vFact[n] * vInvFact[r] * vInvFact[n-r];
  }
  T binom_dup(int n, int r) { return binom(n + r - 1, r); }
  // The number of permutation extracting r from n.
  T perm(int n, int r) {
    return vFact[n] * vInvFact[n-r];
  }
};

constexpr int primeA = 1'000'000'007;
constexpr int primeB = 998'244'353;          // '
using FpA = FpG<primeA>;
using FpB = FpG<primeB>;

// ---- end mod.cc

// ---- inserted library file cmpNaive.cc

const string end_mark("^__=end=__^");

int naive(istream& cin, ostream& cout);
int body(istream& cin, ostream& cout);

void cmpNaive() {
  while (true) {
    string s;
    getline(cin, s);
    bool run_body;
    if (s.at(0) == 'Q') {
      return;
    }else if (s.at(0) == 'B') {
      run_body = true;
    }else if (s.at(0) == 'N') {
      run_body = false;
    }else {
      cerr << "Unknown body/naive specifier.\n";
      exit(1);
    }
    string input_s;
    while (true) {
      getline(cin, s);
      if (s == end_mark) break;
      input_s += s;
      input_s += "\n";
    }
    stringstream ss_in(move(input_s));
    stringstream ss_out;
    ss_out << setprecision(20);
    if (run_body) {
      body(ss_in, ss_out);
    }else {
      naive(ss_in, ss_out);
    }
    cout << ss_out.str() << end_mark << endl;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if CMPNAIVE
  if (argc == 2) {
    if (strcmp(argv[1], "cmpNaive") == 0) {
      cmpNaive();
    }else if (strcmp(argv[1], "naive") == 0) {
      naive(cin, cout);
    }else if (strcmp(argv[1], "skip") == 0) {
      exit(0);
    }else {
      cerr << "Unknown argument.\n";
      exit(1);
    }
  }else {
#endif
    body(cin, cout);
#if CMPNAIVE
  }
#endif
  return 0;
}

/*
int naive(istream& cin, ostream& cout) {
  return 0;
}
int body(istream& cin, ostream& cout) {
  return 0;
}
*/

// ---- end cmpNaive.cc

// @@ !! LIM -- end mark --

using Fp = FpB;

int naive(istream& cin, ostream& cout) {
  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A, dec=1) [ZtYcDT3M]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [ZtYcDT3M]

  REP(q, 0, Q) {
    ll tp, l, r; cin >> tp >> l >> r; l--;
    if (tp == 1) {
      vector tbl_d(4, 0LL);
      vector tbl_s(4, 0LL);
      REP(i, l, r) {
        auto prev_d = tbl_d;
        auto prev_s = tbl_s;
        REP(k, 0, 4) if (k != A[i]) tbl_d[A[i]] += prev_d[k] + prev_s[k];
        tbl_s[A[i]]++;
      }
      ll ans = 0;
      REP(k, 0, 4) ans += tbl_d[k];
      cout << ans << "\n";
    }else if (tp == 2) {
      ll x; cin >> x; x--;
      REP(i, l, r)  A[i] = x;
    }
  }
  return 0;
}

using M_t = Matrix<Fp>;
M_t m_unit = M_t(5, 5).unit();
struct S {
  M_t mat;
  ll len;
  S(const M_t& mat_, ll len_) : mat(mat_), len(len_) {};
  S() : mat(m_unit), len(0) {}
};

S build_S(ll k, ll len) {
  S ret;
  REP(i, 0, 5) ret.mat.at(k, i) = i == k ? 1 : len;
  ret.len = len;
  return ret;
}

string show_M(const M_t& m) {
  stringstream ss;
  REP(i, 0, m.dimI) {
    REP(j, 0, m.dimJ) ss << m.at(i, j) << " ";
    ss << endl;
  }
  return ss.str();
}


int body(istream& cin, ostream& cout) {

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A, dec=1) [ZtYcDT3M]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [ZtYcDT3M]

  using OP = optional<ll>;
  auto myadd = [](const S& x, const S& y) -> S { return S(x.mat * y.mat, x.len + y.len); };
  auto comp = [](OP f, OP g) -> OP { return f ? f : g; };
  auto appl = [](OP f, S x) -> S { return f ? build_S(*f, x.len) : x; };
  vector<S> init_vec(N);
  REP(i, 0, N) init_vec[i] = build_S(A[i], 1);
  auto st = make_seg_tree_lazy(S{m_unit, 0}, OP(), myadd, comp, appl, init_vec);

  REP(q, 0, Q) {
    ll tp, l, r; cin >> tp >> l >> r; l--;
    if (tp == 1) {
      if (l + 1 == r) {
        cout << 0 << "\n";
      }else {
        auto d = st.query(l, r);
        M_t vv(5, 1);
        vv.at(4, 0) = Fp(1);
        auto s = d.mat * vv;
        Fp ans = s.at(0, 0) + s.at(1, 0) + s.at(2, 0) + s.at(3, 0) - (r - l);
        cout << ans << "\n";
      }
    }else if (tp == 2) {
      ll x; cin >> x; x--;
      st.update(l, r, x);
    }else assert(0);
  }

  return 0;
}

