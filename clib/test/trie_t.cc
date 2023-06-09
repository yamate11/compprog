#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug trie)

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
#line 42 "/home/y-tanabe/proj/compprog/clib/debug.cc"
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

// ---- inserted library file trie.cc
#line 54 "/home/y-tanabe/proj/compprog/clib/trie.cc"

template <typename T = ll>
struct Trie {

  struct TrNode {
    vector<int> _next;
    int _parent;
    bool _exists;
    T _user;
    TrNode(int sz = 0, int _parent_ = -1) : _next(sz, -1), _parent(_parent_), _exists(false), _user() {}
  };

  char from;
  int br_size;
  vector<TrNode> nodes;

  Trie(char from_, char to_)
    : from(from_), br_size(to_ - from_ + 1), nodes(1, TrNode(br_size)) {}

  int _index(const string& s, bool create) {
    int idx = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      int c = s[i] - from;
      if (nodes[idx]._next[c] < 0) {
        if (not create) return -1;
        nodes[idx]._next[c] = nodes.size();
        nodes.emplace_back(br_size, idx);
        idx = nodes.size() - 1;
      }else {
	idx = nodes[idx]._next[c];
      }
    }
    return idx;
  }

  int insert(const string& s) {
    int idx = _index(s, true);
    nodes[idx]._exists = true;
    return idx;
  }

  bool erase(int idx) {
    bool ret = nodes[idx]._exists;
    nodes[idx]._exists = false;
    return ret;
  }

  bool erase(const string& s) {
    int idx = _index(s, false);
    if (idx < 0) return false;
    return erase(idx);
  }

  int index(const string& s, bool exists_only = true) {
    int idx = _index(s, false);
    if (idx < 0) return -1;
    if (exists_only and not nodes[idx]._exists) return -1;
    return idx;
  }

  int parent(int idx) { return nodes[idx]._parent; }

  int child(int idx, char c) { return nodes[idx]._next[c - from]; }

  bool exists(int idx) { return nodes[idx]._exists; }

  T& user(int idx) { return nodes[idx]._user; }

  // for debugging
  vector<string> to_vector_string() {
    vector<string> vec;
    auto sub = [&](auto rF, int idx, string& s) -> void {
      if (nodes[idx]._exists) vec.push_back(s);
      for (int i = 0; i < br_size; i++) {
        int j = nodes[idx]._next[i];
        if (j >= 0) {
          s.push_back(from + i);
          rF(rF, j, s);
          s.pop_back();
        }
      }
    };
    string s = "";
    sub(sub, 0, s);
    return vec;
  }

};

template <typename T>
ostream& operator<<(ostream& ostr, Trie<T> trie) {
  ostr << trie.to_vector_string();
  return ostr;
}


// ---- end trie.cc

// @@ !! LIM -- end mark --
#line 7 "trie_skel.cc"


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    Trie<ll> trie('a', 'd');
    int i0 = trie.insert("abcd");
    trie.user(i0) = 0;
    int i1 = trie.insert("abc");
    trie.user(i1) = 1;
    int i2 = trie.insert("acd");
    trie.user(i2) = 2;
    int i3 = trie.insert("ba");
    trie.user(i3) = 3;
    assert((trie.to_vector_string() == vector<string>{"abc", "abcd", "acd", "ba"}));
    assert(trie.from == 'a');
    assert(trie.br_size == 4);
    trie.erase("abc");
    trie.user(i2) -= 2;
    trie.erase(i3);
    trie.user(i3) -= 3;
    DLOGK(trie.to_vector_string());
    assert((trie.to_vector_string() == vector<string>{"abcd", "acd"}));
    assert(trie.index("abc") == -1);
    assert(trie.index("ba") == -1);
    assert(trie.parent(i0) == i1);
    assert(trie.child(i1, 'd') == i0);
    assert(trie.exists(i0));
    assert(not trie.exists(i3));
    assert(trie.user(i1) == 1);
    assert(trie.user(i2) == 0);
  }
  {
    stringstream ss1;
    stringstream ss2;
    Trie trie('a', 'z');
    vector<string> vec{"xyz", "abcd", "a", "ae"};
    for (string s : vec) trie.insert(s);
    auto vec1 = vec;
    sort(vec1.begin(), vec1.end());
    ss1 << trie;
    ss2 << vec1;
    assert(ss1.str() == ss2.str());
  }

  cout << "ok\n";
  return 0;
}
