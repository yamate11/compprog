#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
#include <atcoder/segtree>
using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(mo coordCompr debug)

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

// ---- inserted library file coordCompr.cc

template <class T = ll, class Compare = std::less<T>>
struct CoordCompr {
  mutable bool built = false;
  mutable vector<T> rev;
  Compare comp;

  CoordCompr() = default;
  explicit CoordCompr(Compare c) : built(false), rev(), comp(move(c)) {}
  explicit CoordCompr(vector<T> v, Compare c = Compare{}) : built(false), rev(std::move(v)), comp(move(c)) {}

  void add(const T& x) { rev.push_back(x); built = false; }

  void add(const vector<T>& v) {
    rev.insert(rev.end(), v.begin(), v.end());
    built = false;
  }

  bool equiv(const T& a, const T& b) const { return !comp(a, b) && !comp(b, a); }

  void build() const {
    if (built) return;
    sort(rev.begin(), rev.end(), comp);
    rev.erase(unique(rev.begin(), rev.end(), [this](const T& a, const T& b) { return equiv(a, b); }),
              rev.end());
    built = true;
  }

  int c(const T& x) const {
    build();
    auto it = lower_bound(rev.begin(), rev.end(), x, comp);
    assert(it != rev.end() && equiv(*it, x));
    return (int)(it - rev.begin());
  }

  const T& d(int i) const {
    build();
    assert(0 <= i and i < (int)rev.size());
    return rev[i];
  }

  int size() const {
    build();
    return (int)rev.size();
  }
};

// ---- end coordCompr.cc

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

template<typename T1, typename T2, typename T3 = ll>
struct a_pair {
  T1 _1 = T1();
  T2 _2 = T2();
  a_pair operator -() const { return a_pair(-_1, -_2); }
  a_pair& operator +=(const a_pair& o) { _1 += o._1; _2 += o._2; return *this; }
  a_pair& operator -=(const a_pair& o) { return *this += -o; }
  a_pair operator +(const a_pair& o) const { a_pair x(*this); return x += o; }
  a_pair operator -(const a_pair& o) const { return *this + (-o); }
  friend a_pair operator *(const T3& k, const a_pair& a) { return a_pair(k * a._1, k * a._2); }
  friend a_pair operator *(const a_pair& a, const T3& k) { return a_pair(a._1 * k, a._2 * k); }
  friend ostream& operator<<(ostream& os, const a_pair a) { return os << "(" << a._1 << ", " << a._2 << ")"; }
};

ll myplus(ll a, ll b) { return a + b; }
ll myunit() { return 0; }

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [aLun20ui]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [aLun20ui]
  // @InpVec(N, B) [n2NflWff]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [n2NflWff]
  ll K; cin >> K;
  // @InpMVec(K, ((X, dec=0), (Y, dec=0))) [SCptwcZT]
  auto X = vector(K, ll());
  auto Y = vector(K, ll());
  for (int i = 0; i < K; i++) {
    ll v1; cin >> v1; v1 -= 0; X[i] = v1;
    ll v2; cin >> v2; v2 -= 0; Y[i] = v2;
  }
  // @End [SCptwcZT]

  CoordCompr cc;
  REP(i, 0, N) { cc.add(A[i]); cc.add(B[i]); }
  ll sz = cc.size();

  // using MyPair = a_pair<ll, ll>;
  /*
  auto st_x = make_seg_tree(MyPair(), plus<MyPair>(), vector<MyPair>(sz));
  auto st_y = make_seg_tree(MyPair(), plus<MyPair>(), vector<MyPair>(sz));
  */
  segtree<ll, myplus, myunit> st_x_cnt(sz);
  segtree<ll, myplus, myunit> st_x_sum(sz);
  segtree<ll, myplus, myunit> st_y_cnt(sz);
  segtree<ll, myplus, myunit> st_y_sum(sz);

  /*
  auto st_x_cnt = make_seg_tree(0LL, plus<ll>(), vector<ll>(sz));
  auto st_x_sum = make_seg_tree(0LL, plus<ll>(), vector<ll>(sz));
  auto st_y_cnt = make_seg_tree(0LL, plus<ll>(), vector<ll>(sz));
  auto st_y_sum = make_seg_tree(0LL, plus<ll>(), vector<ll>(sz));
  */

  vector<ll> ans(K);
  ll sum_x = 0;
  ll cnt_x = 0;
  ll sum_y = 0;
  ll cnt_y = 0;
  ll val = 0;

  Mo mo(N + 1);
  REP(i, 0, K) mo.add_query(X[i], Y[i]);

  vector<ll> ca(N);
  vector<ll> cb(N);
  REP(i, 0, N) ca[i] = cc.c(A[i]);
  REP(i, 0, N) cb[i] = cc.c(B[i]);

  auto op_x = [&](ll x, ll k) -> void {
    // ll a = cc.c(A[x]);
    ll a = ca[x];
    ll cnt_lo = st_y_cnt.prod(0, a);
    ll sum_lo = st_y_sum.prod(0, a);
    ll cnt_hi = cnt_y - cnt_lo;
    ll sum_hi = sum_y - sum_lo;
    ll cval = k * ((sum_hi - A[x] * cnt_hi) + (A[x] * cnt_lo - sum_lo));
    val += cval;
    st_x_cnt.set(a, st_x_cnt.get(a) + k);
    st_x_sum.set(a, st_x_sum.get(a) + k * A[x]);
    cnt_x += k;
    sum_x += k * A[x];
    DLOGKL("op_x", x, k, a, cnt_lo, sum_lo, cnt_hi, sum_hi, cval);
  };
  auto op_y = [&](ll y, ll k) -> void {
    // ll a = cc.c(B[y]);
    ll a = cb[y];
    ll cnt_lo = st_x_cnt.prod(0, a);
    ll sum_lo = st_x_sum.prod(0, a);
    ll cnt_hi = cnt_x - cnt_lo;
    ll sum_hi = sum_x - sum_lo;
    ll cval = k * ((sum_hi - B[y] * cnt_hi) + (B[y] * cnt_lo - sum_lo));
    val += cval;
    st_y_cnt.set(a, st_y_cnt.get(a) + k);
    st_y_sum.set(a, st_y_sum.get(a) + k * B[y]);
    cnt_y += k;
    sum_y += k * B[y];
    DLOGKL("op_y", y, k, a, cnt_lo, sum_lo, cnt_hi, sum_hi, cval);
  };

  auto out_left  = [&](ll x) -> void { op_x(x,  1); };
  auto in_left   = [&](ll x) -> void { op_x(x, -1); };
  auto in_right  = [&](ll y) -> void { op_y(y,  1); };
  auto out_right = [&](ll y) -> void { op_y(y, -1); };
  auto calc = [&](ll k) -> void {
    DLOGKL("calc", k, val);
    ans[k] = val;
  };

  mo.run(in_left, in_right, out_left, out_right, calc);
  REPOUT(k, 0, K, ans[k], "\n");

  return 0;
}

