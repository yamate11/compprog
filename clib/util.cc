#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- util.cc


// operator<< definitions for some classes
// @@ !! FUNC BEGIN <<
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

// @@ !! FUNC END <<

// operator>> definitions for some classes
// @@ !! FUNC BEGIN >>
template <typename T1, typename T2>
istream& operator>> (istream& is, pair<T1,T2>& p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T1, typename T2, typename T3>
istream& operator>> (istream& is, tuple<T1,T2,T3>& t) {
  is >> get<0>(t) >> get<1>(t) >> get<2>(t);
  return is;
}

template <typename T1, typename T2, typename T3, typename T4>
istream& operator>> (istream& is, tuple<T1,T2,T3,T4>& t) {
  is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t);
  return is;
}

template <typename T>
istream& operator>> (istream& is, vector<T>& v) {
  for (size_t i = 0; i < v.size(); i++) { is >> v[i]; }
  return is;
}

template <typename T>
vector<T> read_vector(istream& is) {
  size_t n; cin >> n;
  return read_vector_n(is, n);
}

template <typename T>
vector<T> read_vector_n(istream& is, size_t n) {
  vector<T> ret(n);
  for (size_t i = 0; i < n; i++) cin >> ret[i];
  return ret;
}
// @@ !! FUNC END >>

/* 
   Power functions.   Time complexity is O(log b).

   If T supports "operation *=" and "cast from int 1", then
   you can use power(a, b).

   Otherwise, use ah_power(T a, ll b, T e, Op m).  e is the unit element
   of T and m : T -> T -> T is the multiplication.  
 */
// @@ !! FUNC BEGIN power
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
// @@ !! FUNC END power

// @@ !! FUNC BEGIN gcd

tuple<ll, ll, ll> mut_div(ll a, ll b, ll c, bool eff_c = true) {
  // auto [g, s, t] = mut_div(a, b, c, eff_c)
  //    If eff_c is true (default),
  //        g == gcd(|a|, |b|) and as + bt == c, if such s,t exists
  //        (g, s, t) == (-1, -1, -1)            otherwise
  //    If eff_c is false,                                 
  //        g == gcd(|a|, |b|) and as + bt == g           
  //    N.b.  gcd(0, t) == gcd(t, 0) == t.
  if (a == 0) {
    if (eff_c) {
      if (c % b != 0) return {-1, -1, -1};
      else            return {abs(b), 0, c / b};
    }else {
      if (b < 0) return {-b, 0, -1};
      else       return { b, 0,  1};
    }
  }else {
    auto [g, t, u] = mut_div(b % a, a, c, eff_c);
    // DLOGK(b%a, a, c, g, t, u);
    if (g == -1) return {-1, -1, -1};
    return {g, u - (b / a) * t, t};
  }
}

// auto [g, s, t] = eGCD(a, b)  --->  sa + tb == g == gcd(|a|, |b|)
//    N.b.  gcd(0, t) == gcd(t, 0) == t.
tuple<ll, ll, ll> eGCD(ll a, ll b) { return mut_div(a, b, 0, false); }

pair<ll, ll> crt_sub(ll a1, ll x1, ll a2, ll x2) {
  // DLOGKL("crt_sub", a1, x1, a2, x2);
  a1 = a1 % x1;
  a2 = a2 % x2;
  auto [g, s, t] = mut_div(x1, -x2, a2 - a1);
  // DLOGK(g, s, t);
  if (g == -1) return {-1, -1};
  ll z = x1 / g * x2;
  // DLOGK(z);
  s = s % (x2 / g);
  ll r = (x1 * s + a1) % z;
  // DLOGK(r);
  if (r < 0) r += z;
  // DLOGK(r);
  return {r, z};
};

// Chinese Remainder Theorem
//
//    r = crt(a1, x1, a2, x2)
//    ==>   r = a1 (mod x1);  r = a2 (mod x2);  0 <= r < lcm(x1, x2)
//    If no such r exists, returns -1
//    Note: x1 and x2 should >= 1.  a1 and a2 can be negative or zero.
//
//    r = crt(as, xs)
//    ==>   for all i. r = as[i] (mod xs[i]); 0 <= r < lcm(xs)
//    If no such r exists, returns -1
//    Note: xs[i] should >= 1.  as[i] can be negative or zero.
//          It should hold: len(xs) == len(as) > 0

ll crt(ll a1, ll x1, ll a2, ll x2) { return crt_sub(a1, x1, a2, x2).first; }

ll crt(vector<ll> as, vector<ll> xs) {
  // DLOGKL("crt", as, xs);
  assert(xs.size() == as.size() && xs.size() > 0);
  ll r = as[0];
  ll z = xs[0];
  for (size_t i = 1; i < xs.size(); i++) {
    // DLOGK(i, r, z, as[i], xs[i]);
    tie(r, z) = crt_sub(r, z, as[i], xs[i]);
    // DLOGK(r, z);
    if (r == -1) return -1;
  }
  return r;
}

// @@ !! FUNC END gcd

// @@ !! FUNC BEGIN updMaxMin
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
// @@ !! FUNC END updMaxMin

// @@ !! FUNC BEGIN intDiv
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
//   Just a note.  For d \in Z and t \in R,
//       d < t <=> d < ceil(t),     d <= t <=> d <= floor(t),
//       d > t <=> d > floor(t),    d >= t <=> d >= ceil(t).

// @@ !! FUNC END intDiv

// @@ !! FUNC BEGIN mex

// E.g.,  vector<int> v1({2,0,3});  assert(mex(v1.begin(), v1.end()) == 1);
template<class ForwardIt>
int mex(ForwardIt first, ForwardIt last) {
  int sz = 1024;
  vector<bool> seen(sz);
  for (ForwardIt it = first; it != last; it++) {
    if (*it >= sz) {
      while (*it >= sz) sz *= 2;
      seen.resize(sz);
    }
    seen[*it] = true;
  }
  for (ll i = 0; i < sz; i++) if (!seen[i]) return i;
  return sz;
}

// @@ !! FUNC END   mex

// @@ !! FUNC BEGIN shortVector

// Vector for small integers such as 0..3, fit in a small bit width,
// represented with a long long int.
//   - val should be in [0, 1LL << bit_width)
//   - index should be in [0, 1LL << (64 / bit_width))

// bit_width, short_vector, index, value
void sv_set(int bw, ll& sv, int idx, int val) {
  ll mask = (1LL << bw) - 1;
  sv = sv & ~(mask << (idx * bw));
  sv = sv | (val << (idx * bw));
}

ll sv_get(int bw, ll sv, int idx) {
  ll mask = (1LL << bw) - 1;
  return (sv >> (idx * bw)) & mask;
}

string sv_show(int bw, ll sv, ll len = -1) {
  ll mask = (1LL << bw) - 1;
  ll bnd = len < 0 ? 64 : len;
  string ret = "[";
  for (ll i = 0; i < bnd; i++) {
    if (len < 0 && sv == 0) break;
    if (i > 0) ret += ", ";
    ret += to_string(sv & mask);
    sv >>= bw;
  }
  ret += "]";
  return ret;
}
// @@ !! FUNC END   shortVector

// @@ !! FUNC BEGIN perfmeas

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// @@ !! FUNC END perfmeas

// @@ !! END ---- util.cc

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
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))




int main() {

  random_device rd;
  mt19937 rng(rd());

  assert(divFloor( 18,  3) ==  6);
  assert(divCeil(  18,  3) ==  6);
  assert(divFloor(-18,  3) == -6);
  assert(divCeil( -18,  3) == -6);
  assert(divFloor( 18, -3) == -6);
  assert(divCeil(  18, -3) == -6);
  assert(divFloor(-18, -3) ==  6);
  assert(divCeil( -18, -3) ==  6);

  assert(divFloor( 19,  3) ==  6);
  assert(divCeil(  19,  3) ==  7);
  assert(divFloor(-19,  3) == -7);
  assert(divCeil( -19,  3) == -6);
  assert(divFloor( 19, -3) == -7);
  assert(divCeil(  19, -3) == -6);
  assert(divFloor(-19, -3) ==  6);
  assert(divCeil( -19, -3) ==  7);

  assert(divFloor( 20,  3) ==  6);
  assert(divCeil(  20,  3) ==  7);
  assert(divFloor(-20,  3) == -7);
  assert(divCeil( -20,  3) == -6);
  assert(divFloor( 20, -3) == -7);
  assert(divCeil(  20, -3) == -6);
  assert(divFloor(-20, -3) ==  6);
  assert(divCeil( -20, -3) ==  7);

  {
    assert(imod( 3,  7) ==  3);
    assert(imod(-3,  7) ==  4);
    assert(imod( 3, -7) == -4);
    assert(imod(-3, -7) == -3);
    assert(imod( 100,  7) ==  2);
    assert(imod(-100,  7) ==  5);
    assert(imod( 100, -7) == -5);
    assert(imod(-100, -7) == -2);
    assert(imod(0, 5) == 0);
    assert(imod(0, -5) == 0);
    assert(imod( 9, 1) == 0);
    assert(imod( 9, -1) == 0);
    assert(imod(-9, 1) == 0);
    assert(imod(-9, -1) == 0);
    assert(imod( 22,  11) == 0);
    assert(imod( 22, -11) == 0);
    assert(imod(-22,  11) == 0);
    assert(imod(-22, -11) == 0);
  }

  {
    vector<pair<ll, ll>> v({
	{5,8},{540,150},{-70,105},{14,-30},{-33,24},{-35,-99}
	,{0,6},{6,0},{0,-6},{-6,0},{0,0}});
    for (auto [a, b] : v) {
      auto [g, s, t] = eGCD(a, b);
      // DLOGK(g, gcd(a, b), a, b, s, t, a*s + b*t);
      assert(g == gcd(a, b) && a * s + b * t == g);
    }
  }
  {
    for (ll x1 = 1; x1 <= 12; x1++) {
      for (ll x2 = 1; x2 <= 12; x2++) {
	vector rr(x1, vector(x2, -1));
	ll lcm = x1 * x2 / gcd(x1, x2);
	for (ll r = 0; r < lcm; r++) rr[r % x1][r % x2] = r;
	for (ll a1 = 0; a1 < x1; a1++) {
	  for (ll a2 = 0; a2 < x2; a2++) {
	    for (ll c1 = -2; c1 <= 2; c1++) {
	      for (ll c2 = -2; c2 <= 2; c2++) {
		ll aa1 = a1 + c1 * x1;
		ll aa2 = a2 + c2 * x2;
		assert(crt(aa1, x1, aa2, x2) == rr[a1][a2]);
	      }
	    }
	  }
	}
      }
    }
    
    vector<ll> rcs({0,1,53,37193,409287402,32123784915});
    vector<ll> xs({  2,4,  8,  3,5, 6,15,24,30});
    for (ll rc : rcs) {
      vector<ll> as;
      for (ll x : xs) as.push_back(rc % x);
      ll r = crt(as, xs);
      // DLOGK(as, xs);
      assert(r >= 0);
      for (ll i = 0; i < (ll)as.size(); i++) {
	assert((r - as[i]) % xs[i] == 0);
      }
    }
    vector<ll> as1({1,1,1,1,1,4,1,1,1});
    assert(crt(as1, xs) == -1);
  }

  {
    uniform_int_distribution<ll> dist9(1, (ll)1e9);
    uniform_int_distribution<ll> dist9z(-(ll)1e9, (ll)1e9);
    uniform_int_distribution<ll> dist18(1, (ll)1e18);
    for (ll i = 0; i < 1000; i++) {
      ll r0 = dist18(rng);
      ll x1 = dist9(rng);
      ll x2 = dist9(rng);
      ll a1 = r0 % x1;
      ll a2 = r0 % x2;
      a1 += dist9z(rng) * x1;
      a2 += dist9z(rng) * x2;
      ll r = crt(a1, x1, a2, x2);
      bool b = r >= 0 && (r - a1) % x1 == 0 && (r - a2) % x2 == 0;
      if (!b) {
	DLOGK(r, a1, x1, a2, x2);
	assert(false);
      }
    }
  }


  assert(power(10LL, 12) == (ll)1e12);
  // power<Fp> is tested in mod.cc
  using T01 = vector<int>;
  int N01 = 5;
  auto comp = [&](const T01& f, const T01& g) -> T01 {
    T01 ret(N01);
    for (int i = 0; i < N01; i++) ret.at(i) = f.at(g.at(i));
    return ret;
  };
  T01 unit01({0,1,2,3,4});
  T01 vec01({1,2,3,4,0});
  assert(ah_power(vec01, 0, unit01, comp) == unit01);
  assert(ah_power(vec01, 1, unit01, comp) == vec01);
  assert(ah_power(vec01, 2, unit01, comp) == T01({2,3,4,0,1}));
  assert(ah_power(vec01, 1000000000003LL, unit01, comp) == T01({3,4,0,1,2}));

  {
    set<ll> s1({5, 2, 4});
    set<ll, greater<ll>> s2({5, 2, 4});
    stringstream ss;
    ss << s1 << " " << s2;
    assert(ss.str() == "{2, 4, 5} {5, 4, 2}");
  }

  {
    vector<ll> v1(3000);
    iota(v1.begin(), v1.end(), 0);
    assert(mex(v1.begin(), v1.end()) == 3000);
    v1[2500] = 500;
    assert(mex(v1.begin(), v1.end()) == 2500);
    v1[100] = 500;
    assert(mex(v1.begin(), v1.end()) == 100);
    v1[0] = 500;
    assert(mex(v1.begin(), v1.end()) == 0);
  }

  {
    ll sv = 0;
    for (ll i = 0; i < 9; i++) sv_set(2, sv, i, i % 4);
    assert(sv_show(2, sv, 9) == "[0, 1, 2, 3, 0, 1, 2, 3, 0]");
    assert(sv_show(2, sv) == "[0, 1, 2, 3, 0, 1, 2, 3]");
    for (ll i = 0; i < 6; i++) {
      sv_set(2, sv, i, (sv_get(2, sv, i) + 1) % 4);
    }
    assert(sv_show(2, sv, 9) == "[1, 2, 3, 0, 1, 2, 2, 3, 0]");
  }

  cout << "Test done." << endl;
  return 0;
}
