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

// @@ !! LIM(f:<< debug)

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

/*
struct SternBrocotNode {
  vector<ll> coeff;
  ll numer;
  ll denom;
  bool eff_coeff;
  bool eff_numden;
  string show() const {
    string ret;
    if (eff_coeff) {
      ret = "[";
      for (ll i = 0; i < ssize(coeff) - 1; i++) ret += to_string(coeff[i]) + ", ";
      if (ssize(coeff) > 0) ret += to_string(coeff.back());
      ret += "]  ";
    }
    if (eff_numden) { ret += "(" + to_string(numer) + ", " + to_string(denom) + ")"; }
    return ret;
  }
  void set_coeff(const vector<ll> v) {
    coeff = move(v);
    eff_coeff = true;
    eff_numden = false;
  }
  void set_numden(ll a, ll b) {
    ll g = gcd(a, b);
    numer = a / g;
    denom = b / g;
    eff_numden = true;
    eff_coeff = false;
  }
  SternBrocotNode() : eff_coeff(false), eff_numden(false) {}
  SternBrocotNode(const vector<ll> v) { set_coeff(move(v)); }
  SternBrocotNode(ll a, ll b) { set_numden(a, b); }
  void _calc_numden() {
    if (eff_numden) return;
    if (not eff_coeff) { throw runtime_error("No coeff"); }
    ll sz = ssize(coeff);
    ll a = coeff[sz - 1], b = 1;
    for (int i = ssize(coeff) - 2; i >= 0; i--) {
      swap(a, b);
      a += coeff[i] * b;
    }
    numer = a;
    denom = b;
    eff_numden = true;
  }
  void _calc_coeff() {
    if (eff_coeff) return;
    if (not eff_numden) { throw runtime_error("No num/den"); }
    coeff = vector<ll>();
    ll a = numer;
    ll b = denom;
    if (a >= b and a % b == 0) {
      coeff.push_back(a / b);
    }else {
      while (true) {
        ll p = a / b;
        ll q = a % b;
        coeff.push_back(p);
        if (q == 1) {
          coeff.push_back(b);
          break;
        }
        a = b;
        b = q;
      }
    }
    eff_coeff = true;
  }
  bool equals(SternBrocotNode& o) {
    if (eff_numden and o.eff_numden) return numer == o.numer and denom == o.denom;
    if (eff_coeff and o.eff_coeff) return coeff == o.coeff;
    if (o.eff_numden) _calc_numden();
    else {
      assert(eff_numden);
      o._calc_numden();
    }
    assert (eff_numden and o.eff_numden);
    return numer == o.numer and denom == o.denom;
  }
  vector<ll>& get_coeff() {
    _calc_coeff();
    return coeff;
  }
  pair<ll, ll> get_numden() {
    _calc_numden();
    return make_pair(numer, denom); 
  }
  ll get_numer() {
    _calc_numden();
    return numer;
  }
  ll get_denom() {
    _calc_numden();
    return denom;
  }
  bool is_root() { return ssize(coeff) == 1 and coeff[0] == 1); }
  ll depth() {
    _calc_coeff();
    return accumulate(coeff.begin(), coeff.end(), 0LL) - 1;
  }
  static SternBrocotNode lca(SternBrocotNode& n1, SternBrocotNode& n2) {
    n1._calc_coeff();
    n2._calc_coeff();
    // DLOGKL("lca", n1.show(), n2.show());
    int i = 0;
    for (; i < ssize(n1.coeff) and i < ssize(n2.coeff) and n1.coeff[i] == n2.coeff[i]; i++);
    if (i == ssize(n1.coeff) and i == ssize(n2.coeff)) {
      // DLOGKL("lca ret A", n1.show());
      return n1;
    }
    if (i == ssize(n1.coeff)) {
      // DLOGKL("lca ret B", n1.show());
      return n1;
    }
    if (i == ssize(n2.coeff)) {
      // DLOGKL("lca ret C", n2.show());
      return n2;
    }
    auto& p = n1.coeff[i] < n2.coeff[i] ? n1 : n2;
    if (ssize(p.coeff) == i + 1) {
      // DLOGKL("lca ret D", p.show());
      return p;
    }
    vector<ll> vec = p.coeff;
    vec.resize(i + 1);
    vec[i] += 1;
    auto ret = SternBrocotNode(move(vec));
    // DLOGKL("lca ret E", ret.show());
    return ret;
  }
  SternBrocotNode lca(SternBrocotNode& o) { return SternBrocotNode::lca(*this, o); }
  optional<SternBrocotNode> parent() {
    _calc_coeff();
    vector<ll> vec = coeff;
    ll y = vec.back();
    if (y == 1) return nullopt;
    if (y == 2) {
      if (ssize(vec) == 1) {
        vec[0] = 1;
      }else {
        vec.pop_back();
        vec.back() += 1;
      }
    }else {
      vec.back() -= 1;
    }
    return SternBrocotNode(move(vec));
  }
  optional<SternBrocotNode> ancestor(ll dep) {
    if (dep == 0) return SternBrocotNode(1, 1);
    _calc_coeff();
    vector<ll> vec = coeff;
    ll s = 0;
    for (ll i = 0; i < ssize(coeff); i++) {
      if (s + coeff[i] >= dep + 1) {
        vec.resize(i + 1);
        vec[i] = dep + 1 - s;
        if (vec[i] == 1) {
          vec.pop_back();
          vec.back() += 1;
        }
        return SternBrocotNode(move(vec));
      }
      s += coeff[i];
    }
    return nullopt;
  }
  pair<optional<SternBrocotNode>, optional<SternBrocotNode>> range() {
    _calc_coeff();
    if (ssize(coeff) == 1) {
      if (coeff[0] == 1) return {nullopt, nullopt};
      return {SternBrocotNode(coeff[0] - 1, 1), nullopt};
    }else if (ssize(coeff) == 2 and coeff[0] == 0) {
      return {nullopt, SternBrocotNode(1, coeff[1] - 1)};
    }else {
      auto p = *(parent());
      vector<ll> vec = coeff;
      vec.pop_back();
      vec.back() += 1;
      auto q = *(SternBrocotNode(move(vec)).parent());
      if (ssize(coeff) % 2 == 0) return {move(q), move(p)};
      else                       return {move(p), move(q)};
    }
  }
};

int libcheck() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);


  {
    SternBrocotNode sbn1(1, 1);
    DLOGK(sbn1.get_coeff());
    SternBrocotNode sbn2(2, 1);
    DLOGK(sbn2.get_coeff());
    SternBrocotNode sbn3(3, 5);
    DLOGK(sbn3.get_coeff());
    vector<ll> vec4{1, 1, 2};
    SternBrocotNode sbn4(vec4);
    DLOGK(sbn4.get_numden());
    SternBrocotNode sbn5(5, 3);
    DLOGK(sbn5.get_coeff());
    SternBrocotNode sbn6(1, 4);
    DLOGK(sbn6.get_coeff());
    SternBrocotNode sbn7(2, 5);
    DLOGK(sbn7.get_coeff());
  }


  ll T; cin >> T;
  REP(t, 0, T) {
    string tp; cin >> tp;
    if (tp == "ENCODE_PATH") {
      ll a, b; cin >> a >> b;
      SternBrocotNode sbn(a, b);
      vector vec = sbn.get_coeff();
      if (ssize(vec) == 1 and vec[0] == 1) {
        cout << 0 << "\n";
      }else {
        ll i0 = vec[0] == 0 ? 1 : 0;
        cout << ssize(vec) - i0;
        REP(i, i0, ssize(vec)) {
          if (i % 2 == 0) cout << " R ";
          else            cout << " L ";
          if (i == ssize(vec) - 1) cout << vec[i] - 1;
          else                     cout << vec[i];
        }
        cout << "\n";
      }
    }else if (tp == "DECODE_PATH") {
      ll k; cin >> k;
      vector<char> C(k);
      vector<ll> N(k);
      REP(i, 0, k) cin >> C[i] >> N[i];
      auto sbn = SternBrocotNode();
      if (k == 0) sbn.set_numden(1, 1);
      else {
        if (C[0] == 'L') N.insert(N.begin(), 0);
        N.back()++;
        sbn.set_coeff(N);
      }
      auto [a, b] = sbn.get_numden();
      cout << a << " " << b << "\n";
    }else if (tp == "LCA") {
      ll a, b, c, d; cin >> a >> b >> c >> d;
      SternBrocotNode sbn1(a, b);
      SternBrocotNode sbn2(c, d);
      auto sbn0 = sbn1.lca(sbn2);
      auto [f, g] = sbn0.get_numden();
      cout << f << " " << g << "\n";
    }else if (tp == "ANCESTOR") {
      ll k, a, b; cin >> k >> a >> b;
      SternBrocotNode sbn(a, b);
      auto p = sbn.ancestor(k);
      if (not p) cout << -1 << "\n";
      else cout << p->get_numer() << " " << p->get_denom() << "\n";
    }else if (tp == "RANGE") {
      ll a, b; cin >> a >> b;
      SternBrocotNode sbn(a, b);
      auto tmp = sbn.range();
      auto& [p, q] = tmp;
      if (not p) cout << "0 1 ";
      else cout << p->get_numer() << " " << p->get_denom() << " ";
      if (not q) cout << "1 0\n";
      else cout << q->get_numer() << " " << q->get_denom() << "\n";
    }else assert(0);
  }
  return 0;
}
*/

int main() {
  auto solve = [&]() -> ll{
    ll a, b, c, d; cin >> a >> b >> c >> d;
    DLOGK(a, b, c, d);
    SternBrocotNode sbn1(a, b);
    SternBrocotNode sbn2(c, d);
    auto sbn0 = sbn1.lca(sbn2);
    DLOGKL("sbn0", sbn0.show(), sbn1.show(), sbn2.show());
    auto f = [&](auto& sbnU, auto& sbnL) -> SternBrocotNode {
      DLOGKL("f", sbnU.show(), sbnL.show());
      ll k = sbnU.depth();
      if (sbnL.depth() > k + 1) {
        auto ret = *sbnL.ancestor(k + 1);
        DLOGKL("ret f A", ret.show());
        return move(ret);
      }else {
        auto vec = sbnL.get_coeff();
        vec.back() = 1;
        vec.push_back(2);
        SternBrocotNode ret(vec);
        DLOGKL("ret f B", ret.get_numden());
        return ret;
      }
    };
    SternBrocotNode med = sbn0.equals(sbn1) ? f(sbn0, sbn2) : sbn0.equals(sbn2) ? f(sbn0, sbn1) : move(sbn0);
    return med.get_denom();
  };
    
  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

