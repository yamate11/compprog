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

void solve() {
  ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;
  DLOG("N=", N, "A=", A);

  ll x = N;
  ll cost = 0;
  while (x > 0) {
    if (x % 2 == 0) {
      x /= 2;
      cost += A;
    }else {
      x -= 1;
      cost += D;
    }
  }

  map<ll, ll> mp;
  using Pair = pair<ll, ll>;
  priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
  pq.emplace(0, 0);
  ll cand = LLONG_MAX;
  while (!pq.empty()) {
    DLOG("pq", pq);
    auto [d, v] = pq.top(); pq.pop();
    DLOG("popped d=", d, "v=", v);
    if (mp.find(v) != mp.end()) continue;
    DLOG("first");
    mp[v] = d;
    if (cand < d) {
      cout << cand << endl;
      return;
    }
    if (v >= N) {
      if ((LLONG_MAX - d) / D > v - N) {
	d += (v - N) * D;
	cand = min(cand, d);
	DLOG("cand is set to ", cand);
      }
      continue;
    }
    if (v <= LLONG_MAX / 2) {
      ll vv = v * 2;
      ll dd = d + A;
      if (mp.find(vv) == mp.end() || mp[vv] > dd) {
	pq.emplace(dd, vv);
      }
    }
    if (v <= LLONG_MAX / 3) {
      ll vv = v * 3;
      ll dd = d + B;
      if (mp.find(vv) == mp.end() || mp[vv] > dd) {
	pq.emplace(dd, vv);
      }
    }
    if (v <= LLONG_MAX / 5) {
      ll vv = v * 5;
      ll dd = d + C;
      if (mp.find(vv) == mp.end() || mp[vv] > dd) {
	pq.emplace(dd, vv);
      }
    }
    {
      ll vv = v + 1;
      ll dd = d + D;
      DLOG("last opt vv=", vv, "dd=", dd);
      if (mp.find(vv) == mp.end() || mp[vv] > dd) {
	DLOG("last opt emplace", dd, vv);
	pq.emplace(dd, vv);
      }
    }
  }
  if (cand < LLONG_MAX) {
    cout << cand << endl;
    return;
  }
  assert(0);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

