#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Skelton for Interactive Problems

  (1) Edit the following member functions in JudgeRem class 
      They are for adjusting the interface.
      - constructor
      - ask()   (or ask_q() and ask_a())
      - answer()
  (2) Write function game().  This is for writing your algorithm.
  (3) For hand debugging, compile and run.
  (4) For automated testing, do the following
  (4.1) Set the value of macro JUDGE_LOC to 1.
  (4.2) Edit JudgeLoc struct

  Testing
    (*) ./cans
       This is the true program.  You can manually input data into its
       stdin.
    (**) ./cans judge < din.txt
       One-shot testing.  The format of din.txt is not defined by the
       writer of the question.  You can freely set the spec for the input
       file so that JudgeLoc() can read the input.
    (***) cmpNaive -i -e -p './cans judge'
       cmpNaive testing.  Runs multiple times against test files
       generated by `gen' script.  A test run is regarded as a success
       if its exit code is zero.
 */

// @@ !! LIM(sieve debug)
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

// When you debug with JudgeLoc class, the value should be 1
// #define JUDGE_LOC 0
#define JUDGE_LOC 1

const string end_mark("^__=end=__^");

struct SolveExc : exception {};

void do_game(bool is_judge);

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  bool is_judge = false;
  if (argc == 2) {
    if (strcmp(argv[1], "judge") == 0) {
      is_judge = true;
    }else if (strcmp(argv[1], "skip") == 0) {
      return 0;
    }else {
      cerr << "Unknown argument" << endl;
      exit(1);
    }
  }
    
  try {
    do_game(is_judge);
  }catch (const SolveExc& e) {
  }
  return 0;
}

/* External variables, typically for values given as initial input. */
ll N, M;

struct Judge {
  virtual bool ask(ll h, ll w, ll i1, ll j1, ll i2, ll j2) = 0;
  virtual void answer(ll ans) = 0;

  // Call ac() in JudgeLoc when the answer is correct.
  void ac() {
    cout << "AC" << endl;
    throw SolveExc();
  }

  // Call wa() in JudgeLoc when the answer is not correct.
  void wa() {
    cout << "WA" << endl;
    exit(1);
  }
};

#if JUDGE_LOC
// This is a class for local testing.
struct JudgeLoc : Judge {
  ll r, c;
  ll rem;
  ll expected;

  JudgeLoc() {
    // Typically, read the question for testing from stdin
    cin >> N >> M >> r >> c;
    rem = 3 * llround(ceil(log(N + M) / log(2)));
    expected = getDivisors(N / r).size() * getDivisors(M / c).size();
  }

  // Returns the answer for a query x.
  bool ask(ll h, ll w, ll i1, ll j1, ll i2, ll j2) {
    if (rem <= 0) {
      DLOG("exceeded");
      wa();
    }
    rem--;
    if (i1 <= 0 || j1 <= 0 || i2 <= 0 || j2 <= 0 ||
        i1 + h > N+1 || j1 + w > M+1 || i2 + h > N+1 || j2 + w > M+1) {
      DLOGKL("out of range", h, w, i1, j1, i2, j2);
      wa();
    }
    return (i2 - i1) % r == 0 && (j2 - j1) % c == 0;
  }

  // Always call ac() or wa().
  void answer(ll ans) {
    if (ans == expected) ac();
    else {
      DLOG("fin ans is incorrect");
      wa();
    }
  }
};
#endif // JUDGE_LOC

// The class that implements interfaces to the external judge program.
struct JudgeRem : Judge {

  // Read initial information in the constructor.  
  // Typically you need to read a parameter
  // such as the size of the question.  You may want to define a global
  // variable, such as N, just the above of line of "struct Judge{".
  JudgeRem() {
    cin >> N >> M;
  }

  // Asks for and receives information
  bool ask(ll h, ll w, ll i1, ll j1, ll i2, ll j2) {
    cout << "? " << h << " " << w << " " << i1 << " " << j1 << " "
         << i2 << " " << j2 << endl;
    ll ret; cin >> ret;
    return ret == 1;
  }
  /*
  An example:
    bool ask(ll x, ll y) {
      cout << "? " << x << " " << y << endl;
      string ret; cin >> ret;
      return ret == "YES";
    }
  */

  // Final output.  Typically prepended by "! " and followed by endl
  // You need to throw SolveExc() at the end of the function.
  void answer(ll ans) {
    cout << "! " << ans << endl;
    throw SolveExc();
  }

};

// You write your algorithm using judge.ask()
// (or judge.ask_a() and judge.ask_q()).
// Note that you need to call judge.answer() to correctly terminate
// the program.
void game(Judge&& judge) {

  auto func = [&](ll x, ll y, ll dir) -> ll {
    auto dividable = [&](ll p) -> bool {
      auto check = [&](ll sz, ll c1, ll c2) -> bool {
        DLOGKL("check", sz, c1, c2);
        ll rsz = sz * (x / p);
        ll m1 = c1 * (x / p);
        ll m2 = c2 * (x / p);
        DLOGKL("asking", rsz, m1, m2, y, dir);
        if (dir == 0) return judge.ask(rsz, y, 1+m1, 1, 1+m2, 1);
        else          return judge.ask(y, rsz, 1, 1+m1, 1, 1+m2);
      };

      ll h0 = 1LL << (62 - __builtin_clzll(p));
      DLOGKL("in dividable", p, h0);
      for (ll h = h0; h >= 1; h /= 2) if (!check(h, 0, h)) return false;
      if (h0 * 2 < p) if (!check(p - h0 * 2, 0, h0 * 2)) return false;
      return true;
    };

    for (auto [p, r] : prfac(x)) {
      for (ll i = 0; i < r; i++) if (dividable(p)) x /= p;
    }
    return x;
  };

  ll x = func(N, M, 0);
  ll y = func(M, N, 1);
  ll xx = N / x;
  ll yy = M / y;
  ll ans = getDivisors(xx).size() * getDivisors(yy).size();
  judge.answer(ans);
}

// You should not edit this function.
void do_game(bool is_judge) {
#if JUDGE_LOC
  if (is_judge) game(JudgeLoc());
  else          game(JudgeRem());
#else
  game(JudgeRem());
#endif
}


