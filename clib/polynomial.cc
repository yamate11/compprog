#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Polynomial

  - Template: Polynomial<typename T, int use_fft>
    - use_fft = 0 : convolution is naive
    - use_fft = 1 : Use this only when T = Fp, with 2^c | Fp::MOD - 1.
    - use_fft = 2 : Use this only when T = ll
  - Use either of the following for ordinary cases:
    - using PolyLL = Polynomial<ll, 2>;
    - using PolyFp = Polynomial<Fp, 1>;
      (with possibly #define CONSTANT_MOD 998'244'353)

  - Constructor:
    - no arg
        PolyLL p;                  // 0
    - Initializer List
        PolyFp p({-1, 0, 1, 2});   // -1 + X^2 + 2 X^3
    - Constant
        PolyLL p(5);               // 5
    - vector
        vector<ll> vec = ....;
        PolyLL p(vec);  // or
        PolyLL p(move(vec));
  - Indeterminate element
        const SparsePoly<T> X;   
  - X^n
        SparsePoly<T> Xn(int n);
  - Degree
        int d = (-1.0 + X*X).degree()        // d == 2
        // The degree of the zero polynomial is zero; and the
        // coefficient vector is empty.
  - Coefficients
        double x = (-1.0 + 20*X + 30*X*X).getCoef(2) // 30
        double x = (-1.0 + 20*X + 30*X*X).getCoef(10) // 0
        vector<double> v = (-1.0 + X*X).coefVec()    // [-1.0, 0.0, 1.0]
  - Copy constructor, assignment, ...
        // as usual
  - Operators
        +, -, *, +=, -=, *=, ==, !=
  - Value at t
        T v = p.atval(T t);
  - Cutoff
        p.cutoff(deg) is the polynomial for the degrees up to deg.
        (mainly for FPS)
  - Division (divmod)
        auto [d, m] = p.divmod(q);
        // p == q * d + m, degree(m) < degree(q)
        - Either of the following should hold, but not checked in divmod()
            - T is a field, or
            - the coefficient of the highest degree of q is (T)1.
  - Division by linear term X-c (for performance)
        auto [d, m] = p.divideLinear(c);   // p = (X-c) * d + m
  - Formal Power Series for division (naive method)
        Polynomial a = p.divFormalSeries(q, n)
        //    a.degree() == n
        //    a.coef[i] is the [x^i](p/q) (as a formal power series) 
        //         for i <= n
        // T should be a field or q.coef[0] should be (T)1, but this
        // is not checked.
  - Bostan-Mori method 
    computes the n-th coefficency of formal power series p/q.
    The following should hold:
         - deg(p) < deg(q)
         - q.coef[0] == 1
    - signature: 
        friend T bostanMori(const Polynomial& p, const Polynomial& q, int n);
    - usage:   
        Fp a = bostanMori(p, q, n);

  - Sparse polynomials
          template<typename T> struct SparsePoly;
      Give the constructor a vector of pair of a power and a coefficient.
      E.g.,  3 - X^10 + 2X^20 ... SparsePoly<ll> sp({{0,3},{10,-1},{20,2}});

      For 
          Polynomial<T, use_fft> p;
          SparsePoly<T> sp;
      the following operations are supported
          p + sp, p - sp, p * sp
          p.mult(sp, cutoff=-1)     p.selfMult(sp, cutoff=-1)
          p.divFPS(sp, cutoff=-1)   p.selfDivFPS(sp, cutoff=-1)


 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN(f:<< mod convolution) ---- polynomial.cc

#if ! defined(DLOG_LIB)
  #define DLOG_LIB(...)
  #define DLOGK_LIB(...)
  #define DLOGKL_LIB(lab, ...)
#endif

template<typename T> struct SparsePoly;

template<typename T>
vector<T> polyConvolution(const vector<T>& a, const vector<T>& b) {
  assert(0);
}

template<int mod=0>
vector<FpG<mod>> polyConvolution(const vector<FpG<mod>>& a,
                                 const vector<FpG<mod>>& b) {
  vector<FpG<mod>> aa(a);
  vector<FpG<mod>> bb(b);
  return convolution(move(aa), move(bb));
}

template<typename T>
vector<T> polyConvolution_ll(const vector<T>& a, const vector<T>& b) {
  assert(0);
}

template<>
vector<ll> polyConvolution_ll(const vector<ll>& a, const vector<ll>& b) {
  return convolution_ll(a, b);
}

// value of use_fft
//    0 ... multiplication is naive
//    1 ... multiplication uses convolution
//             in this case, T must be Fp with 2^c | Fp::MOD - 1
//    2 ... multiplication uses convolution_ll
//             in this case, T must be ll
template<typename T, int use_fft>
struct Polynomial {
  using value_type = T;
  using SP = SparsePoly<T>;

private:
  // The highest coefficient should not be zero.
  // Thus, the zero polynomial should be represented by the empty vector.
  vector<T> coef;

public:
  const vector<T>& coefVec() const { return coef; }
  T getCoef(ll n) const {
    if (n > degree()) return (T)0;
    return coef[n];
  }

  // Degree of the zero polynomial is -1.
  int degree() const { return coef.size() - 1; }

  void normalize() {
    while (!coef.empty() && coef.back() == (T)0) coef.pop_back();
  }

  Polynomial() : coef() {}
  Polynomial(T t) : coef() { if (t != (T)0) { coef.push_back(t); } }

  Polynomial(const vector<T>& coef_) : coef(coef_) { normalize(); }
  Polynomial(vector<T>&& coef_) : coef(move(coef_)) { normalize(); }

  Polynomial(const Polynomial& o) : coef(o.coef) {}
  Polynomial(Polynomial&& o) : coef(move(o.coef)) {}
  Polynomial& operator =(const Polynomial& o) {
    coef = o.coef;
    return *this;
  }
  Polynomial& operator =(Polynomial&& o) {
    coef = move(o.coef);
    return *this;
  }
  Polynomial& operator =(T t) {
    coef.resize(0);
    if (t != (T)0) { coef.push_back(t); }
    return *this;
  }

  void _from_sparse(const SP& sp) {
    coef = vector<T>(sp.degree() + 1);
    for (auto [i, t] : sp.coef) coef[i] = t;
  }
  Polynomial(const SP& sp) { _from_sparse(sp); }
  Polynomial& operator =(const SP& sp) {
    _from_sparse(sp);
    return *this;
  }

  Polynomial& operator +=(const Polynomial& o) {
    int deg = max(degree(), o.degree());
    if ((int)coef.size() < deg + 1) { coef.resize(deg + 1); }
    for (int i = 0; i <= o.degree(); i++) { coef[i] += o.coef[i]; }
    normalize();
    return *this;
  }

  Polynomial& operator -=(const Polynomial& o) {
    int deg = max(degree(), o.degree());
    if ((int)coef.size() < deg + 1) { coef.resize(deg + 1); }
    for (int i = 0; i <= o.degree(); i++) { coef[i] -= o.coef[i]; }
    normalize();
    return *this;
  }

  vector<T> coef_conv(const vector<T>& a, const vector<T>& b) const {
    if (use_fft == 0) {
      int a_size = a.size();
      int b_size = b.size();
      int new_size = a_size + b_size - 1;
      auto ret = vector<T>(new_size);
      for (int i = 0; i < new_size; i++) {
        for (int j = max(0, i - b_size + 1); j <= min(i, a_size - 1); j++) {
          ret[i] += a[j] * b[i - j];
        }
      }
      return ret;
    }else if (use_fft == 1) {
      return polyConvolution(a, b);
    }else if (use_fft == 2) {
      return polyConvolution_ll(a, b);
    }else {
      assert(0);
    }
  }

  constexpr Polynomial& operator *=(const Polynomial& o) {
    coef = coef_conv(coef, o.coef);
    normalize();
    return *this;
  }
  
  Polynomial operator -() const {
    return Polynomial() -= *this;
  }
  Polynomial operator +(const Polynomial& o) const {
    return Polynomial(*this) += o;
  }
  Polynomial operator -(const Polynomial& o) const {
    return Polynomial(*this) -= o;
  }
  Polynomial operator *(const Polynomial& o) const {
    return Polynomial(*this) *= o;
  }

  bool operator ==(const Polynomial& o) const { return coef == o.coef; }
  bool operator !=(const Polynomial& o) const { return coef != o.coef; }

  T atval(T t) const {
    T ret = 0;
    for (ll i = coef.size() - 1; i >= 0; i--) { ret = ret * t + coef[i]; }
    return ret;
  }

  Polynomial& selfCutoff(int deg) {
    if (degree() <= deg) return *this;
    coef.resize(deg + 1);
    normalize();
    return *this;
  }

  Polynomial cutoff(int deg) const {
    int new_deg = min(deg, degree());
    vector<T> new_coef(new_deg + 1);
    for (int i = 0; i <= new_deg; i++) new_coef[i] = coef[i];
    return Polynomial(move(new_coef));
  }

  T selfDivideLinear(T c) {
    if (coef.empty()) { return (T)0; }
    T x = coef.back();
    for (ll i = coef.size() - 2; i >= 0; i--) {
      T y = coef[i] + x * c;
      coef[i] = x;
      x = y;
    }
    coef.pop_back();
    return x;
  }

  pair<Polynomial, T> divideLinear(T c) const {
    Polynomial ret(*this);
    T t = ret.selfDivideLinear(c);
    return {ret, t};
  }

  // p.divmod(q) returns pair (d, r),
  // where p = qd + r, degree(r) < degree(q).
  // Either of the following should hold, but no check is done.
  //   - T is a field, or
  //   - the coefficient of the highest degree of q is (T)1.
  pair<Polynomial, Polynomial> divmod(const Polynomial& q) const {
    int this_deg = degree();
    int q_deg = q.degree();
    if (q_deg == 0) {
      vector<T> new_coef(coef);
      for (ll i = 0; i <= this_deg; i++) { new_coef[i] /= q.coef[0]; }
      return {Polynomial(move(new_coef)), Polynomial()};
    }
    int div_deg = this_deg - q_deg;
    if (div_deg < 0) { return { (T)0, *this }; }
    int mod_deg = q_deg - 1;
    vector<T> div_coef(div_deg + 1);
    vector<T> mod_coef(coef);
    DLOGK_LIB(div_deg, mod_deg);
    DLOGK_LIB(div_coef, mod_coef);
    for (int i = 0; i <= div_deg; i++) {
      T c = mod_coef[this_deg - i] / q.coef[q_deg];
      div_coef[div_deg - i] = c;
      for (int j = 0; j <= q_deg; j++) {
        mod_coef[this_deg - i - j] -= c * q.coef[q_deg - j];
      }
      DLOGK_LIB(i, div_coef, mod_coef);
    }
    mod_coef.resize(mod_deg + 1);
    return { Polynomial(div_coef), Polynomial(mod_coef) };
  }

  Polynomial divFormalSeries(const Polynomial& q, int n) const {
    vector<T> ret(n + 1);
    int p_deg = degree();
    int q_deg = q.degree();
    for (int i = 0; i <= n; i++) {
      T s = i <= p_deg ? coef[i] : (T)0;
      for (int k = 1; k <= min(i, q_deg); k++) {
        s -= ret[i - k] * q.coef[k];
      }
      ret[i] = q.coef[0] == (T)1 ? s : s / q.coef[0];
    }
    return Polynomial(move(ret));
  }

  T subBostanMori(const Polynomial& o, ll n) const {
    auto rev = [](vector<T> &f) -> void {
      for (int i = 1; i < (int)f.size(); i += 2) { f[i] = -f[i]; }
    };
    auto shift = [](vector<T> &f, int bit) -> void {
      int d = ((int)f.size() + 1 - bit) >> 1;
      for (int i = 0; i < d; i++) f[i] = f[(i << 1) | bit];
      f.resize(d);
    };
    if (o.coef[0] != (T)1) {
      throw runtime_error("subBostanMori: o.coef[0] should be 1.");
    }
    if (degree() >= o.degree()) {
      throw runtime_error("subBostanMori: broken: degree() < o.degree()");
    }
    vector<T> p(coef), q(o.coef), q_rev(o.coef);
    rev(q_rev);
    for (; n; n >>= 1) {
      p = coef_conv(move(p), q_rev);
      shift(p, n % 2);
      q = coef_conv(move(q), move(q_rev));
      shift(q, 0);
      q_rev = q; rev(q_rev);
    }
    return p[0] / q[0];
  }

  friend T bostanMori(const Polynomial& p, const Polynomial& q, ll n) {
    return p.subBostanMori(q, n);
  }


  Polynomial& operator +=(T t) {
    coef[0] += t;
    normalize();
    return *this;
  }
  Polynomial& operator -=(T t) { return *this += (-t); }
  Polynomial& operator *=(T t) {
    if (t == (T)0) {
      coef.resize(0);
    }else {
      for (int i = 0; i < (int)coef.size(); i++) coef[i] *= t;
    }
    return *this;
  }
  Polynomial operator +(T t) const { return Polynomial(*this) += t; }
  Polynomial operator -(T t) const { return Polynomial(*this) -= t; }
  Polynomial operator *(T t) const { return Polynomial(*this) *= t; }
  friend Polynomial operator +(T t, const Polynomial& p) { return p + t; }
  friend Polynomial operator -(T t, const Polynomial& p) { return (-p) + t; }
  friend Polynomial operator *(T t, const Polynomial& p) { return p * t; }


  Polynomial& operator +=(const SP& o) {
    if (degree() < o.degree()) { coef.resize(o.degree() + 1); }
    for (auto [i, t] : o.coef) { coef[i] += t; }
    normalize();
    return *this;
  }

  Polynomial& operator -=(const SP& o) { 
    if (degree() < o.degree()) { coef.resize(o.degree() + 1); }
    for (auto [i, t] : o.coef) { coef[i] -= t; }
    normalize();
    return *this;
  }

  Polynomial& selfMult(const SP& o, int lim = -1) {
    if (coef.empty()) return *this;
    if (o.coef.empty()) { coef.resize(0); return *this; }
    int dd = degree() + o.degree();
    if (lim < 0 || dd < lim) lim = dd;
    auto old_coef = move(coef);
    coef = vector<T>(lim + 1);
    for (auto [i, t] : o.coef) {
      for (int j = 0; j < (int)old_coef.size() && j <= lim - i; j++) {
        coef[i + j] += t * old_coef[j];
      }
    }
    normalize();
    return *this;
  }

  Polynomial mult(const SP& o, int lim = -1) const {
    Polynomial p(*this);
    return p.selfMult(o, lim);
  }

  Polynomial& operator *=(const SP& o) { return selfMult(o, -1); }

  // the constant term of o should have the inverse.
  Polynomial& selfDivFPS(const SP& o, int lim = -1) {
    if (o.coef.empty()) throw runtime_error("selfDivFPS: o.coef.empty");
    auto [i, t0] = o.coef.front();
    if (i != 0) throw runtime_error("selfDivFPS: no constant factor");
    T invt = (T)1 / t0;
    if (invt * t0 != (T)1) throw runtime_error("selfDivFPS: no inverse");
    if (lim < 0) lim = degree();
    else if (lim > degree()) coef.resize(lim + 1);
    auto work = move(coef);
    coef = vector<T>(lim + 1);
    for (int j = 0; j <= lim; j++) {
      coef[j] = work[j] * invt;
      for (auto [k, t] : o.coef) {
        if (j + k > lim) break;
        work[j + k] -= coef[j] * t;
      }
    }
    normalize();
    return *this;
  }

  Polynomial divFPS(const SP& o, int lim = -1) const {
    Polynomial p(*this);
    return p.selfDivFPS(o, lim);
  }

  Polynomial operator +(SP t) const { return Polynomial(*this) += t; }
  Polynomial operator -(SP t) const { return Polynomial(*this) -= t; }
  Polynomial operator *(SP t) const { return Polynomial(*this) *= t; }
  friend Polynomial operator +(SP t, const Polynomial& p) { return p + t; }
  friend Polynomial operator -(SP t, const Polynomial& p) { return (-p) + t; }
  friend Polynomial operator *(SP t, const Polynomial& p) { return p * t; }


  friend ostream& operator<< (ostream& os, const Polynomial& p) {
    os << p.coef;
    return os;
  }

  static const SparsePoly<T> X;
  static SparsePoly<T> Xn(int n) { return SparsePoly<T>::Xn(n); }

};
template<typename T, int use_fft>
const SparsePoly<T> Polynomial<T, use_fft>::X({{1,1}});


template<typename T>
struct SparsePoly {   // Sparse Polynomial
  using coef_elm_t = pair<ll, T>;      
  using coef_t = vector<coef_elm_t>;   
  coef_t coef;      
  // {k, t} in coef means t*X^k.  all t should not be (T)0
  // Thus, 0 (as polynomial) should be represented by the empty vector.

  // degree of 0 (as polynomial) is -1
  int degree() const {
    if (coef.empty()) return -1;
    return coef.back().first;
  }
  void normalize() {
    while (!coef.empty() && coef.back().second == (T)0) coef.pop_back();
  }

  SparsePoly() : coef() {}
  SparsePoly(const SparsePoly& sp) : coef(sp.coef) {}
  SparsePoly(SparsePoly&& sp) : coef(move(sp.coef)) {}
  SparsePoly(T t) : coef() { if (t != (T)0) { coef.emplace_back(0, t); } }

  // argument coef_ should be sorted and should not contain (T)0
  SparsePoly(const coef_t& coef_) : coef(coef_) { normalize(); }
  SparsePoly(coef_t&& coef_) : coef(move(coef_)) { normalize(); }
  SparsePoly(initializer_list<coef_elm_t> init) : coef(init) { normalize(); }

  void from_vec(const vector<T>& vec) {
    coef.resize(0);
    for (size_t i = 0; i < vec.size(); i++) {
      if (vec[i] != (T)0) { coef.emplace_back(i, vec[i]); }
    }
    normalize();
  }

  SparsePoly(const vector<T>& vec) { from_vec(vec); }
  template<int use_fft>
  SparsePoly(const Polynomial<T, use_fft>& p) { from_vec(p.coefVec()); }

  SparsePoly& operator=(const SparsePoly& sp) {
    coef = sp.coef;
    return *this;
  }
  SparsePoly& operator=(SparsePoly&& sp) {
    coef = move(sp.coef);
    return *this;
  }
  SparsePoly& operator=(T t) {
    if (t != (T)0) { coef.emplace_back(0, t); }
    normalize();
    return *this;
  }
  SparsePoly& operator=(const coef_t& coef_) {
    coef = coef_; normalize();
    return *this;
  }
  SparsePoly& operator=(coef_t&& coef_) {
    coef = move(coef_); normalize();
    return *this;
  }
  SparsePoly& operator=(initializer_list<coef_elm_t> init) {
    coef = init;
    normalize();
    return *this;
  }
  SparsePoly& operator=(const vector<T>& vec) {
    from_vec(vec);
    return *this;
  }
  template<int use_fft>
  SparsePoly& operator=(const Polynomial<T, use_fft>& p) {
    from_vec(p.coefVec());
    return *this;
  }

  /*
  static SparsePoly getX() { return SparsePoly({{1, 1}}); }
  static SparsePoly getXn(int n) { return SparsePoly({{n, 1}}); }
  */

  coef_t _plus_minus(const coef_t& a, const coef_t& b, int flag) const {
    coef_t ret;
    int i = 0, j = 0;
    while (true) {
      auto [ka, ta] = i < (int)a.size() ? a[i] : coef_elm_t(LLONG_MAX, 0);
      auto [kb, tb] = j < (int)b.size() ? b[j] : coef_elm_t(LLONG_MAX, 0);
      if (flag != 1) tb = -tb;
      if (ka < kb) {
        ret.emplace_back(ka, ta);
        i++;
      }else if (ka > kb) {
        ret.emplace_back(kb, tb);
        j++;
      }else if (ka == LLONG_MAX) { break; }
      else {
        T tt = ta + tb;
        if (tt != (T)0) ret.emplace_back(ka, tt);
        i++; j++;
      }
    }
    return ret;
  }

  SparsePoly operator -() const {
    coef_t new_coef;
    for (const auto& [k, t] : coef) new_coef.emplace_back(k, -t);
    return SparsePoly(new_coef);
  }
  SparsePoly& operator +=(const SparsePoly& o) {
    coef = _plus_minus(coef, o.coef, 1);
    return *this;
  }
  SparsePoly& operator -=(const SparsePoly& o) {
    coef = _plus_minus(coef, o.coef, 2);
    return *this;
  }
  SparsePoly& operator *=(const SparsePoly& o) {
    coef_t new_coef;
    for (const auto& [ko, to]: o.coef) {
      coef_t shifted;
      for (auto& [k, t] : coef) { shifted.emplace_back(k + ko, t * to); }
      new_coef = _plus_minus(new_coef, shifted, 1);
    }
    coef = move(new_coef);
    return *this;
  }
  SparsePoly operator +(const SparsePoly& o) const {
    return SparsePoly(*this) += o;
  }
  SparsePoly operator -(const SparsePoly& o) const {
    return SparsePoly(*this) -= o;
  }
  SparsePoly operator*(const SparsePoly& o) const {
    return SparsePoly(*this) *= o;
  }

  bool operator ==(const SparsePoly& o) const { return coef == o.coef; }
  bool operator !=(const SparsePoly& o) const { return coef != o.coef; }

  friend SparsePoly operator+(const SparsePoly& sp, T t) {
    return SparsePoly(sp) += t;
  }
  friend SparsePoly operator-(const SparsePoly& sp, T t) {
    return SparsePoly(sp) -= t;
  }
  friend SparsePoly operator*(const SparsePoly& sp, T t) {
    return SparsePoly(sp) *= t;
  }
  friend SparsePoly operator+(T t, const SparsePoly& sp) { return sp + t; }
  friend SparsePoly operator-(T t, const SparsePoly& sp) { return -(sp - t); }
  friend SparsePoly operator*(T t, const SparsePoly& sp) { return sp * t; }

  friend ostream& operator<<(ostream& os, const SparsePoly& sp) {
    if (sp.coef.empty()) {
      cout << "0";
    }else {
      bool first = true;
      for (const auto& [k, t] : sp.coef) {
        if (first) first = false;
        else cout << " ";
        if (k == 0) cout << t;
        else if (k == 1) cout << "+ " << t << "X";
        else cout << "+ " << t << "X^" << k;
      }
    }
    return os;
  }

  static const SparsePoly X;
  static SparsePoly Xn(int n) { return SparsePoly({{n,1}}); }

};
template<typename T>
const SparsePoly<T> SparsePoly<T>::X({{1,1}});

using PolyLL = Polynomial<ll, 2>;
using PolyFpA = Polynomial<FpA, 0>;
using PolyFpB = Polynomial<FpB, 1>;

// @@ !! END ---- polynomial.cc
