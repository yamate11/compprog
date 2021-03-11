#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Trie 

  Signatures:

    struct TrNode {
      vector<int> next;      
          // The size is (to - from + 1) if invoked as Trie(from, to)
      int cont;
          // The number of strings that pass through this node.
          // This does not contain those that terminate here.
      int term;
          // The number of strings that terminate at this node.
      TrNode(int sz = 0);
    };
    
    struct Trie {
      char from;
      int br_size;
      vector<TrNode> nodes;
      Trie(char from_, char to_);
      int index(const string& s, int add = 0);
          // index of nodes
          // parameter add should be 0 unless called from insert
      void insert(const string& s);
    };
    
    ostream& operator<< (ostream& os, const Trie& trie);


  The following code:

    Trie trie('a', 'd');

    trie.insert(string("abcd"));
    trie.insert(string("abc"));
    trie.insert(string("acd"));
    trie.insert(string("ba"));
    DLOG(trie);

  generates something like:

                  'a' 'b' 'c' 'd'
      0(c:4,t:0) [ 1,  7, -1, -1]
      1(c:3,t:0) [-1,  2,  5, -1]
      2(c:2,t:0) [-1, -1,  3, -1]
      3(c:1,t:1) [-1, -1, -1,  4]
      4(c:0,t:1) [-1, -1, -1, -1]
      5(c:1,t:0) [-1, -1, -1,  6]
      6(c:0,t:1) [-1, -1, -1, -1]
      7(c:1,t:0) [ 8, -1, -1, -1]
      8(c:0,t:1) [-1, -1, -1, -1]

          0-8: index
          c: the value of cont
          t: the value of term

  If you want to know the number of strings whose prefix is "ab":

    int idx = trie.index("ab")
    cout << trie.nodes[idx].cont + trie.nodes[idx].term << endl;

*/


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

template <typename T>
ostream& operator<< (ostream& os, const set<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const multiset<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const map<T1, T2>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const unordered_map<T1, T2>& mp) {
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
void dbgLog(Head&& head) {
  cerr << head << endl;
}

template <class Head, class... Tail>
void dbgLog(Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(__VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(__VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif

// ---- end debug.cc
// @@ !! LIM  -- end mark --
// --> f:<< debug



//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- trie.cc

struct TrNode {
  vector<int> next;
  int cont;
  int term;
  TrNode(int sz = 0) : next(sz, -1), cont(0), term(0) {}
};

struct Trie {
  char from;
  int br_size;
  vector<TrNode> nodes;

  Trie(char from_, char to_)
    : from(from_), br_size(to_ - from_ + 1), nodes(1, TrNode(br_size)) {}

  int index(const string& s, int add = 0) {
    int idx = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      nodes[idx].cont += add;
      auto& nxt = nodes[idx].next;
      char c = s[i] - from;
      if (nxt[c] < 0) {
	idx = nodes.size();
	nxt[c] = idx;
	nodes.emplace_back(br_size);
      }else {
	idx = nxt[c];
      }
    }
    return idx;
  }

  void insert(const string& s) {
    int idx = index(s, 1);
    nodes[idx].term ++;
  }
};

ostream& operator<< (ostream& os, const Trie& trie) {
  for (ll i = 0; i < (ll)trie.nodes.size(); i++) {
    const auto& nd = trie.nodes[i];
    os << i << "(c:" << nd.cont << ",t:" << nd.term << ") " << nd.next << "\n";
  }
  return os;
}


// @@ !! END ---- trie.cc

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    Trie trie('a', 'd');
    trie.insert(string("abcd"));
    trie.insert(string("abc"));
    trie.insert(string("acd"));
    trie.insert(string("ba"));
    DLOG(trie);

    assert(trie.nodes[0].cont == 4);

    ll idx = trie.index("ab");
    assert(trie.nodes[idx].cont == 2);
    assert(trie.nodes[idx].term == 0);
  }

  cout << "ok\n";
  return 0;
}
