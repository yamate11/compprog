#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(mod)

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

// ---- inserted function f:gcd from util.cc

// auto [g, s, t] = eGCD(a, b)
//     g == gcd(|a|, |b|) and as + bt == g           
//     |a| and |b| must be less than 2^31.
tuple<ll, ll, ll> eGCD(ll a, ll b) {
#if DEBUG
  if (abs(a) >= (1LL << 31) or abs(b) >= (1LL << 31)) throw runtime_error("eGCD: not within the range");
#endif    
  array<ll, 50> vec;  // Sufficiently large for a, b < 2^31.
  ll idx = 0;
  while (a != 0) {
    ll x = b / a;
    ll y = b % a;
    vec[idx++] = x;
    b = a;
    a = y;
  }
  ll g, s, t;
  if (b < 0) { g = -b; s = 0; t = -1; }
  else       { g =  b; s = 0; t =  1; }
  while (idx > 0) {
    ll x = vec[--idx];
    ll old_t = t;
    t = s;
    s = old_t - x * s;
  }
  return {g, s, t};
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

// @@ !! LIM -- end mark --

using Fp = FpB;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll N = SIZE(S);
  vector<ll> plus;
  plus.push_back(-1);
  REP(i, 0, N) if (S[i] == '+') plus.push_back(i);
  plus.push_back(N);
  ll numPlus = SIZE(plus);
  Fp ans = 0;
  REP(ii, 0, numPlus - 1) {
    ll st = plus[ii] + 1;
    ll en = plus[ii + 1];
    vector<ll> star;
    star.push_back(st - 1);
    REP(j, st, en) if (S[j] == '*') star.push_back(j);
    star.push_back(en);
    vector fl(en - st, Fp(0));
    Fp cur = 0;
    Fp prod = 1;
    REP(j, st, en) {
      if (S[j] == '*') {
        fl[j - st] = 0;
        prod *= cur;
        cur = 0;
      }else {
        cur = 10 * cur + (S[j] - '0');
        fl[j - st] = prod * cur;
      }
    }
    vector fr(en - st, Fp(0));
    cur = 0;
    prod = 1;
    Fp mul = 1;
    REPrev(j, en - 1, st) {
      if (S[j] == '*') {
        fr[j - st] = 0;
        prod *= cur;
        cur = 0;
        mul = 1;
      }else {
        cur += mul * (S[j] - '0');
        mul *= 10;
        fr[j - st] = prod * cur;
      }
    }
    assert(fl[en - st - 1] == fr[0]);
    Fp in_full = fr[0];
    Fp in_from_left = 0;
    Fp in_from_right = 0;
    REP(j, 0, en - st) in_from_left += fl[j];
    REP(j, 0, en - st) in_from_right += fr[j];
    ll numStar = SIZE(star);
    Fp in_two = 0;
    vector sfl(en - st + 1, Fp(0)); REP(j, 0, en - st) sfl[j + 1] = sfl[j] + fl[j];
    REP(k, 0, numStar - 2) {
      Fp z = 0;
      Fp cur2 = 0;
      REP(j, star[k] + 1, star[k + 1]) {
        cur2 = cur2 * 10 + (S[j] - '0') * (j - star[k]);
        z += cur2;
      }
      in_two += z;
      in_two += cur2 * (sfl[en - st] - sfl[star[k + 1] - st]) / fl[star[k + 1] - 1 - st];
    }
    ll left = plus[ii] - ii + 1;
    ll right = N - plus[ii + 1] + ii - (numPlus - 2);
    Fp num1 = left * right * in_full;
    Fp num2 = left * in_from_left;
    Fp num3 = right * in_from_right;
    Fp num4 = in_two;
    ans += num1 + num2 + num3 + num4;
  }
  cout << ans << endl;

  return 0;
}

