#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/* 
   With iskel environment, you can build a debuggable version by:
       $ DEBUG=1 make
 */

/*
  DLOG() prints obj with operator<< to stderr

    string s1("hello");
    DSTR(s1, "beautiful", 15, 'X');

    pair<int, string> p1({3, "foo"});
    vector<int> v1({10, 5, 2});
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    DSTR(p1, v1, pq);

  DFMT() is similar to fprintf(stderr, ...),
  But you still need to convert a string into a const char*.  See below.
  It inserts a newline at the end.

     long long int   x, y;
     double          d;
     char*           p = "hello";
     string          str = string("world");
     DFMT("(x,y) = (%lld, %lld)", x, y);
     DFMT("length = %.12f", d);
     DFMT("word1: %s, word2: %s", p, str.c_str());

  DCALL(f, a, b, c) is just translated to f(a, b, c)
 */

//-----------------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN(f:<<)
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

// @@ !! END ----------------------------------------
//////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------

// ALMOST OBSOLETE.  Use DLOG("v = ", v) instead.
//
// Returns a string representation of a container, such as a vector.
// Works for a container whose iterator has begin() and end()
// E.g.
//       vector<ll> v = {1, 2, 3};
//       DLOG('v =', v)
//       DFMT("v = %s", be_string(v).c_str());
// NOTE: c_str() is still needed for DFMT.  (This is inevitable.
//       If b_string(v) returned a const char* instead of a string, the
//       allocated memory would be garbage-collected before it is passed
//       to dbgFormat().)

string be_string(auto v) { // ALMOST OBSOLETE.  
  stringstream ss;
  ss << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin())  ss << ", ";
    // If the value_type is not printable,
    // you need to define operator<<.
    // See below for an example for pair.
    ss << *it;
  }
  ss << "]";
  return ss.str();
}
// ALMOST OBSOLETE

//-----------------------------------------------------------------------------

int main() {
  cout << setprecision(20);
  
  string s1("hello");
  string s2("world");
  // DLOG(s1, s2, "there", make_pair(2, 5));
  DLOG(10, 1LL << 40, 1 << 15);

  /*
  vector<vector<int>> v1({{2}, {5}});
  v1.push_back({8, -2, 7});
  v1.push_back({4, 0});
  DLOG("v1 = ", v1);

  int special = 4;
  auto comp = [&](int p, int q) -> bool {
    if (p != special && q == special) return true;
    if (p == special) return false;
    return p < q;
  };
  priority_queue<int, vector<int>, decltype(comp)> pq(comp);
  pq.push(4), pq.push(10), pq.push(1), pq.push(20), pq.push(35);
  DLOG(pq);
  */
  
  ll x = 1LL << 50;
  DFMT("x = %lld", x);

  auto func1 = [&x](int d) {
    for (int i = 0; i < 1LL << 28; i++) x += d;
  };
  DCALL(func1, 1);
  
  return 0;

}

