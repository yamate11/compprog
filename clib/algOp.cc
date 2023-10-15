#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/* 
   Algebraic Operations

   Functions:

     - T zero<T>(const T& t)
     - T one<T>(const T& t)
     - T inverse<T>(const T& t)

     These functions are defined for basic types such as int, ll, double.  (inverse is only for double
     and the likes)  A user-defined structure T should define (non-static) member functions with the same
     name, if the structure supports corresponding operations.  Then, the functions above call them.

     The argument t is typically used to determine the size of the object.  For example, if T is a square matrix,
     the size of the underlying vector will be t.size().  

   Structure MyAlg<Op>.

     This structure is a convenience structure to define algebraic class.  You need to define structure
     Op with appropriate operations and define an alias such as:

         using Alg = MyAlg<Op>;

     Structure Op should have (some of) the following:

         using value_type = some_type;

         static value_type zero(const value_type& u);
         static value_type one(const value_type& u);

         static value_type add(       const value_type& u, const value_type& v);
         static value_type subt(      const value_type& u, const value_type& v);
         static value_type mult(      const value_type& u, const value_type& v);
         static void       subst_add(       value_type& u, const value_type& v);
         static void       subst_subt(      value_type& u, const value_type& v);
         static void       subst_mult(      value_type& u, const value_type& v);
         static value_type inverse(   const value_type& u);

     Using the above-mentioned static member functions, MyAlg<Op> defines non-static member functions:

         template <typename Opdef>
         struct MyAlg {
           using value_type = typename Opdef::value_type;
           value_type v;
           MyAlg();
           MyAlg(const value_type& v_);
           MyAlg(value_type&& v_) : v(move(v_));
           bool operator==(MyAlg o) const;
           bool operator!=(MyAlg o) const;
           operator value_type() const;
           MyAlg zero() const;
           MyAlg one() const;
           MyAlg inverse() const;
           MyAlg operator/=(const MyAlg& o);
           MyAlg operator/(const MyAlg& o);
           MyAlg operator-() const;
           MyAlg& operator +=(const MyAlg& o);
           MyAlg operator +(const MyAlg& o) const;
           MyAlg& operator *=(const MyAlg& o);
           MyAlg operator *(const MyAlg& o) const;
           MyAlg& operator -=(const MyAlg& o);
           MyAlg operator -(const MyAlg& o) const;
           friend istream& operator >>(istream& is, MyAlg& t);
           friend ostream& operator <<(ostream& os, const MyAlg& t);
         };

     Internally, the detection ideom is used to check if the corresponding method such as subst_add is defined 
     in Opdef.

     Examples:

       Min-Plus algebra over long long:
          struct MinPlusLL {
            using value_type = ll;
            static value_type zero(      const value_type& u)                      { return LLONG_MAX; }
            static value_type one(       const value_type& u)                      { return 0; }
            static value_type add(       const value_type& u, const value_type& v) { return min(u, v); }
            static void       subst_mult(      value_type& u, const value_type& v) { u += v; }
          };
          using MMP = MyAlg<MinPlusLL>;
       You cannot define subt() or subst_subt() because no such operation is available in this semiring.

       2x2 matrix over double:
          using VT = vector<vector<double>>;
          struct OpMatrix2 {
            using value_type = VT;
            static value_type zero(      const value_type& dummy) { return VT(2, vector(2, 0.0)); }
            static value_type one(       const value_type& dummy) { ... }
            static void       subst_add(       value_type& u, const value_type& v) { ... }
            static void       subst_subt(      value_type& u, const value_type& v) { ... }
            static value_type mult(      const value_type& u, const value_type& v) { ... }
            static value_type inverse(   const value_type& u) { ... }
          };
          using MyMatrix = MyAlg<OpMatrix2>;
*/

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- algOp.cc

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





// @@ !! END ---- algOp.cc

