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

struct SternBrocotNode {
  vector<ll> coeff;
  ll numer;
  ll denom;
  bool eff_coeff;
  bool eff_numden;
  string show() const { // for DEBUG
    string ret;
    ret = "[";
    for (ll i = 0; i < ssize(coeff) - 1; i++) ret += to_string(coeff[i]) + ", ";
    if (ssize(coeff) > 0) ret += to_string(coeff.back());
    ret += "]  ";
    ret += "(" + to_string(numer) + ", " + to_string(denom) + ")";
    return ret;
  }
  SternBrocotNode() : coeff{{1}}, numer(1), denom(1) {}
  SternBrocotNode(const vector<ll> coeff_) { set(move(coeff_)); }
  SternBrocotNode(ll a, ll b) { set(a, b); }
  void set(const vector<ll> coeff_) {
    coeff = move(coeff_);
    ll sz = ssize(coeff);
    numer = coeff[sz - 1];
    denom = 1;
    for (int i = ssize(coeff) - 2; i >= 0; i--) {
      swap(numer, denom);
      numer += coeff[i] * denom;
    }
  }
  void set(ll a, ll b) {
    coeff = vector<ll>();
    if (a == b) {
      coeff = vector<ll>{{1}};
      numer = denom = 1;
      return;
    }
    ll r, s;
    if (a > b) {
      r = b;
      s = a;
    }else {
      r = a;
      s = b;
      coeff.push_back(0);
    }
    while (true) {
      ll p = s / r;
      ll q = s % r;
      coeff.push_back(p);
      if (q == 0) {
        numer = a / r;
        denom = b / r;
        return;
      }
      s = r;
      r = q;
    }
  }
  bool operator==(const SternBrocotNode& o) const { return numer == o.numer and denom == o.denom; }
  // != is automatically defined after C++20
  bool is_root() { return numer == 1 and denom == 1; }
  ll depth() { return accumulate(coeff.begin(), coeff.end(), 0LL) - 1; }
  SternBrocotNode lca(const SternBrocotNode& o) const {
    int i = 0;
    for (; i < ssize(coeff) and i < ssize(o.coeff) and coeff[i] == o.coeff[i]; i++);
    if (i == ssize(coeff)) return *this;
    if (i == ssize(o.coeff)) return o;
    const auto& p = coeff[i] < o.coeff[i] ? *this : o;
    if (ssize(p.coeff) == i + 1) return p;
    vector<ll> vec = p.coeff;
    vec.resize(i + 1);
    vec[i] += 1;
    return SternBrocotNode(move(vec));
  }
  static SternBrocotNode lca(const SternBrocotNode& n1, const SternBrocotNode& n2) { return n1.lca(n2); }
  optional<SternBrocotNode> parent() const {
    if (denom == 1) {
      if (numer == 1) return nullopt;
      else return SternBrocotNode(numer - 1, 1);
    }
    vector<ll> vec = coeff;
    assert(ssize(vec) > 1);
    if (vec.back() == 2) {
      vec.pop_back();
      vec.back()++;
    }else {
      vec.back()--;
    }
    return SternBrocotNode(move(vec));
  }
  optional<SternBrocotNode> ancestor(ll dep) const {
    if (dep == 0) return SternBrocotNode(1, 1);
    vector<ll> vec = coeff;
    ll s = 0;
    for (ll i = 0; i < ssize(coeff); i++) {
      if (s + coeff[i] < dep + 1) {
        s += coeff[i];
      }else {
        vec.resize(i + 1);
        vec[i] = dep + 1 - s;
        if (vec[i] == 1) {
          assert(i >= 1);
          vec.pop_back();
          vec.back()++;
        }
        return SternBrocotNode(move(vec));
      }
    }
    return nullopt;
  }
  pair<optional<SternBrocotNode>, optional<SternBrocotNode>> range() {
    if (is_root()) return {nullopt, nullopt};
    if (denom == 1) return {SternBrocotNode(numer - 1, 1), nullopt};
    if (numer == 1) return {nullopt, SternBrocotNode(1, denom - 1)};
    auto p = move(*parent());
    auto vec = coeff;
    vec.pop_back();
    vec.back()++;
    auto q = move(*SternBrocotNode(move(vec)).parent());
    if (ssize(coeff) % 2 == 0) return {move(q), move(p)};
    else                       return {move(p), move(q)};
  }
};

int libcheck() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);


  {
    SternBrocotNode sbn1(1, 1);
    DLOGK(sbn1.show());
    SternBrocotNode sbn2(2, 1);
    DLOGK(sbn2.show());
    SternBrocotNode sbn3(3, 5);
    DLOGK(sbn3.show());
    vector<ll> vec4{1, 1, 2};
    SternBrocotNode sbn4(vec4);
    DLOGK(sbn4.show());
    SternBrocotNode sbn5(5, 3);
    DLOGK(sbn5.show());
    SternBrocotNode sbn6(1, 4);
    DLOGK(sbn6.show());
    SternBrocotNode sbn7(2, 5);
    DLOGK(sbn7.show());
  }


  ll T; cin >> T;
  REP(t, 0, T) {
    string tp; cin >> tp;
    if (tp == "ENCODE_PATH") {
      ll a, b; cin >> a >> b;
      SternBrocotNode sbn(a, b);
      const auto& vec = sbn.coeff;
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
      if (k == 0) sbn.set(1, 1);
      else {
        if (C[0] == 'L') N.insert(N.begin(), 0);
        N.back()++;
        sbn.set(N);
      }
      cout << sbn.numer << " " << sbn.denom << "\n";
    }else if (tp == "LCA") {
      ll a, b, c, d; cin >> a >> b >> c >> d;
      SternBrocotNode sbn1(a, b);
      SternBrocotNode sbn2(c, d);
      auto sbn0 = sbn1.lca(sbn2);
      cout << sbn0.numer << " " << sbn0.denom << "\n";
    }else if (tp == "ANCESTOR") {
      ll k, a, b; cin >> k >> a >> b;
      SternBrocotNode sbn(a, b);
      auto p = sbn.ancestor(k);
      if (not p) cout << -1 << "\n";
      else cout << p->numer << " " << p->denom << "\n";
    }else if (tp == "RANGE") {
      ll a, b; cin >> a >> b;
      SternBrocotNode sbn(a, b);
      const auto& [p, q] = sbn.range();
      if (not p) cout << "0 1 ";
      else cout << p->numer << " " << p->denom << " ";
      if (not q) cout << "1 0\n";
      else cout << q->numer << " " << q->denom << "\n";
    }else assert(0);
  }
  return 0;
}


int main() {

  libcheck();

  /*
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
  */

  return 0;
}

