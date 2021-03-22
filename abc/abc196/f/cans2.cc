#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(fft debug)
// --> fft f:<< debug
// ---- inserted library file fft.cc

#define RERROR_LONGDOUBLE 0
#if RERROR_LONGDOUBLE
using Real = long double;
#define G_PI 3.141592653589793238462643383279502884L
#else
using Real = double;
#define G_PI 3.14159265358979323846
#endif
using Complex = complex<Real>;

int ceil_two_power_log(ll n) {
  int k = 31 - __builtin_clz(n);
  if ((1 << k) == n) return k;
  else               return k + 1;
}

int ceil_two_power(ll n) {
  return 1 << ceil_two_power_log(n);
}

void fft_inplace(vector<Complex>& vec, bool inverse = false) {
  int n = ceil_two_power_log(vec.size());
  int sz = 1 << n;
  if (sz != (int)vec.size()) vec.resize(sz);

  // order replace
  for (int i = 0; i < sz; i++) {
    int j = 0;
    for (int p = 0; p < n; p++) if ((i >> p) & 1) j |= (1 << (n-1 - p));
    if (i < j) swap(vec[i], vec[j]);
  }

  // butterfly
  int num_block = sz / 2;
  int block_size_half = 1;
  for (int i = 0; i < n; i++) {
    // Performance notice:  If you put polar() into the k-loop,
    // it makes things slower significantly (around 10 times).
    Real argn = G_PI / block_size_half;
    Complex wn = polar(Real(1.0), inverse ? -argn : argn);
    for (int j = 0; j < num_block; j++) {
      int block_top = 2 * j * block_size_half;
      Complex wk = 1;
      for (int k = 0; k < block_size_half; k++) {
	int p = block_top + k;
	int q = block_top + k + block_size_half;
	Complex x = vec[p] + wk * vec[q];
	Complex y = vec[p] - wk * vec[q];
	vec[p] = x;
	vec[q] = y;
	wk *= wn;
      }
    }
    num_block /= 2;
    block_size_half *= 2;
  }

  if (inverse) for (int i = 0; i < sz; i++) vec[i] /= sz;
}

template<typename T>
vector<Complex> fft(vector<T> vec, bool inverse = false) {
  vector<Complex> vec1(vec.size());
  for (int i = 0; i < (int)vec.size(); i++) {
    vec1[i] = Complex(vec[i]);
  }
  fft_inplace(vec1, inverse);
  return vec1;
}

// x <- x `conv` y
void convolve_inplace(vector<Complex>& x, vector<Complex>& y) {
  ll n = ceil_two_power(x.size() + y.size() - 1);
  x.resize(n);
  y.resize(n);
  fft_inplace(x);
  fft_inplace(y);
  for (ll i = 0; i < n; i++) x[i] *= y[i];
  fft_inplace(x, true);
}

vector<ll> convolve_ll(const vector<ll>& x, const vector<ll>& y) {
  int sz = x.size() + y.size() - 1;
  int n = ceil_two_power(sz);
  vector<Complex> cx;
  vector<Complex> cy;
  cx.reserve(n);
  cy.reserve(n);
  for (ll t : x) cx.emplace_back(t);
  for (ll t : y) cy.emplace_back(t);
  convolve_inplace(cx, cy);
  vector<ll> ret(sz);
  for (int i = 0; i < sz; i++) ret[i] = ll(cx[i].real() + 0.5);
  return ret;
}


// ---- end fft.cc
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

  string S, T; cin >> S >> T;
  ll szS = S.size();
  ll szT = T.size();
  vector<Complex> v1(szS), v2(szT), v3(szS), v4(szT);
  for (ll j = 0; j < szS; j++) {
    v1[j] = S[j] - '0';
    v3[j] = Complex(1) - v1[j];
  }
  for (ll j = 0; j < szT; j++) {
    v4[j] = T[szT-1 - j] - '0';
    v2[j] = Complex(1) - v4[j];
  }
  DLOGK(v1, v2, v3, v4);
  convolve_inplace(v1, v2);
  convolve_inplace(v3, v4);
  DLOGK(v1);
  DLOGK(v3);
  ll ans = LLONG_MAX;
  for (ll j = 0; j < szS - szT + 1; j++) {
    ll x = llround(v1[szT - 1 + j].real() + v3[szT - 1 + j].real());
    ans = min(ans, x);
  }
  cout << ans << endl;

  return 0;
}

