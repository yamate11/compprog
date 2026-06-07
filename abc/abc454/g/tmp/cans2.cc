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

#include <boost/unordered/unordered_flat_map.hpp>

// @@ !! LIM(mod cmpNaive unordered_map tree debug)

// ---- inserted library file algOp.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/algOp.cc

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
template<> const cpp_int zero(const cpp_int&) { return cpp_int(0); }
template<> const cpp_int one(const cpp_int&) { return cpp_int(1); }
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
// published at https://github.com/yamate11/compprog-clib/blob/master/mod.cc

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
  T inv_fact(int n) { return vInvFact[n]; }
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

// ---- inserted library file cmpNaive.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/cmpNaive.cc

const string end_mark("^__=end=__^");

int naive(istream& cin, ostream& cout);
int body(istream& cin, ostream& cout);

void cmpNaive() {
  while (true) {
    string s;
    getline(cin, s);
    bool run_body;
    if (s.at(0) == 'Q') {
      return;
    }else if (s.at(0) == 'B') {
      run_body = true;
    }else if (s.at(0) == 'N') {
      run_body = false;
    }else {
      cerr << "Unknown body/naive specifier.\n";
      exit(1);
    }
    string input_s;
    while (true) {
      getline(cin, s);
      if (s == end_mark) break;
      input_s += s;
      input_s += "\n";
    }
    stringstream ss_in(move(input_s));
    stringstream ss_out;
    ss_out << setprecision(20);
    if (run_body) {
      body(ss_in, ss_out);
    }else {
      naive(ss_in, ss_out);
    }
    cout << ss_out.str() << end_mark << endl;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if CMPNAIVE
  if (argc == 2) {
    if (strcmp(argv[1], "cmpNaive") == 0) {
      cmpNaive();
    }else if (strcmp(argv[1], "naive") == 0) {
      naive(cin, cout);
    }else if (strcmp(argv[1], "skip") == 0) {
      exit(0);
    }else {
      cerr << "Unknown argument.\n";
      exit(1);
    }
  }else {
#endif
    body(cin, cout);
#if CMPNAIVE
  }
#endif
  return 0;
}

/*
int naive(istream& cin, ostream& cout) {
  return 0;
}
int body(istream& cin, ostream& cout) {
  return 0;
}
*/

// ---- end cmpNaive.cc

// ---- inserted library file unordered_map.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/unordered_map.cc

/* This code is based on https://codeforces.com/blog/entry/62393 */

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#if !defined(__TEMPLATE_SAFE_CUSTOM_HASH__)
#define __TEMPLATE_SAFE_CUSTOM_HASH__
template <typename T, typename Enable = void>
struct safe_custom_hash;
#endif

// For integer types (int, ll, u64, unsigned, ....)
template <typename T>
struct safe_custom_hash<T, typename enable_if<is_integral<T>::value>::type> {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

// For string
template <>
struct safe_custom_hash<string, void> {
  static uint64_t mix(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
  }

  size_t operator()(const string& s) const {
    static const uint64_t seed = chrono::steady_clock::now().time_since_epoch().count();
    uint64_t h = seed ^ 0x9e3779b97f4a7c15ULL;
    const unsigned char* p = (const unsigned char*)s.data();
    size_t n = s.size();
    while (n >= 8) {
      uint64_t v;
      memcpy(&v, p, 8);
      h = mix(h ^ v);
      p += 8; n -= 8;
    }
    uint64_t tail = 0;
    for (size_t i = 0; i < n; ++i) tail |= uint64_t(p[i]) << (8*i);
    h = mix(h ^ tail);
    return (size_t)h;
  }
};

// For pair
template <typename T1, typename T2>
struct safe_custom_hash<pair<T1, T2>, void> {
  size_t operator()(const pair<T1, T2>& x) const {
    static const uint64_t frand = chrono::steady_clock::now().time_since_epoch().count();
    static const uint64_t a = (frand ^ 0x9e3779b97f4a7c15) | 1;
    static const uint64_t b = (frand ^ 0xbf58476d1ce4e5b9) | 1;
    return a * safe_custom_hash<T1>{}(x.first) + b * safe_custom_hash<T2>{}(x.second);
  }
};

template <typename T_key, typename T_value, bool useGP = false>
using safe_umap = conditional_t<useGP, gp_hash_table<T_key, T_value, safe_custom_hash<T_key>>,
                                unordered_map<T_key, T_value, safe_custom_hash<T_key>>>;
template <typename T_key, bool useGP = false>
using safe_uset = conditional_t<useGP, gp_hash_table<T_key, null_type, safe_custom_hash<T_key>>,
                                unordered_set<T_key, safe_custom_hash<T_key>>>;
template <typename T_key>
using safe_umultiset = unordered_multiset<T_key, safe_custom_hash<T_key>>;


// ---- end unordered_map.cc

// ---- inserted library file tree.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/tree.cc

struct function_error : runtime_error {
  function_error(const string& msg) : runtime_error(msg) {}
};

struct Tree {

  struct pe_t {
    ll peer;
    ll edge;
    pe_t(ll peer_ = -1, ll edge_ = -1) : peer(peer_), edge(edge_) {}
  };

  using nbr_t = vector<pe_t>;

  template<bool get_peer, bool excl_parent>
  struct nbr_iterator {
    const nbr_t& body;
    ll pe_idx;
    explicit nbr_iterator(const nbr_t& body_, ll pe_idx_) : body(body_), pe_idx(pe_idx_) {}
    auto operator*() const -> typename conditional<get_peer, ll, const pe_t&>::type {
      if constexpr (get_peer) return body[pe_idx].peer;
      else                    return body[pe_idx];
    }
    const nbr_iterator& operator++() {
      pe_idx++;
      return *this;
    }
    bool operator !=(const nbr_iterator& o) const { return pe_idx != o.pe_idx; }
  };

  template<bool get_peer, bool excl_parent = true>
  struct children_view {
    const Tree& tr;
    ll nd;
    children_view(const Tree& tr_, ll nd_) : tr(tr_), nd(nd_) {}
    auto begin() const { return nbr_iterator<get_peer, excl_parent>(tr._nbr[nd], 0); }
    auto end()   const {
      ll excl_last = (excl_parent and nd != tr.root) ? 1 : 0;
      return nbr_iterator<get_peer, excl_parent>(tr._nbr[nd], ssize(tr._nbr[nd]) - (excl_last ? 1 : 0));
    }
  };

  ll numNodes;
  ll root;
  vector<nbr_t> _nbr;    // parent is moved to the rightmost place in _set_parent()
  vector<pair<ll, ll>> _edges;   // (x, y) in _edges => x < y
  vector<ll> _stsize;
  vector<ll> _depth;
  vector<ll> _euler_in;
  vector<ll> _euler_out;
  vector<pair<ll, bool>> _euler_edge;
  bool use_hl_decomp;
  vector<ll> _heavy_head;
  vector<vector<vector<ll>>> _lca_tbl;

  Tree(ll numNodes_, ll root_ = 0, bool use_hl_decomp_ = false)
    : numNodes(numNodes_), root(root_), _nbr(numNodes_), use_hl_decomp(use_hl_decomp_) {
    if (numNodes == 1) _set_parent();
  }

  ll add_edge(ll x, ll y) {
    ll i = ssize(_edges);
    if (i >= numNodes - 1) throw range_error("add_edge");
    _nbr[x].emplace_back(y, i);
    _nbr[y].emplace_back(x, i);
    _edges.emplace_back(min(x, y), max(x, y));
    if (i + 1 == numNodes - 1) _set_parent();
    return i;
  }

  void _set_parent() {   // called from constructor, add_edge() and change_root()

    _depth.resize(numNodes);
    _stsize.resize(numNodes);

    auto dfs = [&](auto rF, ll nd, ll pt) -> void {
      _depth[nd] = pt == -1 ? 0 : _depth[pt] + 1;
      _stsize[nd] = 1;
      ll idx_parent = -1;
      ll sz_nbr = ssize(_nbr[nd]);
      for (ll i = 0; i < sz_nbr; i++) {
        auto [c_id, c_eg] = _nbr[nd][i];
        if (c_id == pt) idx_parent = i;
        else {
          rF(rF, c_id, nd);
          _stsize[nd] += _stsize[c_id];
        }
      }
      if (nd != root) {
        assert(idx_parent >= 0);
        swap(_nbr[nd][idx_parent], _nbr[nd][sz_nbr - 1]);
      }
    };

    dfs(dfs, root, -1);

    if (use_hl_decomp) _set_heavy();
  }

  void mature_check() const {
#if DEBUG
    if (ssize(_edges) != numNodes - 1) throw function_error("Not enough edges have been added.");
#endif    
  }

  pe_t parent_pe(ll nd) const {
    mature_check();
    return nd == root ? pe_t(-1, -1) : _nbr[nd][ssize(_nbr[nd]) - 1];
  }
  ll parent(ll nd) const { return nd == root ? -1 : parent_pe(nd).peer; }
  ll num_children(ll nd) const {
    mature_check();
    return ssize(_nbr[nd]) - (nd == root ? 0 : 1);
  }
  pe_t child_pe(ll nd, ll idx) const {
    mature_check();
    return _nbr[nd][idx];
  }
  ll child(ll nd, ll idx) const { return child_pe(nd, idx).peer; }
  ll child_edge(ll nd, ll idx) const { return child_pe(nd, idx).edge; }
  auto children_pe(ll nd) const {
    mature_check();
    return children_view<false, true>(*this, nd);
  }
  auto children(ll nd) const {
    mature_check();
    return children_view<true, true>(*this, nd);
  }
  auto neighbor_pe(ll nd) const {
    mature_check();
    return children_view<false, false>(*this, nd);
  }
  auto neighbor(ll nd) const {
    mature_check();
    return children_view<true, false>(*this, nd);
  }

  ll stsize(ll nd) const {
    mature_check();
    return _stsize[nd];
  }

  ll depth(ll nd) const {
    mature_check();
    return _depth[nd];
  }

  ll _enc_node_pair(ll x, ll y) const { return (x + 1) * (numNodes + 1) + (y + 1); }

  ll edge_idx(ll x, ll y) const {
    auto [py, ey] = parent_pe(y);
    if (x == py) return ey;
    auto [px, ex] = parent_pe(x);
    if (y == px) return ex;
    return -1LL;
  }

  pair<ll, ll> nodes_of_edge(ll e, ll mode = 0) const {
    if (mode == -1) {
      return _edges[e];
    }else {
      const auto& [x, y] = _edges[e];
      if ((x == parent(y)) == (mode == 0)) return {x, y};
      else return {y, x};
    }
  }

  void _set_euler() {
    if (not _euler_in.empty()) return;

    mature_check();
    _euler_in.resize(numNodes);
    _euler_out.resize(numNodes);
    _euler_edge.resize(2 * numNodes);
    ll euler_idx = 0;

    auto dfs = [&](auto rF, ll nd) -> void {
      ll edge = nd == root ? numNodes - 1 : edge_idx(nd, parent(nd));
      _euler_edge[euler_idx] = {edge, 0};
      _euler_in[nd] = euler_idx;
      euler_idx++;
      for (ll c : children(nd)) rF(rF, c);
      _euler_edge[euler_idx] = {edge, 1};
      _euler_out[nd] = euler_idx;
      euler_idx++;
    };
    dfs(dfs, root);

  };

  ll euler_in(ll nd) {
    _set_euler();
    return _euler_in[nd];
  }

  ll euler_out(ll nd) {
    _set_euler();
    return _euler_out[nd];
  }

  tuple<ll, ll, ll> euler_elem(ll idx) {
    _set_euler();

    if (idx == 0) return {numNodes - 1, -1, root};
    else if (idx == 2 * numNodes - 1) return {numNodes - 1, root, -1};
    else {
      auto [e, b] = _euler_edge[idx];
      auto [x, y] = nodes_of_edge(e, b);
      return {e, x, y};
    }
  }
  ll euler_elem_edge(ll idx) { return get<0>(euler_elem(idx)); }
  ll euler_elem_from(ll idx) { return get<1>(euler_elem(idx)); }
  ll euler_elem_to(ll idx) { return get<2>(euler_elem(idx)); }

  void _set_heavy() {
    if (not _heavy_head.empty()) return;

    mature_check();
    if (not _euler_in.empty()) {
      throw function_error("_set_heavy() was called too late.  Consider `use_hl_decomp` parameter of the Tree constructor.");
    }
    _heavy_head.resize(numNodes);

    auto dfs = [&](auto rF, ll nd, ll head) -> void {
      _heavy_head[nd] = head;
      if (ll nc = num_children(nd); nc == 0) return;
      else {
        ll i0 = -1, vmax = 0;
        for (ll i = 0; i < nc; i++) if (ll v = stsize(child(nd, i)); v > vmax) { vmax = v; i0 = i; }
        if (i0 > 0) swap(_nbr[nd][0], _nbr[nd][i0]);
        rF(rF, child(nd, 0), head);
        for (ll i = 1; i < nc; i++) rF(rF, child(nd, i), child(nd, i));
      }
    };
    dfs(dfs, root, root);
  }

  ll heavy_head(ll x) {
    _set_heavy();
    return _heavy_head[x];
  }

  template<bool constr_path>
  auto _hl_follow(ll x, ll y) {
    _set_heavy();
    assert(x != y);
    ll hx = heavy_head(x);
    ll hy = heavy_head(y);
    vector<pll> vx{{hx, x}};
    vector<pll> vy{{hy, y}};

    auto op = [&](ll& h, auto& v) {
      ll p = parent(h);
      h = heavy_head(p);
      if constexpr (constr_path) v.emplace_back(h, p);
      else                      v[0] = {h, p};
    };

    while (hx != hy) {
      if (depth(hx) < depth(hy)) op(hy, vy);
      else op(hx, vx);
    }

    auto [_dummy_x, tx] = vx.back(); vx.pop_back();
    auto [_dummy_y, ty] = vy.back(); vy.pop_back();

    if constexpr (constr_path) {

      vector<pair<ll, ll>> ret;
      auto append_ret = [&](const auto& vec) -> void {
        for (int i = ssize(vec) - 1; i >= 0; i--) {
          auto [h, t] = vec[i];
          ret.emplace_back(euler_in(h), euler_in(t) + 1);
        }
      };

      if (tx == ty) {
        if (not vx.empty() and not vy.empty() and euler_in(vx.back().first) > euler_in(vy.back().first)) swap(vx, vy);
        append_ret(vx);
        append_ret(vy);
      }else {
        if (depth(tx) < depth(ty)) {
          swap(tx, ty);
          swap(vx, vy);
        }
        ret.emplace_back(euler_in(ty) + 1, euler_in(tx) + 1);
        append_ret(vx);
        append_ret(vy);
      }
      return ret;

    }else {
      return depth(tx) < depth(ty) ? tx : ty;
    }
  }

  vector<pair<ll, ll>> hl_path(ll x, ll y) {
    _set_heavy(); // this should be called even if x == y
    return (x == y) ? vector<pair<ll,ll>>{} : _hl_follow<true>(x, y);
  }

  // Lowest Common Ancestor
  ll lca(ll x, ll y) {
    _set_heavy(); // this should be called even if x == y
    return (x == y) ? x : _hl_follow<false>(x, y);
  }

  // the path between two nodes (list of nodes, including x and y)
  vector<ll> nnpath(ll x, ll y) {
    vector<ll> ret;
    ll c = lca(x, y);
    for ( ; x != c; x = parent(x)) ret.push_back(x);
    ret.push_back(c);
    ll len = (ll)ret.size();
    for ( ; y != c; y = parent(y)) ret.push_back(y);
    reverse(ret.begin() + len, ret.end());
    return ret;
  }

  ll ancestor_at_depth(ll x, ll dp) {
    if (depth(x) < dp) return -1;
    while (true) {
      ll h = heavy_head(x);
      if (depth(h) <= dp) return euler_elem_to(euler_in(h) + dp - depth(h));
      x = parent(h);
    }
  }


  tuple<ll, ll, ll, ll, ll> diameter() {
    if (numNodes == 1) return {0, 0, 0, 0, 0};
    if (numNodes == 2) return {1, 0, 1, 0, 1};
    mature_check();
    ll nd0 = max_element(_depth.begin(), _depth.end()) - _depth.begin();
    vector<ll> parent2(numNodes);
    auto dfs2 = [&](auto rF, ll nd, ll dp, ll pt) -> pair<ll, ll> {
      parent2[nd] = pt;
      pair<ll, ll> ret(dp, nd);
      for (auto [cld, _e] : _nbr[nd]) {
        if (cld == pt) continue;
        auto c_val = rF(rF, cld, dp + 1, nd);
        if (ret.first < c_val.first) ret = c_val;
      }
      return ret;
    };
    auto [dp, nd1] = dfs2(dfs2, nd0, 0, -1);
    ll ct0, ct1;
    {
      ll x = nd1;
      for (ll i = 0; i < dp / 2; i++) x = parent2[x];
      if (dp % 2 == 0) ct0 = ct1 = x;
      else {
        ct1 = x;
        ct0 = parent2[x];
      }
    }
    return {dp, nd0, nd1, ct0, ct1};
  }

  pair<ll, ll> centroids() {
    auto dfs = [&](auto rF, ll nd) -> pair<ll, ll> {
      for (ll c : children(nd)) {
        ll a = 2 * stsize(c);
        if (a > numNodes) return rF(rF, c);
        if (a == numNodes) return make_pair(nd, c);
      }
      return make_pair(nd, -1);
    };
    return dfs(dfs, root);
  }

  void change_root(ll newRoot) {
    _stsize.clear();
    _depth.clear();
    _euler_in.clear();
    _euler_out.clear();
    _lca_tbl.clear();

    root = newRoot;
    _set_parent();
  }

  string show() { // for debug
    string ret;
    for (int nd = 0; nd < numNodes; nd++) {
      string sc;
      for (int c : children(nd)) sc += format("{:2d} ", c);
      ret += format("{:1} {:2d}: {}\n", nd == root ? "R" : "", nd, sc);
    }
    string se;
    for (int e = 0; e < numNodes - 1; e++) {
      auto [a, b] = nodes_of_edge(e);
      se += format("({}: {}-{}) ", e, a, b);
    }
    ret += se;
    return ret;
  }


};

// const Tree::pe_t end_object{-1, -1};

template <typename M>
auto reroot(Tree& tree, const M& unit, auto add, auto mod1, auto mod2) {
  using A = decltype(mod2(M(), 0));
  vector<A> result(tree.numNodes);
  vector<vector<M>> sum_left(tree.numNodes);
  vector<vector<M>> sum_right(tree.numNodes);
  
  auto dfs1 = [&](const auto& recF, ll nd) -> A {
    ll k = tree.num_children(nd);
    vector<M> ws(k);
    for (ll i = 0; i < k; i++) {
      ll c = tree.child(nd, i);
      ws[i] = mod1(recF(recF, c), nd, c);
    }
    sum_left[nd].resize(k + 1, unit);
    sum_right[nd].resize(k + 1, unit);
    for (ll i = 0; i < k; i++) sum_left[nd][i + 1] = add(sum_left[nd][i], ws[i]);
    for (ll i = k - 1; i >= 0; i--) sum_right[nd][i] = add(sum_right[nd][i + 1], ws[i]);
    return mod2(sum_right[nd][0], nd);
  };
  dfs1(dfs1, tree.root);

  auto dfs2 = [&](const auto& recF, ll nd, const M& t) -> void {
    result[nd] = mod2(add(sum_right[nd][0], t), nd);
    ll k = tree.num_children(nd);
    for (ll i = 0; i < k; i++) {
      ll c = tree.child(nd, i);
      M excl_c = add(sum_left[nd][i], sum_right[nd][i + 1]);
      M m_for_c = add(excl_c, t);
      A v_for_c = mod2(m_for_c, nd);
      M pass_c = mod1(v_for_c, c, nd);
      recF(recF, c, pass_c);
    }
  };
  dfs2(dfs2, tree.root, unit);
  
  return result;
}

template <typename M>
vector<M> reroot(Tree& tree, const M& unit, auto add, auto mod1) {
  return reroot<M>(tree, unit, add, mod1, [](const M& m, ll) -> M { return m; });
}

// ---- end tree.cc

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

template <typename T, size_t N>
ostream& operator<< (ostream& os, const array<T, N>& v);

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

template <typename T, size_t N>
ostream& operator<< (ostream& os, const array<T, N>& v) {
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
// Known problem: "1 << 127" cannot be handled.
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
// published at https://github.com/yamate11/compprog-clib/blob/master/debug.cc
// https://github.com/yamate11/compprog-clib/blob/master/debug.cc

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

using Fp = FpB;

void impl(istream& cin, ostream& cout, bool isNaive);

int naive(istream& cin, ostream& cout) {
  impl(cin, cout, true);
  return 0;
}
int body(istream& cin, ostream& cout) {
  impl(cin, cout, false);
  return 0;
}

void impl(istream& cin, ostream& cout, bool isNaive) {
  ll N, seed, M, F; cin >> N >> seed >> M >> F;
  // @InpVec(M - 1, Q, dec=1) [xi2QZVvv]
  auto Q = vector(M - 1, ll());
  for (int i = 0; i < M - 1; i++) { ll v; cin >> v; v -= 1; Q[i] = v; }
  // @End [xi2QZVvv]
  // @InpVec(M, D, dec=1) [FsII7J0v]
  auto D = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; v -= 1; D[i] = v; }
  // @End [FsII7J0v]

  ll state = seed;
  vector<ll> parent(N);
  vector<vector<ll>> children(N);
  vector<ll> C(N);
  vector<ll> ans_m(N), ans_k(N);
  
  auto impl_naive = [&]() -> void {
    Tree tr(N);
    REP(i, 0, N - 1) {
      ll p; 
      if (i + 2 <= M) p = Q[i];
      else {
        p = state % (i + 1);
        state = (state * 1103515245 + 12345) % (1LL << 31);
      }

      // parent[i + 1] = p;
      // children[p].push_back(i + 1);
    }
    REP(i, 0, N) {
      if (i + 1 <= M) C[i] = D[i];
      else {
        C[i] = (state % F);
        state = (state * 1103515245 + 12345) % (1LL << 31);
      }
    }

    using mymap = safe_umap<ll, ll>;

    auto enc = [&](ll seq, ll col) { return seq * N + col; };
    mymap mp;

    auto append = [&](auto& used, ll nd, ll seq, ll col, ll num) -> void {
      ll e = enc(seq, col);
      auto [it, b] = mp.try_emplace(e, num);
      if (b) {
        used.emplace_back(col);
      }else {
        it->second += num;
      }
      if (it->second > ans_m[nd]) {
        ans_m[nd] = it->second;
        ans_k[nd] = 1;
      }else if (it->second == ans_m[nd]) {
        ans_k[nd]++;
      }
    };
    ll nxt_seq = 1;
    auto dfs = [&](auto rF, ll nd, auto& used, ll seq) -> void {
      auto proc_children = [&]() -> void {
        if (tr.num_children(nd) == 0) {
          return;
        }else {
          ll cld0 = -1;
          ll mx = 0;
          for (ll c : tr.children(nd)) {
            if (tr.stsize(c) > mx) {
              mx = tr.stsize(c);
              cld0 = c;
            }
          }
          rF(rF, cld0, used, seq);
          ans_m[nd] = ans_m[cld0];
          ans_k[nd] = ans_k[cld0];
          for (ll c : tr.children(nd)) if (c != cld0) {
              ll c_seq = nxt_seq++;
              vector<ll> c_used;
              rF(rF, c, c_used, c_seq);
              for (ll col : c_used) {
                auto it = mp.find(enc(c_seq, col));
                append(used, nd, seq, col, it->second);
                mp.erase(it);
              }
            }
          return;
        }
      };
      proc_children();
      append(used, nd, seq, C[nd], 1);
    };
    vector<ll> used0;
    dfs(dfs, 0, used0, nxt_seq++);
  };

  using mymap = boost::unordered_flat_map<ll, ll>;

  auto impl_body = [&]() -> void {
    Tree tr(N, 0, true);
    REP(i, 0, N - 1) {
      ll p; 
      if (i + 2 <= M) p = Q[i];
      else {
        p = state % (i + 1);
        state = (state * 1103515245 + 12345) % (1LL << 31);
      }
      tr.add_edge(p, i + 1);
      // parent[i + 1] = p;
      // children[p].push_back(i + 1);
    }
    REP(i, 0, N) {
      if (i + 1 <= M) C[i] = D[i];
      else {
        C[i] = (state % F);
        state = (state * 1103515245 + 12345) % (1LL << 31);
      }
    }

#if DEBUG
    DLOGK(tr.show());
#endif
    DLOGK(C);

    auto dfs = [&](auto rF, ll nd) -> tuple<mymap, ll, ll> {
      ll nc = tr.num_children(nd);
      if (nc == 0) {
        mymap mp;
        mp[C[nd]] = 1;
        ans_m[nd] = 1;
        ans_k[nd] = 1;
        DLOGK(nd, ans_m[nd], ans_k[nd]);
        return {move(mp), 1, 1};
      }
      auto [mp, m, maxcnt] = rF(rF, tr.child(nd, 0));
      auto append = [&](ll col, ll n) -> void {
        auto [it, b] = mp.try_emplace(col, n);
        if (not b) it->second += n;
        if (m < it->second) {
          m = it->second;
          maxcnt = 1;
        }else if (m == it->second) maxcnt++;
      };
      REP(i, 1, nc) {
        auto [mp_c, m_c, maxcnt_c] = rF(rF, tr.child(nd, i));
        for (auto [col, n] : mp_c) append(col, n);
      }
      append(C[nd], 1);

      ans_m[nd] = m;
      ans_k[nd] = maxcnt;
      DLOGK(nd, ans_m[nd], ans_k[nd]);
      return {move(mp), m, maxcnt};
    };
    dfs(dfs, 0);
  };

  if (isNaive) impl_naive();
  else impl_body();

  DLOGK(ans_m);
  DLOGK(ans_k);

  Fp ans = 0;
  REP(i, 0, N) ans += (ans_m[i] ^ (i + 1)) * (ans_k[i] ^ (i + 1));
  cout << ans << endl;

}

