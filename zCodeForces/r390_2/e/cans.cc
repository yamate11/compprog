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

  ll n, m; cin >> n >> m;
  vector<string> S(n);
  for (ll i = 0; i < n; i++) cin >> S[i];
  ll rr, cc; cin >> rr >> cc;
  vector<string> PP(rr);
  for (ll i = 0; i < rr; i++) cin >> PP[i];
  ll r = min(rr, n);
  ll c = min(cc, m);
  vector<string> P(r);
  for (ll y = 0; y < r; y++) P[y] = string(c, '?');
  for (ll yy = 0; yy < rr; yy++) {
    for (ll xx = 0; xx < cc; xx++) {
      ll y = yy % n;
      ll x = xx % m;
      if (PP[yy][xx] == '?') continue;
      if (P[y][x] == '?') P[y][x] = PP[yy][xx];
      else if (P[y][x] != PP[yy][xx]) {
	for (ll i = 0; i < n; i++) cout << string(m, '0') << "\n";
	return 0;
      }
    }
  }
#if DEBUG
  const ll bssize = 10*10;
#else
  const ll bssize = 400*400;
#endif
  vector<bitset<bssize>> perc(26);
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      int ch = S[i][j] - 'a';
      perc[ch].set(i * m + j);
    }
  }
  vector<bitset<bssize>> rowU(n+1), rowD(n+1), colL(m+1), colR(m+1);
  for (ll i = 0; i <= n; i++) {
    for (ll j = 0; j < i; j++) {
      for (ll k = 0; k < m; k++) {
	rowU[i].set(j * m + k);
	rowD[i].set((n - 1 - j) * m + k);
      }
    }
  }
  for (ll i = 0; i <= m; i++) {
    for (ll j = 0; j < i; j++) {
      for (ll k = 0; k < n; k++) {
	colL[i].set(k * m + j);
	colR[i].set(k * m + (m - 1) - j);
      }
    }
  }
  auto bitset_str = [&](const auto& bs) -> string {
    stringstream ss;
    for (ll y = 0; y < n; y++) {
      for (ll x = 0; x < m; x++) {
	ss << (bs.test(y * m + x) ? '1' : '0');
      }
      ss << "\n";
    }
    return ss.str();
  };
  auto sft = [&](const auto& bs, ll y, ll x) -> bitset<bssize> {
    DLOG("sft, y=", y, "x=", x, "bs=");
    DLOG(bitset_str(bs));
    bitset<bssize> bs1 = ((rowD[n - y] & bs) >> (m * y)) |
    ((rowU[y] & bs) << (m * (n - y)));
    DLOG("sft, y=", y, "x=", x, "bs1=");
    DLOG(bitset_str(bs1));
    bitset<bssize> bs2 = ((colR[m - x] & bs1) >> x) |
    ((colL[x] & bs1) << (m - x));
    DLOG("sft, y=", y, "x=", x, "bs2=");
    DLOG(bitset_str(bs2));
    return bs2;
  };
  bitset<bssize> res;
  res.set();
  for (ll y = 0; y < r; y++) {
    for (ll x = 0; x < c; x++) {
      if (P[y][x] == '?') continue;
      int ch = P[y][x] - 'a';
      auto shifted = sft(perc[ch], y, x);
      DLOG("y=", y, "x=", x, "shifted=");
      DLOG(bitset_str(shifted));
      res &= move(shifted);
      DLOG("res=");
      DLOG(bitset_str(res));
    }
  }
  cout << bitset_str(res);

  return 0;
}

