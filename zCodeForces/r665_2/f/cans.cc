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

  ll N, Q; cin >> N >> Q;
  ll sz = 1 << N;
  vector<ll> vec(2 * sz);

  auto height = [&](ll m) -> ll { return N - (63 - __builtin_clzll(m)); };
  auto num_nodes = [&](ll m) -> ll { return 1LL << height(m); };

  for (ll i = 0; i < sz; i++) {
    ll a; cin >> a;
    vec[sz + i] = a;
  }
  for (ll m = sz - 1; m >= 1; m--) {
    vec[m] = vec[2*m + 0] + vec[2*m + 1];
  }

  vector<bool> swapped(N+1);

  auto nxt_ind = [&](ll m, ll x) -> pair<ll, ll> {
    ll ht = height(m);
    ll brd = num_nodes(m) / 2;
    if (!swapped[ht]) {
      if (x < brd) return {2*m + 0, x};
      else         return {2*m + 1, x - brd};
    }else {
      if (x < brd) return {2*m + 1, x};
      else         return {2*m + 0, x - brd};
    }
  };

  auto replace = [&](auto rF, ll m, ll x, ll k) -> void {
    if (height(m) == 0) {
      vec[m] = k;
      return;
    }
    auto [m1, x1] = nxt_ind(m, x);
    rF(rF, m1, x1, k);
    vec[m] = vec[2*m + 0] + vec[2*m + 1];
  };

  auto query = [&](auto rF, ll m, ll l, ll r) -> ll {
    DLOG("query: m=", m, "l=", l, "r=", r);
    if (l == r) return 0;
    ll nn = num_nodes(m);
    if (l == 0 && r == nn) return vec[m];
    auto [ml, xl] = nxt_ind(m, l);
    auto [mr, xr] = nxt_ind(m, r);
    if (ml == mr) {
      ll v1 = rF(rF, ml, xl, xr);
      return v1;
    }else {
      ll vl = rF(rF, ml, xl, nn / 2);
      ll vr = rF(rF, mr, 0, xr);
      return vl + vr;
    }
  };

  for (ll _q = 0; _q < Q; _q++) {
    ll tp = 0; cin >> tp;
    if (tp == 1) {
      ll x, k; cin >> x >> k; x--;
      replace(replace, 1, x, k);
      // DLOG("rep after replace: vec", vec);
    }else if (tp == 2) {
      ll k; cin >> k;
      for (ll p = 1; p <= k; p++) {
	swapped[p] = !swapped[p];
      }
    }else if (tp == 3) {
      ll k; cin >> k;
      swapped[k + 1] = !swapped[k + 1];
    }else if (tp == 4) {
      ll l, r; cin >> l >> r; l--;
      ll v = query(query, 1, l, r);
      cout << v << "\n";
    }else assert(0);
    
  }


  return 0;
}

