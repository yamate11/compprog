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

// @@ !! LIM(debug f:perfmeas)

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

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

/*
template<typename Key, typename T, typename Compare = less<Key>>
struct mgs : map<Key, T, Compare> {

  const T def;
  mgs(const T& def_ = T()) : map<Key, T, Compare>(), def(def_) {}

  const T& get(const Key& k) {
    auto it = this->find(k);
    if (it == this->end()) return def;
    else return it->second;
  }

  template<typename T1>
  void set(const Key& k, T1&& t) {
    if (t == def) this->erase(k);
    else (*this)[k] = forward<T1>(t);
  }
};
*/

template<typename MP>
struct mgs : MP {
  using Key = typename MP::key_type;
  using T = typename MP::mapped_type;

  const T def;
  mgs(const T& def_ = T()) : MP(), def(def_) {}

  const T& get(const Key& k) {
    auto it = this->find(k);
    if (it == this->end()) return def;
    else return it->second;
  }

  template<typename T1>
  void set(const Key& k, T1&& t) {
    if (t == def) this->erase(k);
    else (*this)[k] = forward<T1>(t);
  }
};



int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {

    mgs<map<ll, ll>> mp;
    mp[0] = 1;
    mp[10] = 3;
    mp[100] = 5;

    assert(mp.get(10) == 3);
    assert(mp.get(20) == 0);
    assert(mp.find(20) == mp.end());

    mgs<map<ll, ll>> mp1(mp);
    mp1[1000] = 7;

    assert(mp1.get(100) == 5);
    assert(mp1.get(1000) == 7);
    assert(mp1.get(30) == 0);
    assert(mp1.find(30) == mp1.end());

    mgs<map<ll, ll>> mp2(move(mp1));
    mp2[10000] = 9;

    assert(mp2.get(1000) == 7);
    assert(mp2.get(10000) == 9);
    assert(mp2.get(40) == 0);

    mp2.set(10, -3);
    assert(mp2.get(10) == -3);
    mp2.set(100, 0);
    assert(mp2.get(100) == 0);
    assert(mp2.find(100) == mp2.end());

  }

  {
    mgs<unordered_map<ll, ll>> mp;
    mp[0] = 1;
    mp[10] = 3;
    mp[100] = 5;

    assert(mp.get(10) == 3);
    assert(mp.get(20) == 0);
    assert(mp.find(20) == mp.end());

    mgs<unordered_map<ll, ll>> mp1(mp);
    mp1[1000] = 7;

    assert(mp1.get(100) == 5);
    assert(mp1.get(1000) == 7);
    assert(mp1.get(30) == 0);
    assert(mp1.find(30) == mp1.end());

    mgs<unordered_map<ll, ll>> mp2(move(mp1));
    mp2[10000] = 9;

    assert(mp2.get(1000) == 7);
    assert(mp2.get(10000) == 9);
    assert(mp2.get(40) == 0);

    mp2.set(10, -3);
    assert(mp2.get(10) == -3);
    mp2.set(100, 0);
    assert(mp2.get(100) == 0);
    assert(mp2.find(100) == mp2.end());

  }

  {  // move constructor
    ll lim = 3000;
    mgs<map<ll, vector<ll>>> mp;
    for (ll i = 0; i < lim; i++) mp[i] = vector(lim, 0LL);
    double t0 = get_time_sec();
    mgs<map<ll, vector<ll>>> mp1(mp);
    double t1 = get_time_sec();
    mgs<map<ll, vector<ll>>> mp2(move(mp));
    double t2 = get_time_sec();
    assert((t1 - t0) > 3 * (t2 - t1));
  }

  {  // get returns a reference, not a copy
    mgs<map<ll, vector<ll>>> mp;
    ll lim = 3000;
    for (ll i = 0; i < lim; i++) mp.set(i, vector<ll>(lim));
    double t0 = get_time_sec();
    ll s = 0;
    for (ll i = 0; i < lim; i++) {
      auto& v = mp.get(i);
      s += v[i];
    }
    double t1 = get_time_sec();
    s = 0;
    for (ll i = 0; i < lim; i++) {
      auto v = mp.get(i);
      s += v[i];
    }
    double t2 = get_time_sec();
    assert((t2 - t1) > 3 * (t1 - t0));
  }

  { // set employs the move semantics
    mgs<map<ll, vector<ll>>> mp;
    ll lim = 3000;
    vector vec(lim, vector(lim, 0LL));
    double t0 = get_time_sec();
    for (ll i = 0; i < lim; i++) mp.set(i, vec[i]);
    double t1 = get_time_sec();
    for (ll i = 0; i < lim; i++) mp.set(i, move(vec[i]));
    double t2 = get_time_sec();
    assert((t1 - t0) > 3 * (t2 - t1));
  }

  // translation from older testsets
  {
    mgs<map<ll, ll>> mp;
    mp.set(1, 5);
    mp.set(7, -1);
    assert(mp.get(1) == 5);
    assert(mp.get(7) == -1);
    assert(mp.get(100) == 0);
    assert(mp.find(100) == mp.end());
    mp.set(4, 2);
    assert(mp.get(4) == 2);
    mp.set(7, 0);
    assert(mp.get(7) == 0);
    assert(mp.find(7) == mp.end());
  }
  {
    mgs<map<ll, ll>> mp;
    mp.set(1, 1); // constant
    ll x = 2;
    mp.set(2, x); // l-value
    const ll y = 3;
    mp.set(3, y); // const l-value
    mp.set(4, move(x)); // r-value
    assert(mp.get(1) == 1);
    assert(mp.get(2) == 2);
    assert(mp.get(3) == 3);
    assert(mp.get(4) == 2);
  }
  {
    using vi = vector<int>;
    mgs<map<int, vi>> mp;
    mp.set(3, vi{1, 2, 3});
    mp.set(7, move(vi{-1, -2}));
    mp.set(10, vi{});
    assert(mp.get(3) == (vi{1, 2, 3}));
    assert(mp.get(7) == (vi{-1, -2}));
    assert(mp.get(10) == vi{});
    assert(mp.get(100000) == vi{});
    assert(mp.find(10) == mp.end());
    mp.set(7, vi{});
    assert(mp.size() == 1);
  }
  {
    mgs<map<int, string>> mp("---");
    mp.set(4, "");
    mp.set(5, "hello");
    mp.set(2, "world");
    mp.set(7, "---");
    assert(mp.get(2) == "world");
    assert(mp.get(7) == "---");
    assert(mp.get(-10) == "---");
  }

  return 0;
}

