/*
  Fracion

  Usage:
    using Frac = fraction<ll>;
    // or   using Frac = fraction<cpp_int>;  or whatever
    Frac f1(-2);  // integer
    Frac f2(3, 5);  // numerator and denominator
    Frac(10, -2).num == -5 and Frac(10, -2).den == 1;   // auto normalized
    Frac x, y;
    -x; x + y; x - y; x * y; x / y; x += y; x -= y; x *= y; x /= y; abs(x);
    cout << x;
    x < y; x > y; x <= y; x >= y;

*/

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()    ---- fraction.cc

template<typename Int = ll>
struct fraction {
  Int num;
  Int den;

  void _normalize() {
    if (den < 0) { num = -num; den = -den; }
    Int g = gcd(num, den);
    if (g != 1) {
      num /= g;
      den /= g;
    }
  }

  fraction(Int a = (Int)0) : num(a), den(1) {}
  fraction(Int num_, Int den_) : num(num_), den(den_) { _normalize(); }
  fraction(const fraction& o) : num(o.num), den(o.den) {}

  fraction& operator=(const fraction& o) { num = o.num; den = o.den; return *this; }
  fraction& operator=(fraction&& o) { num = move(o.num); den = move(o.den); return *this; }

  bool operator==(const fraction& o) { return num == o.num and den == o.den; }
  bool operator!=(const fraction& o) { return not (*this == o); }

  fraction& self_negate() {
    num = -num;
    return *this;
  }
  fraction operator-() const {
    fraction ret(*this);
    return ret.self_negate();
  }
  fraction& operator +=(const fraction& o) {
    Int g = gcd(den, o.den);
    Int x = den / g, y = o.den / g;
    num = num * y + o.num * x;
    den *= y;
    _normalize();
    return *this;
  }
  fraction& operator-=(const fraction& o) { return *this += -o; }

  fraction& operator *=(const fraction& o) {
    Int g1 = gcd(num, o.den);
    Int g2 = gcd(den, o.num);
    num = (num / g1) * (o.num / g2);
    den = (den / g2) * (o.den / g1);
    return *this;
  }
  fraction& self_inverse() {
    if (num == 0) throw runtime_error("fraction::self_inverse: numerator is zero.");
    swap(num, den);
    if (den < 0) { num = -num; den = -den; }
    return *this;
  }
  fraction inverse() const {
    fraction ret(*this);
    return ret.self_inverse();
  }
  fraction& operator /=(const fraction& o) { return *this *= o.inverse(); }

  fraction operator+(const fraction& o) const {
    fraction ret(*this);
    return ret += o;
  }
  fraction operator*(const fraction& o) const {
    fraction ret(*this);
    return ret *= o;
  }
  fraction operator-(const fraction& o) const { return (*this) + (-o); }
  fraction operator/(const fraction& o) const { return (*this) * o.inverse(); }

  bool positive() const { return num > 0; }
  bool negative() const { return num < 0; }
  bool is_zero() const { return num == 0; }
  bool operator<(const fraction& o) const { return (o - *this).positive(); }
  bool operator>(const fraction& o) const { return (*this - o).positive(); }
  bool operator<=(const fraction& o) const { return not (*this > o); }
  bool operator>=(const fraction& o) const { return not (*this < o); }

};

template<typename Int>
ostream& operator<<(ostream& os, const fraction<Int>& f) {
  return os << "frac(" << f.num << ", " << f.den << ")";
}

template<typename Int>
fraction<Int> abs(const fraction<Int>& f) { return f.negative() ? -f : f; }

// @@ !! END ---- fraction.cc

