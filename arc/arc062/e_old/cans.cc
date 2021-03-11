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

ll mask4 = 0xFFFFFFFFFFLL;
ll mask1 = 0x3FFLL;

ll rot(ll c, ll e) {
  if (c == 1) { return ((e << 10) | (e >> 30)) & mask4; }
  if (c == 2) { return ((e << 20) | (e >> 20)) & mask4; }
  if (c == 3) { return ((e << 30) | (e >> 10)) & mask4; }
  assert(0);
}

ll dNum(ll e) {
  if (rot(1, e) == e) return 4;
  if (rot(2, e) == e) return 2;
  return 1;
}

ll enc(ll x1, ll x2, ll x3, ll x4) {
  ll e = (x1 << 30) | (x2 << 20) | (x3 << 10) | x4;
  return min(min(min(e, rot(1,e)), rot(2,e)), rot(3,e));
}

ll dec(ll e, ll i) { return (e >> ((3 - i) * 10)) & mask1; }

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> vec(N);
  unordered_map<ll, ll> mp, dbl;
  for (ll i = 0; i < N; i++) {
    ll x1, x2, x3, x4; cin >> x1 >> x2 >> x3 >> x4;
    ll e = enc(x1, x2, x3, x4);
    vec.at(i) = e;
    if (mp[e]++ == 0) dbl[e] = dNum(e);
  }
  ll tot = 0;
  for (ll i = 0; i < N; i++) {
    mp[vec.at(i)]--;
    ll head = vec.at(i);
    DLOG("i = ", i, "tot = ", tot);
    for (ll j = 0; j < N; j++) {
      if (j == i) continue;
      mp[vec.at(j)]--;
      ll tail = vec.at(j);
      for (ll k = 0; k < 4; k++, tail = rot(1, tail)) {
	ll cnt = 1;
	vector<ll> used;
	auto op = [&](ll p, ll q, ll r, ll s) -> bool{
	  ll e = enc(dec(head, p), dec(head, q), dec(tail, r), dec(tail, s));
	  auto it = mp.find(e);
	  if (it == mp.end()) {
	    cnt = 0;
	    return false;
	  }
	  DLOG("FOUND: ", i, j, k, it->second, dbl.at(e));
	  cnt *= it->second * dbl.at(e);
	  mp[e]--;
	  used.push_back(e);
	  return true;
	};
	op(1, 0, 1, 0) && op(2, 1, 0, 3) && op(3, 2, 3, 2) && op(0, 3, 2, 1);
	tot += cnt;
	for (ll u : used) mp[u]++;
      }
      mp[vec.at(j)]++;
    }
    mp[vec.at(i)]++;
  }

  cout << tot / 6 << endl;
  return 0;
}

