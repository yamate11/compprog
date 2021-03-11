#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(sieve f:power debug)
// --> sieve f:power f:<< debug
// ---- inserted library file sieve.cc

// sieve(upto) returns the list of prime numbers up to upto.
//   Size: upto(1e8).size() ... 5.7e6,  upto(1e9).size() ... 5.1e7
//   Performance: upto(1e8) ... 0.7sec,   upto(1e9) ... 9.2sec
vector<int> sieve(int upto) {
  vector<int> res;
  vector<bool> tbl(upto+1);
  ll lim = (int)(sqrt((double)upto)) + 1;
  for (int x = 2; x <= upto; x++) {
    if (tbl.at(x))  continue;
    res.push_back(x);
    if (x > lim)  continue;
    for (int y = x * 2; y <= upto; y += x) tbl.at(y) = true;
  }
  return res;
}

/*
  Prime Factorization
    Two versions:
      - prfac(n)
      - prfac(n, primes)
 */

vector<pair<ll, int>> prfac(ll n, const vector<int>& primes) {
  //      primes should contain prime numbers at least up to sqrt(n)
  vector<pair<ll, int>> res;
  ll x = n;
  for (ll p : primes) {
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

vector<pair<ll, int>> prfac(ll n) {
  return prfac(n, sieve((int)(sqrt((double)n)) + 1));
}

/*
    List of divisors
      - getDivisors(n)
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

vector<ll> getDivisors(ll n) {
  auto fs = prfac(n);
  return gdsub(0, fs.size(), fs);
}

// ---- end sieve.cc
// ---- inserted function power from util.cc
/* *** WARNING ***  
      ll x = power(10, 12) 
   does not work since it is interpreted as 
      ll x = power<int>((int)10, 12)
   Use power<ll>(10, 12) or power(10LL, 12).
 */
template<typename T>
T power(T a, ll b) {
  T twoPow = a;
  T rv(1);
  while (b > 0) {
    if (b & 1LL) rv *= twoPow;
    twoPow *= twoPow;
    b >>= 1;
  }
  return rv;
}

// ad-hoc power function
template<typename T, typename Op>
T ah_power(T a, ll b, const T& unit_t, Op op) {
  T two_pow = a;
  T ret = unit_t;
  while (b > 0) {
    if (b & 1LL) ret = op(ret, two_pow);
    two_pow = op(two_pow, two_pow);
    b >>= 1;
  }
  return ret;
}
// ---- end power
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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<ll> vec1(n), vec2(n);

  ll lim = (ll)1e7 + 10;
  vector<ll> mindiv(lim);
  iota(mindiv.begin(), mindiv.end(), 0);
  ll sqlim = ll(sqrt(lim) + 10);
  for (ll i = 2; i < sqlim; i++) {
    if (mindiv.at(i) < i) continue;
    for (ll j = i * i; j < lim; j += i) {
      if (mindiv.at(j) == j) mindiv.at(j) = i;
    }
  }
  DLOG("point 1");

  auto func = [&]() -> pair<ll, ll> {
    ll a; cin >> a;
    DLOG("a=", a);
    ll p = mindiv.at(a);
    ll q = p;
    while (true) {
      DLOG("q=", q);
      if (a % (q * p) != 0) break;
      q *= p;
    }
    if (q == a) return {-1, -1};
    return {q, a / q};
  };

  for (ll i = 0; i < n; i++) {
    auto [x, y] = func();
    vec1.at(i) = x;
    vec2.at(i) = y;
  }

  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << vec1.at(i);
  }
  cout << endl;
  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << vec2.at(i);
  }
  cout << endl;

  return 0;
}

