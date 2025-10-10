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

// @@ !! LIM(wavelet ipoint input binsearch debug)

// ---- inserted library file wavelet.cc

struct BitVector {
  ll N;
  ll vsize;
  vector<int> vs;
  vector<u64> vb;
  bool built;
  BitVector() = default;
  BitVector(ll N_) : N(N_), vsize((N + 63) / 64), vs(vsize + 1), vb(vsize), built(false) {}
  void set(bool val, int k) {
    if (built) throw runtime_error("already built.");
    if (val) vb[k >> 6] |=   1ULL << (k & 63);
    else     vb[k >> 6] &= ~(1ULL << (k & 63));
  }
  bool at(ll k) { return static_cast<bool>(vb[k >> 6] >> (k & 63) & 1); }
  void build() {
    if (not built) {
      for (ll i = 0; i < vsize; i++) vs[i + 1] = vs[i] + popcount(vb[i]);
      built = true;
    }
  }
  ll rank(bool val, ll k) {
    if (not built) build();
    ll cnt1 = (k >= N) ? vs.back() : vs[k >> 6] + popcount(vb[k >> 6] & ((1ULL << (k & 63)) - 1));
    if (val) return cnt1;
    else     return k - cnt1;
  }

  // for debugging
  vector<bool> vec_view() {
    vector<bool> vec(N);
    for (ll i = 0; i < N; i++) vec[i] = at(i);
    return vec;
  }

};

template<typename INT=ll>
struct WaveletMatrix {
  ll N;
  ll ht;
  vector<BitVector> vbv;
  vector<int> mid;

  pair<bool, INT> _h_rest(ll h, INT t) { return {t >> h & 1, t & ((static_cast<INT>(1) << h) - 1)}; }

  WaveletMatrix() = default;
  WaveletMatrix(const auto& vec, ll amax) { _init(vec, amax); }
  void _init(const auto& vec, ll amax) {
    if (amax < 0) amax = vec.empty() ? 1 : *max_element(vec.begin(), vec.end());
    N = ssize(vec);
    ht = bit_width((u64)amax);
    vbv = vector(ht, BitVector(N));
    mid = vector<int>(ht);
    vector tmpA{vec, vector<INT>(N)};
    vector tmpB(2, vector<INT>(N));
    vector<ll> a{N, 0};
    vector<ll> b{0, 0};
    for (ll h = ht - 1; h >= 0; h--) {
      for (int e = 0; e < 2; e++) {
        for (ll i = 0; i < a[e]; i++) {
          auto [x, y] = _h_rest(h, tmpA[e][i]);
          vbv[h].set(x, e == 0 ? i : a[0] + i);
          tmpB[x][b[x]++] = y;
        }
      }
      mid[h] = b[0];
      swap(tmpA, tmpB);
      a = b;
      b[0] = b[1] = 0;
    }
  }
  
  pair<ll, ll> _next_range(bool x, ll l, ll r, ll h) {
    return {x * mid[h] + vbv[h].rank(x, l), x * mid[h] + vbv[h].rank(x, r)};
  }

  // vec[p]
  INT access(ll p) {
    INT ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      bool x = vbv[h].at(p);
      if (x == 1) ret |= INT(1) << h;
      if (x == 0) p =          vbv[h].rank(0, p);
      else        p = mid[h] + vbv[h].rank(1, p);
    }
    return ret;
  }

  // #{ i < r : vec[i] == t }
  ll rank(INT t, ll r) {
    if (bit_width((u64)t) > ht) return 0;
    ll l = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll x = t >> h & 1;
      tie (l, r) = _next_range(x, l, r, h);
    }
    return r - l;
  }

  // k-th smallest value in vec[l, r)   (0-indexed)
  INT kth_smallest(ll k, ll l, ll r) {
    if (k < 0 or k >= r - l) throw runtime_error("k out of range");
    INT ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll num0 = vbv[h].rank(0, r) - vbv[h].rank(0, l);
      bool x = k >= num0;
      if (x) {
        k -= num0;
        ret |= INT(1) << h;
      }
      tie(l, r) = _next_range(x, l, r, h);
    }
    return ret;
  }

  // k-th largest value in vec[l, r)   (0-indexed)
  INT kth_largest(ll k, ll l, ll r) { return kth_smallest(r - l - 1 - k, l, r); }

  // #{ i \in [l, r) : vec[i] < hi }
  ll range_freq(INT hi, ll l, ll r) {
    if (bit_width((u64)hi) > ht) return r - l;
    ll ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll x = hi >> h & 1;
      if (x == 1) ret += vbv[h].rank(0, r) - vbv[h].rank(0, l);
      tie(l, r) = _next_range(x, l, r, h);
    }
    return ret;
  }

  // #{i \in [l, r) : lo <= vec[i] < hi }
  ll range_freq(INT lo, INT hi, ll l, ll r) { return range_freq(hi, l, r) - range_freq(lo, l, r); }


};



// ---- end wavelet.cc

// ---- inserted library file ipoint.cc

struct IPoint {
  ll x;
  ll y;
  IPoint(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}

  IPoint rotate(int r = 1) const {
    ll rd = r % 4;
    ll rr = r >= 0 ? rd : rd == 0 ? 0 : rd + 4;
    if      (rr == 0) return IPoint( x,  y);
    else if (rr == 1) return IPoint(-y,  x);
    else if (rr == 2) return IPoint(-x, -y);
    else if (rr == 3) return IPoint( y, -x);
    assert(0);
  }

  IPoint mirror_x() const { return IPoint(x, -y); }
  IPoint mirror_y() const { return IPoint(-x, y); }

  auto operator<=>(const IPoint&) const = default;   // This generates ==, !=, <, >, <=, >=.

  IPoint& operator +=(const IPoint& o) {
    x += o.x;
    y += o.y;
    return *this;
  }

  IPoint& operator -=(const IPoint& o) {
    x -= o.x;
    y -= o.y;
    return *this;
  }

  IPoint& operator *=(ll k) {
    x *= k;
    y *= k;
    return *this;
  }

  IPoint operator +(const IPoint& o) const { return IPoint(x, y) += o; }
  IPoint operator -(const IPoint& o) const { return IPoint(x, y) -= o; }
  IPoint operator *(ll k) const { return IPoint(x, y) *= k; }
  IPoint operator -() const { return IPoint(-x, -y); }

  bool parallel(const IPoint o) const { return x * o.y == y * o.x; }

  // For "argument sort".  The origin is treated as the maximum.
  static bool lt_arg(const IPoint& p1, const IPoint& p2) {
    bool b1 = p1.y > 0 or (p1.y == 0 and p1.x > 0);
    bool b2 = p2.y > 0 or (p2.y == 0 and p2.x > 0);
    if (b1 != b2) return b1;
    else return p1.x * p2.y > p1.y * p2.x;
  }

};
    
IPoint operator *(ll k, const IPoint& p) { return p * k; }
istream& operator >>(istream& is, IPoint& p) {
  ll x_, y_; is >> x_ >> y_;
  p.x = x_;
  p.y = y_;
  return is;
}
ostream& operator <<(ostream& os, const IPoint& p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

namespace std {
  template<>
  struct hash<IPoint> {
    std::size_t operator()(const IPoint& p) const {
      static const uint64_t frand = chrono::steady_clock::now().time_since_epoch().count();
      static const uint64_t a = (frand ^ 0x9e3779b97f4a7c15) | 1;
      static const uint64_t b = (frand ^ 0xbf58476d1ce4e5b9) | 1;
      return a * (uint64_t)p.x + b * (uint64_t)p.y;
    }
  };
}


// ---- end ipoint.cc

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// ---- inserted library file binsearch.cc

template <typename T>
requires integral<T>
T binsearch(auto check, T yes, T no) {
  while (abs(no - yes) > 1) {
    T mid = yes + (no - yes) / 2;  // avoiding unnecessary overflow
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template <typename T>
requires floating_point<T>
T binsearch(auto check, T yes, T no, T err, const bool abs_only = false) {
  T rep_in_t = ceil(log(abs(yes - no) / err) / log(2.0));
  constexpr int lim = INT_MAX - 10;
  int rep = rep_in_t > (T)lim ? lim : llround(rep_in_t) + 1;
  for (int r = 0; r < rep; r++) {
    T mid = (yes + no) / 2.0;
    if (not abs_only) {
      if (abs(yes - mid) < err * min(abs(mid), abs(yes))) return mid;
    }
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc

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

// @DefStruct(v, (x, y, i), ord=(x, y)) [LCIQFINZ]
struct v_t {
  ll x;
  ll y;
  ll i;
  v_t(ll x_ = ll(), ll y_ = ll(), ll i_ = ll()) : x(x_), y(y_), i(i_) {}
  friend istream& operator>>(istream& istr, v_t& t) {
    istr >> t.x >> t.y >> t.i;
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const v_t& t) {
    ostr << "(" << t.x << ", " << t.y << ", " << t.i << ")";
    return ostr;
  }
  bool operator<(const v_t& o) const {
    if (x < o.x) return true;
    if (x > o.x) return false;
    if (y < o.y) return true;
    if (y > o.y) return false;
    return false;
  }
};
// @End [LCIQFINZ]

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll big = 1e10;
  ll N; cin >> N;
  // @InpVec(N, XY, type=IPoint) [lhjrjdPm]
  auto XY = vector(N, IPoint());
  for (int i = 0; i < N; i++) { IPoint v; cin >> v; XY[i] = v; }
  // @End [lhjrjdPm]
  vector<v_t> V(N);
  REP(i, 0, N) { V[i] = v_t(XY[i].x - XY[i].y, XY[i].x + XY[i].y, i); }
  sort(ALL(V));
  vector<ll> vecy(N);
  REP(i, 0, N) vecy[i] = V[i].y;
  WaveletMatrix wm(vecy, -1);

  map<ll, ll> mp_xi;
  REPrev(i, N - 1, 0) mp_xi[V[i].x] = i;

  auto count = [&](ll a, ll b, ll d) -> ll { // (a, b) から距離 d 以下の点の個数
    if (d < 0) return 0;
    auto itL = mp_xi.lower_bound(a - d);
    if (itL == mp_xi.end()) return 0;
    ll iL = itL->second;
    auto itH = mp_xi.lower_bound(a + d + 1);
    ll iH = itH == mp_xi.end() ? N : itH->second;
    ll ret = wm.range_freq(max(0LL, b - d), b + d + 1, iL, iH);
    DLOGK(a, b, d, ret, b - d, b + d + 1, iL, iH);
    return ret;
  };

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll a, b, k; cin >> a >> b >> k;
    ll s = a - b;
    ll t = a + b;
    auto check1 = [&](ll d) -> bool { // (s, t) から 距離 d 未満の点の数は k 個未満
      return count(s, t, d - 1) < k;
    };
    ll d = binsearch<ll>(check1, 0, big);
    cout << d << "\n";
  }

  return 0;
}

