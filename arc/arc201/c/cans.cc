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

// @@ !! LIM(mod power)

// ---- inserted library file trie.cc

// ---- end trie.cc

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

// @@ !! LIM -- end mark --

template <int bt_size, char from, typename User = monostate,
  typename S = string, bool compact = 2 < bt_size, bool has_offset = true>
struct Trie {

  Trie* parent = nullptr;

  using c_pat_t = conditional_t<compact, unsigned long long, monostate>;
  [[no_unique_address]] c_pat_t c_pat{};

  using cpt_children_t = conditional_t<compact, vector<Trie*>, monostate>;
  [[no_unique_address]] cpt_children_t cpt_children{};

  using children_t = conditional_t<compact, monostate, array<Trie*, bt_size>>;
  [[no_unique_address]] children_t children{};

  using offset_t = conditional_t<has_offset, int, monostate>;
  static consteval offset_t make_default_offset() {
    if constexpr (is_same_v<offset_t, int>) return -1;
    else return {};
  }
  [[no_unique_address]] offset_t offset = make_default_offset();

  bool reside = false;

  int size_st = 0;

  [[no_unique_address]] User user{};

  Trie() = default;
  Trie(Trie* p, int offset_) : parent(p) {
    if constexpr (has_offset) offset = offset_;
  }

  Trie* get_child_val(int c, bool create = false) { return get_child_offset(c - from, create); }

  Trie* get_child_offset(int d, bool create = false) {
    if constexpr(compact) {
      ll idx = popcount(c_pat & ((1ULL << d) - 1));
      if (c_pat >> d & 1) return cpt_children[idx];
      if (not create) return nullptr;
      Trie* p = new Trie(this, d);
      cpt_children.insert(cpt_children.begin() + idx, p);
      c_pat |= 1ULL << d;
      return p;
    }else {
      Trie* p = children[d];
      if (p) return p;
      if (not create) return nullptr;
      p = children[d] = new Trie(this, d);
      return p;
    }
  }

  struct children_iterator {
    Trie* node;
    int idx;
    int offset;
    explicit children_iterator(Trie* node_, int idx_, int offset_) : node(node_), idx(idx_), offset(offset_) {
      _next_effective_child();
    }
    pair<Trie*, char> operator*() const {
      Trie* p;
      if constexpr (compact) p = node->cpt_children[idx];
      else                   p = node->children[idx];
      return make_pair(p, from + offset);
    }
    void _next_effective_child() {
      if constexpr (compact) {
        if constexpr (has_offset) {
          if (idx < ssize(node->cpt_children)) offset = node->cpt_children[idx]->offset;
          else offset = bt_size;
        }else {
          while (offset < bt_size and not (node->c_pat >> offset & 1)) offset++;
        }
      }else {
        while (idx < bt_size and not node->children[idx]) idx++;
        offset = idx;
      }
    }
    const children_iterator& operator++() {
      idx++;
      offset++;
      _next_effective_child();
      return *this;
    }
    bool operator !=(const children_iterator& o) const { return node != o.node or offset != o.offset; }
  };

  struct children_view {
    Trie* node;
    children_view(Trie* node_) : node(node_) {}
    children_iterator begin() const { return children_iterator(node, 0, 0); }
    children_iterator end() const { return children_iterator(node, bt_size, bt_size); }
  };

  auto children_w_val() { return children_view(this); }

  Trie* get_node(const auto& s, bool create = false) {
    Trie* tr = this;
    for (auto c : s) {
      auto cld = tr->get_child_val(c, create);
      if (not cld) return nullptr;
      tr = cld;
    }
    return tr;
  }
  Trie* get_node(const char* s, bool create = false) { return get_node(string(s), create); }

  Trie* search(const auto& s) {
    Trie* p = get_node(s);
    if (p and not p->reside) p = nullptr;
    return p;
  }
  Trie* search(const char* s) { return search(string(s)); }

  Trie* insert(const auto& s) {
    Trie* tr = get_node(s, true);
    if (not tr->reside) {
      tr->reside = true;
      for (Trie* p = tr; p; p = p->parent) p->size_st++;
    }
    return tr;
  }
  Trie* insert(const char* s) { return insert(string(s)); }

  void erase() {
    if (reside) for (Trie* tr = this; tr; tr = tr->parent) tr->size_st--;
    reside = false;
  }

  int get_offset() {
    if constexpr (has_offset) return offset;
    else {
      Trie* p = parent;
      if (not p) return -1;
      for (int d = 0; d < bt_size; d++) if (p->get_child_offset(d) == this) return d;
      assert(0);
    }
  }

  S repr() {
    S ret;
    for (Trie* tr = this; true; tr = tr->parent) {
      ll d = tr->get_offset();
      if (d < 0) break;
      ret.push_back(from + tr->get_offset());
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  void _show_sub(auto& vec) {
    if (reside) vec.push_back(repr());
    for (int i = 0; i < bt_size; i++) {
      Trie* p = get_child_offset(i);
      if (p) p->_show_sub(vec);
    }
  }

  vector<S> show() {
    vector<S> ret;
    _show_sub(ret);
    return ret;
  }

  const Trie* const _def_obj() const {
    static Trie the_object;
    return &the_object;
  }
    
  static const User& safe_user(Trie* p) { return p ? p->user : p->_def_obj()->user; }

};


using Fp = FpB;

struct sta {
  Fp val;
  ll num;
  bool inS;
  sta() : val(0), num(0), inS(false) {}
};
  

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, S, type=string) [UQ4gt3hJ]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [UQ4gt3hJ]

  auto root = new Trie<2, 'A', Fp>();
  REP(k, 0, N) {
    auto p = root->insert(S[k]);
    for (; p; p = p->parent) {
      Fp t1 = p->safe_user(p->get_child_val('A'));
      Fp t2 = p->safe_user(p->get_child_val('A'));
      Fp t = t1 * t2;
      if (p->reside) t += power<Fp>(2, p->size_st - 1);
      p->user = t;
    }
    cout << root->user << endl;
  }


  return 0;
}

