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

  ll lim = 2e5;
  ll N; cin >> N;
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  for (ll i = 0; i < N; i++) cin >> B[i];
  vector<ll> numA(lim + 1), numB(lim + 1);
  for (ll i = 0; i < N; i++) {
    numA[A[i]]++;
    numB[B[i]]++;
  }
  using sta = pair<ll, ll>;
  vector<sta> app;
  for (ll i = 1; i <= lim; i++) {
    ll nab = numA[i] + numB[i];
    if (nab > N) {
      cout << "No\n";
      return 0;
    }
    if (nab == 0) continue;
    app.emplace_back(nab, i);
  }
  sort(app.begin(), app.end(), greater<sta>());
  DLOG("app=", app);
  ll j0 = app[0].second;
  ll cov = 0;
  ll div2 = -1;
  ll type = -1;
  ll j1 = -1;
  for (auto [nab, j] : app) {
    if (cov + nab < N) {
      cov += nab;
      continue;
    }
    div2 = cov + nab - N;
    if (numB[j0] >= numA[j]) {
      type = 0;
    }else {
      assert(numA[j0] >= numB[j]);
      type = 1;
    }
    j1 = j;
    break;
  }
  vector<ll> vA(N), vB(N);
  {
    ll p = 0;
    ll q = N - 1;
    for (auto [nab, j] : app) {
      ll nA = (type == 0 && j == j1) ? numA[j] - div2 : numA[j];
      ll nB = (type == 1 && j == j1) ? numB[j] - div2 : numB[j];
      for (ll t = 0; t < nA; t++) vA[p++] = j;
      for (ll t = 0; t < nB; t++) vB[q--] = j;
    }
    if (type == 0) for (ll t = 0; t < div2; t++) vA[p++] = j1;
    if (type == 1) for (ll t = 0; t < div2; t++) vB[q--] = j1;
  }
  using stb = pair<ll, ll>;
  vector<stb> vAB;
  for (ll i = 0; i < N; i++) vAB.emplace_back(vA[i], vB[i]);
  sort(vAB.begin(), vAB.end());
  bool first = true;
  cout << "Yes\n";
  for (auto [a,b] : vAB) {
    if (first) first = false;
    else cout << " ";
    cout << b;
  }
  cout << endl;
  return 0;
}

