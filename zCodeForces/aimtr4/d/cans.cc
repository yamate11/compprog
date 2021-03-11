#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug)
// --> f:<< debug
// ---- inserted function << from util.cc
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

// ---- end <<
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

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

// ---- end debug.cc
// @@ !! LIM  -- end mark --

const string end_mark("^__=end=__^");

struct SolveExc : exception {};

struct Judge {
  bool testing;
  // You always need the bool member testing.
  // Other members can be freely added.  Mainly for testing purposes.
  ll n;
  ll start;
  ll x;
  ll expected;
  vector<ll> val;
  vector<ll> nxt;

  Judge(bool testing_) : testing(testing_) {
    if (testing) {
      // Typically, the question for testing is read from stdin.
      cin >> n >> start >> x >> expected;
      val = vector<ll>(n);
      nxt = vector<ll>(n);
      for (ll i = 0; i < n; i++) cin >> val[i] >> nxt[i];
    }else {
      // Real initial input is to be written here, if any.
      cin >> n >> start >> x;
    }
  }

  tuple<ll, ll, ll> init() {
    // Initial input
    return {n, start, x};
  }

  pair<ll, ll> ask(int i) {
    if (testing) {
      i--;
      return {val[i], nxt[i]};
    }else {
      // Information asking.  Typically prepended by "? " and followed by endl
      cout << "? " << i << endl;
      ll l, r; cin >> l >> r;
      return {l, r};
    }
  }

  void answer(int v) {
    if (testing) {
      // Always call ac() or wa().
      if (v == expected) ac();
      wa();
    }else {
      // Final output.  Typically prepended by "! " and followed by endl
      cout << "! " << v << endl;
      // Need to throw SolveExc()
      throw SolveExc();
    }
  }

  void wa() {
    cout << "WA\n";
    exit(1);
  }

  void ac() {
    cout << "AC\n";
    throw SolveExc();
  }
};

void solve(Judge& judge);

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  bool is_judge = false;
  if (argc == 2) {
    if (strcmp(argv[1], "judge") == 0) {
      is_judge = true;
    }else {
      cerr << "Unknown argument\n";
      exit(1);
    }
  }
    
  try {
    Judge judge(is_judge);
    solve(judge);
  }catch (const SolveExc& e) {
  }
  return 0;
}

void solve(Judge& judge) {
  
  auto [n, start, x0] = judge.init();
  vector<bool> asked(n + 1), in_next(n + 1);

  random_device rand_dev;
#if DEBUG
  mt19937 rng;
#else
  mt19937 rng(rand_dev());
#endif
  uniform_int_distribution<ll> dist(1, n);

  auto get_unasked = [&]() -> ll {
    ll fcnt = 10;
    while (fcnt > 0) {
      ll x = dist(rng);
      if (!asked[x] && !in_next[x]) {
        return x;
      }
      fcnt--;
    }
    ll x = dist(rng);
    while (asked[x]) {
      x++;
      if (x > n) x = 1;
    }
    return x;
  };

  vector<pair<ll, ll>> info;

  auto ask = [&](ll x) -> pair<ll, ll> {
    auto [v, nxt] = judge.ask(x);
    if (v == -1 && nxt == -1) throw SolveExc();
    info.emplace_back(v, nxt);
    asked[x] = true;
    if (nxt >= 0) in_next[nxt] = true;
    return make_pair(v, nxt);
  };
  
  ask(start);
#if DEBUG
  const ll lim = 2;
#else
  const ll lim = 1000;
#endif
  for (ll i = 0; i < min(n - 1, lim); i++) {
    ll x = get_unasked();
    ask(x);
  }

  sort(info.begin(), info.end());
  DLOGKL("sorted", info);
  auto it = lower_bound(info.begin(), info.end(), make_pair(x0, ll(1e15)));
  if (it == info.begin()) {
    auto [v, nxt] = *it;
    judge.answer(v);
  }
  it--;
  auto [v, nxt] = *it;
  DLOGKL("start", v, nxt);
  if (v == x0) judge.answer(x0);
  if (nxt == -1) judge.answer(-1);
  ll x = nxt;
  while (true) {
    auto [v2, nxt2] = ask(x);
    if (v2 >= x0) judge.answer(v2);
    if (nxt2 == -1) judge.answer(-1);
    x = nxt2;
  }

}

