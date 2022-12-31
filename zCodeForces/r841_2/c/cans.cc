#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM(sieve forall debug)

// ---- inserted function f:itrange from util.cc

struct ItRange {
  ll st;
  ll en;

  struct Itr {
    using iterator_category = input_iterator_tag;
    using value_type = ll;
    using difference_type = ptrdiff_t;
    using reference = value_type const&;
    using pointer = value_type const*;

    ll val;

    bool operator ==(const Itr& o) const { return val == o.val; }
    bool operator !=(const Itr& o) const { return val != o.val; }

    reference operator *() const { return val; }
    pointer operator ->() const { return &val; }

    Itr& operator ++() {
      val++;
      return *this;
    }
    Itr operator ++(int) {
      Itr const tmp(*this);
      ++*this;
      return tmp;
    }

  };

  using iterator = Itr;

  ItRange(ll v_start, ll v_end): st(v_start), en(v_end) {}
  Itr begin() { return Itr({st}); }
  Itr end() { return Itr({en}); }
};

#define ALLIR(a, b) ItRange(a, b).begin(), ItRange(a, b).end()

// Imitation to Python range operator....


// ---- end f:itrange

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

vector<pair<ll, int>> _prfac_sub(ll n, const auto& it_beg, const auto& it_end) {
  vector<pair<ll, int>> res;
  ll x = n;
  for (auto it = it_beg; it != it_end and *it * *it <= x; it++) {
    ll p = *it;
    int r = 0;
    while (x % p == 0) {
      x /= p;
      r++;
    }
    if (r > 0) res.push_back(make_pair(p, r));
  }
  if (x > 1) res.push_back(make_pair(x, 1));
  return res;
}

vector<pair<ll, int>> prfac(ll n) {
  ItRange itr(2, n + 1);
  return _prfac_sub(n, itr.begin(), itr.end());
}
vector<pair<ll, int>> prfac(ll n, const vector<int>& primes) {
  return _prfac_sub(n, primes.begin(), primes.end());
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
    List of divisors
      - getDivisors(n)
      - getDivisors(n, primes)
            primes should contain prime numbers at least up to sqrt(n)
    Note: the results are NOT sorted
 */

// _gdsub ... aux function used in getDivisors()
vector<ll> _gdsub(int i, auto fs) {
  if (i == (int)fs.size()) { return vector<ll>({1}); }
  auto part = _gdsub(i+1, fs);
  auto [p, r] = fs[i];
  ll pp = p;    // pp = p^m, for m \in [1, r]
  int partOrigLen = part.size();
  for (int m = 1; m <= r; m++) {
    for (int j = 0; j < partOrigLen; j++) part.push_back(pp * part[j]);
    pp *= p;
  }
  return part;
}

vector<ll> getDivisors(ll n) { return _gdsub(0, prfac(n)); }
vector<ll> getDivisors(ll n, const vector<int>& primes) { return _gdsub(0, prfac(n, primes)); }
vector<ll> getDivisorsDivSieve(ll n, const vector<int>& divSieve) { return _gdsub(0, prfacDivSieve(n, divSieve)); }

// ---- end sieve.cc

// ---- inserted library file forall.cc

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define COUNT_BASE(rep_part, cond) ([&](){ ll ret = 0; rep_part if (cond) ret++; return ret; }())
#define COUNT(i, from, to, cond) COUNT_BASE(EX_REP_LL(i, from, to), cond)
#define COUNT_C(x, coll, cond) COUNT_BASE(EX_REP_RB(x, coll), cond)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// ---- inserted function f:<< from util.cc
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

// ---- end f:<<

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

/*
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
*/

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

#if DEBUG_LIB
  #define DLOG_LIB   DLOG
  #define DLOGK_LIB  DLOGK
  #define DLOGKL_LIB DLOGKL
#endif

// ---- end debug.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll lim = 1LL << 18;
  auto primes = sieve(1000);
  auto oddND = vector<ll>{0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400, 441, 484, 529, 576, 625, 676, 729, 784, 841, 900, 961, 1024, 1089, 1156, 1225, 1296, 1369, 1444, 1521, 1600, 1681, 1764, 1849, 1936, 2025, 2116, 2209, 2304, 2401, 2500, 2601, 2704, 2809, 2916, 3025, 3136, 3249, 3364, 3481, 3600, 3721, 3844, 3969, 4096, 4225, 4356, 4489, 4624, 4761, 4900, 5041, 5184, 5329, 5476, 5625, 5776, 5929, 6084, 6241, 6400, 6561, 6724, 6889, 7056, 7225, 7396, 7569, 7744, 7921, 8100, 8281, 8464, 8649, 8836, 9025, 9216, 9409, 9604, 9801, 10000, 10201, 10404, 10609, 10816, 11025, 11236, 11449, 11664, 11881, 12100, 12321, 12544, 12769, 12996, 13225, 13456, 13689, 13924, 14161, 14400, 14641, 14884, 15129, 15376, 15625, 15876, 16129, 16384, 16641, 16900, 17161, 17424, 17689, 17956, 18225, 18496, 18769, 19044, 19321, 19600, 19881, 20164, 20449, 20736, 21025, 21316, 21609, 21904, 22201, 22500, 22801, 23104, 23409, 23716, 24025, 24336, 24649, 24964, 25281, 25600, 25921, 26244, 26569, 26896, 27225, 27556, 27889, 28224, 28561, 28900, 29241, 29584, 29929, 30276, 30625, 30976, 31329, 31684, 32041, 32400, 32761, 33124, 33489, 33856, 34225, 34596, 34969, 35344, 35721, 36100, 36481, 36864, 37249, 37636, 38025, 38416, 38809, 39204, 39601, 40000, 40401, 40804, 41209, 41616, 42025, 42436, 42849, 43264, 43681, 44100, 44521, 44944, 45369, 45796, 46225, 46656, 47089, 47524, 47961, 48400, 48841, 49284, 49729, 50176, 50625, 51076, 51529, 51984, 52441, 52900, 53361, 53824, 54289, 54756, 55225, 55696, 56169, 56644, 57121, 57600, 58081, 58564, 59049, 59536, 60025, 60516, 61009, 61504, 62001, 62500, 63001, 63504, 64009, 64516, 65025, 65536, 66049, 66564, 67081, 67600, 68121, 68644, 69169, 69696, 70225, 70756, 71289, 71824, 72361, 72900, 73441, 73984, 74529, 75076, 75625, 76176, 76729, 77284, 77841, 78400, 78961, 79524, 80089, 80656, 81225, 81796, 82369, 82944, 83521, 84100, 84681, 85264, 85849, 86436, 87025, 87616, 88209, 88804, 89401, 90000, 90601, 91204, 91809, 92416, 93025, 93636, 94249, 94864, 95481, 96100, 96721, 97344, 97969, 98596, 99225, 99856, 100489, 101124, 101761, 102400, 103041, 103684, 104329, 104976, 105625, 106276, 106929, 107584, 108241, 108900, 109561, 110224, 110889, 111556, 112225, 112896, 113569, 114244, 114921, 115600, 116281, 116964, 117649, 118336, 119025, 119716, 120409, 121104, 121801, 122500, 123201, 123904, 124609, 125316, 126025, 126736, 127449, 128164, 128881, 129600, 130321, 131044, 131769, 132496, 133225, 133956, 134689, 135424, 136161, 136900, 137641, 138384, 139129, 139876, 140625, 141376, 142129, 142884, 143641, 144400, 145161, 145924, 146689, 147456, 148225, 148996, 149769, 150544, 151321, 152100, 152881, 153664, 154449, 155236, 156025, 156816, 157609, 158404, 159201, 160000, 160801, 161604, 162409, 163216, 164025, 164836, 165649, 166464, 167281, 168100, 168921, 169744, 170569, 171396, 172225, 173056, 173889, 174724, 175561, 176400, 177241, 178084, 178929, 179776, 180625, 181476, 182329, 183184, 184041, 184900, 185761, 186624, 187489, 188356, 189225, 190096, 190969, 191844, 192721, 193600, 194481, 195364, 196249, 197136, 198025, 198916, 199809, 200704, 201601, 202500, 203401, 204304, 205209, 206116, 207025, 207936, 208849, 209764, 210681, 211600, 212521, 213444, 214369, 215296, 216225, 217156, 218089, 219024, 219961, 220900, 221841, 222784, 223729, 224676, 225625, 226576, 227529, 228484, 229441, 230400, 231361, 232324, 233289, 234256, 235225, 236196, 237169, 238144, 239121, 240100, 241081, 242064, 243049, 244036, 245025, 246016, 247009, 248004, 249001, 250000, 251001, 252004, 253009, 254016, 255025, 256036, 257049, 258064, 259081, 260100, 261121};
  // vector<ll> oddND{0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400, 441, 484, 529, 576, 625, 676, 729, 784, 841, 900, 961, 1024, 1089, 1156, 1225, 1296, 1369, 1444, 1521, 1600, 1681, 1764, 1849, 1936, 2025, 2116, 2209, 2304, 2401, 2500, 2601, 2704, 2809, 2916, 3025, 3136, 3249, 3364, 3481, 3600, 3721, 3844, 3969, 4096, 4225, 4356, 4489, 4624, 4761, 4900, 5041, 5184, 5329, 5476, 5625, 5776, 5929, 6084, 6241, 6400, 6561, 6724, 6889, 7056, 7225, 7396, 7569, 7744, 7921, 8100, 8281, 8464, 8649, 8836, 9025, 9216, 9409, 9604, 9801, 10000, 10201, 10404, 10609, 10816, 11025, 11236, 11449, 11664, 11881, 12100, 12321, 12544, 12769, 12996, 13225, 13456, 13689, 13924, 14161, 14400, 14641, 14884, 15129, 15376, 15625, 15876, 16129, 16384, 16641, 16900, 17161, 17424, 17689, 17956, 18225, 18496, 18769, 19044, 19321, 19600, 19881, 20164, 20449, 20736, 21025, 21316, 21609, 21904, 22201, 22500, 22801, 23104, 23409, 23716, 24025, 24336, 24649, 24964, 25281, 25600, 25921, 26244, 26569, 26896, 27225, 27556, 27889, 28224, 28561, 28900, 29241, 29584, 29929, 30276, 30625, 30976, 31329, 31684, 32041, 32400, 32761, 33124, 33489, 33856, 34225, 34596, 34969, 35344, 35721, 36100, 36481, 36864, 37249, 37636, 38025, 38416, 38809, 39204, 39601, 40000, 40401, 40804, 41209, 41616, 42025, 42436, 42849, 43264, 43681, 44100, 44521, 44944, 45369, 45796, 46225, 46656, 47089, 47524, 47961, 48400, 48841, 49284, 49729, 50176, 50625, 51076, 51529, 51984, 52441, 52900, 53361, 53824, 54289, 54756, 55225, 55696, 56169, 56644, 57121, 57600, 58081, 58564, 59049, 59536, 60025, 60516, 61009, 61504, 62001, 62500, 63001, 63504, 64009, 64516, 65025, 65536, 66049, 66564, 67081, 67600, 68121, 68644, 69169, 69696, 70225, 70756, 71289, 71824, 72361, 72900, 73441, 73984, 74529, 75076, 75625, 76176, 76729, 77284, 77841, 78400, 78961, 79524, 80089, 80656, 81225, 81796, 82369, 82944, 83521, 84100, 84681, 85264, 85849, 86436, 87025, 87616, 88209, 88804, 89401, 90000, 90601, 91204, 91809, 92416, 93025, 93636, 94249, 94864, 95481, 96100, 96721, 97344, 97969, 98596, 99225, 99856, 100489, 101124, 101761, 102400, 103041, 103684, 104329, 104976, 105625, 106276, 106929, 107584, 108241, 108900, 109561, 110224, 110889, 111556, 112225, 112896, 113569, 114244, 114921, 115600, 116281, 116964, 117649, 118336, 119025, 119716, 120409, 121104, 121801, 122500, 123201, 123904, 124609, 125316, 126025, 126736, 127449, 128164, 128881, 129600, 130321, 131044, 131769, 132496, 133225, 133956, 134689, 135424, 136161, 136900, 137641, 138384, 139129, 139876, 140625, 141376, 142129, 142884, 143641, 144400, 145161, 145924, 146689, 147456, 148225, 148996, 149769, 150544, 151321, 152100, 152881, 153664, 154449, 155236, 156025, 156816, 157609, 158404, 159201, 160000, 160801, 161604, 162409, 163216, 164025, 164836, 165649, 166464, 167281, 168100, 168921, 169744, 170569, 171396, 172225, 173056, 173889, 174724, 175561, 176400, 177241, 178084, 178929, 179776, 180625, 181476, 182329, 183184, 184041, 184900, 185761, 186624, 187489, 188356, 189225, 190096, 190969, 191844, 192721, 193600, 194481, 195364, 196249, 197136, 198025, 198916, 199809};

  /*
  vector<ll> oddND;
  oddND.push_back(0);
  oddND.push_back(1);
  REP(i, 2, lim) {
    bool b = true;
    for (auto [p, r] : prfac(i, primes)) {
      if (r % 2 == 1) { b = false; break; }
    }
    if (b) oddND.push_back(i);
  }
  DLOGK(oddND);
  */
  DLOGK(SIZE(oddND));

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, A) [GirTLUm2]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [GirTLUm2]
    vector<ll> S(N + 1);
    REP(i, 0, N) S[i + 1] = S[i] ^ A[i];
    
    ll z = 64 - __builtin_clzll(N);
    ll lim0 = 1LL << z;

    ll rans = 0;
    vector<ll> e(lim0);
    e[S[0]] = 1;
    REP(j, 1, N + 1) {
      for (ll x : oddND) {
        if (x >= lim0) break;
        rans += e[S[j] ^ x];
      }
      e[S[j]]++;
    }
    ll ans = N * (N + 1) / 2 - rans;
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

