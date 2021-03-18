#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:updMaxMin debug)
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

  ll n, l; cin >> n >> l;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  ll totlen = 0;
  vector<string> S(n);
  for (ll i = 0; i < n; i++) {
    cin >> S[i];
    totlen += (ll)S[i].size();
  }
  vector conn(n, vector(n, -1LL));
  vector<vector<ll>> bonus(n);
  for (ll i = 0; i < n; i++) bonus[i] = vector<ll>(S[i].size());
  for (ll i = 0; i < n; i++) {
    ll si = S[i].size();;
    for (ll j = 0; j < n; j++) {
      ll sj = S[j].size();
      if (j != i) {
	for (ll k = 0; k <= si - sj; k++) {
	  if (S[i].substr(k, sj) == S[j]) {
	    // A[i] += A[j];
	    for (ll p = 0; p < k + (ll)S[j].size(); p++) {
	      bonus[i][p] += A[j];
	    }
	  }
	}
      }
      for (ll k = max(1LL, si - sj + 1); k < si; k++) {
	if (S[i].substr(k) == S[j].substr(0, si - k)) {
	  conn[i][j] = (ll)S[i].size() - k;
	  break;
	}
      }
      if (conn[i][j] == -1) conn[i][j] = 0;
    }
  }
  DLOG("A=", A);
  DLOG("conn=", conn);
  vector tbl(totlen + 1, vector(n, -1LL));
  for (ll i = 0; i < n; i++) {
    updMax(tbl[S[i].size()][i], A[i] + bonus[i][0]);
  }
  for (ll i = 1; i < totlen; i++) {
    for (ll j = 0; j < n; j++) {
      ll cv = tbl[i][j];
      if (cv == -1) continue;
      for (ll k = 0; k < n; k++) {
	ll np = i - conn[j][k] + (ll)S[k].size();
	if (np <= totlen) {
	  updMax(tbl[np][k], cv + A[k] + bonus[k][conn[j][k]]);
	}
      }
    }
  }
  for (ll j = 0; j < n; j++) {
    for (ll i = 1; i <= totlen; i++) updMax(tbl[i][j], tbl[i-1][j]);
  }

  using sta = tuple<ll, ll, ll>;
  vector<sta> cycle(n);
  for (ll i = 0; i < n; i++) {
    double density = 0;
    ll length = -1;
    ll value = -1;
    ll residue = -1;
    auto regist = [&](ll len, ll val, ll res) -> void {
      DLOG("regist: len=", len, "val=", val, "res=", res);
      double newDen = double(val) / double(len);
      if (density < newDen || (density == newDen && residue > res)) {
	density = newDen;
	length = len;
	value = val;
	residue = res;
	DLOG("  updated", density, length, value, residue);
      }
    };
    vector<bool> onStack(n);
    auto dfs = [&](auto rF, ll p, ll len, ll val) -> void {
      ll c = conn[p][i] ;
      DLOG("registering, i=", i, "p=", p);
      regist(len - c, val - (bonus[i][0] - bonus[i][c]), c);
      for (ll j = 0; j < n; j++) {
	if (j == i) continue;
	if (conn[p][j] == 0) continue;
	if (onStack[j]) continue;
	onStack[j] = true;
	rF(rF, j, len + (ll)S[j].size() - conn[p][j],
	   val + A[j] + bonus[j][conn[p][j]]);
	onStack[j] = false;
      }
    };
    dfs(dfs, i, S[i].size(), A[i] + bonus[i][0]);
    cycle[i] = {length, value, residue};
  }
  ll ans = 0;
  DLOG("tbl=", tbl);
  DLOG("cycle=", cycle);
  for (ll i = 1; i <= totlen; i++) {
    for (ll j = 0; j < n; j++) {
      if (tbl[i][j] == -1) continue;
      auto [len, val, res] = cycle[j];
      ll nc = (l - (i - S[j].size()) - res) / len;
      ans = max(ans, tbl[i][j] - A[j] + nc * val);
    }
  }
  cout << ans << endl;

  return 0;
}

