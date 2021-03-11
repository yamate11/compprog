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

  ll N; cin >> N;
  vector<pair<ll,ll>> U, V;
  ll tot = 0;
  ll bot = 0;
  ll eqhi = LLONG_MIN;
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    tot += a - b;
    if (a == b) {
      eqhi = max(eqhi, a);
    }else if (a < b) {
      U.emplace_back(b - a, a);
      bot += a - b;
    }else {
      V.emplace_back(a - b, b);
    }
  }
  auto cmp = [](auto p, auto q) -> bool { return p.second < q.second; };
  sort(U.begin(), U.end(), cmp);
  sort(V.begin(), V.end(), cmp);

  auto chk1 = [&](const auto& vec, ll lim) -> bool {
    ll curLim = lim;
    priority_queue<pair<ll,ll>> pq;
    auto it = vec.begin();
    while (true) {
      for ( ; it != vec.end() && it->second <= curLim ; it++) pq.emplace(*it);
      if (it == vec.end()) return true;
      if (pq.empty()) {
	return false;
      }else {
	auto p = pq.top(); pq.pop();
	curLim += p.first;
      }
    }
  };

  auto chk = [&](ll lim) -> bool {
    return eqhi <= lim - bot && chk1(U, lim) && chk1(V, lim - tot);
  };


  ll ng = 0;
#if DEBUG
  ll ok = 30;
#else
  ll ok = 1e14;
#endif
  while (ng + 1 < ok) {
    ll mi = (ng + ok) / 2;
    DLOG("mi", mi);
    if (chk(mi)) ok = mi;
    else         ng = mi;
  }
  cout << ok << endl;

  return 0;
}

