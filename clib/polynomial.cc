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
  - Using get_X()
        auto X = PolyFp::get_X();   // X
        auto p = -1 + X*X + 2*X*X*X;        // -1 + X^2 + 2 X^3
  - Degree
        int d = (-1.0 + X*X).degree()        // d == 2
  - Coefficients
        vector<double> v = (-1.0 + X*X).coef    // [-1.0, 0.0, 1.0]
  - Copy constructor, assignment, ...
        // as usual
  - Operators
        +, -, *, +=, -=, *=, ==, !=
  - Value at t
        T v = p.atval(T t);
  - Division (divmod)
        auto [d, m] = p.divmod(q);
        // p == q * d + m, degree(m) < degree(q)
        - Either of the following should hold, but not checked in divmod()
            - T is a field, or
            - the coefficient of the highest degree of q is (T)1.
  - Division by linear term X-c (for performance)
        auto [d, m] = p.divideLinear(c);   // p = (X-c) * d + m
  - Formal Power Series for division
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
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN(f:<< mod convolution) ---- polynomial.cc

#if ! defined(DLOG_LIB)
  #define DLOG_LIB(...)
  #define DLOGK_LIB(...)
  #define DLOGKL_LIB(lab, ...)
#endif

template<typename T>
vector<T> polyConvolution(const vector<T>& a, const vector<T>& b) {
  assert(0);
}

template<>
vector<Fp> polyConvolution(const vector<Fp>& a, const vector<Fp>& b) {
  vector<Fp> aa(a);
  vector<Fp> bb(b);
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
  vector<T> coef;

  int degree() const { return coef.size() - 1; }

  Polynomial() : coef({(T)0}) {}
  Polynomial(T t) : coef({t}) {}

  Polynomial(const vector<T>& coef_) : coef(coef_) { adj_degree(); }
  Polynomial(vector<T>&& coef_) : coef(move(coef_)) { adj_degree(); }

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
    coef.resize(1);
    coef[0] = t;
    return *this;
  }

  void adj_degree() {
    while (coef.size() > 1 && coef.back() == (T)0) coef.pop_back();
  }

  Polynomial& operator +=(const Polynomial& o) {
    int deg = max(degree(), o.degree());
    if ((int)coef.size() < deg + 1) { coef.resize(deg + 1); }
    for (int i = 0; i <= o.degree(); i++) { coef[i] += o.coef[i]; }
    adj_degree();
    return *this;
  }

  Polynomial& operator -=(const Polynomial& o) {
    int deg = max(degree(), o.degree());
    if ((int)coef.size() < deg + 1) { coef.resize(deg + 1); }
    for (int i = 0; i <= o.degree(); i++) { coef[i] -= o.coef[i]; }
    adj_degree();
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
    return *this;
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
  Polynomial operator -() const {
    return Polynomial() -= *this;
  }

  bool operator ==(const Polynomial& o) const { return coef == o.coef; }
  bool operator !=(const Polynomial& o) const { return coef != o.coef; }

  static Polynomial get_X() {
    return Polynomial({(T)0, (T)1});
  }

  T atval(T t) const {
    T ret = 0;
    for (ll i = coef.size() - 1; i >= 0; i--) { ret = ret * t + coef[i]; }
    return ret;
  }

  T selfDivideLinear(T c) {
    if (degree() == 0) {
      T m = coef[0];
      coef[0] = (T)0;
      return m;
    }
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
};

template<typename T, int use_fft>
Polynomial<T, use_fft> operator +(T t, const Polynomial<T, use_fft>& p) {
  return Polynomial<T, use_fft>(t) + p;
}
template<typename T, int use_fft>
Polynomial<T, use_fft> operator -(T t, const Polynomial<T, use_fft>& p) {
  return Polynomial<T, use_fft>(t) - p;
}
template<typename T, int use_fft>
Polynomial<T, use_fft> operator *(T t, const Polynomial<T, use_fft>& p) {
  return Polynomial<T, use_fft>(t) * p;
}
template<typename T, int use_fft>
Polynomial<T, use_fft> operator +(const Polynomial<T, use_fft>& p, T t) {
  return p + Polynomial<T, use_fft>(t);
}
template<typename T, int use_fft>
Polynomial<T, use_fft> operator -(const Polynomial<T, use_fft>& p, T t) {
  return p - Polynomial<T, use_fft>(t);
}
template<typename T, int use_fft>
Polynomial<T, use_fft> operator *(const Polynomial<T, use_fft>& p, T t) {
  return p * Polynomial<T, use_fft>(t);
}

template<typename T, int use_fft>
ostream& operator<< (ostream& os, const Polynomial<T, use_fft>& p) {
  os << p.coef;
  return os;
}

using PolyLL = Polynomial<ll, 2>;
using PolyFp = Polynomial<Fp, 1>;

// @@ !! END ---- polynomial.cc
