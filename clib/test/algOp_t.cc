#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(algOp)

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

// @@ !! LIM -- end mark --
#line 7 "algOp_skel.cc"


int main() {
  
  {
    struct MinPlusLL {
      using value_type = ll;
      static ll add(const ll& u, const ll& v) { return min(u, v); }
      static void subst_mult(ll& u, const ll& v) { u += v; }
      static ll zero(const ll& u) { return LLONG_MAX; }
      static ll one(const ll& u) { return 0; }
    };
    using MMP = MyAlg<MinPlusLL>;
    MMP a2(2), a5(5), a7(7), a10(10);
    assert(a7 == a7 + a10);
    assert(a7 == a2 * a5);
    MMP sum1 = a2.zero();
    sum1 += a10;
    sum1 += a5 + a7;
    sum1 = sum1 + a2;
    assert(sum1.v == 2);
    MMP prod1 = a2.one();
    prod1 *= a10;
    prod1 *= a5 * a7;
    prod1 = prod1 * a2;
    assert(prod1.v = 24);
  }

  {
    using VT = vector<vector<double>>;
    struct OpMatrix2 {
      using value_type = VT;
      static value_type zero(const value_type& dummy) { return VT(2, vector(2, 0.0)); }
      static value_type one(const value_type& dummy) {
        VT ret(2, vector(2, 0.0));
        ret[0][0] = ret[1][1] = 1.0;
        return ret;
      }
      static void subst_add(value_type& u, const value_type& v) {
        for (size_t i = 0; i < 2; i++) for (size_t j = 0; j < 2; j++) u[i][j] += v[i][j];
      }
      static void subst_subt(value_type& u, const value_type& v) {
        for (size_t i = 0; i < 2; i++) for (size_t j = 0; j < 2; j++) u[i][j] -= v[i][j];
      }
      static value_type mult(const value_type& u, const value_type& v) {
        value_type ret(2, vector(2, 0.0));
        for (size_t i = 0; i < 2; i++) for (size_t j = 0; j < 2; j++) for (size_t k = 0; k < 2; k++) {
              ret[i][j] += u[i][k] * v[k][j];
            }
        return ret;
      }
      static value_type inverse(const value_type& u) {
        double d = u[0][0] * u[1][1] - u[0][1] * u[1][0];
        return value_type({{u[1][1] / d, -u[0][1] / d}, {-u[1][0] / d, u[0][0] / d}});
      }
    };
    using MM = MyAlg<OpMatrix2>;
    MM m1(VT({{2, 3}, {1, 1}}));
    MM m2(VT({{1, 2}, {-3, -5}}));
    MM m3(VT({{1, 0}, {2, -1}}));
    assert((m1 + m2).v == VT({{3, 5}, {-2, -4}}));
    assert((m2 * m3).v == VT({{5,-2}, {-13, 5}}));
    assert(m1 * (m2 + m3) == m1 * m2 + m1 * m3);
    assert((m1 - m2) * m3 == m1 * m3 - m2 * m3);
    assert(m1 * m1.one() == m1);
    assert(m2 + m2.zero() == m2);
    MM m2i = m2.inverse();
    assert(m2 * m2i == m2.one());
    assert(m2i * m2 == m2.one());
    assert((m2 / m3) * m3 == m2);
    MM m4(m1);
    m4 += m2;
    assert(m4 == m1 + m2);
    MM m5(m2);
    m5 *= m3;
    assert(m5 == m2 * m3);
    MM m6(m3);
    m6 -= m1;
    assert(m6 == m3 - m1);
    MM m7 = -m2;
    assert(m1 - m2 == m1 + m7);

    

  }

  return 0;
}
