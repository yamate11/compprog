#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(coordCompr debug intervalSet)

// ---- inserted library file coordCompr.cc

class CoordCompr {
  bool built;
  unordered_map<ll, int> mp;
                       // map from an original value to a compressed value
  vector<ll> rev;      // vector of original values

  void build() {
    built = true;
    sort(rev.begin(), rev.end());
    rev.erase(unique(rev.begin(), rev.end()), rev.end());
    mp = unordered_map<ll, int>();
    for (size_t i = 0; i < rev.size(); i++) mp[rev[i]] = i;
  }

public:

  CoordCompr() : built(false) {}
  CoordCompr(const vector<ll>& vec) : built(false), rev(vec) {}
  CoordCompr(vector<ll>&& vec) : built(false), rev(move(vec)) {}

  void add(ll x) {
    rev.push_back(x);
    built = false;
  }

  void add(const vector<ll>& vec) {
    for (ll x : vec) rev.push_back(x);
    built = false;
  }

  int c(ll x) {
    if (! built) build();
    return mp[x];
  }

  ll d(int i) {
    if (! built) build();
    return rev[i];
  }

  int size() {
    if (! built) build();
    return rev.size();
  }

};

// ---- end coordCompr.cc

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

// ---- inserted library file intervalSet.cc

template<typename T>
struct itv_set {
  
  auto get_it(ll x) {
    auto it = repl.lower_bound(x);
    if (it == repl.end()) {
      throw runtime_error("get_it: out of range");
    }
    if (it->first == x) return it;
    if (it == repl.begin()) {
      throw runtime_error("get_it: out of range");
    }
    return prev(it);
  }

  auto get_it(ll x) const {
    auto it = repl.lower_bound(x);
    if (it == repl.end()) {
      throw runtime_error("get_it: out of range");
    }
    if (it->first == x) return it;
    if (it == repl.begin()) {
      throw runtime_error("get_it: out of range");
    }
    return prev(it);
  }

  auto divide(ll x) {
    auto it = get_it(x);
    if (it->first == x) return it;
    auto [y, t] = *it;
    auto [it2, rc] = repl.emplace(x, t);
    assert(rc);
    return it2;
  }

  ll l0;
  ll r0;
  map<ll, T> repl;

  itv_set(ll l0_, ll r0_, T t) : l0(l0_), r0(r0_) {
    repl[l0] = t; repl[r0] = t;
  }
  itv_set(ll l0_, const vector<T>& vec) : l0(l0_), r0(l0_ + (ll)vec.size()) {
    for (int i = 0; i < (int)vec.size(); i++) {
      repl[l0 + i] = vec[i];
    }
    repl[r0] = vec[0];
  }

  void put(ll x, T t) {
    divide(x + 1);
    auto it = divide(x);
    it->second = t;
  }

  void put(ll l, ll r, T t) {
    auto it1 = divide(l);
    auto it2 = divide(r);
    auto it = it1;
    it->second = t;
    for (it++; it != it2; it = repl.erase(it));
  }

  T get(ll x) const {
    auto it = get_it(x);
    return it->second;
  }

  vector<tuple<ll, ll, T>> get(ll l, ll r) const {
    vector<tuple<ll, ll, T>> ret;
    auto it = get_it(l);
    ll l1 = l;
    while (true) {
      auto it2 = next(it);
      if (r <= it2->first) {
        ret.emplace_back(l1, r, it->second);
        return ret;
      }
      ret.emplace_back(l1, it2->first, it->second);
      it = it2;
      l1 = it->first;
    }
  }

  tuple<ll, ll, T> get_itv(ll x) const {
    auto it = get_it(x);
    auto it2 = next(it);
    return {it->first, it2->first, it->second};
  }

};

// ---- end intervalSet.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  CoordCompr cc;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
    cc.add(A[i]);
  }
  ll Q; cin >> Q;
  using stb = tuple<ll, ll, ll>;
  vector<stb> Query;
  for (ll q = 0; q < Q; q++) {
    ll l, r, x; cin >> l >> r >> x; l--;
    Query.emplace_back(l, r, x);
    cc.add(x);
  }
  ll sz = cc.size();
  itv_set<ll> expr(0, N, 0);
  vector<ll> count(sz);
  for (ll i = 0; i < N; i++) {
    ll y = cc.c(A[i]);
    expr.put(i, y);
    count[y]++;
  }
  ll cur = 0;

  auto comb = [&](ll x) -> ll { return x * (x - 1) / 2; };
  DLOGK(count);
  for (ll i = 0; i < sz; i++) cur += comb(count[i]);
  DLOGKL("init", cur);

  for (ll q = 0; q < Q; q++) {
    auto [l, r, x] = Query[q];
    x = cc.c(x);
    for (auto [l2, r2, x2] : expr.get(l, r)) {
      cur -= comb(count[x2]) - comb(count[x2] - (r2 - l2));
      count[x2] -= (r2 - l2);
    }
    expr.put(l, r, x);
    cur += comb(count[x] + (r - l)) - comb(count[x]);
    count[x] += r - l;
    cout << cur << "\n";
  }

  return 0;
}

