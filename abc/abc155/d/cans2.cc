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

  ll N, K; cin >> N >> K;
  vector<ll> vP, vN;
  ll zero = 0;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (a == 0) zero++;
    else if (a > 0) vP.push_back(a);
    else            vN.push_back(-a);
  }
  sort(vP.begin(), vP.end());
  sort(vN.begin(), vN.end());
  ll pos = vP.size();
  ll neg = vN.size();
  if (pos * neg >= K) {
    ll hi = 1e18;
    ll lo = 0;
    while (lo+1 < hi) {
      ll mid = (lo + hi) / 2;
      ll cnt = 0;
      for (ll i = 0; i < pos; i++) {
	ll lim = (mid + (vP.at(i) - 1)) / vP.at(i);
	auto it = lower_bound(vN.begin(), vN.end(), lim);
	cnt += distance(it, vN.end());
      }
      if (cnt < K) hi = mid;
      else         lo = mid;
    }
    cout << -lo << endl;
    return 0;
  }else if (pos * neg + (pos + neg) * zero + (zero * (zero-1) / 2) >= K) {
    cout << 0 << endl;
    return 0;
  }else {
    K -= (pos * neg) + (pos + neg) * zero + (zero * (zero-1) / 2);
    DLOG("3rd pattern, K = ", K);
    ll lo = 0;
    ll hi = 1e18;
    while (lo+1 < hi) {
      ll mid = (lo + hi) / 2;
      ll cnt = 0;

      for (ll i = 0; i < pos; i++) {
	ll lim = (mid + 0) / vP.at(i);
	if (vP.at(i) <= lim) {
	  cnt += i;
	  continue;
	}
	auto it = upper_bound(vP.begin(), vP.end(), lim);
	cnt += distance(vP.begin(), it);
      }

      for (ll i = 0; i < neg; i++) {
	ll lim = (mid + 0) / vN.at(i);
	if (vN.at(i) <= lim) {
	  cnt += i;
	  continue;
	}
	auto it = upper_bound(vN.begin(), vN.end(), lim);
	cnt += distance(vN.begin(), it);
      }
      if (cnt < K) lo = mid;
      else         hi = mid;
    }
    cout << hi << endl;
    return 0;
  }

  return 0;
}

