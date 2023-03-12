#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(debug)

// ---- inserted function f:<< from util.cc
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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto mkval = [&](ll x, ll bnd) -> pair<ll, vector<ll>> {
    vector<ll> ret{1};
    while (ret.back() * x <= bnd) ret.push_back(ret.back() * x);
    return {SIZE(ret), ret};
  };

  string sn; cin >> sn;
  ll K; cin >> K;
  vector<ll> q2{0, 0, 1, 0, 2, 0, 1, 0, 3, 0};
  vector<ll> q3{0, 0, 0, 1, 0, 0, 1, 0, 0, 2};
  vector<ll> q5{0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
  vector<ll> q7{0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
  auto [lim2, val2] = mkval(2, K);
  auto [lim3, val3] = mkval(3, K);
  auto [lim5, val5] = mkval(5, K);
  auto [lim7, val7] = mkval(7, K);
  vector chk(lim2, vector(lim3, vector(lim5, vector(lim7, false))));
  REP(c2, 0, lim2) {
    ll v2 = val2[c2];
    if (v2 > K) break;
    REP(c3, 0, lim3) {
      ll v3 = v2 * val3[c3];
      if (v3 > K) break;
      REP(c5, 0, lim5) {
        ll v5 = v3 * val5[c5];
        if (v5 > K) break;
        REP(c7, 0, lim7) {
          ll v7 = v5 * val7[c7];
          if (v7 > K) break;
          DLOGKL("chk", c2, c3, c5, c7);
          chk[c2][c3][c5][c7] = true;
        }
      }
    }
  }
  enum {ALL_ZERO = 0, CONT_ZERO = 1, OVER = 2, ORDINARY = 3};
  vector tbl_init(2, vector(4, vector(lim2, vector(lim3, vector(lim5, vector(lim7, 0LL))))));
  auto tbl = tbl_init;
  tbl[1][ALL_ZERO][0][0][0][0] = 1;
  REP(i, 0, SIZE(sn)) {
    auto prev = move(tbl);
    tbl = tbl_init;
    ll d = sn[i] - '0';
    REP(eq, 0, 2) REP(ax, 0, 4) REP(c2, 0, lim2) REP(c3, 0, lim3) REP(c5, 0, lim5) REP(c7, 0, lim7) {
      ll t = prev[eq][ax][c2][c3][c5][c7];
      if (t == 0) continue;
      REP(x, 0, 10) {
        if (eq and x > d) continue;
        ll new_eq = eq and x == d;
        ll new_c2 = c2 + q2[x];
        ll new_c3 = c3 + q3[x];
        ll new_c5 = c5 + q5[x];
        ll new_c7 = c7 + q7[x];
        ll new_ax;
        if (x == 0) {
          if (ax == ALL_ZERO) new_ax = ALL_ZERO;
          else {
            new_ax = CONT_ZERO;
            new_c2 = new_c3 = new_c5 = new_c7 = 0;
          }
        }else {
          if (ax == CONT_ZERO) {
            new_ax = CONT_ZERO;
            new_c2 = new_c3 = new_c5 = new_c7 = 0;
          }else if (ax == OVER
                    or new_c2 >= lim2 or new_c3 >= lim3 or new_c5 >= lim5 or new_c7 >= lim7
                    or not chk[new_c2][new_c3][new_c5][new_c7]) {
            new_ax = OVER;
            new_c2 = new_c3 = new_c5 = new_c7 = 0;
          }else {
            new_ax = ORDINARY;
          }
        }
        tbl[new_eq][new_ax][new_c2][new_c3][new_c5][new_c7] += t;
      }
    }
  }
  ll ans = 0;
  REP(eq, 0, 2) REP(ax, 0, 4) REP(c2, 0, lim2) REP(c3, 0, lim3) REP(c5, 0, lim5) REP(c7, 0, lim7) {
    if (ax == ALL_ZERO or ax == OVER) continue;
    ll x = tbl[eq][ax][c2][c3][c5][c7];
    if (x > 0) {
      DLOGK(eq, ax, c2, c3, c5, c7, x);
      ans += x;
    }
  }
  cout << ans << endl;
  

  return 0;
}

