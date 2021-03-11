#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(f:updMaxMin debug debug)
// --> f:updMaxMin f:<< debug
// ---- inserted function updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end updMaxMin
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

  string s; cin >> s;
  ll ns = s.size();
  string s_price; cin >> s_price;
  ll plen = s_price.size();

  vector s0_cmb(100, vector<ll>());
  {
    vector s_cmb(9, vector(100, vector<ll>()));
    for (ll i = 0; i < ns; i++) {
      ll x = s[i] - '0';
      if (x == 0) continue;
      s_cmb[0][x].push_back(x);
    }
    for (ll p = 1; p < 9; p++) {
      for (ll j = 0; j < 100; j++) {
	const auto& vec = s_cmb[p - 1][j];
	ll l = vec.size();
	if (l == 0) continue;
	for (ll i = 0; i < ns; i++) {
	  ll x = s[i] - '0';
	  if (x == 0) continue;
	  ll l2 = s_cmb[p][j + x].size();
	  if (l2 > 0 && l2 <= l + 1) continue;
	  s_cmb[p][j + x] = vec;
	  s_cmb[p][j + x].push_back(x);
	}
      }
    }
    for (ll j = 0; j < 100; j++) {
      for (ll p = 0; p < 9; p++) {
	if (s_cmb[p][j].size() > 0) {
	  s0_cmb[j] = s_cmb[p][j];
	  break;
	}
      }
    }
  }
#if DEBUG
  for (ll i = 0; i < 100; i++) {
    if (s0_cmb[i].size() > 0) DLOG("i=", i, "s0_cmb=", s0_cmb[i]);
  }
#endif

  // k:keta, m:slots c:carry
  // v_tbl[k][c][m]: min_score
  ll big = 1e9;
  vector v_tbl(plen + 1, vector(10, vector(10, big)));
  vector r_tbl(plen + 1, vector(10, vector(10, 0LL)));
  vector c_tbl(plen + 1, vector(10, vector(10, 0LL)));
  vector m_tbl(plen + 1, vector(10, vector(10, 0LL)));
  v_tbl[0][0][0] = 0;
  for (ll k = 0; k < plen; k++) {
    for (ll c = 0; c < 10; c++) {
      ll x = s_price[k] - '0';
      ll y;
      ll cc;
      if (x >= c) {
	y = x - c;
	cc = 0;
      }else {
	y = 10 + x - c;
	cc = 1;
      }
      for (ll w = 0; w < 10; w++) {
	ll v = w * 10 + y;
	ll m0 = s0_cmb[v].size();
	if (v > 0 && m0 == 0) continue;
	w += cc;
	ll vmin = big;
	ll marg = -1;
	for (ll m = 0; m < m0; m++) {
	  if (v_tbl[k][w][m] < vmin) {
	    vmin = v_tbl[k][w][m];
	    marg = m;
	  }
	}
	for (ll m = m0; m < 10; m++) {
	  if (v_tbl[k][w][m] < vmin) {
	    vmin = v_tbl[k][w][m];
	    marg = m;
	  }
	  ll& upd = v_tbl[k+1][c][m];
	  if (upd > vmin + m) {
	    upd = vmin + m;
	    r_tbl[k+1][c][m] = v;
	    c_tbl[k+1][c][m] = w;
	    m_tbl[k+1][c][m] = marg;
	    DLOG("k=", k, "c=", c, "v=", v, "m=", m,
		 "v_tbl=", upd, "c_tbl=", w, "m_tbl=", marg);
	  }
	}
      }
    }
  }

  DLOG("...", v_tbl[plen][0]);

  ll vmin = big;
  ll arg = -1;
  for (ll m = 1; m < 10; m++) {
    ll add = (m > 1) ? m : 0;
    if (add + v_tbl[plen][0][m] < vmin) {
      vmin = add + v_tbl[plen][0][m];
      arg = m;
    }
  }
  vector ans(arg, vector(plen + 1, 0LL));
  ll m0 = arg;
  ll c0 = 0;
  for (ll k = plen; k >= 1; k--) {
    ll r = r_tbl[k][c0][m0];
    const auto& vec = s0_cmb[r];
    for (ll i = 0; i < (ll)vec.size(); i++) {
      ans[i][k] = vec[i];
    }
    ll c = c_tbl[k][c0][m0];
    ll m = m_tbl[k][c0][m0];
    c0 = c;
    m0 = m;
  }
  for (ll i = 0; i < arg; i++) {
    ll k = 1;
    for (; k <= plen && ans[i][k] == 0; k++);
    for (; k <= plen; k++) cout << ans[i][k]; 
    if (i + 1 < arg) cout << '+';
  }
  if (arg > 1) cout << '=';
  cout << endl;

  return 0;
}

