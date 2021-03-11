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

// ---- end debug.cc
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if DEBUG
  ll lim = 100;
#else
  ll lim = (ll)1e5;
#endif

  ll N; cin >> N;
  vector<ll> V(N+1), W(N+1);
  for (ll i = 1; i <= N; i++) {
    cin >> V.at(i) >> W.at(i);
  }
  ll K = 1;
  while ((1LL<<(2*K)) <= N) K++;
  DLOG("K=", K);
  vector precom(1LL<<K, vector<ll>(lim+1, 0LL));
  for (ll v = 1; v < min(N+1, (1LL<<K)); v++) {
    const auto& prev = precom.at(v/2);
    auto& cur = precom.at(v);
    ll val = V.at(v);
    ll weight = W.at(v);
    for (ll w = lim; w >= 0; w--) {
      if (w - weight >= 0) {
	cur.at(w) = max(prev.at(w), prev.at(w - weight) + val);
      }else {
	cur.at(w) = prev.at(w);
      }
    }
  }
#if DEBUG
  for (ll v = 0; v < (1LL<<K); v++) {
    DLOG("v=", v, "precom.at(v)=", precom.at(v));
  }
#endif

  ll Q; cin >> Q;
  for (ll _q = 0; _q < Q; _q++) {
    ll v, L; cin >> v >> L;
    if (v < (1LL<<K)) {
      cout << precom.at(v).at(L) << "\n";
      continue;
    }
    ll t0 = 64 - __builtin_clzll(v) - K;
    ll vv = v >> t0;
    vector<ll> st_v(1LL<<t0), st_w(1LL<<t0);
    ll ans = precom.at(vv).at(L);
    DLOG("init: precom.at(vv): ", precom.at(vv));
    DLOG("init: ans=", ans);
    for (ll t = 0; t < t0; t++) {
      ll this_v = V.at(v >> t);
      ll this_w = W.at(v >> t);
      for (ll s = 0; s < (1LL<<t); s++) {
	ll idx = (1LL<<t) | s;
	ll v1 = st_v.at(idx) = this_v + st_v.at(s);
	ll w1 = st_w.at(idx) = this_w + st_w.at(s);
	DLOG("idx=", idx, "v1=", v1, "w1=", w1);
	if (w1 > L) continue;
	ll cand = v1 + precom.at(vv).at(L - w1);
	updMax(ans, cand);
	DLOG("ans possibly updated: v1=", v1, "w1=", w1, "cand=", cand);
      }
    }
    cout << ans << "\n";
  }

  return 0;
}

