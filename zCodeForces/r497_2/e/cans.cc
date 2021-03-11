#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(interactive debug)
// --> interactive f:<< debug
// ---- inserted library file interactive.cc

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
      cerr << "Unknown argument\n";
      exit(1);
    }
  }
    
  try {
    do_game(is_judge);
  }catch (const SolveExc& e) {
  }
  return 0;
}

/* 
   Copy and edit the following into the part below END
 */
/*
ll sz;

struct Judge {
  using ask_q_t = ll;
  using ask_a_t = string;
  using answer_t = ll;

  virtual void ask_q(ask_q_t x) = 0;
  virtual ask_a_t ask_a() = 0;
  virtual void answer(answer_t x) = 0;

  void wa() {
    cout << "WA\n";
    exit(1);
  }

  void ac() {
    cout << "AC\n";
    throw SolveExc();
  }
};

struct JudgeLoc : Judge {
  ll expected;
  ll asked;

  JudgeLoc() {
    // Typically, read the question for testing from stdin
    cin >> sz >> expected;
  }
  void ask_q(ask_q_t x) {
    asked = x;
  }
  ask_a_t ask_a() {
    return asked == expected ? "EQ" : asked < expected ? "LT" : "GT";
  }
  void answer(answer_t x) {
    // Always call ac() or wa().
    if (x == expected) ac();
    else wa();
  }
};

struct JudgeRem : Judge {
  JudgeRem() {
    // Read initial information, if any.
    cin >> sz;
  }
  void ask_q(ask_q_t x) {
    // Information asking.  Typically prepended by "? " and followed by endl
    cout << "? " << x << endl;
  }
  ask_a_t ask_a() {
    // Responce to the asking
    string rep; cin >> rep;
    return rep;
  }
  void answer(answer_t x) {
    // Final output.  Typically prepended by "! " and followed by endl
    cout << "! " << x << endl;
    // Need to throw SolveExc()
    throw SolveExc();
  }
};

void game(Judge&& judge) {
  ll left = 1;
  ll right = sz;
  while (true) {
    ll mid = (left + right) / 2;
    judge.ask_q(mid);
    string rep = judge.ask_a();
    if (rep == "EQ") judge.answer(mid);
    if (rep == "LT") left = mid;
    if (rep == "GT") right = mid;
  }
}

void do_game(bool is_judge) {
  if (is_judge) game(JudgeLoc());
  else          game(JudgeRem());
}
*/

// ---- end interactive.cc
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

ll N;

struct Judge {
  using ask_q_t = pair<ll, ll>;
  using ask_a_t = ll;
  using answer_t = ll;

  virtual void ask_q(ll x, ll y) = 0;
  virtual ask_a_t ask_a() = 0;
  virtual void answer(answer_t x) = 0;

  ask_a_t ask(ll x, ll y) {
    ask_q(x, y);
    return ask_a();
  }

  void wa() {
    cout << "WA\n";
    exit(1);
  }

  void ac() {
    cout << "AC\n";
    throw SolveExc();
  }
};

struct JudgeLoc : Judge {
  ll a;
  ll b;
  ll x;
  ll y;
  bool cyc;
  bool done;

  JudgeLoc() {
    // Typically, read the question for testing from stdin
    cin >> N >> a >> b;
    cyc = false;
    done = false;
  }
  void ask_q(ll x_, ll y_) {
    x = x_;
    y = y_;
  }
  ask_a_t ask_a() {
    if (a == x && b == y) {
      ac();
      return 0;
    }
    vector<ll> v;
    if (x < a) v.push_back(1);
    if (y < b) v.push_back(2);
    if (x > a || y > b) v.push_back(3);
    if (v.size() == 1) return v[0];
    if (v.size() == 2) {
      cyc = !cyc;
      return cyc ? v[0] : v[1];
    }
    assert(0);
  }
  void answer(answer_t xxx) {
    // Always call ac() or wa().
    if (done) ac();
    else wa();
  }
};

struct JudgeRem : Judge {
  JudgeRem() {
    // Read initial information, if any.
    cin >> N;
  }
  void ask_q(ll x, ll y) {
    // Information asking.  Typically prepended by "? " and followed by endl
    cout << x << " " << y << endl;
  }
  ask_a_t ask_a() {
    // Responce to the asking
    ask_a_t rep; cin >> rep;
    if (rep == 0) throw SolveExc();
    return rep;
  }
  void answer(answer_t x) {
    // Final output.  Typically prepended by "! " and followed by endl
    // cout << "! " << x << endl;
    // Need to throw SolveExc()
    throw SolveExc();
  }
};

enum {RECT, HOOK};

void game(Judge&& judge) {
  ll xL = 1;
  ll yL = 1;
  ll xH = N;
  ll yH = N;
  ll xM = -1;
  ll yM = -1;
  
  ll status = RECT;

  while (true) {
    DLOGK(status, xL, xH, yL, yH, xM, yM);
    if (status == RECT) {
      ll x = (xL + xH) / 2;
      ll y = (yL + yH) / 2;
      ll a = judge.ask(x, y);
      if (a == 1) {
        xL = x + 1;
      }else if (a == 2) {
        yL = y + 1;
      }else if (a == 3) {
        xM = x - 1;
        yM = y - 1;
        status = HOOK;
      }else assert(0);
    }else if (status == HOOK) {
      ll x = (xM + xL) / 2;
      ll y = (yM + yL) / 2;
      ll a = judge.ask(x, y);
      if (a == 1) {
        xL = x + 1;
        ll a2 = judge.ask(xM, y);
        if (a2 == 1) {
          xL = xM + 1;
          yH = yM;
          status = RECT;
        }else if (a2 == 2) {
          yL = y + 1;
        }else if (a2 == 3) {
          xM = xM - 1;
          yM = y - 1;
        }else assert(0);
      }else if (a == 2) {
        yL = y + 1;
        ll a2 = judge.ask(x, yM);
        if (a2 == 2) {
          yL = yM + 1;
          xH = xM;
          status = RECT;
        }else if (a2 == 1) {
          xL = x + 1;
        }else if (a2 == 3) {
          yM = yM - 1;
          xM = x - 1;
        }else assert(0);
      }else if (a == 3) {
        xM = x - 1;
        yM = y - 1;
      }else assert(0);
    }else assert(0);
  }
}

void do_game(bool is_judge) {
  if (is_judge) game(JudgeLoc());
  else          game(JudgeRem());
}

