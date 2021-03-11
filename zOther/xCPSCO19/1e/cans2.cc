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

struct MyT {
  ll axor;
  ll cnt;
  MyT(ll x = 0, ll c = 0) : axor(x), cnt(c) {}
  static const MyT unit() { return MyT(); }
  static const MyT madd(const MyT& x, const MyT& y) {
    if ((x.cnt + y.cnt) % 2 == 0) return MyT();
    else                          return MyT(x.axor ^ y.axor, 1);
  }
  static const MyT constRange(const MyT& w, int lo, int hi) {
    if ((hi - lo) % 2 == 0)  return MyT();
    else                     return MyT(w.axor, 1);
  }
  string toString() {
    stringstream ss;
    ss << "(axor: " << axor << ", cnt: " << cnt << ")";
    return ss.str();
  }
};


ll N, Q;
vector<ll> A, L, R, X;
vector<ll> nCmpr;
unordered_map<ll, ll> rCmpr;

int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N >> Q;
  A.resize(N); L.resize(Q); R.resize(Q); X.resize(Q);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  for (ll i = 0; i < Q; i++) {
    ll r;
    cin >> L.at(i) >> r >> X.at(i);
    R.at(i) = r + 1;
  }
  
  set<ll> cmpr;
  for (ll i = 0; i < N; i++)  cmpr.insert(A.at(i));
  for (ll i = 0; i < Q; i++) {
    cmpr.insert(L.at(i));
    cmpr.insert(R.at(i));
    cmpr.insert(X.at(i));
  }
  {
    ll i = 0;
    for (ll x : cmpr) {
      nCmpr.push_back(x);
      rCmpr[x] = i;
      i++;
    }
  }
  SegTree<MyT> st(nCmpr.size());
  for (ll i = 0; i < N; i++) {
    int j = rCmpr[A.at(i)];
    st.update(j, j+1, MyT(A.at(i), 1));
  }
  DCALL(st.show);
  for (ll i = 0; i < Q; i++) {
    MyT res = st.query(rCmpr[L.at(i)], rCmpr[R.at(i)]);
    cout << res.axor << "\n";
    DLOG("res.axor == %lld, res.cnt == %lld", res.axor, res.cnt);
    st.update(rCmpr[L.at(i)], rCmpr[R.at(i)], MyT());
    DLOG("xx");
    DCALL(st.show);
    if (res.cnt % 2 == 1) {
      st.update(rCmpr[X.at(i)], rCmpr[X.at(i)]+1, T(X.at(i), 1));
    }
    DLOG("yy");
    DCALL(st.show);
  }

  return 0;
}

