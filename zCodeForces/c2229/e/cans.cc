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

// @@ !! LIM(mod tree)

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

  tuple<ll, ll, ll> euler_edge(ll idx) {
    _set_euler();

    if (idx == 0) return {numNodes - 1, -1, root};
    else if (idx == 2 * numNodes - 1) return {numNodes - 1, root, -1};
    else {
      auto [e, b] = _euler_edge[idx];
      auto [x, y] = nodes_of_edge(e, b);
      return {e, x, y};
    }
  }

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
          ret.emplace_back(euler_in(h), -1);
          if (h != t) ret.emplace_back(euler_in(h) + 1, euler_in(t) + 1);
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
      if (depth(h) <= dp) {
        auto [e, p, q] = euler_edge(euler_in(h) + dp - depth(h));
        return q;
      }
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

// @@ !! LIM -- end mark --

using Fp = FpB;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> Fp {
    ll N; cin >> N;
    Tree tr(N, N - 1);
    REP(i, 0, N - 1) {
      ll u, v; cin >> u >> v; u--; v--;
      tr.add_edge(u, v);
    }
    if (tr.num_children(N - 1) == 1) return Fp(1);
    vector<bool> L(N, false);
    vector<bool> done(N, false);
    vector<Fp> f(N);
    L[N - 1] = true;
    done[N - 1] = true;
    f[N - 1] = 1;
    bool root_singleton = true;
    Fp M = 1;
    REPrev(nd, N - 2, 0) {
      if (done[nd]) continue;
      ll p = nd;
      while (true) {
        p = tr.parent(p);
        if (done[p]) break;
        done[p] = true;
      }
      if (L[p]) {
        if (p == N - 1 and root_singleton) {
          root_singleton = false;
        }else {
          L[p] = false;
          M -= f[p];
        }
      }
      f[nd] = M;
      if (tr.num_children(nd) == 0) return f[nd];
      done[nd] = true;
      L[nd] = true;
      M += f[nd];
    }
    assert(0);
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

