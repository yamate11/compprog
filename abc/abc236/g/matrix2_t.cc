#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// Library Insertion Mark
// @@ !! LIM(mod)

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
  FpG<mod> comb(int n, int r) {
    if (r < 0 || r > n) return 0;
    return vFact.at(n) * vInvFact.at(r) * vInvFact.at(n-r);
  }
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

// @@ !! LIM -- end mark --


template<typename AO>
using ult_t = typename AO::ult;

// ao_is_no_arg<AO>::value is true iff AO().zero() is valid (instead of AO().zero(const ult_t<AO>& t))
template<typename AO>
struct ao_is_no_arg {
  template<typename T>
  static auto check(int) -> typename std::is_same< decltype( declval<T>().zero() ), ult_t<T> >::type;
  template<typename>
  static false_type check(...);
  using _type = decltype(check<AO>(0));
  static const bool value = _type::value;
};

template<typename T>
struct AO_basic { // Algebra Operations -- default operations
  using ult = T;
  ult zero() const { return (T)0; }
  ult one() const { return (T)1; }
  void subst_add(T& v, const T& w) const { v += w; }
  void subst_subt(T& v, const T& w) const { v -= w; }
  void subst_mult(T& v, const T& w) const { v *= w; }
};

template<typename T>
struct AO_def : AO_basic<T> {
  using typename AO_basic<T>::ult;
};

template<>
struct AO_def<double> : AO_basic<double> {
  using typename AO_basic<double>::ult;
  ult inverse(const ult& w) const { return 1.0 / w; }
};

template<int p>
struct AO_def<FpG<p>> : AO_basic<FpG<p>> {
  using typename AO_basic<FpG<p>>:: ult;
  ult inverse(const ult& w) const { return w.inv(); }
};

template<typename T>
struct AO_vec {
  using ult = vector<T>;
  ult zero(const ult& v) const { return vector<T>(v.size()); }
  ult one(const ult& v) const { return vector<T>(v.size(), (T)1); }
  void subst_add(vector<T>& v, const vector<T>& w) const { for(int i = 0; i < (int)v.size(); i++) v[i] += w[i]; }
  void subst_subt(vector<T>& v, const vector<T>& w) const { for(int i = 0; i < (int)v.size(); i++) v[i] -= w[i]; }
  void subst_mult(vector<T>& v, const vector<T>& w) const { for(int i = 0; i < (int)v.size(); i++) v[i] *= w[i]; }
};

template<typename AO> ult_t<AO> get_zero(const ult_t<AO>& t) {
  if constexpr(ao_is_no_arg<AO>::value) return AO().zero(); else return AO().zero(t);
}
template<typename AO> ult_t<AO> get_one(const ult_t<AO>& t) {
  if constexpr(ao_is_no_arg<AO>::value) return AO().one(); else return AO().one(t);
}

template<typename AO>
ult_t<AO> power(const ult_t<AO>& a, ll b) {
  auto two_pow = a;
  auto ret = get_one<AO>(a);
  while (b > 0) {
    if (b & 1LL) AO().subst_mult(ret, two_pow);
    AO().subst_mult(two_pow, two_pow);
    b >>= 1;
  }
  return ret;
}

template<typename T>
T power(const T& a, ll b) { return power<AO_def<T>>(a, b); }


template<typename AO>
struct BwAO { // body with AO
  using T = typename AO::ult;
  T v;  // value
  BwAO(const T& v_) : v(v_) {}
  BwAO(T&& v_) : v(move(v_)) {}
  BwAO& operator =(const T& v_) { v = v_; return *this; }
  BwAO& operator =(T&& v_) { v = move(v_); return *this; }
  operator T() const { return v; }
  bool operator ==(const BwAO& o) { return v == o.v; }
  bool operator !=(const BwAO& o) { return v != o.v; }
  BwAO zero() const { return BwAO(get_zero<AO>()); }
  BwAO one() const { return BwAO(get_one<AO>()); }
  BwAO& operator +=(const BwAO& o) { AO(v).subst_add(v, o.v); return *this; }
  BwAO& operator -=(const BwAO& o) { AO(v).subst_subt(v, o.v); return *this; }
  BwAO& operator *=(const BwAO& o) { AO(v).subst_mult(v, o.v); return *this; }
  BwAO inverse() const { return BwAO(AO(v).inverse(v)); }
  BwAO& operator /=(const BwAO& o) { AO(v).subst_mult(v, AO(v).inverse(o.v)); return *this; }
  BwAO operator +(const BwAO& o) const { return BwAO(v) += o; }
  BwAO operator -(const BwAO& o) const { return BwAO(v) -= o; }
  BwAO operator *(const BwAO& o) const { return BwAO(v) *= o; }
  BwAO operator /(const BwAO& o) const { return (*this) * o.inverse(); }
};


// ---- inserted library file matrix.cc

template <typename AO> struct AO_matrix;

template <typename AO>
struct Mat {
  using T = typename AO::ult;

  struct Part {
    const Mat& mat;
    int i_size;
    int j_size;
    int i_0;
    int j_0;
    Part(const Mat& mat_, int i_size_ = -1, int j_size_ = -1, int i_0_ = 0, int j_0_ = 0)
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
  
  Mat() : dimI(1), dimJ(1), mem(1) {}
  Mat(int dimI_, int dimJ_) : dimI(dimI_), dimJ(dimJ_), mem(dimI*dimJ) {}
  Mat(int dimI_, int dimJ_, const T& t) : dimI(dimI_), dimJ(dimJ_), mem(dimI*dimJ, t) {}

  template<typename Z>
  void _from_vec(int dimI_, int dimJ_, Z&& vec) {
    int sz = vec.size();
    dimI = dimI_ <= 0 ? sz / dimJ_ : dimI_;
    dimJ = dimJ_ <= 0 ? sz / dimI_ : dimJ_;
    if (dimI * dimJ != sz) throw domain_error("_from_vec: inconsistent sizes");
    mem = forward<Z>(vec);
  }
  Mat(int dimI_, int dimJ_, const vector<T>& vec) { _from_vec(dimI_, dimJ_, vec); }
  Mat(int dimI_, int dimJ_, vector<T>&&      vec) { _from_vec(dimI_, dimJ_, move(vec)); }

  Mat(initializer_list<initializer_list<T>> il) {
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

  Mat(const Part& cs) : dimI(cs.i_size), dimJ(cs.j_size), mem(dimI*dimJ) {
    for (int i = 0; i < dimI; i++) for (int j = 0; j < dimJ; j++) at(i, j) = cs.mat.at(cs.i_0 + i, cs.j_0 + j);
  }

  T _zero_T() const { return get_zero<AO>(at(0, 0)); }
  T _one_T() const { return get_one<AO>(at(0, 0)); }
  T _minus(const T& t) const { T z = _zero_T();  AO().subst_subt(z, t);  return z; }

  bool operator ==(const Mat& r) const {
    if (dimI != r.dimI or dimJ != r.dimJ) return false;
    if (rev_rc == r.rev_rc) return mem == r.mem;
    for (int i = 0; i < dimI; i++) for (int j = 0; j < dimJ; j++) if (at(i, j) != r.at(i, j)) return false;
    return true;
  }
  bool operator !=(const Mat& r) const { return !(*this == r); }

  template<int sign>
  Mat& _add_subt(const Mat& r) {
    if (dimI != r.dimI or dimJ != r.dimJ) throw domain_error("_add_subt: dimension mismatch");
    for (int i = 0; i < dimI; i++) {
      for (int j = 0; j < dimJ; j++)
        if (sign > 0) AO().subst_add(at(i,j), r.at(i,j));
        else          AO().subst_subt(at(i,j), r.at(i,j));
    }
    return *this;
  }
  Mat& operator +=(const Mat& r) { return _add_subt<1>(r); }
  Mat& operator -=(const Mat& r) { return _add_subt<-1>(r); }
  Mat operator +(const Mat& r) const { return Mat(*this) += r; }
  Mat operator -(const Mat& r) const { return Mat(*this) -= r; }

  // Unlike + and -, we anyway need a new object for multiplication.
  // Thus, we first define operator *, and then define operator *=
  // using operator *.
  Mat operator *(const Mat& r) const {
    if (dimJ != r.dimI) throw domain_error("mult: dimension mismatch");
    Mat result(dimI, r.dimJ);
    for (int i = 0; i < dimI; i++) {
      for (int j = 0; j < r.dimJ; j++) {
	T s = _zero_T();
	for (int k = 0; k < dimJ; k++) {
          T t = at(i, k);
          AO().subst_mult(t, r.at(k, j));
          AO().subst_add(s, t);
        }
	result.at(i,j) = s;
      }
    }
    return result;
  }
  Mat& operator *=(const Mat& r) { return *this = *this * r; }

  Mat& operator *=(const T& t) {
    for (int p = 0; p < dimI * dimJ; p++) AO().subst_mult(mem[p], t);
    return *this;
  }
  friend Mat operator *(const Mat& m, const T& t) { return Mat(m) *= t; }
  friend Mat operator *(const T& t, const Mat& m) {
    Mat ret(m);
    for (int p = 0; p < m.dimI * m.dimJ; p++) ret.mem[p] = t * ret.mem[p];
    return ret;
  }

  static Mat from_vvec(const vector<vector<T>>& vvec) {
    int dimI_ = vvec.size();
    if (dimI_ == 0) throw domain_error("from_vvec: zero rows");
    int dimJ_ = vvec[0].size();
    if (dimJ_ == 0) throw domain_error("from_vvec: zero columns");
    Mat ret(dimI_, dimJ_);
    for (int i = 0; i < dimI_; i++) {
      if ((int)vvec[i].size() != dimJ_) throw domain_error("from_vvec: not in rectangular shape");
      for (int j = 0; j < dimJ_; j++) ret.mem[i*dimJ_ + j] = vvec[i][j];
    }
    return ret;
  }

  Mat zero() const { return Mat(dimI, dimJ, _zero_T()); }
  Mat unit() const {
    if (dimI != dimJ) throw domain_error("unit: dimension mismatch");
    Mat ret(dimI, dimI, _zero_T());
    for (int i = 0; i < dimI; i++) ret.at(i, i) = _one_T();
    return ret;
  }

  Part part(int i_size_ = -1, int j_size_ = -1, int i_0_ = 0, int j_0_ = 0) const {
    return Part(*this, i_size_, j_size_, i_0_, j_0_);
  }

  Mat rowVec(int i) const { return Mat(part(1, -1, i, 0)); }
  Mat colVec(int j) const { return Mat(part(-1, 1, 0, j)); }

  void memcopy(const Part& cs, int i_1 = 0, int j_1 = 0) {
    for (int i = 0; i < cs.i_size; i++) for (int j = 0; j < cs.j_size; j++) {
        at(i_1 + i, j_1 + j) = cs.mat.at(cs.i_0 + i, cs.j_0 + j);
      }
  }

  Mat matpower(ll x) const { return power<AO_matrix<AO>>(*this, x); }

  Mat& self_transpose() {
    rev_rc = not rev_rc;
    swap(dimI, dimJ);
    return *this;
  }
  Mat transpose() { return Mat(*this).self_transpose(); }

  /* aux functions for sweepout */

  void basic_mult(int i, T t) {               // multiplies i-th row by t
    for (int j = 0; j < dimJ; j++) AO().subst_mult(at(i, j), t);
  }
  void basic_xchg(int i1, int i2) {           // exchanges i1-th and i2-th rows
    for (int j = 0; j < dimJ; j++) swap(at(i1, j), at(i2, j));
  }
  void basic_mult_add(int i1, T t, int i2) {  // adds t times of i1-th row to i2-th row
    for (int j = 0; j < dimJ; j++) {
      T t1 = t;
      AO().subst_mult(t1, at(i1, j));
      AO().subst_add(at(i2, j), t1);
    }
  }

  pair<int, int> _find_nz(int i0, int j0) const {
    for ( ; j0 < dimJ; j0++) {
      int i = i0;
      for ( ; i < dimI && at(i, j0) == _zero_T(); i++);
      if (i < dimI) return {i, j0};
    }
    return {dimI, dimJ};
  }

  /*
    Sweepout for the vertical direction.
    Returns a pair (rank, det)
      rank: the rank of the matrix
      det: internally used for determinant calculation
    T should be a field.
   */
  pair<int, T> self_sweepout() {
    T det = _one_T();
    int j0 = 0;
    int i0 = 0;
    for ( ; i0 < dimI; i0++, j0++) {
      auto [i1, j1] = _find_nz(i0, j0);
      if (i1 == dimI) break;
      j0 = j1;
      if (i1 != i0) {
        det = _minus(det);
	basic_xchg(i0, i1);
      }
      AO().subst_mult(det, at(i0, j0));
      basic_mult(i0, AO().inverse(at(i0, j0)));
      for (int i = 0; i < dimI; i++) {
	if (i == i0) continue;
        basic_mult_add(i0, _minus(at(i, j0)), i);
      }
    }
    return {i0, move(det)};
  }
  
  pair<int, T> sweepout() const { 
    Mat res1(*this);
    return res1.self_sweepout();
  }

  /* T should be a field. */
  T determinant() const {
    auto [rank, det] = sweepout();
    return (rank == dimI) ? det : _zero_T();
  }

  /* T should be a field. */
  optional<Mat> inverse() const {
    if (dimI != dimJ) throw domain_error("inverse: not square");
    Mat work(dimI, dimI * 2);
    work.memcopy(part());
    work.memcopy(unit().part(), 0, dimI);
    work.self_sweepout();
    if (work.at(dimI - 1, dimI - 1) != _one_T()) return {};
    Mat ret(dimI, dimI);
    ret.memcopy(work.part(dimI, dimI, 0, dimI));
    return ret;
  }

  /* WARNING: T should be a field. */
  // Solves linear euqation "(*this) x = bs".
  //        dimI and dimJ can be different.
  // arguments:
  //    bs ... vector<T>.  bs.size() == dimI should hold.
  //    ret_kernel ... if false, returned kernel is empty.
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
  /*
    bs: (dimI, 1)-matrix (col vector)
   */
  template<bool ret_kernel = false>
  optional<pair<Mat, vector<Mat>>> linSolution(const Mat& bs) const {
    if (dimI != bs.dimI or bs.dimJ != 1) throw domain_error("linSolution: invalid bs");
    Mat work(dimI, dimJ + 1);
    work.memcopy(part());
    work.memcopy(bs.part(), 0, dimJ);
    auto [rank, _] = work.self_sweepout();
    Mat sol(dimJ, 1);
    vector<Mat> kernel;
    if (rank == 0) {
      if (not ret_kernel) return make_pair(move(sol), move(kernel));
      for (int j = 0; j < dimJ; j++) {
        Mat m(dimJ, 1);
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
    if (not ret_kernel) return make_pair(move(sol), move(kernel));
    vector<bool> cor(dimJ, false);
    int i = 0;
    for (int j = 0 ; j < dimJ; j++) {
      if (i == dimI || work.at(i, j) == _zero_T()) {
        Mat vec(dimJ, 1);
        vec.at(j, 0) = _one_T();
        for (int p = 0, q = 0; p < i; p++, q++) {
          while (!cor[q]) q++;
          vec.at(q, 0) = _minus(work.at(p, j));
        }
        kernel.push_back(move(vec));
      }else {
        cor[j] = true;
        if (i < dimI) i++;
      }
    }
    return make_pair(move(sol), move(kernel));
  }

  friend istream& operator >>(istream& is, Mat& mat) {
    is >> mat.dimI >> mat.dimJ;
    mat.rev_rc = false;
    mat.mem.resize(mat.dimI * mat.dimJ);
    for (int i = 0; i < mat.dimI; i++) for (int j = 0; j < mat.dimJ; j++) is >> mat.at(i, j);
    return is;
  }

  friend ostream& operator <<(ostream& os, const Mat& mat) {
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

template <typename AO> // base algebra operation
struct AO_matrix {
  AO_matrix() {}
  using ult = Mat<AO>;
  ult zero(const ult& m) { return m.zero(); }
  ult one(const ult& m) { return m.unit(); }
  void subst_add(ult& v, const ult& w) { v += w; }
  void subst_subt(ult& v, const ult& w) { v -= w; }
  void subst_mult(ult& v, const ult& w) { v *= w; }
  ult inverse(const ult& w) const { return w.inverse(); }
};

template <typename T>
using Matrix = Mat<AO_def<T>>;   // make Matrix<ll> equals to Mat<AO_def<ll>>

// ---- end matrix.cc

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

    AO_matrix<AO_def<ll>> ao1;
    AO_matrix<AO_def<Fp>> ao2;

    cerr << "power" << endl;
    assert(mat7.matpower(5) == mat7*mat7*mat7*mat7*mat7);
    assert(power<AO_matrix<AO_def<ll>>>(mat7, 5) == mat7*mat7*mat7*mat7*mat7);
    assert(mat7.matpower(11) == mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7);
    Matrix<double> mat8 = {{1.0, 2.0}, {3.0, 4.0}};
    Matrix<double> mat9 = {{7.0, 10.0}, {15.0, 22.0}};
    assert(mat9 == mat8 * mat8);
    Matrix<Fp> mat9a = {{1,2,3}, {5,5,5}, {-3,-1,0}};
    assert(power<AO_matrix<AO_def<Fp>>>(mat9a, 5) == mat9a*mat9a*mat9a*mat9a*mat9a);
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
    assert(mat13c * mat13c.inverse().value() == matUnit3);
    Matrix<Fp> mat18 = {{2,3,5}, {1,4,-2}, {2+1,3+4,5-2}};
    assert(not mat18.inverse().has_value());
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
