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
      void update(const T& x)                      ... update operation
      string toString()                            ... for debugging
 */

template <class T>
class SegTree {
  int size;
  vector<T> vec;

  void _update(int i, T t, int n, int lo, int hi) {
    if (hi == lo + 1) {
      vec.at(n).update(t);
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
  SegTree(int s, T initT) : size(s), vec(4*s, initT) {}

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

struct MyT {
  int v;
  MyT(int _v = INT_MIN) : v(_v) {}
  static const MyT unit() { return MyT(); }
  static const MyT madd(const MyT& x, const MyT& y) {
    return MyT(max(x.v, y.v));
  }
  void update(const MyT& x) { v = max(v, x.v); }
  string toString() {
    stringstream ss;
    ss << v;
    return ss.str();
  }
};



ll N;
vector<ll> A;

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

  ll aMax = 0;
  cin >> N;
  A.resize(N);
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    A.at(i) = a;
    aMax = max(a, aMax);
  }
  SegTree<MyT> st(aMax+1, MyT(0));
  for (ll i = 0; i < N; i++) {
    ll Ai = A.at(i);
    vector<pair<ll,ll>> nxt;
    ll rt = sqrt(Ai);
    for (ll j = 1; j <= rt; j++) {
      ll t = Ai / j;
      ll val = st.query(j, j+1).v;
      nxt.emplace_back(t, val + t);
    }
    for (ll j = Ai/rt - 1; j >= 1; j--) {
      ll val = st.query(Ai/(j+1) + 1, Ai/j + 1).v;
      nxt.emplace_back(j, val + j);
    }
    for (auto p : nxt) {
      st.update(p.first, p.second);
    }
  }
  cout << st.query(0, aMax+1).v << endl;

  return 0;
}

