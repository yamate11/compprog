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

  auto par = [](string s) -> bool {
    ll p = 0;
    ll q = s.size() - 1;
    while (p < q) {
      if (s[p] != s[q]) return false;
      p++;
      q--;
    }
    return true;
  };

  auto lsplit = [](string s, ll len) -> pair<string, string> {
    return {s.substr(0, len), s.substr(len)};
  };
  auto rsplit = [&](string s, ll len) -> pair<string, string> {
    return lsplit(s, s.size() - len);
  };

  ll N; cin >> N;
  vector<string> S(N);
  vector<ll> C(N);
  for (ll i = 0; i < N; i++) cin >> S[i] >> C[i];

  const int8_t LEFT = 0;
  const int8_t RIGHT = 1;

  using sta = pair<int8_t, string>;
  using stb = pair<ll, sta>;
  priority_queue<stb, vector<stb>, greater<stb>> pque;
  map<sta, ll> cost_store;
  sta init(RIGHT, "");
  pque.push({0, init});
  cost_store[init] = 0;
  while (!pque.empty()) {
    auto [this_cost, this_state] = pque.top(); pque.pop();
    DLOG("from pque", this_state);
    if (cost_store[this_state] < this_cost) continue;
    auto [dir, s] = this_state;
    if (this_cost > 0 && par(s)) {
      cout << this_cost << endl;
      return 0;
    }
    for (ll i = 0; i < N; i++) {
      auto succ = [&](int8_t new_dir, string new_s) -> void {
	sta new_st(new_dir, new_s);
	DLOG("succ", this_state, "->", new_st, "; S[i]=", S[i]);
	ll new_cost = this_cost + C[i];
	auto [it, b] = cost_store.emplace(new_st, LLONG_MAX);
	if (new_cost < it->second) {
	  it->second = new_cost;
	  pque.emplace(new_cost, new_st);
	}
      };

      string t(S[i]); reverse(t.begin(), t.end());
      if (t.size() <= s.size()) {
	if (dir == LEFT) {
	  auto [ls, rs] = lsplit(s, t.size());
	  if (ls == t) {
	    DLOG("1: ", "s=", s, "t=", t, "ls=", ls, "rs=", rs);
	    succ(LEFT, rs);
	  }
	}else if (dir == RIGHT) {
	  auto [ls, rs] = rsplit(s, t.size());
	  if (rs == t) succ(RIGHT, ls);
	}else assert(0);
      }else {
	string srev(s); reverse(srev.begin(), srev.end());
	if (dir == LEFT) {
	  auto [ls, rs] = rsplit(S[i], s.size());
	  if (rs == srev) succ(RIGHT, ls);
	}else if (dir == RIGHT) {
	  auto [ls, rs] = lsplit(S[i], s.size());
	  if (ls == srev) succ(LEFT, rs);
	}else assert(0);
      }
    }
  }
  cout << -1 << endl;

  return 0;
}

