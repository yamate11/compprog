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

// @@ !! LIM(debug cmpNaive f:perfmeas)

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
  ll N, M; cin >> N >> M;
  // @InpMVec(M, (T, (P, dec=1))) [rYQVSkKc]
  auto T = vector(M, ll());
  auto P = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; v2 -= 1; P[i] = v2;
  }
  // @End [rYQVSkKc]
  ll Q; cin >> Q;
  // @InpMVec(Q, ((A, dec=1), (B, dec=1))) [TxFcDGaz]
  auto A = vector(Q, ll());
  auto B = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
  }
  // @End [TxFcDGaz]

  vector qidx(N, vector(N, -1LL));
  REP(qi, 0, Q) {
    qidx[A[qi]][B[qi]] = qi;
    qidx[B[qi]][A[qi]] = qi;
  }
  vector is_on(N, false);
  vector s_time(Q, -1LL);
  vector<ll> ans(Q, 0LL);
  REP(i, 0, M) {
    ll t = T[i];
    ll p = P[i];
    is_on[p] = not is_on[p];
    REP(a, 0, N) {
      if (not is_on[a]) continue;
      ll idx = qidx[a][p];
      if (idx < 0) continue;
      if (is_on[p]) s_time[idx] = t;
      else {
        ans[idx] += t - s_time[idx];
        s_time[idx] = -1;
      }
    }
  }
  REPOUT(i, 0, Q, ans[i], "\n");

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N, M; cin >> N >> M;
  // @InpMVec(M, (T, (P, dec=1))) [rYQVSkKc]
  auto T = vector(M, ll());
  auto P = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; v2 -= 1; P[i] = v2;
  }
  // @End [rYQVSkKc]
  ll Q; cin >> Q;
  // @InpMVec(Q, ((A, dec=1), (B, dec=1))) [TxFcDGaz]
  auto A = vector(Q, ll());
  auto B = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
  }
  // @End [TxFcDGaz]

  vector t_on(N, vector<ll>());
  vector t_off(N, vector<ll>());
  {
    vector<bool> tmp_on(N, false);
    REP(i, 0, M) {
      if (tmp_on[P[i]]) {
        t_off[P[i]].push_back(i);
      }else {
        t_on[P[i]].push_back(i);
      }
      tmp_on[P[i]] = not tmp_on[P[i]];
    }
  }
  
#if DEBUG
  ll limM = llround(sqrt(M / 2));
  // limM = 0;
  // ll limM = 100;
#else
  ll limM = llround(sqrt(M / 2));
#endif

  auto freqP = [&](ll i) -> bool { return ssize(t_on[i]) >= limM; };

  auto enc = [&](ll a, ll b) -> ll { return a * N + b; };
  unordered_map<ll, ll> mp;
  vector<ll> dup(Q, -1LL);
  vector<ll> ans(Q);
  vector freq_peer(N, vector<pll>());
  vector seld_peer(N, vector<pll>());
  REP(qi, 0, Q) {
    ll a = A[qi], b = B[qi];
    ll e = enc(a, b);
    auto it = mp.find(e);
    if (it != mp.end()) {
      dup[qi] = it->second;
      continue;
    }
    mp[e] = qi;
    if (freqP(a) and freqP(b)) {
      freq_peer[a].emplace_back(b, qi);
      freq_peer[b].emplace_back(a, qi);
    }else if (freqP(a)) {
      seld_peer[a].emplace_back(b, qi);
    }else if (freqP(b)) {
      seld_peer[b].emplace_back(a, qi);
    }else {
      DLOGK(a, b);
      ll val = 0;
      ll i = 0;
      ll j = 0;
      ll sza = ssize(t_on[a]);
      ll szb = ssize(t_on[b]);
      while (i < sza and j < szb) {
        ll lo = max(T[t_on[a][i]], T[t_on[b][j]]);
        ll hi = min(T[t_off[a][i]], T[t_off[b][j]]);
        DLOGK(i, j, lo, hi);
        if (lo < hi) {
          val += hi - lo;
        }
        if (T[t_off[a][i]] < T[t_off[b][j]]) i++;
        else                               j++;
        DLOGKL("next i, j", i, j);
      }
      ans[qi] = val;
    }
  }

  vector<bool> on(N, false);
  vector<ll> don_start(Q, -1LL);
  REP(i, 0, M) {
    ll t = T[i], p = P[i];
    if (not freqP(p)) continue;
    on[p] = not on[p];
    for (auto [q, idx] : freq_peer[p]) {
      if (on[q]) {
        if (on[p]) {
          DLOGKL("donstart", p, q, t);
          don_start[idx] = t;
        }else {
          DLOGKL("add answer", p, q, t, t - don_start[idx]);
          ans[idx] += t - don_start[idx];
          don_start[idx] = -1;
        }
      }else {
        DLOGKL("q is off", p, q, t);
      }
    }
  }

  REP(a, 0, N) {
    if (not seld_peer[a].empty()) {
      vector vec(M, 0LL);
      bool tmp2_on = P[0] == a;
      REP(i, 1, M) {
        if (tmp2_on) vec[i] = vec[i - 1] + T[i] - T[i - 1];
        else vec[i] = vec[i - 1];
        if (P[i] == a) tmp2_on = not tmp2_on;
      }
      for (auto [b, idx] : seld_peer[a]) {
        REP(j, 0, ssize(t_on[b])) ans[idx] += vec[t_off[b][j]] - vec[t_on[b][j]];
      }
    }
  }

  REPOUT(i, 0, Q, dup[i] >= 0 ? ans[dup[i]] : ans[i], "\n");

  return 0;
}

