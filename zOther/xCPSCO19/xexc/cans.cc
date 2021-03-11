#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#if defined(DEBUG)

#include <unistd.h>
#include <sys/fcntl.h>
#define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
#define DCALL(func, ...) func(__VA_ARGS__)

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#else  // defined(DEBUG)

#define DLOG(...)
#define DCALL(func, ...)

#endif // defined(DEBUG)

/*
  Segment Tree 
    Two operations: update and query
    Storing type T is specified as template parameter.
    T should have the following methods:
      static const T madd(const T& x, const T& y)  ... monoid operation
      static const T unit()                        ... monoid unit
      string toString()                            ... for debugging
 */

template <class T>
class SegTree {
  int size;
  vector<T> vec;

  void _update(int i, T t, int n, int lo, int hi) {
    if (hi == lo + 1) {
      vec.at(n) = t;
      return;
    }
    int mid = (lo + hi) / 2;
    if (i < mid) _update(i, t, 2*n + 1, lo, mid);
    else         _update(i, t, 2*n + 2, mid, hi);
    vec.at(n) = T::madd(vec.at(2*n + 1), vec.at(2*n + 2));
  }

  const T _query(int i, int j, int n, int lo, int hi) {
    if (hi <= i || j <= lo) return T::unit();
    if (i <= lo && hi <= j) return vec.at(n);
    int mid = (lo + hi) / 2;
    T tL = _query(i, j, 2*n + 1, lo, mid);
    T tH = _query(i, j, 2*n + 2, mid, hi);
    return T::madd(tL, tH);
  }

  // Used by toStringDetail() (for debugging)
  void _toSD(vector<string>& stVec, int n, int lo, int hi) {
    stringstream ss;
    ss << "(" << n << "," << lo << "," << hi << "," 
       << vec.at(n).toString() << ")";
    stVec.at(n) = ss.str();
    if (lo + 1 < hi) {
      int mid = (lo + hi) / 2;
      _toSD(stVec, 2*n + 1, lo, mid);
      _toSD(stVec, 2*n + 2, mid, hi);
    }
  }

public:
  SegTree(int s) : size(s), vec(4*s) {}

  void update(int i, T t) { _update(i, t, 0, 0, size); }

  T query(int i, int j) { return _query(i, j, 0, 0, size); }

  string toStringDetail() { // for debug
    vector<string> stVec(4*size);
    _toSD(stVec, 0, 0, size);
    stringstream ss;
    ss << "[";
    for (int n = 0; n < 4*size; n++) {
      if (n > 0) ss << ", ";
      ss << stVec.at(n);
    }
    ss << "]";
    return ss.str();
  }

  string toString() { // for degbug
    stringstream ss;
    ss << "[";
    for (int i = 0; i < size; i++) {
      T t = query(i, i+1);
      if (i > 0) ss << ", ";
      ss << "(" << i << "," << t.toString() << ")";
    }
    ss << "]";
    return ss.str();
  }

};

/*
  An example for class T used in SegTree.
  This MyT is for Range Minimum Query.
 */

constexpr int vUnit = ((unsigned)1 << 31) - 1;
struct MyT {
  int v;
  MyT(int _v = vUnit) : v(_v) {}
  static const MyT unit() { return MyT(); }
  static const MyT madd(const MyT& x, const MyT& y) {
    return MyT(min(x.v, y.v));
  }
  string toString() {
    stringstream ss;
    ss << v;
    return ss.str();
  }
};

int N, Q;

int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cout << setprecision(20);

  cin >> N >> Q;
  SegTree<MyT> st(N);
  for (int i = 0; i < N; i++) st.update(i, vUnit);
  for (int i = 0; i < Q; i++) {
    int com, x, y; cin >> com >> x >> y;
    if (com == 0) {
      st.update(x, MyT(y));
    }else {
      int v = st.query(x, y + 1).v;
      cout << v << "\n";
    }
  }

#if defined(DEBUG)
  st.toString();
  st.toStringDetail();
#endif

  return 0;
}

/*
  test

naive.py
----------------------------------------------------------------------
#!/usr/bin/env python3

vUnit = (1<<31) - 1

def main():
    (N, Q) = map(int, input().split())
    A = [vUnit for _ in range(N)]
    for _ in range(Q):
        (com, x, y) = map(int, input().split())
        if com == 0:
            A[x] = y
        else:
            v = min(A[x : y+1])
            print(v)

main()
----------------------------------------------------------------------

gen.py
----------------------------------------------------------------------
#!/usr/bin/env python3

import random
from random import randrange 

N = 10
Q = 10
aLim = 10

def main():
    print(N, Q)
    for j in range(Q):
        com = randrange(2)
        if com == 0:
            x = randrange(N)
            y = randrange(aLim)
        else:
            x = randrange(N)
            y = randrange(x, N)
        print(com, x, y)

main()
----------------------------------------------------------------------


 */
