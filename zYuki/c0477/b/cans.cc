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

// @@ !! LIM(matrix mod debug)

// ---- inserted library file algOp.cc

// Common definitions
//    zero, one, inverse

template<typename T>
const T zero(const T& t) {
  if constexpr (is_integral_v<T> || is_floating_point_v<T>) { return (T)0; }
  else { return t.zero(); }
}

template<typename T>
const T one(const T& t) {
  if constexpr (is_integral_v<T> || is_floating_point_v<T>) { return (T)1; }
  else { return t.one(); }
}

template<typename T>
const T inverse(const T& t) {
  if constexpr (is_floating_point_v<T>) { return 1.0 / t; }
  else { return t.inverse(); }
}

#ifdef BOOST_MP_CPP_INT_HPP
template<> const cpp_int zero(const cpp_int& t) { return cpp_int(0); }
template<> const cpp_int one(const cpp_int& t) { return cpp_int(1); }
#endif // BOOST_MP_CPP_INT_HPP

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

// a >= 0, b >= 0;  If overflow, returns -1.
ll llpower(ll a, ll b) {  
  if (b == 0) return 1;   // 0^0 == 1
  if (b == 1) return a;
  if (a == 0) return 0;
  if (a == 1) return 1;
  if (a == 2) {
    if (b >= 63) return -1;
    else return 1LL << b;
  }
  if (b == 2) {
    ll ret;
    if (__builtin_smulll_overflow(a, a, &ret)) return -1;
    return ret;
  }
  ll two_pow = a;
  ll ret = 1;
  assert(b > 0);
  while (true) {
    if (b & 1LL) {
      if (__builtin_smulll_overflow(ret, two_pow, &ret)) return -1;
    }
    b >>= 1;
    if (b == 0) break;
    if (__builtin_smulll_overflow(two_pow, two_pow, &two_pow)) return -1;
  }
  return ret;
}

// a >= 0;   Returns x s.t. x*x <= a < (x+1)*(x+1)
ll llsqrt(ll a) {
  ll x = llround(sqrt((double)a));
  ll y;
  if (__builtin_smulll_overflow(x, x, &y) or a < y) return x - 1;
  else return x;
}

// a >= 0, m >= 2;  Returns x s.t. x^m <= a < (x + 1)^m
ll llroot(ll a, ll m) {
  ll x = llround(pow(a, 1.0 / m));
  ll y = llpower(x, m);
  if (y == -1 or a < y) return x - 1;
  else return x;
}

//  base >= 2, a >= 1;  Returns x s.t. base^{x} <= a < base^{x + 1}
ll lllog(ll base, ll a) {
  ll x = llround(log(a) / log(base));
  ll y = llpower(base, x);
  if (y == -1 or a < y) return x - 1;
  else return x;
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

  vector<T> operator *(const vector<T>& vec) const {
    auto m = (*this) * Matrix(0, 1, vec);
    return m.mem;
  }

  vector<T> operator *(vector<T>&& vec) const {
    auto m = (*this) * Matrix(0, 1, move(vec));
    return m.mem;
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

// ---- inserted function f:gcd from util.cc

// auto [g, s, t] = eGCD(a, b)
//     g == gcd(|a|, |b|) and as + bt == g           
//     It guarantees that max(|s|, |t|) <= max(|a| / g, |b| / g)   (when g != 0)
//     Note that gcd(a, 0) == gcd(0, a) == a.
template<typename INT=ll>
tuple<INT, INT, INT> eGCD(INT a, INT b) {
  INT sa = a < 0 ? -1 : 1;
  INT ta = 0;
  INT za = a * sa;
  INT sb = 0;
  INT tb = b < 0 ? -1 : 1;
  INT zb = b * tb;
  while (zb != 0) {
    INT q = za / zb;
    INT r = za % zb;
    za = zb;
    zb = r;
    INT new_sb = sa - q * sb;
    sa = sb;
    sb = new_sb;
    INT new_tb = ta - q * tb;
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

template<int mod=0, typename INT=ll>
struct FpG {   // G for General
  static INT dyn_mod;

  static INT getMod() {
    if (mod == 0) return dyn_mod;
    else          return (INT)mod;
  }
  
  // Effective only when mod == 0.
  // _mod must be less than the half of the maximum value of INT.
  static void setMod(INT _mod) {  
    dyn_mod = _mod;
  }

  static INT _conv(INT x) {
    if (x >= getMod())  return x % getMod();
    if (x >= 0)         return x;
    if (x >= -getMod()) return x + getMod();
    INT y = x % getMod();
    if (y == 0) return 0;
    return y + getMod();
  }

  INT val;

  FpG(INT t = 0) : val(_conv(t)) {}
  FpG(const FpG& t) : val(t.val) {}
  FpG& operator =(const FpG& t) { val = t.val; return *this; }
  FpG& operator =(INT t) { val = _conv(t); return *this; }

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
  
  operator INT() const { return val; }

  friend FpG operator +(INT x, const FpG& y) { return FpG(x) + y; }
  friend FpG operator -(INT x, const FpG& y) { return FpG(x) - y; }
  friend FpG operator *(INT x, const FpG& y) { return FpG(x) * y; }
  friend FpG operator /(INT x, const FpG& y) { return FpG(x) / y; }
  friend bool operator ==(INT x, const FpG& y) { return FpG(x) == y; }
  friend bool operator !=(INT x, const FpG& y) { return FpG(x) != y; }
  friend FpG operator +(const FpG& x, INT y) { return x + FpG(y); }
  friend FpG operator -(const FpG& x, INT y) { return x - FpG(y); }
  friend FpG operator *(const FpG& x, INT y) { return x * FpG(y); }
  friend FpG operator /(const FpG& x, INT y) { return x / FpG(y); }
  friend bool operator ==(const FpG& x, INT y) { return x == FpG(y); }
  friend bool operator !=(const FpG& x, INT y) { return x != FpG(y); }

  /* The following are needed to avoid warnings in cases such as FpG x; x = 5 + x; rather than x = FpG(5) + x; */
  friend FpG operator +(int x, const FpG& y) { return FpG(x) + y; }
  friend FpG operator -(int x, const FpG& y) { return FpG(x) - y; }
  friend FpG operator *(int x, const FpG& y) { return FpG(x) * y; }
  friend FpG operator /(int x, const FpG& y) { return FpG(x) / y; }
  friend bool operator ==(int x, const FpG& y) { return FpG(x) == y; }
  friend bool operator !=(int x, const FpG& y) { return FpG(x) != y; }
  friend FpG operator +(const FpG& x, int y) { return x + FpG(y); }
  friend FpG operator -(const FpG& x, int y) { return x - FpG(y); }
  friend FpG operator *(const FpG& x, int y) { return x * FpG(y); }
  friend FpG operator /(const FpG& x, int y) { return x / FpG(y); }
  friend bool operator ==(const FpG& x, int y) { return x == FpG(y); }
  friend bool operator !=(const FpG& x, int y) { return x != FpG(y); }

  friend istream& operator>> (istream& is, FpG& t) {
    INT x; is >> x;
    t = x;
    return is;
  }

  friend ostream& operator<< (ostream& os, const FpG& t) {
    os << t.val;
    return os;
  }

};
template<int mod, typename INT>
INT FpG<mod, INT>::dyn_mod;

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
using FpA = FpG<primeA, ll>;
using FpB = FpG<primeB, ll>;

// ---- end mod.cc

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

template <typename T1, typename T2, typename T3, typename T4, typename T5>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5>& t);

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t);

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

ostream& operator<< (ostream& os, const __int128& x);

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

template <typename T1, typename T2, typename T3, typename T4, typename T5>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ", " << get<4>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ", " << get<4>(t) << ", " << get<5>(t) << ")";
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

// for Enum type; just displays ordinals.
template <typename E>
typename std::enable_if<std::is_enum<E>::value, std::ostream&>::type
operator<<(std::ostream& os, E e) {
    return os << static_cast<typename std::underlying_type<E>::type>(e);
}

// This is a very ad-hoc implementation...
ostream& operator<<(ostream& os, const __int128& v) {
  unsigned __int128 a = v < 0 ? -v : v;
  ll i = 0;
  string s(64, ' ');
  if (v == 0) {
    s[i++] = '0';
  }else {
    while (a > 0) {
      s[i++] = '0' + (char)(a % 10);
      a /= 10;
    }
  }
  if (v < 0) {
    s[i++] = '-';
  }
  s.erase(s.begin() + i, s.end());
  reverse(s.begin(), s.end());
  os << s;
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

// @@ !! LIM -- end mark --

using Fp = FpG<67, ll>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto f = [&](ll a1, ll b1, ll c1, ll d1, ll a2, ll b2, ll c2, ll d2) -> tuple<ll, ll, ll, ll> {
    ll a3 = a1 * a2 + b1 * c2;
    ll b3 = a1 * b2 + b1 * d2;
    ll c3 = c1 * a2 + d1 * c2;
    ll d3 = c1 * b2 + d1 * d2;
    return {a3, b3, c3, d3};
  };


  ll a1, b1, c1, d1; cin >> a1 >> b1 >> c1 >> d1; 
  ll a2, b2, c2, d2; cin >> a2 >> b2 >> c2 >> d2;

  Matrix mat1(2, 2, vector<Fp>{a1, b1, c1, d1});
  Matrix mat2(2, 2, vector<Fp>{a2, b2, c2, d2});

  REP(a3, 0, 67) REP(b3, 0, 67) REP(c3, 0, 67) REP(d3, 0, 67) {
    if (a3 * d3 - b3 * c3 == 0) continue;
    auto [a5, b5, c5, d5] = f(a3, b3, c3, d3, a1, b1, c1, d1);
    auto [a6, b6, c6, d6] = f(a2, b2, c2, d2, a3, b3, c3, d3);
    
    if ((a5 - a6) % 67 == 0 and (b5 - b6) % 67 == 0 and (c5 - c6) % 67 == 0 and (d5 - d6) % 67 == 0) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}

