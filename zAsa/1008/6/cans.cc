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

// @@ !! LIM(doubling binsearch debug cmpNaive f:perfmeas)

// ---- inserted library file doubling.cc

template<typename T = void, typename Add = void>
struct Doubling {
  static constexpr bool HAS_T = not is_void_v<T>;
  using Node = conditional_t<HAS_T, pair<int, T>, int>;

  int n{};
  vector<vector<Node>> tbl;
  [[no_unique_address]] conditional_t<HAS_T, T, monostate> unit{};
  [[no_unique_address]] conditional_t<HAS_T, Add, monostate> add{};

  int& nd_int(Node& nd) { if constexpr (HAS_T) return nd.first; else return nd; }

  void prepare_tbl(u64 lim, const auto& nxt) {
    int K = 64 - countl_zero(lim);
    tbl.resize(K, vector<Node>(n));
    for (int i = 0; i < n; i++) nd_int(tbl[0][i]) = nxt[i];
  }

  void fill_tbl(u64 lim) {
    for (int k = 0; k + 1 < ssize(tbl); k++) {
      for (int i = 0; i < n; i++) {
        nd_int(tbl[k + 1][i]) = nd_int(tbl[k][nd_int(tbl[k][i])]);
        if constexpr (HAS_T) tbl[k + 1][i].second = add(tbl[k][i].second, tbl[k][tbl[k][i].first].second);
      }
    }
  }

  Doubling() {}

  Doubling(ll lim, int n_, const auto& nxt) requires (not HAS_T) : n(n_) {
    prepare_tbl(lim, nxt);
    fill_tbl(lim);
  }

  template<typename U = T, typename A = Add> requires (HAS_T)
  Doubling(ll lim, int n_, const auto& nxt, const auto& mapping, U unit_, A add_)
    : n(n_), unit(unit_), add(add_) {
    prepare_tbl(lim, nxt);
    for (int i = 0; i < n; i++) tbl[0][i].second = mapping[i];
    fill_tbl(lim);
  }

  Node val(ll x, int i) {
    Node ret;
    nd_int(ret) = i;
    if constexpr (HAS_T) ret.second = unit;
    for (int k = 0; x > 0; x >>= 1, k++) {
      if (x & 1) {
        Node cur = tbl[k][nd_int(ret)];
        nd_int(ret) = nd_int(cur);
        if constexpr (HAS_T) ret.second = add(ret.second, cur.second);
      }
    }
    return ret;
  }

};

template<typename T, typename Add>
auto make_doubling_with_monoid_unit_add(ll lim, int n, const auto& nxt, const auto& mapping, T unit, Add add) {
  return Doubling<T, decltype(add)>(lim, n, nxt, mapping, unit, add);
}
template<typename T>
auto make_doubling_with_monoid(ll lim, int n, const auto& nxt, const auto& mapping) {
  return make_doubling_with_monoid_unit_add(lim, n, nxt, mapping, T(), plus<T>());
}



/*
struct DoublingFRel { // from functional relation
  int n;
  vector<vector<int>> tbl;

  void _init(ll lim, auto frel) {
    int K = 64 - countl_zero((u64)lim);
    tbl.resize(K, vector<int>(n));
    for (int i = 0; i < n; i++) tbl[0][i] = frel(i);
    for (int k = 0; k + 1 < K; k++) for (int i = 0; i < n; i++) tbl[k + 1][i] = tbl[k][tbl[k][i]];
  }

  DoublingFRel(ll lim, int n_, auto frel) : n(n_) { _init(lim, frel); }
  static DoublingFRel from_container(ll lim, int n, auto vec) {
    return DoublingFRel(lim, n, [&](int i) { return vec[i]; });
  }

  int val(ll x, int i) { // Calculates frel^{(x)}(i).  Should be x <= lim.
    for (int k = 0; x > 0; x >>= 1, k++) if (x & 1) i = tbl[k][i];
    return i;
  }
};
  
template <typename T, typename add_t>
struct DoublingCum {
  const DoublingFRel& d;
  T unit;
  add_t add;
  vector<vector<T>> tbl;

  void _init(auto mapping) {
    int K = d.tbl.size();
    tbl.resize(K, vector<T>(d.n));
    for (int i = 0; i < d.n; i++) tbl[0][i] = mapping(i);
    for (int k = 0; k + 1 < K; k++) for (int i = 0; i < d.n; i++) tbl[k + 1][i] = add(tbl[k][i], tbl[k][d.tbl[k][i]]);
  }

  DoublingCum(const DoublingFRel& d_, auto mapping, T unit_, add_t add_)
    : d(d_), unit(unit_), add(add_) { _init(mapping); }

  T val(ll x, int i) { // the monoid sum of x objs from i.  i.e. from i to i + x - 1.
    T ret = unit;
    for (int k = 0; x > 0; x >>= 1, k++) if (x & 1) {
        ret = add(ret, tbl[k][i]);
        i = d.tbl[k][i];
      }
    return ret;
  }
};

DoublingFRel doubling_from_func(ll lim, int n, auto func) { return DoublingFRel(lim, n, func); }
DoublingFRel doubling_from_container(ll lim, int n, auto vec) {
  return DoublingFRel(lim, n, [&vec](int i) { return vec[i]; });
}
template<typename T, typename add_t = std::plus<T>>
auto doubling_cum_from_func(const DoublingFRel& d, auto mapping, T unit = T(), add_t add = plus<T>()) {
  return DoublingCum<T, decltype(add)>(d, mapping, unit, add);
}
template<typename T, typename add_t = std::plus<T>>
auto doubling_cum_from_container(const DoublingFRel& d, auto vec_mapping, T unit = T(), add_t add = plus<T>()) {
  return DoublingCum<T, decltype(add)>(d, [&vec_mapping](int i) { return vec_mapping[i]; }, unit, add);
}
*/

// ---- end doubling.cc

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

// ---- inserted library file cmpNaive.cc

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

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  ll N; cin >> N;
  string S, T; cin >> S >> T;
  string P;
  REP(i, 0, N) P += S;
  for (ll k = 1; true; k++) {
    auto check = [&]() -> bool {
      ll iP = 0;
      for (char c : T) {
        REP(x, 0, k) {
          while (iP < ssize(P) and P[iP] != c) iP++;
          if (iP == ssize(P)) return false;
          iP++;
        }
      }
      return true;
    };
    if (not check()) {
      cout << k - 1 << endl;
      return 0;
    }
  }

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll nalph = 26;
  ll N; cin >> N;
  string S, T; cin >> S >> T;

  double t1 = get_time_sec();

  ll szS = ssize(S);
  vector app(nalph, vector<ll>());
  REP(i, 0, szS) app[S[i] - 'a'].push_back(i);
  vector fwd(szS, 0LL);
  vector last_app(szS, 0LL);
  REP(d, 0, nalph) {
    REP(i, 0, ssize(app[d])) {
      if (i == ssize(app[d]) - 1) {
        fwd[app[d][i]] = app[d][0];
        last_app[app[d][i]] = 1;
      }else {
        fwd[app[d][i]] = app[d][i + 1];
        last_app[app[d][i]] = 0;
      }
    }
  }
  ll big = 1e18;
  auto dobj = make_doubling_with_monoid<ll>(big, szS, fwd, last_app);

  double t2 = get_time_sec();

  auto check = [&](ll k) -> bool {
    ll cyc = 0, pos = 0;
    for (char c : T) {
      ll d = c - 'a';
      if (app[d].empty()) return false;
      ll i = lower_bound(ALL(app[d]), pos) - app[d].begin();
      if (i == ssize(app[d])) {
        cyc++;
        pos = app[d][0];
      }else pos = app[d][i];
      auto [x, y] = dobj.val(k - 1, pos);
      cyc += y;
      pos = x;
      if (cyc >= N) return false;
      pos++;
      if (pos == szS) { cyc++; pos = 0; }
    }
    DLOGK(k, cyc, pos);
    return true;
  };
  ll k = binsearch<ll>(check, 0, big);

  double t3 = get_time_sec();

  cout << k << endl;

  cerr << t2 - t1 << endl;
  cerr << t3 - t2 << endl;

  return 0;
}

