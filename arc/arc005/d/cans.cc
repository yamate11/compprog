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
  ll price = stoll(s_price);
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
  /*
  for (ll i = 0; i < 100; i++) {
    if (s0_cmb[i].size() > 0) DLOG("i=", i, "s0_cmb=", s0_cmb[i]);
  }
  */
#endif

  const ll big = 1e18;
  using sta = pair<ll, ll>;
  using stb = pair<ll, vector<ll>>; // tot_num_digits, components
  map<sta, stb> mp;
  ll x = 0;
  mp[{0,0}] = {0, vector<ll>()};
  for (ll ii = 0; ii < plen; ii++) {
    x = x * 10 + (s_price[ii] - '0');
    DLOG("x=", x);
    for (ll y = x; y >= x - 9 && y >= 0; y--) {
      DLOG("start: y=", y);
      ll p = y % 10;
      vector<stb> valsy(10, stb(big, vector<ll>()));
      for (ll q = 0; q < 10; q++) {
	ll w = q * 10 + p;
	ll len = s0_cmb[w].size();
	if (w > 0 && len == 0) continue;
	if (w > y) continue;
	ll z = (y - w) / 10;

	DLOG("z=", z, "w=", w);
	ll nmin = big;
	ll narg = -1;
	for (ll m = 0; m <= len; m++) {
	  auto it = mp.find({z, m});
	  if (it == mp.end()) continue;
	  const auto& [nd, vec] = it->second;
	  if (nd < nmin) {
	    nmin = nd;
	    narg = m;
	  }
	}
	auto myget = [&](const auto& vec, ll i) -> ll {
	  if (i < (ll)vec.size()) return vec[i];
	  else return 0;
	};
	auto update = [&](ll m1, ll m2) -> void {
	  DLOG("    update, m1=", m1, "m2=", m2);
	  const auto& [nd, vec] = mp[{z, m2}];
	  if (nd + m1 >= valsy[m1].first) return;
	  vector<ll> newvec(m1);
	  for (ll i = 0; i < m1; i++) {
	    newvec[i] = myget(vec, i) * 10 + myget(s0_cmb[w], i);
	  }
	  valsy[m1] = stb(nd + m1, move(newvec));
	  DLOG("    valsy[m1]=", valsy[m1]);
	};
	DLOG("  len=", len, "narg=", narg);
	if (narg >= 0) update(len, narg);
	for (ll m = len + 1; m < 10; m++) {
	  auto it = mp.find({z, m});
	  if (it == mp.end()) continue;
	  update(m, m);
	}
      }
      for (ll m = 0; m < 10; m++) {
	if (valsy[m].first < big) {
	  mp[{y, m}] = move(valsy[m]);
	  DLOG("  y=", y, "m=", m, "mp[{y,m}]=", mp[{y,m}]);
	}
      }
    }
  }
  DLOG("mp=", mp);
  ll score = big;
  ll arg = -1;
  for (ll m = 1; m < 10; m++) {
    auto it = mp.find({price, m});
    if (it == mp.end()) continue;
    const auto& [nd, vec] = it->second;
    ll sc = m == 1 ? nd : nd + m;
    if (score > sc) {
      score = sc;
      arg = m;
    }
  }
  const auto& [dummy, vec] = mp[{price, arg}];
  if (arg == 1) {
    cout << vec[0] << endl;
  }else {
    for (ll i = 0; i < (ll)vec.size(); i++) {
      cout << vec[i];
      if (i < (ll)vec.size() - 1) cout << "+";
      else cout << "=\n";
    }
  }

  return 0;
}

