#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(bintrie debug)

// ---- inserted library file bintrie.cc

struct BTNode {
  int ne; // number of elements stored
  int p0; // index for 0 successor (-1 if not exists)
  int p1; // index for 1 successor (-1 if not exists)
  BTNode() : ne(0), p0(-1), p1(-1) {}
  int& nxt(int b) { return b == 0 ? p0 : p1; }
};

struct BinTrie {
  int len;
  vector<BTNode> body;

  BinTrie(int len_) : len(len_), body(1) {}

  int _num_branch(int b, int idx) {
    int p = body[idx].nxt(b);
    return p < 0 ? 0 : body[p].ne;
  }

  void insert(ll x, int num = 1) {
    int idx = 0;
    for (int i = len - 1; i >= 0; i--) {
      int& pp = body[idx].nxt(x >> i & 1);
      if (pp < 0) {
        pp = body.size();
        body.resize(pp + 1);
        // Caution: now pp is invalidated
      }
      body[idx].ne += num;
      idx = body[idx].nxt(x >> i & 1);
    }
    body[idx].ne += num;
  }

  int find(ll x) {
    int idx = 0;
    for (int i = len - 1; i >= 0; i--) {
      int& pp = body[idx].nxt(x >> i & 1);
      if (pp < 0) return 0;
      idx = pp;
    }
    return body[idx].ne;
  }

  void erase(ll x, int num = 1) { insert(x, -num); }

  int erase_safe(ll x, int num = 1) {
    int m = find(x);
    if (m == 0) return 0;
    int k = min(m, num);
    insert(x, -k);
    return k;
  }

  int num_le(ll x) {
    if (x < 0) return 0;
    if (x >= (1LL << len)) return body[0].ne;
    int ret = 0;
    int idx = 0;
    for (int i = len - 1; i >= 0; i--) {
      int b = x >> i & 1;
      if (b == 1) ret += _num_branch(0, idx);
      if (_num_branch(b, idx) == 0) return ret;
      idx = body[idx].nxt(b);
    }
    ret += body[idx].ne;
    return ret;
  }

  int num_lt(ll x) { return num_le(x - 1); }

  ll kth(int k) {  // 0-indexed.  i.e. kth(0) is the minimum element.
    if (k >= body[0].ne) return -1LL;
    ll ret = 0;
    int idx = 0;
    for (int i = len - 1; i >= 0; i--) {
      int t = _num_branch(0, idx);
      if (k < t) idx = body[idx].p0;
      else {
        k -= t;
        ret |= (1LL << i);
        idx = body[idx].p1;
      }
    }
    return ret;
  }

  ll lower_bound(ll x) {
    if (body[0].ne == 0) return -1;
    int idx = 0;
    int cand_i = -1, cand_idx = -1;
    int i;
    for (i = len - 1; i >= 0; i--) {
      int b = x >> i & 1;
      if (b == 0 and _num_branch(1, idx) > 0) { cand_i = i; cand_idx = idx; }
      if (_num_branch(b, idx) == 0) break;
      idx = body[idx].nxt(b);
    }
    if (i < 0) return x;
    if (cand_i < 0) return -1;
    i = cand_i;
    idx = cand_idx;
    ll mask = ~((1LL << (i + 1)) - 1);
    ll ret = (x & mask) | (1LL << i) ;
    idx = body[idx].p1;
    i--;
    for (; i >= 0; i--) {
      int b = _num_branch(0, idx) > 0 ? 0 : 1;
      ret |= (ll(b) << i);
      idx = body[idx].nxt(b);
    }
    return ret;
  }

  ll upper_bound(ll x) { return lower_bound(x + 1); }
  
};    


// ---- end bintrie.cc

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

  BinTrie bt(60);

  ll Q; cin >> Q;
  REP(q_, Q) {
    ll tp, x; cin >> tp >> x;
    if (tp == 1) {
      bt.insert(x);
    }else if (tp == 2) {
      ll k; cin >> k;
      ll t = bt.num_le(x) - k;
      ll y = t >= 0 ? bt.kth(t) : -1;
      cout << y << "\n";
    }else if (tp == 3) {
      ll k; cin >> k;
      ll t = bt.num_lt(x);
      ll y = bt.kth(t + k - 1);
      DLOGK(t, t + k - 1, y);
      cout << y << "\n";
    }
  }

  return 0;
}

