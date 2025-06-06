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

template<typename T>
struct TrNode {
  unordered_map<T, int> next;
  int cont;
  int term;
  TrNode() : next(), cont(0), term(0) {}
};

template <typename T>
struct Trie {
  vector<TrNode<T>> nodes;

  Trie() : nodes(1) {}

  int index(const auto s, int add = 0) {
    int idx = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      nodes[idx].cont += add;
      auto& nxt = nodes[idx].next;
      auto it = nxt.find(s[i]);
      if (it == nxt.end()) {
	idx = nodes.size();
	nxt[s[i]] = idx;
	nodes.emplace_back();
      }else {
	idx = it->second;
      }
    }
    return idx;
  }

  void insert(const auto s) {
    int idx = index(s, 1);
    nodes[idx].term ++;
  }
};

template <typename T>
ostream& operator<< (ostream& os, const Trie<T>& trie) {
  for (ll i = 0; i < (ll)trie.nodes.size(); i++) {
    const auto& nd = trie.nodes[i];
    os << i << "(c:" << nd.cont << ",t:" << nd.term << ") " << nd.next << "\n";
  }
  return os;
}


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<string> S(N);
  Trie<char> trie;
  for (ll i = 0; i < N; i++) {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    S[i] = s;
    trie.insert(s);
  }

  DLOG("trie=", trie);

  ll tsz = trie.nodes.size();
  vector<unordered_map<char, ll>> char_cnt(tsz);
  vector<ll> str_cnt(tsz);

  auto dfs = [&](auto rF, int idx) -> void {
    auto& nd = trie.nodes[idx];
    for (auto [c0, cld] : nd.next) {
      rF(rF, cld);
      for (auto [c, n] : char_cnt[cld]) {
	if (c == c0) continue;
	char_cnt[idx][c] += char_cnt[cld][c];
      }
      char_cnt[idx][c0] += str_cnt[cld];
      str_cnt[idx] += str_cnt[cld];
    }
    str_cnt[idx] += nd.term;
  };
  dfs(dfs, 0);

  DLOG("char_cnt=", char_cnt);
  DLOG("str_cnt=", str_cnt);

  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    string s = S[i];
    ll slen = s.size();
    ll idx = trie.index(s.substr(0, slen - 1));
    char clast = s[slen - 1];
    DLOG("i=", i, "clast=", clast, "idx=", idx, "xx=", trie.nodes[idx].next);
    for (auto [c, cld] : trie.nodes[idx].next) {
      if (c == clast) {
	ans += str_cnt[cld] - 1;
      }else {
	ans += char_cnt[cld][clast];
      }
    }
  }
  cout << ans << endl;

  return 0;
}

