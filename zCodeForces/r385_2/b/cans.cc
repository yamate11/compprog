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

  auto solve = [&]() -> bool {
    using sta = tuple<ll, ll, ll, ll>;
    vector<vector<char>> bb;
    auto check = [&]() -> bool {

      ll n = bb.size();
      ll m = bb[0].size();

      auto see_line = [&](ll i) -> sta {
	ll j = 0;
	while (j < m && bb[i][j] == '.') j++;
	if (j == m) {
	  DLOG("  SL0 i=", i, "j=", j, "tp=", 0);
	  return sta(0, 0, 0, 0);
	}
	ll a = j;
	while (j < m && bb[i][j] == 'X') j++;
	ll len = j - a;
	while (j < m && j < a + 2 * len) {
	  if (bb[i][j] != '.') {
	    DLOG("  SL1 i=", i, "j=", j);
	    return sta(-1, 0, 0, 0);
	  }
	  j++;
	}
	if (j == m) {
	  DLOG("  SL2 i=", i, "j=", j);
	  return sta(1, a, len, 1);
	}
	ll rep = 1;
	while (j < m) {
	  if (bb[i][j] == '.') {
	    for (; j < m; j++) {
	      if (bb[i][j] != '.') {
		DLOG("  SL7 i=", i, "j=", j);
		return sta(-1, 0, 0, 0);
	      }
	    }
	    DLOG("  SL8 i=", i, "j=", j, "ret=", 1, a, len, rep);
	    return sta(1, a, len, rep);
	  }
	  ll j0 = j;
	  if (j0 + len > m) {
	    DLOG("  len=", len, "j0=", j0, "m=", m);
	    DLOG("  SL3 i=", i, "j=", j, "ret=", -1);
	    return sta(-1, 0, 0, 0);
	  }
	  while (j < m && j < j0 + len) {
	    if (bb[i][j] != 'X') {
	      DLOG("  SL4 i=", i, "j=", j);
	      return sta(-1, 0, 0, 0);
	    }
	    j++;
	  }
	  rep++;
	  while (j < m && j < j0 + 2 * len) {
	    if (bb[i][j] != '.') {
	      DLOG("  SL5 i=", i, "j=", j);
	      return sta(-1, 0, 0, 0);
	    }
	    j++;
	  }
	}
	DLOG("  SL6 i=", i, "j=", j);
	return sta(1, a, len, rep);
      };

      ll i = 0;
      ll tp, a, len, rep;
      while (i < n) {
	tie(tp, a, len, rep) = see_line(i);
	if (tp < 0) return false;
	if (tp == 1) break;
	i++;
      }
      assert(i < n);
      i++;
      while (i < n) {
	auto [tp1, a1, len1, rep1] = see_line(i);
	if (tp1 < 0) return false;
	if (tp1 == 0) break;
	assert(tp1 == 1);
	if (a != a1 || len != len1 || rep != rep1) return false;
	i++;
      }
      while (i < n) {
	auto [tp1, a1, len1, rep1] = see_line(i);
	if (tp1 != 0) return false;
	i++;
      }
      return true;
    };

    ll n, m;  cin >> n >> m;
    vector<vector<char>> brd(n, vector<char>(m, (char)0));
    for (ll i = 0; i < n; i++) for (ll j = 0; j < m; j++) cin >> brd[i][j];
    bb = brd;
    if (check()) return true;
    DLOG("1st, fail");
    bb = vector(m, vector<char>(n, (char)0));
    for (ll i = 0; i < n; i++) for (ll j = 0; j < m; j++) bb[j][i] = brd[i][j];
    if (check()) return true;
    DLOG("2nd, fail");
    return false;
  };
  cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

