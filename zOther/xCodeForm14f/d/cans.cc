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

  ll N; cin >> N;
  vector<ll> H(N), H1(N);
  ll hh = 0;
  for (ll i = 0; i < N; i++) {
    cin >> H1.at(i);
    hh += H1.at(i);
    H.at(i) = hh;
  }
  using Pair = pair<ll, ll>;
  vector<vector<Pair>> se(N);
  for (ll i = 0; i < N; i++) {
    ll m, s, e; cin >> m >> s >> e; m--;
    se.at(m).emplace_back(s, e);
  }
  using Tuple = tuple<ll, ll, ll>; // s, e, h
  vector<Tuple> allse;
  for (ll i = 0; i < N; i++) {
    auto& mse = se.at(i);
    sort(mse.begin(), mse.end(),
	 [&](Pair& a, Pair& b) -> bool { return a.second < b.second; }
	 );
    ll mses = mse.size();
    for (ll j = 0; j < mses; j++) {
      ll s0, e0; tie(s0, e0) = mse.at(j);
      ll eff = 0;
      allse.emplace_back(s0, e0, H.at(eff));
      for (ll k = j+1; k < mses; k++) {
	ll s1, e1; tie(s1, e1) = mse.at(k);
	if (e0 <= s1) {
	  eff++;
	  e0 = e1;
	  allse.emplace_back(s0, e0, H.at(eff));
	}
      }
    }
  }

  sort(allse.begin(), allse.end());

#if DEBUG
  ll tmax = 900;
#else
  ll tmax = 100000;
#endif
  vector<ll> dp(tmax+1);
  ll cur = 0;
  ll idx = 0;
  for (ll t = 0; t <= tmax; t++) {
    updMax(cur, dp.at(t));
    DLOG("t=", t, "cur=", cur);
    while (idx < (ll)allse.size()) {
      ll s, e, h; tie(s, e, h) = allse.at(idx);
      if (t < s) break;
      updMax(dp.at(e), cur + h);
      DLOG("place: ", allse.at(idx), "at", e, "with", cur + h);
      idx++;
    }
  }
  cout << cur << endl;

  return 0;
}

