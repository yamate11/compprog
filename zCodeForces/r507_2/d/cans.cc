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

// When you debug with JudgeLoc class, the value should be 1
// #define JUDGE_LOC 0
#define JUDGE_LOC 1

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

const string end_mark("^__=end=__^");

struct SolveExc : exception {};

void do_game(bool is_judge);

random_device rand_dev;

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
ll N, K, cur, num_asked;
ll thr = 100;

struct Judge {
  virtual bool ask(ll l, ll r) = 0;
  virtual void answer() = 0;

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
  mt19937 rng;
  ll num_asked;
  bool finished;
  ll dir;
  ll cur;

  JudgeLoc() : rng(rand_dev()), num_asked(0), finished(false), dir(1) {
    cin >> N >> K >> thr;
    uniform_int_distribution<ll> dist(1, N);
    cur = dist(rng);
  }

  // Returns the answer for a query x.
  bool ask(ll l, ll r) {
    cur += dir * K;
    if (cur < 1) {
      dir = 1;
      cur = 1;
    }
    if (cur > N) {
      dir = -1;
      cur = N;
    }
    if (l < 1 || N < l || r < 1 || N < r) wa();
    if (++num_asked > 4500) {
      DLOG("exceeded");
      wa();
    }
    if (l <= cur && cur <= r) {
      if (l == r) {
        finished = true;
        DLOGKL("finished", num_asked, l);
        cerr << "num_asked = " << num_asked << endl;
      }
      return true;
    }
    else {
      DLOGK(l, r);
      return false;
    }
    // An example for Guessing Number Game.
    /*
    if (x < expected)      return 1;
    else if (x > expected) return -1;
    else                   return 0;
    return ask_a_t();
    */
  }

  // Always call ac() or wa().
  void answer() {
    if (finished) ac();
    else wa();
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
    cin >> N >> K;
  }

  // Asks for and receives information
  bool ask(ll l, ll r) {
    cout << l << " " << r << endl;
    string s; cin >> s;
    if (s == "Yes") return true;
    else if (s == "No") return false;
    else if (s == "Bad") throw SolveExc();
    assert(0);
  }

  // Final output.  Typically prepended by "! " and followed by endl
  // You need to throw SolveExc() at the end of the function.
  void answer() {
    throw SolveExc();
  }

};

// You write your algorithm using judge.ask()
// (or judge.ask_a() and judge.ask_q()).
// Note that you need to call judge.answer() to correctly terminate
// the program.
void game(Judge&& judge) {
  mt19937 rng(rand_dev());
  ll left = 1;
  ll right = N;
  auto widen = [&]() -> void {
    ll mid = (left + right) / 2;
    left -= mid - left;
    if (left < 1) left = 1;
    right += right - mid;
    if (right > N) right = N;
  };
  DLOGK(thr);
  while (true) {
    if (right - left < thr) {
      ll x = max(1LL, left - K);
      ll y = min(N, right + K);
      uniform_int_distribution<ll> dist(x, y);
      
      ll v = dist(rng);
      if (judge.ask(v, v)) judge.answer();
      DLOG("challenged and failed");
      if (!judge.ask(left, right)) {
        DLOG("widen after challenge");
        widen();
      }
    }else {
      ll mid = (left + right) / 2;
      if (judge.ask(left, mid)) {
        right = mid;
      }else if (judge.ask(mid, right)) {
        left = mid;
      }else {
        DLOG("widen");
        widen();
      }
    }
  }
  


  /*
  // example for Guessing Number Game
  ll left = 1;
  ll right = sz;
  while (true) {
    ll mid = (left + right) / 2;
    ll reply = judge.ask(mid);
    if (reply == 0) judge.answer(mid);
    if (reply == -1) right = mid - 1;
    if (reply == 1)  left  = mid + 1;
  }
  */
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

