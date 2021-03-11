#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

using namespace std::chrono;
inline double get_time_sec(void){
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

#define CONSTANT_MOD 200003

// @@ !! LIM(fft mod debug)
// --> fft f:gcd f:intDiv mod f:<< debug
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
// ---- inserted function gcd from util.cc
// g = eGCD(a, b, s, t)  --->  sa + tb = g
ll eGCD(ll a, ll b, ll& s, ll& t) {
  if (a == 0) {
    s = 0;
    t = 1;
    return b;
  }
  ll u = 0;
  ll g = eGCD(b % a, a, t, u);
  s = u - (b / a) * t;
  return g;
}

// gcd(0, x) = x, gcd(-x, y) = gcd(x, y)
ll gcd(ll a, ll b) {
  ll dummy1 = 0;
  ll dummy2 = 0;
  return eGCD(abs(a), abs(b), dummy1, dummy2);
}
// ---- end gcd
// ---- inserted function intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}

// ---- end intDiv
// ---- inserted library file mod.cc

/*
  You may want to put something like:
#define CONSTANT_MOD (1e9 + 7)
#define CONSTANT_MOD 998244353
  in the header part (outside of library paste area)
 */

struct Fp {
#if defined(CONSTANT_MOD)
  static const ll MOD = CONSTANT_MOD;
#else
  static ll MOD;
#endif

  ll val;

  /*
  ll _calc_from_ll(ll t = 0) {
    if      (t >= MOD)  return t % MOD;
    else if (t >= 0)    return t;
    else if (t >= -MOD) return t + MOD;
    else {
      ll v = t % MOD;
      if (v == 0) return 0;
      else        return v + MOD;
    }
  }
  */

  Fp(ll t = 0) : val(imod(t, MOD)) {}
  Fp(const Fp& t) : val(t.val) {}
  Fp& operator =(const Fp& t) { val = t.val; return *this; }
  Fp& operator =(ll t) { val = imod(t, MOD); return *this; }
  Fp& operator =(int t) { val = imod(t, MOD); return *this; }

  Fp& operator +=(const Fp& t) {
    val += t.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  Fp& operator -=(const Fp& t) {
    val -= t.val;
    if (val < 0) val += MOD;
    return *this;
  }

  Fp& operator *=(const Fp& t) {
    val = (val * t.val) % MOD;
    return *this;
  }

  Fp inv() const {
    if (val == 0) {
      cerr << "inv() is called for zero." << endl;
      exit(1);
    }
    ll u = 0;
    ll v = 0;
    eGCD(val, MOD, u, v);
    return Fp(u);
  }

  Fp& operator /=(const Fp& t) {
    return (*this) *= t.inv();
  }

  Fp operator +(const Fp& t) const { return Fp(val) += t; }
  Fp operator -(const Fp& t) const { return Fp(val) -= t; }
  Fp operator *(const Fp& t) const { return Fp(val) *= t; }
  Fp operator /(const Fp& t) const { return Fp(val) /= t; }
  Fp operator -() const { return Fp(-val); }

  bool operator ==(const Fp& t) const { return val == t.val; }
  bool operator !=(const Fp& t) const { return val != t.val; }
  
  operator ll() const { return val; }

};

Fp operator +(int x, const Fp& y) { return Fp(x) + y; }
Fp operator -(int x, const Fp& y) { return Fp(x) - y; }
Fp operator *(int x, const Fp& y) { return Fp(x) * y; }
Fp operator /(int x, const Fp& y) { return Fp(x) / y; }
Fp operator +(ll x, const Fp& y) { return Fp(x) + y; }
Fp operator -(ll x, const Fp& y) { return Fp(x) - y; }
Fp operator *(ll x, const Fp& y) { return Fp(x) * y; }
Fp operator /(ll x, const Fp& y) { return Fp(x) / y; }
Fp operator +(const Fp& x, int y) { return x + Fp(y); }
Fp operator -(const Fp& x, int y) { return x - Fp(y); }
Fp operator *(const Fp& x, int y) { return x * Fp(y); }
Fp operator /(const Fp& x, int y) { return x / Fp(y); }
Fp operator +(const Fp& x, ll y) { return x + Fp(y); }
Fp operator -(const Fp& x, ll y) { return x - Fp(y); }
Fp operator *(const Fp& x, ll y) { return x * Fp(y); }
Fp operator /(const Fp& x, ll y) { return x / Fp(y); }

istream& operator>> (istream& is, Fp& t) {
  ll x; is >> x;
  t = x;
  return is;
}

ostream& operator<< (ostream& os, const Fp& t) {
  os << t.val;
  return os;
}

class Comb {
  int nMax;
  vector<Fp> vFact;
  vector<Fp> vInvFact;
public:
  Comb(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact.at(0) = 1;
    for (int i = 1; i <= nMax; i++) vFact.at(i) = i * vFact.at(i-1);
    vInvFact.at(nMax) = vFact.at(nMax).inv();
    for (int i = nMax; i >= 1; i--) vInvFact.at(i-1) = i * vInvFact.at(i);
  }
  Fp fact(int n) { return vFact.at(n); }
  Fp comb(int n, int r) {
    return vFact.at(n) * vInvFact.at(r) * vInvFact.at(n-r);
  }
  // The number of permutation extracting r from n.
  Fp perm(int n, int r) {
    return vFact.at(n) * vInvFact.at(n-r);
  }
};

#if !defined(CONSTANT_MOD)
ll Fp::MOD = 1e9 + 7;
// ll Fp::MOD = 998244353;
#endif

// ---- end mod.cc
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

void showv(const auto& v) {
#if DEBUG
  for (ll i = 0; i < (ll)v.size(); i++) {
    if (v[i] == 0) continue;
    DLOG("i=", i, "v[i]=", v[i]);
  }
#endif
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll P = Fp::MOD;

  ll N; cin >> N;
  vector<ll> A(N);
  vector<ll> idx_cnt(P);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
    idx_cnt[A[i]]++;
  }
  ll g = 2; // a prime root
  // vector<Fp> pow(N);
  Fp mul = Fp(1);
  ll sz = ceil_two_power(2 * (P - 1) - 1);
  vector<Complex> vec(sz);
  for (ll i = 0; i < P - 1; i++) {
    vec[i] = idx_cnt[ll(mul)];
    mul *= g;
  }
  // DLOG("vec:");
  // showv(vec);
  double d_st = get_time_sec();
  fft_inplace(vec);
  double d_en = get_time_sec();
  cerr << "elapsed = " << d_en - d_st << endl;
  for (ll i = 0; i < (ll)vec.size(); i++) vec[i] *= vec[i];
  fft_inplace(vec, true);
  // auto cv = convolve_ll(vec, vec);
  // DLOG("cv:");
  // showv(cv);
  ll ans = 0;
  mul = Fp(1);
  for (ll i = 0; i < 2 * (P-1) - 1; i++) {
    ans += ll(mul) * ll(vec[i].real() + 0.5);
    mul *= g;
  }
  for (ll i = 0; i < N; i++) ans -= (A[i] * A[i]) % P;
  ans /= 2;
  cout << ans << endl;

  return 0;
}

