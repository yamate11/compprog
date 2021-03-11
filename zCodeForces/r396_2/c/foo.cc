#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

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

#define DLOG1(EXP1) DLOG(#EXP1 "=", EXP1)
#define DLOG2(EXP1, EXP2) DLOG(#EXP1 "=", EXP1, #EXP2 "=", EXP2)

#define LIST4(E) E,E,E,E
#define DLOG3(E) DLOG(LIST4(E))

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)

#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define DUP(...) GET_MACRO(__VA_ARGS__, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...) DLOG(DUP(__VA_ARGS__))

int main() {
  ll x = 10;
  ll y = 20;
  vector vec({5, 2, -4});
  DLOG1(x);
  DLOG2(x + y, x - y);
  DLOGK(x, y, x+y, x-y, x*5, y-4, x*y, x+2*y);
  DLOGK(x, y);
  DLOGK(x);
  ll i = 1;
  DLOGK(vec, i, vec[i]);
  /*
  DLOG(DUP(x,y,2*x,x-5));
  DLOG(DUP(x,y,x+y));
  DLOG(DUP(x,y));
  */
  cout << "Hello, world.\n";
  return 0;
}
