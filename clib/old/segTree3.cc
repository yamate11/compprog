#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

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

// --- SegTree begin --- cut here ---


/*
  Segment Tree (incl. laziness)

  Usage:

    auto xAdd = [](T x, T y) -> T { ... };
    auto xMod = [](int k, S g, T x) -> T { ... };
    auto xComp = [](S h, S g) -> S { ... };
    vector<T> initVec( { ... } );
    SegTree<T, S> st(initVec, xAdd, xMod, xComp, unitT, unitS);
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
  xMod is used for update.  In the bottom level, when the current 
  value is x and update parameter is g, then the new value will be
  xMod(1, g, x).  The first parameter k of xMod has meanings in the
  lazy update: xMod(k, g, x) is the value of g applied to x when
  the length of range is k: 
     xMod (len list) g list == fold xAdd (map (xMod 1 g) list)

  Update procedure should also be regarded as a monoid operation,
  and xComp is the operation and unitS is the unit element.
  But the unit element of an operation may be difficult to be
  expressed by a value.  For example (and as the most often used
  example) consider the assignment operation.  Almost all assignment
  operation can be expressed by the value which is assigned by
  the operation, but the unit element (i.e. "do nothing") cannot be.
  So, the user can specify xMod and xComp for the ordinary operation
  and specify also a value for the unit operation.  E.g., 
    xMod = [](int k, ll g, ll x) -> ll { return g; }
    xComp = [](ll g, ll f) -> ll { return g; }
    unitS = -1  // (if only assignment of positive numbers are considered.
  The library innerly uses modEx and compEx that handles the unit
  element appropriately

  Indices are zero-based and ranges are half-open intervals.
  To update point n with value v, call st.update(n, n+1, v).

  As defining operations and unit elements might be error-prone,
  a sanity check function st.quick_check(genT, genS, n) is provided.  
  Argument genT and genS are functions that randomly generates values
  for T and S, resp. when called with a random engine.  If T and S are
  integers, you can use the return value of st.getGenInt(from, to);
  Argument n is the number of repeats.
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN(f:<<) ---- segTree.cc
template <typename T, typename S>
struct SegTree {

// private: // -- intended to be private, but formally public for debugging

  int size;
  vector<T> st;  // store
  vector<S> lz;  // for lazy evaluation
  T (*add)(T, T);
  T (*mod)(int, S, T);
  S (*comp)(S, S);
  T unitT;
  S unitS;

  T modEx(int k, S f, T x) { return f == unitS ? x : mod(k, f, x); }
  
  S compEx(S f, S g) {
    return f == unitS ? g : g == unitS ? f : comp(f, g);
  }

  void lateUpd(int left, int right) {
    auto sub = [&](const auto& recF, int n, int lo, int hi, S late) -> T {
      S newLate = this->compEx(late, lz.at(n));
      if ((left <= lo && hi <= right) || (right <= lo || hi <= left)) {
	lz.at(n) = newLate;
	return this->modEx(hi - lo, lz.at(n), st.at(n));
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

// public:  -- The following are truly public functions

  SegTree(const vector<T>& _vec, auto _add, auto _mod, auto _comp, 
	  T _unitT, S _unitS) :
    size(_vec.size()), st(4*_vec.size()), lz(4*_vec.size(), _unitS),
    add(_add), mod(_mod), comp(_comp),
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
	lz.at(n) = this->compEx(s, lz.at(n));
	return this->modEx(hi - lo, lz.at(n), st.at(n));
      }else if (right <= lo || hi <= left) {
	return this->modEx(hi - lo, lz.at(n), st.at(n));
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
	return this->modEx(hi - lo, lz.at(n), st.at(n));
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

  // Returns the smallest x such that pred(query(0, x)) returns true.
  //   pred(query(0, 0))    should return false, and
  //   pred(query(0, size)) should return true
  int binsch(bool (*pred)(T)) {
    auto sub2 = [&](int n, int lo, int hi, S late) -> T {
      lz.at(n) = compEx(late, lz.at(n));
      return modEx(hi - lo, lz.at(n), st.at(n));
    };
    auto sub1 = [&](const auto& recF, int n, int lo, int hi, T lval) -> int {
      if (lo + 1 == hi) return hi;
      int mi = (lo + hi) / 2;
      T t1 = sub2(2*n + 1, lo, mi, lz.at(n));
      T t2 = sub2(2*n + 2, mi, hi, lz.at(n));
      st.at(n) = add(t1, t2);
      lz.at(n) = unitS;
      if (pred(add(lval, t1))) {
	return recF(recF, 2*n + 1, lo, mi, lval);
      }else {
	return recF(recF, 2*n + 2, mi, hi, add(lval, t1));
      }
    };
    return sub1(sub1, 0, 0, size, unitT);
  }

  default_random_engine r_eng;
  // default_random_engine r_eng(1234);

  void quick_check(auto genT, auto genS, int repNum = 100) {
    for (int z = 0; z < repNum; z++) {
      T t1 = genT(r_eng);
      T t2 = genT(r_eng);
      T t3 = genT(r_eng);
      S s1 = genS(r_eng);
      S s2 = genS(r_eng);
      S s3 = genS(r_eng);
      // cerr << "*** s ***" << s1 << " " << s2 << " " << s3 << "\n";
      if (add(add(t1, t2), t3) != add(t1, add(t2, t3))) {
	report("T is not assoc: t1 =", t1, "t2 =", t2, "t3 =", t3);
      }
      if (comp(comp(s1, s2), s3) != comp(s1, comp(s2, s3))) {
	report("S is not assoc: s1 =", s1, "s2 =", s2, "s3 =", s3);
      }
      if (add(t1, unitT) != t1) report("unitT is not a unit. t =", t1);
      if (add(unitT, t2) != t2) report("unitT is not a unit. t =", t2);
      uniform_int_distribution<int> dist(1, 5);
      int n1 = dist(r_eng);
      if (mod(n1, s1, mod(n1, s2, t1)) != mod(n1, comp(s1, s2), t1)) {
	report("mod(n1, s1, mod(n1, s2, t)) != mod(n1, comp(s1, s2), t). ",
	       "n1 = ", n1, "s1 =", s1, "s2 =", s2, "t = ", t1);
      }
      int n2 = dist(r_eng);
      vector<T> vec;
      for (int j = 0; j < n2; j++) { vec.push_back(genT(r_eng)); }
      T tL = unitT;
      T tR = unitT;
      for (int j = 0; j < n2; j++) {
	tL = add(tL, mod(1, s1, vec.at(j)));
	tR = add(tR, vec.at(j));
      }
      tR = mod(n2, s1, tR);
      if (tL != tR) {
	report("mod_mult() fails.  s = ", s1, ", ts = ", vec, "\n");
      }
    }
  }

  auto getGenInt(int from, int to) {
    uniform_int_distribution<int> dist(from, to);
    auto ret = [&](auto& _gen) -> int {
      return dist(_gen);
    };
    return ret;
  }
  
  // for library testing/debugging
  void compareNaive(auto genT, auto genS,
		    int repNum, int vecSizeMax, int iMax,
		    bool (*pred)(T)) {
    quick_check(genT, genS);
    uniform_int_distribution<int> distVS(1, vecSizeMax);

    for (int z = 0; z < repNum; z++) {
      int vecSize = distVS(r_eng);
      vector<T> vecData;
      for (int j = 0; j < vecSize; j++) vecData.push_back(genT(r_eng));
      renew(vecData);
      vector<T> cVec(vecData);
      vector<int> vecL, vecR;
      vector<S> vecUpd;
      uniform_int_distribution<int> distL(0, vecSize-1);
      for (int i = 0; i < iMax; i++) {
	int valLeft = distL(r_eng);
	vecL.push_back(valLeft);
	uniform_int_distribution<int> distR(valLeft+1, vecSize);
	vecR.push_back(distR(r_eng));
	uniform_int_distribution<int> distD(1, 5);
	if (i % 2 == 0) vecUpd.push_back(distD(r_eng));
	else            vecUpd.push_back(1);
      }

      for (int i = 0; i < iMax; i++) {
	int left = vecL.at(i), right = vecR.at(i);
	ll x = vecUpd.at(i);
	if (i % 2 == 0) {
	  update(left, right, x);
	  for (int j = left; j < right; j++) {
	    cVec.at(j) = mod(1, x, cVec.at(j));
	  }
	}else {
	  auto errRep = [&]() -> void {
	    cout << "vecData" << vecData << endl;
	    cout << "vecL" << vecL << endl;
	    cout << "vecR" << vecR << endl;
	    cout << "vecUpd" << vecUpd << endl;
	    cout << "i" << i << endl;
	  };
	  if (pred == nullptr || i % 4 == 0) {
	    T p = query(left, right);
	    T q = unitT;
	    for (int j = left; j < right; j++) q = add(q, cVec.at(j));
	    if (p != q) {
	      errRep();
	      cout << "p = " << p << ", q = " << q << endl;
	      assert(false);
	    }
	  }else {
	    int p = binsch(pred);
	    int q = 0;
	    for (T val = unitT;
		 q < vecSize && !pred(val);
		 val = add(val, cVec.at(q++)));
	    if (p != q) {
	      errRep();
	      cout << "p = " << p << ", q = " << q << endl;
	      assert(false);
	    }
	  }
	}
      }
    }
  };

};

// @@ !! END ---- segTree.cc


//----------------------------------------------------------------------

// Query: minimum value in the range
// Update: assignment on a point
void test01(int repNum, int vecSizeMax, int iMax) {
  auto xAdd = [](int x, int y) -> int { return min(x, y); };
  auto xMod = [](int k, int g, int x) -> int { return g; };
  auto xComp = [](int h, int g) -> int { return h; };
  SegTree<int, int> st0(vector<int>(), xAdd, xMod, xComp, INT_MAX, -1);

  auto genInt = [&](auto& _gen) -> int {
    uniform_int_distribution<int> dist(1, vecSizeMax);
    return dist(_gen);
  };
  auto pred = [](int z) { return z < 3; };
  st0.compareNaive(genInt, genInt, repNum, vecSizeMax, iMax, pred);

  vector<int> init1(10000, 100);
  init1.at(1000) = 90;
  init1.at(2000) = 80;
  SegTree<int, int> st1(init1, xAdd, xMod, xComp, INT_MAX, -1);
  assert(st1.query(500, 800) == 100);
  assert(st1.query(600, 1000) == 100);
  assert(st1.query(700, 1001) == 90);
  assert(st1.query(800, 3000) == 80);
  assert(st1.binsch([](int z) { return z <= 100; }) == 1);
  assert(st1.binsch([](int z) { return z <= 90; }) == 1001);
  assert(st1.binsch([](int z) { return z <= 70; }) == 10000);
  st1.update(2500, 2501, 70);
  assert(st1.query(800, 3000) == 70);
  assert(st1.binsch([](int z) { return z <= 70; }) == 2501);
}

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

typedef pair<ll, ll> Test1;

// Query: sum of the range
// Update: multiplies a number uniformly onto the range
void test02(int repNum, int vecSizeMax, int iMax) {
  auto xAdd = [](Test1 a,  Test1 b) -> Test1 {
    return Test1(a.first + b.first, a.second + b.second); };
  auto xMod = [](int k, ll g, Test1 a) -> Test1 {
    return Test1(g * a.first, g * a.second);
  };
  auto xComp = [](ll g, ll h) -> ll { return g * h; };
  Test1 unit1(0, 0);
  ll unit2 = 1;
  SegTree<Test1, ll> st0(vector<Test1>(), xAdd, xMod, xComp, 
			 unit1, unit2);

  auto genInt = [&](auto _gen) -> int {
    uniform_int_distribution<int> dist(1, vecSizeMax);
    return dist(_gen);
  };
  auto genTest1 = [&](auto _gen) -> Test1 {
    return make_pair(genInt(_gen), genInt(_gen));
  };

  st0.compareNaive(genTest1, genInt, repNum, vecSizeMax, iMax, nullptr);
}

void test03(int repNum, int vecSizeMax, int iMax) {
  // query : sum of the range
  // update: add uniformly a number to a range
  auto xAdd = [](int x, int y) -> int { return x + y; };
  auto xMod = [](int k, int g, int x) -> int { return k * g + x; };
  auto xComp = [](int h, int g) -> int { return h + g; };
  SegTree<int, int> st0(vector<int>(), xAdd, xMod, xComp, 0, 0);

  auto genInt = st0.getGenInt(1, vecSizeMax);

  st0.compareNaive(genInt, genInt, repNum, vecSizeMax, iMax, nullptr);
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cerr << "Test 01" << endl;
  test01(1000, 30, 30);
  cerr << "Test 02" << endl;
  test02(1000, 30, 30);
  cerr << "Test 03" << endl;
  test03(1000, 30, 30);
  cerr << "Test completed." << endl;
  
  return 0;

}

