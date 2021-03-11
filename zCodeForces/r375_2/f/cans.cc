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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  vector<vector<ll>> nbr(n);
  for (ll i = 0; i < m; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  ll s, t, ds, dt; cin >> s >> t >> ds >> dt; s--; t--;
  vector<ll> seen(n, -1LL);
  vector<ll> s_next, t_next;
  using sta = pair<ll, ll>;
  vector<sta> st_next;
  seen[s] = s;
  seen[t] = t;
  auto dfs = [&](auto rF, ll p, ll start, ll target) -> ll {
    if (seen[p] >= 0) return -1;
    seen[p] = start;
    ll ret = -1;
    for (ll q : nbr[p]) {
      if (q == target) ret = p;
      else {
	ll x = rF(rF, q, start, target);
	if (x >= 0) ret = x;
      }
    }
    return ret;
  };
  for (ll p : nbr[s]) {
    if (p == t) continue;
    if (seen[p] >= 0) continue;
    auto x = dfs(dfs, p, p, t);
    DLOG("dfs p=", p, "t=", t, "x=", x);
    if (x < 0) s_next.push_back(p);
    else       st_next.emplace_back(p, x);
  }
  for (ll p : nbr[t]) {
    if (p == s) continue;
    if (seen[p] >= 0) continue;
    dfs(dfs, p, p, s);
    t_next.push_back(p);
  }
  DLOG("s_next=", s_next);
  DLOG("t_next=", t_next);
  DLOG("st_next=", st_next);
  DLOG("seen=", seen);
  ll ns = s_next.size();
  ll nt = t_next.size();
  ll nst = st_next.size();
  if (nst == 0) {
    // s and t are directly connected, and no other paths between them.
    if (ns > ds - 1 || nt > dt - 1) {
      cout << "No\n";
      return 0;
    }
  }else {
    if (ns > ds - 1 || nt > dt - 1 || ns + nt + nst + 1 > ds + dt) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  auto dfs2 = [&](auto rF, ll p, ll parent, ll idx) -> void {
    if (seen[p] != idx) return;
    seen[p] = -1;
    if (parent >= 0) {
      cout << parent + 1 << " " << p + 1 << "\n";
    }
    for (ll q : nbr[p]) rF(rF, q, p, idx);
  };
  auto func = [&](ll v, ll w) -> void {
    cout << v + 1 << " " << w + 1 << "\n";
    dfs2(dfs2, w, -1, w);
  };
  for (ll p : s_next) func(s, p);
  for (ll p : t_next) func(t, p);
  ll cnt = 0;
  for (auto [p, q] : st_next) {
    if (ns + cnt < ds) func(s, p);
    else               func(t, q);
    cnt++;
  }
  if (nst == 0) {
    cout << s + 1 << " " << t + 1 << "\n";
  }else {
    cout << st_next[0].second + 1 << " " << t + 1 << "\n";
  }

  return 0;
}

