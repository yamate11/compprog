#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(sieve debug sieve)
// --> sieve f:<< debug
// ---- inserted library file sieve.cc

// sieve(upto) returns the list of prime numbers up to upto.
//   Size: upto(1e8).size() ... 5.7e6,  upto(1e9).size() ... 5.1e7
//   Performance: upto(1e8) ... 0.7sec,   upto(1e9) ... 9.2sec
vector<int> sieve(int upto) {
  vector<int> res;
  vector<bool> tbl(upto+1);
  ll lim = (int)(sqrt((double)upto)) + 1;
  for (int x = 2; x <= upto; x++) {
    if (tbl[x]) continue;
    res.push_back(x);
    if (x <= lim) {
      for (int y = x * x; y <= upto; y += x) tbl[y] = true;
    }
  }
  return res;
}

vector<int> divisorSieve(int upto) {
  vector<int> tbl(upto+1);
  iota(tbl.begin(), tbl.end(), 0);
  ll lim = (int)(sqrt((double)upto)) + 1;
  for (int x = 2; x <= lim; x++) {
    if (tbl[x] < x) continue;
    for (int y = x * x; y <= upto; y += x) if (tbl[y] == y) tbl[y] = x;
  }
  return tbl;
}

/*
  Prime Factorization
    Two versions:
      - prfac(n)
      - prfac(n, primes)
            primes should contain prime numbers at least up to sqrt(n)
 */

const vector<int> dummy_primes;

vector<pair<ll, int>> prfac(ll n, const vector<int>& primes = dummy_primes) {
  vector<int> tmp_primes;
  if (primes.size() == 0) {
    tmp_primes = sieve((int)sqrt((double)n) + 1);
  }
  const vector<int>& prms = primes.size() == 0 ? tmp_primes : primes;

  vector<pair<ll, int>> res;
  ll x = n;
  for (ll p : prms) {
    if (x == 1)  break;
    if (p * p > x)  break;
    if (x % p != 0)  continue;
    int c = 1;
    x /= p;
    while (x % p == 0) {
      c += 1;
      x /= p;
    }
    res.push_back(make_pair(p, c));
  }
  if (x != 1)  res.push_back(make_pair(x, 1));
  return res;
}

vector<pair<int, int>> prfacDivSieve(int n, const vector<int>& divSieve) {
  vector<pair<int, int>> ret;
  int p = -1;
  int r = 0;
  while (n > 1) {
    int q = divSieve[n];
    if (p == q) {
      r++;
    }else {
      if (p > 0) ret.emplace_back(p, r);
      p = q;
      r = 1;
    }
    n /= p;
  }
  if (p > 0) ret.emplace_back(p, r);
  return ret;
}

/*
vector<pair<ll, int>> prfac(ll n) {
  return prfac(n, sieve((int)(sqrt((double)n)) + 1));
}
*/

/*
    List of divisors
      - getDivisors(n)
      - getDivisors(n, primes)
            primes should contain prime numbers at least up to sqrt(n)
    Note: the results are NOT sorted
 */

// gdsub ... aux function used in getDivisors()
vector<ll> gdsub(int i, int n, auto fs) {
  if (i == n) { return vector<ll>({1}); }
  auto part = gdsub(i+1, n, fs);
  ll p  = fs.at(i).first;
  int r = fs.at(i).second;
  ll pp = p;    // pp = p^m, for m \in [1, r]
  int partOrigLen = part.size();
  for (int m = 1; m <= r; m++) {
    for (int j = 0; j < partOrigLen; j++) {
      part.push_back(pp * part.at(j));
    }
    pp *= p;
  }
  return part;
}

vector<ll> getDivisors(ll n, const vector<int>& primes = dummy_primes) {
  auto fs = prfac(n, primes);
  return gdsub(0, fs.size(), fs);
}

vector<ll> getDivisorsDivSieve(ll n, const vector<int>& divSieve) {
  auto fs = prfacDivSieve(n, divSieve);
  return gdsub(0, fs.size(), fs);
}


// ---- end sieve.cc
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
void dbgLog(bool with_nl, Head&& head) {
  cerr << head;
  if (with_nl) cerr << endl;
}

template <class Head, class... Tail>
void dbgLog(bool with_nl, Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(with_nl, forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DLOGNNL(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL_LIB(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)
#define DUP9(E1,...)   DUP1(E1), DUP8(__VA_ARGS__)
#define DUP10(E1,...)   DUP1(E1), DUP9(__VA_ARGS__)
#define DUP11(E1,...)   DUP1(E1), DUP10(__VA_ARGS__)
#define DUP12(E1,...)   DUP1(E1), DUP11(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP12, DUP11, DUP10, DUP9, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

// ---- end debug.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<ll> W, H, C;
  map<ll, vector<ll>> mpW, mpH;
  map<ll, map<ll, ll>> szWH;
  for (ll i = 0; i < n; i++) {
    ll w, h, c; cin >> w >> h >> c;
    W.push_back(w);
    H.push_back(h);
    C.push_back(c);
    mpW[w].push_back(h);
    mpH[h].push_back(w);
    szWH[w][h] = c;
  }
  vector<vector<ll>> aH, aW;
  for (auto& [w, hs] : mpW) {
    sort(hs.begin(), hs.end());
    aH.push_back(hs);
  }
  for (auto& [h, ws] : mpH) {
    sort(ws.begin(), ws.end());
    aW.push_back(ws);
  }
  auto checkSame = [&](const auto& v) -> bool {
    for (ll i = 1; i < (ll)v.size(); i++) {
      if (v[0] != v[i]) return false;
    }
    return true;
  };

  if (!checkSame(aH) || !checkSame(aW)) {
    cout << 0 << endl;
    return 0;
  }
  vector<vector<ll>> cH, cW;
  vector<vector<ll>> vvW;
  for (ll w : aW[0]) {
    vector<ll> v;
    ll g = 0;
    for (ll h : aH[0]) g = gcd(g, szWH[w][h]);
    for (ll h : aH[0]) v.push_back(szWH[w][h] / g);
    vvW.push_back(move(v));
  }
  vector<vector<ll>> vvH;
  for (ll h : aH[0]) {
    vector<ll> v;
    ll g = 0;
    for (ll w : aW[0]) g = gcd(g, szWH[w][h]);
    for (ll w : aW[0]) v.push_back(szWH[w][h] / g);
    vvH.push_back(move(v));
  }
  if (!checkSame(vvW) || !checkSame(vvH)) {
    cout << 0 << endl;
    return 0;
  }
  ll w0 = *aW[0].begin();
  ll h0 = *aH[0].begin();
  ll d = szWH[w0][h0] / (vvW[0][0] * vvH[0][0]);
  ll ans = getDivisors(d).size();
  cout << ans << endl;

  return 0;
}

