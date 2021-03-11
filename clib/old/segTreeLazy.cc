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
  Lazy Segment Tree 
    Two operations: update and query
      - update: updates value to v from i to j
      - query: performs the operation
    template parameter class T should have the following
          as well as init and madd.
      - static const T constRange(t, lo, hi)  
            returns the calculated value for a range [lo,hi) with
            constant value w 
 */

template <class T>
class SegTree {
  int size;
  vector<T> vecF;
  vector<T> vecL;
  vector<bool> toDo;

  void _update(int i, int j, T t, int n, int lo, int hi) {
    if (j <= lo || hi <= i) return;
    if (i <= lo && hi <= j) {
      vecL.at(n) = t;
      toDo.at(n) = true;
      return;
    }
    int mid = (lo + hi) / 2;
    if (toDo.at(n)) {
      _update(lo, hi, vecL.at(n), 2*n + 1, lo, mid);
      _update(lo, hi, vecL.at(n), 2*n + 2, mid, hi);
      vecL.at(n) = T::unit();
    }
    _update(i, j, t, 2*n + 1, lo, mid);
    _update(i, j, t, 2*n + 2, mid, hi);
    T tL = _query(lo, hi, 2*n + 1, lo, mid);
    T tH = _query(lo, hi, 2*n + 2, mid, hi);
    vecF.at(n) = T::madd(tL, tH);
    toDo.at(n) = false;
  }

  const T _query(int i, int j, int n, int lo, int hi) {
    if (j <= lo || hi <= i) return T::unit();
    if (toDo.at(n)) return T::constRange(vecL.at(n), max(i, lo), min(j, hi));
    if (i <= lo && hi <= j) return vecF.at(n);
    int mid = (lo + hi) / 2;
    T tL = _query(i, j, 2*n + 1, lo, mid);
    T tH = _query(i, j, 2*n + 2, mid, hi);
    return T::madd(tL, tH);
  }

  // Used by toStringDetail() (for debugging)
  void _toSD(vector<string>& stVec, int n, int lo, int hi) {
    stringstream ss;
    ss << "(" << n << "," << lo << "," << hi << ",(" 
       << vecF.at(n).toString() << "," << vecL.at(n).toString()
       << "," << toDo.at(n) << "))";
    stVec.at(n) = ss.str();
    if (lo + 1 < hi) {
      int mid = (lo + hi) / 2;
      _toSD(stVec, 2*n + 1, lo, mid);
      _toSD(stVec, 2*n + 2, mid, hi);
    }
  }

public:
  SegTree(int s) : size(s), vecF(4*s), vecL(4*s), toDo(4*s) {}

  void update(int i, int j, T t) { _update(i, j, t, 0, 0, size); }

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
  static const MyT unit() { return MyT(vUnit); }
  static const MyT madd(const MyT& x, const MyT& y) {
    return MyT(min(x.v, y.v));
  }
  static const MyT constRange(const MyT& w, int lo, int hi) {
    return w;
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
  st.update(0, N, vUnit);
  for (int k = 0; k < Q; k++) {
    int com, i, j, x; cin >> com;
    if (com == 0) {
      cin >> i >> j >> x;
      st.update(i, j + 1, MyT(x));
    }else {
      cin >> i >> j;
      int v = st.query(i, j + 1).v;
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

vInit = (1<<31) - 1

def main():
    (N, Q) = map(int, input().split())
    A = [vInit for _ in range(N)]
    for _ in range(Q):
        lst = list(map(int, input().split()))
        if lst[0] == 0:
            (i, j, x) = lst[1:]
            for k in range(i, j+1):
                A[k] = x
        else:
            (i, j) = lst[1:]
            v = min(A[i : j+1])
            print(v)

main()
----------------------------------------------------------------------

gen.py
----------------------------------------------------------------------
#!/usr/bin/env python

import random
from random import randrange 

N = 10
Q = 10
aLim = 100

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    print(N, Q)
    for j in range(Q):
        com = randrange(2)
        if com == 0:
            x = randrange(N)
            y = randrange(x, N)
            t = randrange(aLim)
            print(com, x, y, t)
        else:
            x = randrange(N)
            y = randrange(x, N)
            print(com, x, y)

main()

----------------------------------------------------------------------


 */
