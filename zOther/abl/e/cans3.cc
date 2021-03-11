#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define CONSTANT_MOD 998244353

// @@ !! LIM(mod debug segTree debug)
// --> f:gcd f:intDiv mod f:<< debug segTree
// ---- inserted function gcd from util.cc
// g = eGCD(a, b, s, t)  --->  sa + tb = g
ll eGCD(ll a, ll b, ll& s, ll& t) {
  if (a == 0) {
    s = 0;
    t = 1;
    return b;
  }
  ll u = 0;
  ll g = eGCD(b % a, a, t, u);
  s = u - (b / a) * t;
  return g;
}

// gcd(0, x) = x, gcd(-x, y) = gcd(x, y)
ll gcd(ll a, ll b) {
  ll dummy1 = 0;
  ll dummy2 = 0;
  return eGCD(abs(a), abs(b), dummy1, dummy2);
}

// Chinese Remainder Theorem
//    auto [r, z] = crt(x1, a1, x2, a2)
//    ==>   r = a1 (mod x1);  r = a2 (mod x2);  z = lcm(x1, x2);  0 <= r < z
//    If no such r exists, returns [-1, -1]
//    Note: x1 and x2 should be >= 1.  a1 and a2 can be negative or zero.
pair<ll, ll> crt(ll x1, ll a1, ll x2, ll a2) {
  ll s, t; ll g = eGCD(x1, x2, s, t);
  if (a1 % g != 0 || a2 % g != 0) return {-1, -1};
  ll z = x1 / g * x2;
  ll p = (a2 / g) * s * x1 + (a1 / g) * t * x2;
  ll r = p % z;
  if (r < 0) r += z;
  return {r, z};
};

// ---- end gcd
// ---- inserted function intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}

// ---- end intDiv
// ---- inserted library file mod.cc

/*
  You may want to put something like:
#define CONSTANT_MOD (1e9 + 7)
#define CONSTANT_MOD 998244353
  in the header part (outside of library paste area)
 */

struct Fp {
#if defined(CONSTANT_MOD)
  static const ll MOD = CONSTANT_MOD;
#else
  static ll MOD;
#endif

  ll val;

  /*
  ll _calc_from_ll(ll t = 0) {
    if      (t >= MOD)  return t % MOD;
    else if (t >= 0)    return t;
    else if (t >= -MOD) return t + MOD;
    else {
      ll v = t % MOD;
      if (v == 0) return 0;
      else        return v + MOD;
    }
  }
  */

  Fp(ll t = 0) : val(imod(t, MOD)) {}
  Fp(const Fp& t) : val(t.val) {}
  Fp& operator =(const Fp& t) { val = t.val; return *this; }
  Fp& operator =(ll t) { val = imod(t, MOD); return *this; }
  Fp& operator =(int t) { val = imod(t, MOD); return *this; }

  Fp& operator +=(const Fp& t) {
    val += t.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  Fp& operator -=(const Fp& t) {
    val -= t.val;
    if (val < 0) val += MOD;
    return *this;
  }

  Fp& operator *=(const Fp& t) {
    val = (val * t.val) % MOD;
    return *this;
  }

  Fp inv() const {
    if (val == 0) {
      cerr << "inv() is called for zero." << endl;
      exit(1);
    }
    ll u = 0;
    ll v = 0;
    eGCD(val, MOD, u, v);
    return Fp(u);
  }

  Fp& operator /=(const Fp& t) {
    return (*this) *= t.inv();
  }

  Fp operator +(const Fp& t) const { return Fp(val) += t; }
  Fp operator -(const Fp& t) const { return Fp(val) -= t; }
  Fp operator *(const Fp& t) const { return Fp(val) *= t; }
  Fp operator /(const Fp& t) const { return Fp(val) /= t; }
  Fp operator -() const { return Fp(-val); }

  bool operator ==(const Fp& t) const { return val == t.val; }
  bool operator !=(const Fp& t) const { return val != t.val; }
  
  operator ll() const { return val; }

};

Fp operator +(int x, const Fp& y) { return Fp(x) + y; }
Fp operator -(int x, const Fp& y) { return Fp(x) - y; }
Fp operator *(int x, const Fp& y) { return Fp(x) * y; }
Fp operator /(int x, const Fp& y) { return Fp(x) / y; }
Fp operator +(ll x, const Fp& y) { return Fp(x) + y; }
Fp operator -(ll x, const Fp& y) { return Fp(x) - y; }
Fp operator *(ll x, const Fp& y) { return Fp(x) * y; }
Fp operator /(ll x, const Fp& y) { return Fp(x) / y; }
Fp operator +(const Fp& x, int y) { return x + Fp(y); }
Fp operator -(const Fp& x, int y) { return x - Fp(y); }
Fp operator *(const Fp& x, int y) { return x * Fp(y); }
Fp operator /(const Fp& x, int y) { return x / Fp(y); }
Fp operator +(const Fp& x, ll y) { return x + Fp(y); }
Fp operator -(const Fp& x, ll y) { return x - Fp(y); }
Fp operator *(const Fp& x, ll y) { return x * Fp(y); }
Fp operator /(const Fp& x, ll y) { return x / Fp(y); }

istream& operator>> (istream& is, Fp& t) {
  ll x; is >> x;
  t = x;
  return is;
}

ostream& operator<< (ostream& os, const Fp& t) {
  os << t.val;
  return os;
}

class Comb {
  int nMax;
  vector<Fp> vFact;
  vector<Fp> vInvFact;
public:
  Comb(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact.at(0) = 1;
    for (int i = 1; i <= nMax; i++) vFact.at(i) = i * vFact.at(i-1);
    vInvFact.at(nMax) = vFact.at(nMax).inv();
    for (int i = nMax; i >= 1; i--) vInvFact.at(i-1) = i * vInvFact.at(i);
  }
  Fp fact(int n) { return vFact.at(n); }
  Fp comb(int n, int r) {
    return vFact.at(n) * vInvFact.at(r) * vInvFact.at(n-r);
  }
  // The number of permutation extracting r from n.
  Fp perm(int n, int r) {
    return vFact.at(n) * vInvFact.at(n-r);
  }
};

#if !defined(CONSTANT_MOD)
ll Fp::MOD = 1e9 + 7;
// ll Fp::MOD = 998'244'353;
#endif

// ---- end mod.cc
// ---- inserted function << from util.cc
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

// ---- end <<
// ---- inserted library file debug.cc
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(Head&& head) {
  cerr << head << endl;
}

template <class Head, class... Tail>
void dbgLog(Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(__VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(__VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif

// ---- end debug.cc
// ---- inserted library file segTree.cc

// It seems that we should keep the size power of two,
// considering the binary search.

template <typename DAT, typename OP,
	  typename Fadd, typename Fcomp, typename Fappl> 
struct SegTree {
  int size;	     // power of two; >= 2
  int height;        // size = 1 << height;
  vector<DAT> node;  // vector of size 2*size.
                     // 0                 : unused
                     // 1    ... size-1   : interval
                     // size ... 2*size-1 : leaf
  vector<OP> susp;   // vector of size size.
                     // suspended operation FOR CHILDREN
                     // (already applied to this node)
  DAT unit_dat;
  OP unit_op;
  Fadd add;
  Fcomp comp;
  Fappl appl;
  bool range_update;
    
  SegTree(DAT unit_dat_, OP unit_op_, Fadd add_, Fcomp comp_, Fappl appl_,
	  bool range_update_)
    // , vector<DAT> initdat) 
    : unit_dat(unit_dat_), unit_op(unit_op_), add(add_), comp(comp_),
      appl(appl_), range_update(range_update_) {}

  void set_data(vector<DAT> initdat) {
    if (initdat.size() <= 0) {
      cerr << "the size of initial vector must be >= 1" << endl;
      abort();
    }
    if (initdat.size() == 1) {
      height = 0;
    }else {
      height = sizeof(int) * 8 - __builtin_clz(initdat.size() - 1);
    }
    size = 1 << height;
    node.resize(2*size, unit_dat);
    for (int i = 0; i < (int)initdat.size(); i++) {
      node.at(size + i) = initdat.at(i);
    }
    for (int t = size - 1; t >= 1; t--) {
      node.at(t) = add(node.at(t<<1|0), node.at(t<<1|1));
    }
    susp.resize(size, unit_op);
  }

  void child_updated_sub(int k, int t) {
    node.at(t) = appl(k, susp.at(t),
		      add(node.at(t<<1|0), node.at(t<<1|1)));
  }

  void child_updated(int l, int r) {
    int k = 1;
    r--;
    while (l > 1) {
      l >>= 1;
      r >>= 1;
      k *= 2;
      child_updated_sub(k, l);
      if (l < r) child_updated_sub(k, r);
    }
  }

  void node_op(int i, int k, OP f) {
    node.at(i) = appl(k, f, node.at(i));
    if (i < size) susp.at(i) = comp(f, susp.at(i));
  }

  void push_one(int i, int k) {
    node_op(i<<1|0, k / 2, susp.at(i));
    node_op(i<<1|1, k / 2, susp.at(i));
    susp.at(i) = unit_op;
  }

  void push_upto(int l, int r) {
    for (int s = height; s >= 1; s--) {
      int lz = l >> s;
      int rz = (r-1) >> s;
      int k = 1 << s;
      push_one(lz, k);
      if (lz < rz) push_one(rz, k);
    }
  }

  DAT query(int l, int r) {
    // DLOG("l=", l, "r=", r);
    if (l >= r) return unit_dat;
    DAT ret_l = unit_dat;
    DAT ret_r = unit_dat;
    // DLOG("1: ret_l=", ret_l, "ret_r", ret_r);
    l += size;
    r += size;
    if (range_update) push_upto(l, r);
    while (l < r) {
      if (l & 1) {
	ret_l = add(ret_l, node.at(l));
	// DLOG("l=", l, "ret_l=", ret_l);
	l++;
      }
      if (r & 1) {
	ret_r = add(node.at(r-1), ret_r);
	// DLOG("r=", r, "ret_r=", ret_r);
      }
      l >>= 1;
      r >>= 1;
    }
    DAT ret = add(ret_l, ret_r);
    // DLOG("ret_l=", ret_l, "ret_r", ret_r, "ret", ret);
    return ret;
  }

  void single_update(int i, OP f) {
    update(i, i+1, f);
  }

  void update(int l, int r, OP f) {
    // DLOG("update. 1. node=", node);
    if (l >= r) return;
    if ((! range_update) && (l + 1 < r)) {
      cerr << "FATAL: r - l >= 2 without setting range_update." << endl;
      abort();
    }
    l += size;
    r += size;
    if (range_update) push_upto(l, r);
    // DLOG("update. 2. node=", node);
    int l0 = l, r0 = r;
    int k = 1;
    while (l < r) {
      if (l & 1) {
	node_op(l, k, f);
	l++;
      }
      if (r & 1) {
	node_op(r-1, k, f);
      }
      l >>= 1;
      r >>= 1;
      k *= 2;
    }
    // DLOG("update. 3. node=", node);
    child_updated(l0, r0);
    // DLOG("node=", node);
    // DLOG("susp=", susp);
  }


  // Returns the least r >= l s.t. check(Add(v[l], ..., v[r-1])) == true,
  //    where check :: DAT -> bool
  // If there is no such r, returns -1.
  int binsearch_l(const auto& check, int l) {
    // DLOG("binsearch_l; l=", l);
    int x = l + size;
    DAT val = unit_dat;
    if (check(val)) return l;
    // DLOG("pt1");
    if (range_update) push_upto(x, x+1);
    int k = 1;
    while (true) {
      DAT t = add(val, node.at(x));
      if (check(t)) break;
      if (x & 1) {
	val = t;
	x++;
	if (__builtin_popcount(x) == 1) return -1;
      }
      x >>= 1;
      k <<= 1;
      // DLOG("  x=", x, "val=", val);
    }
    // DLOG("pt2; x=", x, "k=", k);
    while (k > 1) {
      if (range_update) push_one(x, k);
      DAT t = add(val, node.at(x<<1|0));
      if (check(t)) {
	x = (x<<1|0);
      }else {
	x = (x<<1|1);
	val = t;
      }
      k >>= 1;
    }
    // DLOG("pt3; x=", x, "k=", k);
    return x + 1 - size;
  }

};

template<typename DAT, typename OP>
auto make_seg_tree(DAT unit_dat, OP unit_op,
		   auto add, auto comp, auto appl,
		   bool range_update)
  -> SegTree<DAT, OP, decltype(add), decltype(comp), decltype(appl)> {
  return SegTree(unit_dat, unit_op, add, comp, appl, range_update);
}

// ---- end segTree.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  vector<Fp> base(N+1), acc(N+2);
  base[0] = 1;
  for (ll i = 1; i < N + 1; i++) {
    base[i] = base[i-1] * 10;
  }
  for (ll i = 0; i < N + 1; i++) acc[i+1] = acc[i] + base[i];
  DLOG("base=", base);

  using DAT = pair<Fp, ll>;
  using OP = optional<ll>;
  const DAT unit_dat = {0, 0};
  const OP unit_op = nullopt;
  auto xAdd = [&](DAT x, DAT y) -> DAT {
    auto [p, u] = x;
    auto [q, v] = y;
    return {p * base[v] + q, u + v};
  };
  auto xAppl = [&](int k, OP f, DAT x) -> DAT {
    if (f.has_value()) {
      return {f.value() * acc[k], k};
    }else {
      return x;
    }
  };
  auto xComp = [](OP h, OP g) -> OP { return h.has_value() ? h : g; };
  auto st = make_seg_tree(unit_dat, unit_op, xAdd, xComp, xAppl, true);
  
  vector<DAT> init_vec(N, {1, 1});
  st.set_data(init_vec);
  DLOG("node=", st.node);
  DLOG("susp=", st.susp);
#if DEBUG
  auto [w, xxx] = st.query(0, N);
  DLOG("w=", w, "xxx=", xxx);
  auto [w1, xxx1] = st.query(0, 1);
  DLOG("w1=", w1, "xxx1=", xxx1);
  auto [w2, xxx2] = st.query(1, 2);
  DLOG("w2=", w2);
  auto [w3, xxx3] = st.query(0, 2);
  DLOG("w3=", w3, "xxx3=", xxx3);
#endif
  
  
  for (ll _q = 0; _q < Q; _q++) {
    DLOG("*** _q =", _q);
    ll l, r, d; cin >> l >> r >> d; l--;
    st.update(l, r, d);
    DLOG("after update node=", st.node);
    DLOG("susp=", st.susp);
    auto [v, dum] = st.query(0, N);
    DLOG("after query node=", st.node);
    DLOG("susp=", st.susp);
    cout << v << "\n";
  }

  return 0;
}

