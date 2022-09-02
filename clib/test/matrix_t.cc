#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// Library Insertion Mark
// @@ !! LIM(algOp power mod matrix)

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

// ---- inserted function f:gcd from util.cc

tuple<ll, ll, ll> mut_div(ll a, ll b, ll c, bool eff_c = true) {
  // auto [g, s, t] = mut_div(a, b, c, eff_c)
  //    If eff_c is true (default),
  //        g == gcd(|a|, |b|) and as + bt == c, if such s,t exists
  //        (g, s, t) == (-1, -1, -1)            otherwise
  //    If eff_c is false,                                 
  //        g == gcd(|a|, |b|) and as + bt == g           
  //    N.b.  gcd(0, t) == gcd(t, 0) == t.
  if (a == 0) {
    if (eff_c) {
      if (c % b != 0) return {-1, -1, -1};
      else            return {abs(b), 0, c / b};
    }else {
      if (b < 0) return {-b, 0, -1};
      else       return { b, 0,  1};
    }
  }else {
    auto [g, t, u] = mut_div(b % a, a, c, eff_c);
    // DLOGK(b%a, a, c, g, t, u);
    if (g == -1) return {-1, -1, -1};
    return {g, u - (b / a) * t, t};
  }
}

// auto [g, s, t] = eGCD(a, b)  --->  sa + tb == g == gcd(|a|, |b|)
//    N.b.  gcd(0, t) == gcd(t, 0) == t.
tuple<ll, ll, ll> eGCD(ll a, ll b) { return mut_div(a, b, 0, false); }

pair<ll, ll> crt_sub(ll a1, ll x1, ll a2, ll x2) {
  // DLOGKL("crt_sub", a1, x1, a2, x2);
  a1 = a1 % x1;
  a2 = a2 % x2;
  auto [g, s, t] = mut_div(x1, -x2, a2 - a1);
  // DLOGK(g, s, t);
  if (g == -1) return {-1, -1};
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
#line 40 "/home/y-tanabe/proj/compprog/clib/mod.cc"

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
    if (val == 0) {
      throw runtime_error("FpG::inv(): called for zero.");
    }
    auto [g, u, v] = eGCD(val, getMod());
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

template<int mod=0>
class CombG {
  int nMax;
  vector<FpG<mod>> vFact;
  vector<FpG<mod>> vInvFact;
public:
  CombG(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact.at(0) = 1;
    for (int i = 1; i <= nMax; i++) vFact.at(i) = i * vFact.at(i-1);
    vInvFact.at(nMax) = vFact.at(nMax).inv();
    for (int i = nMax; i >= 1; i--) vInvFact.at(i-1) = i * vInvFact.at(i);
  }
  FpG<mod> fact(int n) { return vFact.at(n); }
  FpG<mod> binom(int n, int r) {
    if (r < 0 || r > n) return 0;
    return vFact.at(n) * vInvFact.at(r) * vInvFact.at(n-r);
  }
  FpG<mod> binom_dup(int n, int r) { return binom(n + r - 1, r); }
  // The number of permutation extracting r from n.
  FpG<mod> perm(int n, int r) {
    return vFact.at(n) * vInvFact.at(n-r);
  }
};

constexpr int primeA = 1'000'000'007;
constexpr int primeB = 998'244'353;          // '
using FpA = FpG<primeA>;
using FpB = FpG<primeB>;
using CombA = CombG<primeA>;
using CombB = CombG<primeB>;

// ---- end mod.cc

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

// @@ !! LIM -- end mark --
#line 8 "matrix_skel.cc"

int main() {
  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  {
    using Fp = FpA;

    cerr << "start" << endl;
    cerr << "equation" << endl;
    Matrix<ll> mat0({{0,1,0},{2,0,-1}});
    Matrix<ll> mat1 = Matrix<ll>(2,3);
    mat1.at(0,1) = 1;
    mat1.at(1,0) = 2;
    mat1.at(1,2) = -1;
    assert(mat0 == mat1);
    assert(!(mat0 != mat1));

    cerr << "addition" << endl;
    Matrix<ll> mat2({{1,0,0}, {0,0,1}});
    Matrix<ll> mat3({{4}, {5}, {6}});
    Matrix<ll> mat4({{5}, {2}});
    Matrix<ll> mat5({{1,1,0},{2,0,0}});
    Matrix<ll> tmp = mat2 + mat0;
    bool tmp2 = tmp == mat5;
    assert(tmp2);
    assert(mat2 + mat0 == mat5);
    Matrix<ll> mat6 = mat2;
    mat2 += mat0;
    assert(mat2 == mat5);

    cerr << "subtraction" << endl;
    assert(mat5 - mat0 == mat6);
    mat5 -= mat0;
    assert(mat5 == mat6);

    cerr << "multiplication" << endl;
    assert(mat0 * mat3 == mat4);
    mat0 *= mat3;
    assert(mat0 == mat4);
    Matrix<ll> mat7 = {{1, 3}, {0, 1}};

    cerr << "power" << endl;
    assert(mat7.matpower(5) == mat7*mat7*mat7*mat7*mat7);
    assert(power(mat7, 5) == mat7*mat7*mat7*mat7*mat7);
    assert(mat7.matpower(11) == mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7);
    Matrix<double> mat8 = {{1.0, 2.0}, {3.0, 4.0}};
    Matrix<double> mat9 = {{7.0, 10.0}, {15.0, 22.0}};
    assert(mat9 == mat8 * mat8);
    Matrix<Fp> mat9a = {{1,2,3}, {5,5,5}, {-3,-1,0}};
    assert(power(mat9a, 5) == mat9a*mat9a*mat9a*mat9a*mat9a);
    assert(mat9a.matpower(3) == mat9a*mat9a*mat9a);

    cerr << "at" << endl;
    vector<vector<ll>> vec10 = {{3,2,0}, {5,4,1}};
    Matrix<ll> mat10 = Matrix<ll>::from_vvec(vec10);
    Matrix<ll> mat11(2, 3);
    for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++) {
        mat11.at(i,j) = vec10.at(i).at(j);
      }
    assert(mat10 == mat11);

    cerr << "transpose" << endl;
    Matrix<ll> mat12a = {{0,1,0}, {2,0,-1}};
    Matrix<ll> mat12 = {{0,2}, {1,0}, {0,-1}};
    assert(mat12a == mat12.transpose());
    assert(mat12a.transpose() == mat12);
    assert(mat12a == mat12a.transpose().transpose());

    Matrix<ll> mat13({{1,2,-1}, {3,0,-2}});
    Matrix<ll> mat14({{0,1}, {-1,2}, {3,1}});
    Matrix<ll> mat14b({{0,-1,3}, {1,2,1}});
    mat14.self_transpose();
    assert(mat14 == mat14b);
    assert(mat13 + mat14 == Matrix<ll>({{1,1,2}, {4,2,-1}}));
    assert(mat13 - mat14 == Matrix<ll>({{1,3,-4}, {2,-2,-3}}));
    Matrix<ll> mat15({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
    assert(mat14 * mat15 == mat14b * mat15);
    Matrix<FpB> mat16({{2,3,4},{-1,0,-2},{1,-1,3}});
    Matrix<FpB> mat16a({{2,-1,1},{3,0,-1},{4,-2,3}});
    mat16a.self_transpose();
    assert(mat16 == mat16a);
    assert(mat16a.determinant() != 0);
    assert(mat16.inverse() == mat16a.inverse());
  }

  {
    struct MinMax {
      ll v;
      MinMax(ll v_ = LLONG_MAX) : v(v_) {}
      bool operator ==(const MinMax& o) const { return v == o.v; }
      bool operator !=(const MinMax& o) const { return v != o.v; }
      MinMax zero() const { return LLONG_MAX; }
      MinMax one() const { return LLONG_MIN; }
      MinMax operator +=(const MinMax& o) { if (v > o.v) v = o.v; return *this;}
      MinMax operator *=(const MinMax& o) { if (v < o.v) v = o.v; return *this;}
      MinMax operator +(const MinMax& o) const { return MinMax(v) += o; }
      MinMax operator *(const MinMax& o) const { return MinMax(v) *= o; }
    };
    MinMax x10(10), x2(2), x5(5), x4(4), x6(6);
    Matrix<MinMax> mat1({{x2, x5}, {x10, x2}});
    Matrix<MinMax> mat2({{x5, x5}, {x4,  x6}});
    assert(mat1 + mat2 == Matrix<MinMax>({{x2, x5}, {x4, x2}}));
    assert(mat1 * x6 == Matrix<MinMax>({{x6, x6}, {x10, x6}}));
    assert(mat1 * mat2 == Matrix<MinMax>({{x5, x5}, {x4, x6}}));
  }

  {
    using Fp = FpA;

    cerr << "sweepout, determinant, inverse" << endl;
    Matrix<Fp> mat13  = {{2,5,7}, {4,-2,20}, {4, 6, 42}, {8,-7,7}};
    Matrix<Fp> mat13a = {{2,5,7}, {0,-12,6}, {0, 0, 26}, {0,0,0}};
    Matrix<Fp> mat13b = {{2,0,0}, {4,-12,0}, {4,-4,26}, {8,-27,0}};
    mat13b.at(3,2) = Fp(-69) / Fp(2);
    auto [rank13, det13] = mat13.sweepout();
    assert(rank13 == 3 && det13 == Fp(2) * Fp(-12) * Fp(26));
    auto [rank13x, det13x] = mat13.self_transpose().sweepout();
    assert(rank13x == rank13 && det13x == det13);
    Matrix<Fp> mat13c = {{2,5,7}, {4,-2,20}, {4, 6, 42}};
    assert(mat13c.determinant() == Fp(2) * Fp(-12) * Fp(26));
    Matrix<Fp> mat14  = {{1,1,1}, {2,2,3}, {1,2,3}, {3,3,2}};
    Matrix<Fp> mat14a = {{1,1,1}, {0,1,2}, {0,0,1}, {0,0,0}};
    assert(mat14.sweepout().first == 3);
    Matrix<Fp> mat14b = {{1,1,1}, {2,2,3}, {1,2,3}};
    assert(mat14b.determinant() == Fp(-1));
    Matrix<Fp> mat14c = {{1,1,1}, {2,2,3}, {-1,-1,-2}};
    assert(mat14c.determinant() == Fp(0));
    Matrix<Fp> mat15 = {{0,1}, {1,0}};
    assert(mat15.determinant() == Fp(-1));
    Matrix<Fp> mat16 = {{1,1,0,0},{0,0,1,0},{0,0,1,0}};
    Matrix<Fp> mat17 = {{1,1,0,0},{0,0,1,0},{0,0,0,0}};
    assert(mat16.sweepout().first == 2);
    Matrix<Fp> matUnit3 = {{1,0,0}, {0,1,0}, {0,0,1}};
    assert(mat13c * mat13c.inv().value() == matUnit3);
    Matrix<Fp> mat18 = {{2,3,5}, {1,4,-2}, {2+1,3+4,5-2}};
    assert(not mat18.inv().has_value());
  }
  
  {
    using Fp = FpB;
    Matrix<Fp> mat1a(3, 5);
    for (int i = 0; i < 3; i++) for (int j = 0; j < 5; j++) mat1a.at(i, j) = 42;
    assert(mat1a == Matrix<Fp>(3, 5, 42));
    Matrix<Fp> mat2a(2, 3, {1,2,3,4,5,6});
    Matrix<Fp> mat2b(0, 3, {1,2,3,4,5,6});
    Matrix<Fp> mat2c(2, 0, {1,2,3,4,5,6});
    vector<Fp> vec2d({1,2,3,4,5,6});
    Matrix<Fp> mat2d(2, 3, vec2d);
    Matrix<Fp> mat2e({{1,2,3},{4,5,6}});
    assert(mat2a == mat2b);
    assert(mat2a == mat2c);
    assert(mat2a == mat2d);
    assert(mat2a == mat2e);
    assert(Matrix<Fp>(mat2a.part(1, 2, 1, 1)) == Matrix<Fp>({{5,6}}));
    assert(Matrix<Fp>(mat2a.part(2, 2)) == Matrix<Fp>({{1,2},{4,5}}));
    assert(Matrix<Fp>(mat2a.part()) == mat2a);
    assert(mat1a != mat2a);
    vector<vector<Fp>> vvec2f({{1,2,3},{4,5,6}});
    assert(Matrix<Fp>::from_vvec(vvec2f) == mat2a);
    Matrix<Fp> mat3a({{1,2,3},{4,5,6},{7,8,9}});
    assert(mat3a.zero() == Matrix<Fp>({{0,0,0},{0,0,0},{0,0,0}}));
    assert(mat3a.unit() == Matrix<Fp>({{1,0,0},{0,1,0},{0,0,1}}));
    assert(mat3a.rowVec(1) == Matrix<Fp>({{4,5,6}}));
    assert(mat3a.colVec(1) == Matrix<Fp>(0, 1, {2,5,8}));
    Matrix<Fp> mat3b(mat3a);
    mat3b.memcopy(mat2a.part(1,2,1,1), 2, 1);
    assert(mat3b == Matrix<Fp>({{1,2,3},{4,5,6},{7,5,6}}));
    auto mat3c = mat3a.zero();
    mat3c.memcopy(mat2a.part(1,2,1,1));
    assert(mat3c == Matrix<Fp>({{5,6,0},{0,0,0},{0,0,0}}));
    stringstream ss("2 3 11 12 13 -14 -15 -16 1000");
    int x;
    Matrix<int> mat4a;
    ss >> mat4a >> x;
    assert(mat4a == Matrix<int>({{11,12,13},{-14,-15,-16}}));
    assert(x == 1000);
    stringstream ss2;
    ss2 << mat4a << "foo\n";
    assert(ss2.str() == "11, 12, 13\n-14, -15, -16\nfoo\n");
  }

  {
    using Fp = FpA;

    cerr << "linear equation" << endl;
    Matrix<Fp> mat1({{1,2,3}, {4,5,6}, {3,1,2}});
    Matrix<Fp> vec1({{14,26,11}});
    vec1.self_transpose();
    auto optsol1 = mat1.linSolution<true>(vec1);
    assert(optsol1.has_value());
    auto [sol1, kernel1] = optsol1.value();
    assert(kernel1.size() == 0);
    assert(mat1 * sol1 == vec1);
    
    Matrix<Fp> vv1(1, 0, {2,3,1,1,2,1});
    Matrix<Fp> vv2(1, 0, {0,0,0,2,0,1});
    // vector<Fp> vv3 = {0,0,0,2,1,-1};
    auto vv4 = vv1 + vv2 + Fp(2) * vv1;
    auto vv5 = vv1 + Fp(3) * vv1;
    auto vv6 = Fp(4) * vv1 + Fp(2) * vv5;
    Matrix<Fp> mat2(4, 6);
    mat2.memcopy(vv1.part(), 0, 0);
    mat2.memcopy(vv4.part(), 1, 0);
    mat2.memcopy(vv5.part(), 2, 0);
    mat2.memcopy(vv6.part(), 3, 0);
    Matrix<Fp> vv7(0, 1, {1,2,3,4,5,6});
    auto vec2 = mat2 * vv7;
    auto optsol2 = mat2.linSolution<true>(vec2);
    assert(optsol2.has_value());
    auto [sol2, kernel2] = optsol2.value();
    assert(kernel2.size() == 4);
    assert(mat2 * sol2 == vec2);
    for (const auto& m : kernel2) assert(mat2 * m == Matrix<Fp>(4, 1));

    Matrix<Fp> vec3(0, 1, {1,2,3,4});
    auto optsol3 = mat2.linSolution(vec3);
    assert(!optsol3.has_value());

    ll rep = 1000;
    for (ll i = 0; i < rep; i++) {
      ll n = randrange(1, 10);
      ll m = randrange(1, 10);
      ll rank = randrange(1, min(n, m) + 1);
      // DLOGKL("decided rank is", rank);
      vector<int8_t> dt(n, 0);
      for (ll j = 0; j < rank; j++) dt[j] = 1;
      for (ll j = n; j >= 2; j--) {
          ll p = randrange(0, j);
          if (p != j - 1) swap(dt[p], dt[j-1]);
      }
      ll cur_rank = 0;
      Matrix<Fp> A(n, m);
      for (ll j = 0; j < n; j++) {
        if (dt[j]) {
          cur_rank++;
          while (true) {
            for (ll k = 0; k < m; k++) A.at(j, k) = Fp(randrange(-6, 7));
            auto [chk, _] = A.sweepout();
            if ((ll)chk == cur_rank) break;
          }
        }else {
          for (ll p = 0; p < j; p++) {
            Fp c = Fp(randrange(-6, 7));
            for (ll k = 0; k < m; k++) { A.at(j, k) += c * A.at(p, k); }
          }
        }
      }
      Matrix<Fp> z(n, 1);
      for (ll p = 0; p < m; p++) {
        z = z + Fp(randrange(-6, 7)) * A.colVec(p);
      }
      auto optsol10 = A.linSolution(z);
      assert(optsol10.has_value());
      auto [sol10, kernel10] = optsol10.value();
      assert(A * sol10 == z);
      auto zero_mat = Matrix<Fp>(n, 1);
      for (const auto& kk : kernel10) {
        assert(A * kk == zero_mat);
      }
      if (rank < min(n, m)) {
        Matrix<Fp> B(n, m + 1);
        B.memcopy(A.part());
        while (true) {
          for (ll k = 0; k < n; k++) B.at(k, m) = Fp(randrange(-10, 10));
          auto [chk, _] = B.sweepout();
          // DLOGK(B);
          // DLOGK(chk);
          if ((ll)chk == rank + 1) break;
        }
        auto z2 = B.colVec(m);
        auto optsol11 = A.linSolution(z2);
        // DLOGK(A);
        // DLOGK(z2);
        assert(!optsol11.has_value());
      }
    }

  }
  
  {
    using Fp = FpG<2>;
    
    auto check = [&](const Matrix<Fp>& mat, ll m, ll n) -> void {
      Matrix<Fp> bs(m, 1);
      auto optsol = mat.linSolution<true>(bs);
      assert(optsol);
      auto [_, kernel] = *optsol;
      ll sz = kernel.size();
      Matrix<Fp> zero_m(m, 1);
      ll cnt = 0;
      for (ll x = 0; x < (1LL << n); x++) {
        Matrix<Fp> v(n, 1);
        for (ll i = 0; i < n; i++) v.at(i, 0) = (x >> i) & 1;
        if (mat * v == zero_m) cnt++;
      }
      assert((1LL << sz) == cnt);
    };
      
    ll rep = 1000;
    for (ll _r = 0; _r < rep; _r++) {
      ll m = randrange(1, 9);
      ll n = randrange(1, 9);
      Matrix<Fp> mat(m, n);
      for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) mat.at(i, j) = randrange(0, 2);
      }
      check(mat, m, n);
    }
    ll m = 4, n = 3;
    for (ll xx = 0; xx < (1LL << (m*n)); xx++) {
      Matrix<Fp> mat(m, n);
      for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
          ll t = i * n + j;
          mat.at(i, j) = (xx >> t) & 1;
        }
      }
      check(mat, m, n);
      check(mat.transpose(), n, m);
    }
  }

  cerr << "ok" << endl;
  return 0;
}
