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

struct TrNode {
  vector<int> nxt;
  vector<int> scnt;
  int stot;
  bool term;
  TrNode() : nxt(26, -1), scnt(26, 0), stot(0), term(false) {}
};


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<string> S(N);
  vector<TrNode> trie;
  trie.push_back(TrNode());
  int tidx = 1;
  for (ll i = 0; i < N; i++) {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    S[i] = s;
    ll slen = s.size();
    int idx = 0;
    for (ll j = 0; j < slen; j++) {
      int c = s[j] - 'a';
      if (trie[idx].nxt[c] == -1) {
	trie.push_back(TrNode());
	DLOG("trie[", idx, "].nxt[", c, "]=", tidx);
	trie[idx].nxt[c] = tidx;
	tidx++;
      }
      idx = trie[idx].nxt[c];
    }
    trie[idx].term = true;
  }

  auto dfs = [&](auto rF, int idx) -> void {
    DLOG("dfs", idx);
    TrNode& nd = trie[idx];
    for (int i = 0; i < 26; i++) {
      int p = nd.nxt[i];
      if (p == -1) continue;
      rF(rF, p);
      for (int c = 0; c < 26; c++) {
	if (i == c) {
	  nd.scnt[c] += trie[p].stot;
	}else {
	  nd.scnt[c] += trie[p].scnt[c];
	}
      }
      nd.stot += trie[p].stot;
    }
    if (nd.term) nd.stot ++;
    DLOG("dfs: trie[", idx, "].stot = ", nd.stot);
  };
  dfs(dfs, 0);

  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    string s = S[i];
    ll slen = s.size();
    ll idx = 0;
    for (ll j = 0; j < slen - 1; j++) {
      idx = trie[idx].nxt[s[j] - 'a'];
    }
    int clast = s[slen - 1] - 'a';
    for (ll c = 0; c < 26; c++) {
      int cidx = trie[idx].nxt[c];
      if (cidx == -1) continue;
      if (c == clast) {
	ans += trie[cidx].stot - 1;
      }else {
	ans += trie[cidx].scnt[clast];
      }
    }
  }
  cout << ans << endl;

  return 0;
}

