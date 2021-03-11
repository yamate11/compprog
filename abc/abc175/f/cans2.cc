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

  ll N; cin >> N;
  vector<string> S(N);
  vector<ll> C(N);
  for (ll i = 0; i < N; i++) cin >> S[i] >> C[i];

  using sta = pair<int8_t, string>;
  map<sta, ll> mp;

  auto search = [&](auto rF, int8_t dir, const string& s) -> ll{
    DLOG("search enter, dir=", dir, "s=", s);
    sta st(dir, s);
    ll n = s.size();
    if (mp.find(st) != mp.end()) {
      DLOG("search cache hit, s=", s, "val=", mp[st]);
      return mp[st];
    }
    mp[st] = LLONG_MAX;
    string rev(s); reverse(rev.begin(), rev.end());
    ll vm = LLONG_MAX;
    for (ll i = 0; i < N; i++) {
      auto updvm = [&](ll e) -> void {
	if (e < LLONG_MAX) {
	  vm = min(vm, e + C[i]);
	}
      };

      DLOG("search for s=", s, "checking S[i]=", S[i]);
      ll m = S[i].size();
      if (m < n) {
	if (dir == 0) {
	  if (S[i] == rev.substr(0, m)) {
	    updvm(rF(rF, 1, s.substr(0, n - m)));
	  }
	}else {
	  if (S[i] == s.substr(n-m)) {
	    updvm(rF(rF, 1, s.substr(m)));
	  }
	}
      }else if (m == n) {
	if (S[i] == rev) {
	  DLOG("search terminal node");
	  updvm(0);
	}
      }else { // m > n
	if (dir == 0) {
	  if (S[i].substr(0, n) == rev) {
	    updvm(rF(rF, 1, S[i].substr(n)));
	  }
	}else {
	  if (S[i].substr(m - n) == rev) {
	    updvm(rF(rF, 0, S[i].substr(0, m - n)));
	  }
	}
      }
    }
    DLOG("new value for dir=", dir, "s=", s, "value=", vm);
    mp[st] = vm;
    return vm;
  };

  auto par = [](const string& s) -> bool {
    ll l = 0;
    ll r = s.size() - 1;
    while (l < r) {
      if (s[l] != s[r]) return false;
      l++;
      r--;
    }
    return true;
  };

  ll ans = LLONG_MAX;
  for (ll i = 0; i < N; i++) {
    ll n = S[i].size();
    DLOG("main: checking ", S[i]);
    for (ll t = 0; t <= n; t++) {
      string left = S[i].substr(0, t);
      string right = S[i].substr(t);
      DLOG("main: left=", left, "right=", right);
      if (par(left)) {
	ll e = search(search, 1, right);
	DLOG("e=", e);
	if (e < LLONG_MAX) ans = min(ans, e + C[i]);
      }
      if (par(right)) {
	ll e = search(search, 0, left);
	DLOG("e=", e);
	if (e < LLONG_MAX) ans = min(ans, e + C[i]);
      }
    }
  }
  if (ans == LLONG_MAX) {
    cout << -1 << endl;
  }else {
    cout << ans << endl;
  }

  return 0;
}

