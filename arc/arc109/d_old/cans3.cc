#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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

/*
struct Ku {
  ll x0;
  ll y0;
  ll op_x;
  ll op_y;
  Ku(ll tx0, ll ty0, ll top_x, ll top_y)
    : x0(tx0), y0(ty0), op_x(top_x), op_y(top_y) {}
};
*/

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using Ku = tuple<ll, ll, ll, ll>;
  Ku start(0, 0, 1, 1);
  queue<pair<ll, Ku>> que;
  que.emplace(0, start);
  map<Ku, ll> dist;
  dist[start] = 0;
  ll lim = 400;
  while (true) {
    if (lim-- == 0) break;
    auto [d, ku] = que.front(); que.pop();
    auto [x0, y0, op_x, op_y] = ku;
    ll piv_x = 1 - op_x;
    ll piv_y = 1 - op_y;

    auto reg = [&] (ll xx, ll yy, ll dx, ll dy) -> void {
      Ku newku = Ku(xx, yy, dx, dy);
      auto it = dist.find(newku);
      if (it != dist.end()) return;
      dist[newku] = d + 1;
      que.emplace(d + 1, newku);
    };

    reg(x0, y0, piv_x, piv_y);
    reg(x0, y0, piv_x, op_y);
    reg(x0, y0, op_x, piv_y);
    if (piv_x == 0 && piv_y == 0) {
      reg(x0 - 1, y0, 0, 0);
      reg(x0 - 1, y0, 0, 1);
      reg(x0, y0 - 1, 0, 0);
      reg(x0, y0 - 1, 1, 0);
    }else if (piv_x == 1 && piv_y == 0) {
      reg(x0 + 1, y0, 1, 0);
      reg(x0 + 1, y0, 1, 1);
      reg(x0, y0 - 1, 0, 0);
      reg(x0, y0 - 1, 1, 0);
    }else if (piv_x == 0 && piv_y == 1) {
      reg(x0 - 1, y0, 0, 0);
      reg(x0 - 1, y0, 0, 1);
      reg(x0, y0 + 1, 0, 1);
      reg(x0, y0 + 1, 1, 1);
    }else if (piv_x == 1 && piv_y == 1) {
      reg(x0 + 1, y0, 1, 0);
      reg(x0 + 1, y0, 1, 1);
      reg(x0, y0 + 1, 0, 1);
      reg(x0, y0 + 1, 1, 1);
    }
  }
  for (ll i = 0; i < 2; i++) {
    for (ll j = 0; j < 2; j++) {
      cout << "open " << i << " " << j << "\n";
      for (ll x = -5; x <= 5; x++) {
	for (ll y = -5; y <= 5; y++) {
	  auto it = dist.find(Ku(x, y, i, j));
	  if (it == dist.end()) {
	    cout << "   ";
	  }else {
	    cout << setw(2) << it->second - 2 * max(abs(x), abs(y)) << " ";
	  }
	}
	cout << "\n";
      }
    }
  }



  /*
  ll tt; cin >> tt;
  for (ll _t = 0; _t < tt; _t++) {
    solve();
  }
  */

  return 0;
}

