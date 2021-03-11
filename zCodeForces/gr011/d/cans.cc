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

  ll n; cin >> n;
  vector<ll> vec(n);
  for (ll i = 0; i < n; i++) cin >> vec[i];

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  vector<vector<ll>> operations;

  auto search = [&](ll x, ll y) -> pair<ll, ll> {
    ll p = -1, q = -1;
    for (ll i = 0; i < n; i++) {
      if (vec[i] == x || vec[i] == y) {
	if (p == -1) p = i;
	else q = i;
      }
    }
    return {p, q};
  };

  auto getmid = [&](ll tot, ll lenL, ll lenR) -> vector<ll> {
    if (lenL + lenR == tot) {
      return vector<ll>({lenL, lenR});
    }else {
      return vector<ll>({lenL, tot - (lenL + lenR), lenR});
    }
  };
  auto apply = [&](const auto& op) -> void {
    vector<ll> v(vec);
    ll m = op.size();
    ll asz = 0;
    ll k = 0;
    for (ll i = m-1; i >= 0; i--) {
      asz += op[i];
      for (ll j = 0; j < op[i]; j++) {
	vec[k++] = v[n - asz + j];
      }
    }
  };
  {
    auto [p, q] = search(1, n);
    vector<ll> init = getmid(n, p + 1, n - q);
    operations.push_back(init);
    apply(init);
  }
  auto theOp = [&](ll m0, auto& vv) -> vector<ll> {
    vector<ll> ret;
    for (ll i = 0; i < m0; i++) ret.push_back(1);
    for (ll i = 0; i < (ll)vv.size(); i++) ret.push_back(vv[i]);
    for (ll i = 0; i < m0; i++) ret.push_back(1);
    DLOG("theOp m0=", m0, "vv=", vv, "ret=", ret);
    return ret;
  };

  auto func = [&](auto rF, ll m0) -> void {
    ll m1 = n - m0 + 1;
    ll k0 = m0 + 1;
    ll k1 = m1 - 1;
    if (k0 >= k1) return;
    auto [p, q] = search(k0, k1);
    DLOG("func p=", p, "q=", q, "vec=", vec, "m0=", m0);
    if ((vec[0] == 1 && vec[p] == k1) || (vec[0] == n && vec[p] == k0)) {
      vector<ll> mid({n - m0 * 2});
      auto op = theOp(m0, mid);
      operations.push_back(op);
      apply(op);
      DLOG("func need swap, op=", op, "vec=", vec);
    }
    auto mid = getmid(n - m0 * 2, p + 1 - m0, n - q - m0);
    auto op = theOp(m0, mid);
    operations.push_back(op);
    apply(op);
    DLOG("func main, op=", op, "vec=", vec);
    rF(rF, m0 + 1);
  };
  func(func, 1);
  if (vec[0] == n) {
    vector<ll> op(n);
    for (ll i = 0; i < n; i++) op[i] = 1;
    operations.push_back(op);
    apply(op);
  }
  
  cout << operations.size() << "\n";
  for (const auto& op : operations) {
    cout << op.size();
    for (ll x : op) {
      cout << " " << x;
    }
    cout << "\n";
  }

  return 0;
}

