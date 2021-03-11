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

ll tread(string s) {
  ll h = stoll(s.substr(0, 2));
  ll m = stoll(s.substr(3, 2));
  return h * 60 + m;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<vector<bool>> coex(N, vector<bool>(N));
  {
    vector<ll> si(N), ei(N);
    for (ll i = 0; i < N; i++) {
      string s, e; cin >> s >> e;
      si.at(i) = tread(s);
      ei.at(i) = tread(e);
    }
    for (ll i = 0; i < N; i++) {
      for (ll j = i + 1; j < N; j++) {
	ll x = i, y = j;
	if (si.at(x) > si.at(y)) swap(x, y);
	if (ei.at(x) <= si.at(y) && ei.at(y) <= si.at(x) + 24*60) {
	  coex.at(i).at(j) = coex.at(j).at(i) = true;
	}
      }
    }
  }
  DLOG(coex);
  ll fullsize = 1LL << N;
  ll full = fullsize - 1;
  vector<ll> result(fullsize, -1);
  auto check = [&](const auto& rf, ll x) -> ll {
    auto& ret = result.at(x);
    if (ret == -1) {
      auto unicheck = [&]() -> bool {
	ll lst = __builtin_ctzll(x);
	if (x == (1LL << lst)) return true;
	ll y = x ^ (1LL << lst);
	if (rf(rf, y) != 1) return false;
	for (ll t = lst + 1; t < N; t++) {
	  if (!(x & (1LL << t))) continue;
	  if (!coex.at(lst).at(t)) return false;
	}
	return true;
      };
      if (unicheck()) ret = 1;
      else {
	ret = N;
	for (ll y = ((x - 1) & x); y > 0; y = ((y - 1) & x)) {
	  ret = min(ret, rf(rf, y) + rf(rf, x ^ y));
	}
      }
    }
    return ret;
  };
  ll t = check(check, full);
  cout << t << endl;
  return 0;
}

