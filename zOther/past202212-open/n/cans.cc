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

// @@ !! LIM(debug mo)

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

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

// ---- inserted library file mo.cc

struct Mo {
  using vq_t = tuple<int, int, int>;
  int size;
  int vq_idx;
  vector<vq_t> vq;
  int cl;
  int cr;

  Mo(int size_) : size(size_), vq_idx(0), vq(), cl(0), cr(0) {}
  void add_query(int l, int r) { vq.emplace_back(l, r, vq_idx++); }

  void run(auto in_left, auto in_right, auto out_left, auto out_right, auto calc) {
    int qsz = vq.size();
    int bsize = max(1, int((double)size / sqrt(qsz)));
    cl = 0;
    cr = 0;
    sort(vq.begin(), vq.end(),
         [&](const vq_t& p1, const vq_t& p2) -> bool {
           const auto& [a1, b1, i1] = p1;
           const auto& [a2, b2, i2] = p2;
           int z1 = a1 / bsize;
           int z2 = a2 / bsize;
           if (z1 != z2) return z1 < z2;
           else if (z1 % 2 == 0) return b1 < b2;
           else return b1 > b2;
         });
    for (const auto& [l, r, i] : vq) {
      // in_* must be called before out_*
      while (l < cl)   in_left(--cl);
      while (cr < r)  in_right(cr++);
      while (cl < l)  out_left(cl++);
      while (r < cr) out_right(--cr);
      calc(i);
    }
  }

  void run(auto f_in, auto f_out, auto calc) { return run(f_in, f_in, f_out, f_out, calc); }

};

// ---- end mo.cc

// @@ !! LIM -- end mark --

template<typename Cont>
Cont::iterator my_lower_bound(const Cont& cont, const Cont::key_type& x) { return cont.lower_bound(x); }

template<typename Cont>
struct Vicinity {
  using Key = Cont::key_type;
  Cont& cont;
  const Key& x;
  const Cont::iterator it;
  Vicinity(Cont& cont_, const Key& x_) : cont(cont_), x(x_), it(my_lower_bound(cont_, x)) {}

  Cont::iterator ge() { return it; }
  Cont::iterator lt() {
    if (it == cont.begin()) return cont.end();
    else return std::prev(it);
  }
  Cont::iterator le() {
    if (it != cont.end() and my_get_key(it) == x) return it;
    else return lt();
  }
  Cont::iterator gt() {
    if (it != cont.end() and my_get_key(it) == x) 
  }


  Cont::iterator _le_lt(const Key& x, bool with_eq) {
    if (with_eq) {
      auto it_eq = cont.find(x);
      if (it_eq != cont.end()) return it_eq;
    }
    auto it = cont.lower_bound(x);
    if (it == cont.begin()) return cont.end();
    return std::prev(it);
  }
  Cont::iterator le(const Key& x) { return _le_lt(x, true); }
  Cont::iterator lt(const Key& x) { return _le_lt(x, false); }
  Cont::iterator ge(const Key& x) { return cont.lower_bound(x); }
  Cont::iterator gt(const Key& x) { return cont.upper_bound(x); }

};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [kw3H9PEE]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [kw3H9PEE]
  ll Q; cin >> Q;
  // @InpMVec(Q, ((L, dec=1), R)) [aRtXi8Dd]
  auto L = vector(Q, ll());
  auto R = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
  }
  // @End [aRtXi8Dd]

  auto sq = [&](ll x) -> ll { return x * x; };

  Mo mo(N);
  REP(i, 0, Q) mo.add_query(L[i], R[i]);
  ll lim = 1e10;
  multiset<ll> B{0, lim};
  ll cur = 0;
  vector<ll> ans(Q);
  auto in_func = [&](ll i) -> void {
    ll x = A[i];
    auto it_hi = B.lower_bound(x);
    if (*it_hi != x) {
      ll v_hi = *it_hi, v_lo = *prev(it_hi);
      ll d_lo = 0 < v_lo ? x - v_lo : 0;
      ll d_hi = v_hi < lim ? v_hi - x : 0;
      ll d_both = 0 < v_lo and v_hi < lim ? v_hi - v_lo : 0;
      cur += d_lo + d_hi - d_both;


      if (*it_hi < lim and *prev(it_hi) > 
    }

      if (it_hi == B.begin()) {
        cur += sq(*it_hi - x);
      }else {
        auto it_lo = prev(it_hi);
        if (it_hi == B.end()) {
          cur += sq(x - *it_lo);
        }else {
          cur += sq(x - *it_lo) + sq(*it_hi - x) - sq(*it_hi - *it_lo);
        }
      }
    }
    B.insert(x);
    DLOGK(B);
  };
  auto out_func = [&](ll i) -> void {
    ll x = A[i];
    DLOGK(B, x);
    auto it_this = B.find(x);
    auto it_hi = B.erase(it_this);
    if (B.empty()) {
    }else {
      if (it_hi == B.begin()) {
        cur -= sq(*it_hi - x);
      }else {
        auto it_lo = prev(it_hi);
        if (it_hi == B.end()) {
          cur -= sq(x - *it_lo);
        }else {
          cur -= sq(x - *it_lo) + sq(*it_hi - x) - sq(*it_hi - *it_lo);
        }
      }
    }
  };
  auto calc = [&](ll q) -> void { ans[q] = cur; };
  mo.run(in_func, out_func, calc);
  REPOUT(q, 0, Q, ans[q], "\n");


  return 0;
}

