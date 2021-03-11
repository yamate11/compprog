#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// --- DEBUG begin --- cut here ---
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

// operator<< definitions for some classes

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
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
// --- DEBUG end --- cut here ---


// --- SegTree begin --- cut here ---


/*
  Segment Tree (incl. laziness)

  Usage:

    auto xAdd = [](T x, T y) -> T { ... };
    auto xMod = [](S g, T x) -> T { ... };
    auto xComp = [](S h, S g) -> S { ... };
    auto xMult = [](int k, S g) -> S { ... };
    vector<T> initVec( { ... } );
    SegTree<T, S> st(initVec, xAdd, xMod, xComp, xMult, unitT, unitS);
    st.update(left, right, value);    // 0-based, half-open interval
    t = st.query(left, right);

    #if DEBUG
    // Sanity check for functions and unit elements
    auto genT = st.getGenInt(1, 10); // if T == int or ll
    auto genS = [&](auto _gen) -> S { ... };
    st.quick_check(genT, genS, 1000);
    #endif // DEBUG

    // st can be reused for different data (and same operations):
    st.renew(newVec);

  xAdd is the monoid operation.  +, min, max, ...
  unitT is the monoid unit element.
  xMod is used in the update procedure.  When the current value is x
    and update parameter is g, then the new value will be xMod(g, x).
  Update procedure should also be regarded as a monoid operation,
    and xComp is the operation and unitS is the unit element.
  xAdd and xMod should be commutable with respect to xMult:
    fold xAdd (map (xMod s) list) == xMod (xMult (len list) s) list
  xMult is meaningful only when you have range updates.  Otherwise,
    define it as "xMult _ s = s".
  
  Indices are zero-based and ranges are half-open intervals.
  To update point n with value v, call st.update(n, n+1, v).

  Defining xAdd should be straight forward, but xMod can be
  tricky.  In particular, consider one point assignment.  A naive
  definition of "xMod(g, x) = g" and "xComp(g, h) = g" does not
  work because we need a unit element for S.  Let's assume that
  updating value is always positive.  Then we can employ -1 as the
  unit: "xMod(g, x) = if g == -1 then x else g" and 
  "xComp(g, h) = h if g == -1 else g".

  As defining operations and unit elements might be error-prone,
  a sanity check function st.quick_check(genT, genS, n) is provided.  
  Argument genT and genS are functions that randomly generates values
  for T and S, resp. when called with a random engine.  If T and S are
  integers, you can use the return value of st.getGenInt(from, to);
  Argument n is the number of repeats.
 */

template <typename T, typename S>
class SegTree {

  int size;
  vector<T> st;
  vector<S> lz;
  T (*add)(T, T);
  T (*mod)(S, T);
  S (*comp)(S, S);
  S (*mult)(int, S);
  T unitT;
  S unitS;

  void lateUpd(int left, int right) {
    auto sub = [&](const auto& recF, int n, int lo, int hi, S late) -> T {
      S newLate = comp(late, lz.at(n));
      if ((left <= lo && hi <= right) || (right <= lo || hi <= left)) {
	lz.at(n) = newLate;
	return mod(mult(hi - lo, lz.at(n)), st.at(n));
      }else {
	T t1 = recF(recF, 2*n + 1, lo, (lo + hi) / 2, newLate);
	T t2 = recF(recF, 2*n + 2, (lo + hi) / 2, hi, newLate);
	st.at(n) = add(t1, t2);
	lz.at(n) = unitS;
	return st.at(n);
      }
    };
    sub(sub, 0, 0, size, unitS);
  }

  void sub_report() {}

  template<typename X, typename... Args>
  void sub_report(X t, Args... args) {
    cerr << t;
    sub_report(args...);
  }

  template<typename... Args>
  void report(Args... args) {
    sub_report(args...);
    exit(1);
  }

  T setSt(const vector<T>& _vec, int n, int lo, int hi) {
    if (lo + 1 == hi) {
      // DLOG("init out A", _vec.at(lo), "; ", n, lo, hi);
      return st.at(n) = _vec.at(lo);
    }else {
      T t1 = setSt(_vec, 2*n + 1, lo, (lo + hi) / 2);
      T t2 = setSt(_vec, 2*n + 2, (lo + hi) / 2, hi);
      // DLOG("init out B", add(t1, t2), "; ", n, lo, hi);
      return st.at(n) = add(t1, t2);
    }
  }

public:
  SegTree(const vector<T>& _vec, auto _add, auto _mod, auto _comp, auto _mult,
	  T _unitT, S _unitS) :
    size(_vec.size()), st(4*_vec.size()), lz(4*_vec.size(), _unitS),
    add(_add), mod(_mod), comp(_comp), mult(_mult),
    unitT(_unitT), unitS(_unitS) 
  {
    if (size > 0) setSt(_vec, 0, 0, size);
  }

  void renew(const vector<T>& _vec) {
    size = _vec.size();
    lz = vector<S>(4*size, unitS);
    st = vector<T>(4*size);
    if (size > 0) setSt(_vec, 0, 0, size);
  }

  void update(int left, int right, S s) {
    auto sub = [&](const auto& recF, int n, int lo, int hi) -> T {
      if (left <= lo && hi <= right) {
	lz.at(n) = comp(s, lz.at(n));
	return mod(mult(hi - lo, lz.at(n)), st.at(n));
      }else if (right <= lo || hi <= left) {
	return mod(mult(hi - lo, lz.at(n)), st.at(n));
      }else {
	T t1 = recF(recF, 2*n + 1, lo, (lo + hi) / 2);
	T t2 = recF(recF, 2*n + 2, (lo + hi) / 2, hi);
	st.at(n) = add(t1, t2);
	return st.at(n);
      }
    };
    // DLOG("update in ", left, right, s, st, lz);
    lateUpd(left, right);
    // DLOG("query mid st", st);
    // DLOG("query mid lz", lz);
    sub(sub, 0, 0, size);
    // DLOG("update out st", st);
    // DLOG("update out lz", lz);
  }

  T query(int left, int right) {
    auto sub = [&](const auto& recF, int n, int lo, int hi) -> T {
      // DLOG("in query", n, lo, hi);
      if (left <= lo && hi <= right) {
	return mod(mult(hi - lo, lz.at(n)), st.at(n));
      }else if (right <= lo || hi <= left) {
	return unitT;
      }else {
	T t1 = recF(recF, 2*n + 1, lo, (lo + hi) / 2);
	T t2 = recF(recF, 2*n + 2, (lo + hi) / 2, hi);
	T t = add(t1, t2);
	return t;
      }
    };
    // DLOG("query in", left, right, st, lz);
    lateUpd(left, right);
    // DLOG("query mid st", st);
    // DLOG("query mid lz", lz);
    T t = sub(sub, 0, 0, size);
    // DLOG("query out st", st);
    // DLOG("query out lz", lz);
    return t;
  }

  void quick_check(auto genT, auto genS, int repNum = 100) {
    default_random_engine gen(1234);
    for (int z = 0; z < repNum; z++) {
      T t1 = genT(gen);
      T t2 = genT(gen);
      T t3 = genT(gen);
      S s1 = genS(gen);
      S s2 = genS(gen);
      S s3 = genS(gen);
      if (add(add(t1, t2), t3) != add(t1, add(t2, t3))) {
	report("T is not assoc: t1 =", t1, "t2 =", t2, "t3 =", t3);
      }
      if (comp(comp(s1, s2), s3) != comp(s1, comp(s2, s3))) {
	report("S is not assoc: s1 =", s1, "s2 =", s2, "s3 =", s3);
      }
      if (add(t1, unitT) != t1) report("unitT is not a unit. t =", t1);
      if (add(unitT, t2) != t2) report("unitT is not a unit. t =", t2);
      if (comp(s1, unitS) != s1) report("unitS is not a unit. s =", s1);
      if (comp(unitS, s2) != s2) report("unitS is not a unit. s =", s2);
      if (mod(s1, mod(s2, t1)) != mod(comp(s1, s2), t1)) {
	report("mod(s1, mod(s2, t)) != mod(comp(s1, s2), t). ",
	       "s1 =", s1, "s2 =", s2, "t = ", t1);
      }
      if (mod(unitS, t1) != t1) {
	report("mod(unitS, t) != t: t = ", t1);
      }
      uniform_int_distribution<int> dist(1, 5);
      int n = dist(gen);
      vector<T> vec;
      for (int j = 0; j < n; j++) { vec.push_back(genT(gen)); }
      T tL = unitT;
      T tR = unitT;
      for (int j = 0; j < n; j++) {
	tL = add(tL, mod(s1, vec.at(j)));
	tR = add(tR, vec.at(j));
      }
      tR = mod(mult(n, s1), tR);
      if (tL != tR) {
	report("mult() fails.  s = ", s1, "ts = ", vec);
      }
    }
  }

  auto getGenInt(int from, int to) {
    uniform_int_distribution<int> dist(from, to);
    auto ret = [&](auto _gen) -> int {
      return dist(_gen);
    };
    return ret;
  }
  
  // for library testing/debugging
  void compareNaive(auto gen, auto genT, auto genS,
		    int repNum, int vecSizeMax, int iMax) {
    quick_check(genT, genS);
    uniform_int_distribution<int> distVS(1, vecSizeMax);

    for (int z = 0; z < repNum; z++) {
      int vecSize = distVS(gen);
      vector<T> vecData;
      for (int j = 0; j < vecSize; j++) vecData.push_back(genT(gen));
      renew(vecData);
      vector<T> cVec(vecData);
      vector<int> vecL, vecR;
      vector<S> vecUpd;
      uniform_int_distribution<int> distL(0, vecSize-1);
      for (int i = 0; i < iMax; i++) {
	int valLeft = distL(gen);
	vecL.push_back(valLeft);
	uniform_int_distribution<int> distR(valLeft+1, vecSize);
	vecR.push_back(distR(gen));
	uniform_int_distribution<int> distD(1, 5);
	if (i % 2 == 0) vecUpd.push_back(distD(gen));
	else            vecUpd.push_back(1);
      }

      for (int i = 0; i < iMax; i++) {
	int left = vecL.at(i), right = vecR.at(i);
	ll x = vecUpd.at(i);
	if (i % 2 == 0) {
	  update(left, right, x);
	  for (int j = left; j < right; j++) cVec.at(j) = mod(x, cVec.at(j));
	}else {
	  T p = query(left, right);
	  T q = unitT;
	    for (int j = left; j < right; j++) q = add(q, cVec.at(j));
	  if (p != q) {
	    cout << "vecData" << vecData << endl;
	    cout << "vecL" << vecL << endl;
	    cout << "vecR" << vecR << endl;
	    cout << "vecUpd" << vecUpd << endl;
	    cout << "i = " << i << ", p = " << p << ", q = " << q << endl;
	    assert(false);
	  }
	}
      }
    }
  };

};

// --- SegTree end --- cut here ---


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> C(N), A(N);
  for (ll i = 1; i <= N - 1; i++) cin >> C.at(i) >> A.at(i);
  C.at(0) = A.at(0) = 0;

  vector<ll> iv(N, -1);
  auto xAdd = [](ll x, ll y) -> ll { return min(x, y); };
  auto xMod = [](ll f, ll x) -> ll { return f == -2 ? x : f; };
  auto xComp = [](ll f, ll g) -> ll { return f == -2 ? g : f; };
  auto xMult = [](int k, ll g) -> ll { return g; };
  SegTree<ll, ll> st(iv, xAdd, xMod, xComp, xMult, LLONG_MAX, -2);
  
  ll judge = 0;
  ll gMax = 0;
  st.update(0, 1, 0);
  for (ll i = 1; i <= N-1; i++) {
    auto binsch = [&](ll ng, ll ok) -> ll {
      while (ng + 1 < ok) {
	ll mid = (ng + ok) / 2;
	if (st.query(0, mid+1) < max(0LL, i - C.at(i))) ok = mid;
	else                                            ng = mid;
      }
      return ok;
    };
    ll x = binsch(-1, gMax+1);
    DLOG("i, x", i, x);
    st.update(x, x+1, i);
    gMax = max(gMax, x);
    if (A.at(i) % 2 == 1) judge ^= x;
  }
  cout << (judge ? "First" : "Second") << endl;

  return 0;
}

