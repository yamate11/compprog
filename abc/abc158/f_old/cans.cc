#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(mod binsearch debug segTree)
// --> f:gcd mod binsearch f:<< debug segTree
// ---- inserted function gcd from util.cc
// g = eGCD(a, b, s, t)  --->  sa + tb = g
constexpr ll eGCD(ll a, ll b, ll& s, ll& t) {
  if (a == 0) {
    s = 0;
    t = 1;
    return b;
  }
  ll u = 0;
  ll g = eGCD(b % a, a, t, u);
  s = u - (b / a) * t;
  return g;
}

constexpr ll gcd(ll a, ll b) {
  ll dummy1 = 0;
  ll dummy2 = 0;
  return eGCD(a, b, dummy1, dummy2);
}
// ---- end gcd
// ---- inserted library file mod.cc

ll MOD = 1e9 + 7;
// ll MOD = 998244353;

struct Fp {
  ll val;

  Fp(ll t = 0) {
    if      (t >= MOD)  val = t % MOD;
    else if (t >= 0)    val = t;
    else if (t >= -MOD) val = t + MOD;
    else {
      ll v = t % MOD;
      if (v == 0) val = 0;
      else        val = v + MOD;
    }
  }

  Fp& operator +=(const Fp& t) {
    val += t.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  Fp& operator -=(const Fp& t) {
    val -= t.val;
    if (val < 0) val += MOD;
    return *this;
  }

  Fp& operator *=(const Fp& t) {
    val = (val * t.val) % MOD;
    return *this;
  }

  Fp inv() const {
    if (val == 0) {
      cerr << "inv() is called for zero." << endl;
      exit(1);
    }
    ll u = 0;
    ll v = 0;
    eGCD(val, MOD, u, v);
    return Fp(u);
  }

  Fp& operator /=(const Fp& t) {
    return (*this) *= t.inv();
  }

  Fp operator +(const Fp& t) const { return Fp(val) += t; }
  Fp operator -(const Fp& t) const { return Fp(val) -= t; }
  Fp operator *(const Fp& t) const { return Fp(val) *= t; }
  Fp operator /(const Fp& t) const { return Fp(val) /= t; }
  Fp operator -() const { return Fp(-val); }

  bool operator ==(const Fp& t) const { return val == t.val; }
  bool operator !=(const Fp& t) const { return val != t.val; }
  
  operator ll() const { return val; }

};

class Comb {
  int nMax;
  vector<Fp> vFact;
  vector<Fp> vInvFact;
public:
  Comb(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact.at(0) = 1;
    for (int i = 1; i <= nMax; i++) vFact.at(i) = i * vFact.at(i-1);
    vInvFact.at(nMax) = vFact.at(nMax).inv();
    for (int i = nMax; i >= 1; i--) vInvFact.at(i-1) = i * vInvFact.at(i);
  }
  Fp fact(int n) { return vFact.at(n); }
  Fp comb(int n, int r) {
    return vFact.at(n) * vInvFact.at(r) * vInvFact.at(n-r);
  }
  // The number of permutation extracting r from n.
  Fp perm(int n, int r) {
    return vFact.at(n) * vInvFact.at(n-r);
  }
};

// ---- end mod.cc
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / (T)2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc
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

template <typename T>
ostream& operator<< (ostream& os, const set<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const multiset<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const map<T1, T2>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
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

// ---- end debug.cc
// ---- inserted library file segTree.cc
template <typename T,
	  typename S,
	  typename ADD_T    = T    (*)(T, T),
	  typename MOD_T    = T    (*)(int, S, T),
	  typename COMP_T   = S    (*)(S, S),
	  typename BINSCH_T = bool (*)(T)>
struct SegTree {

// private: // -- intended to be private, but formally public for debugging

  int size;
  vector<T> st;  // store
  vector<S> lz;  // for lazy evaluation
  ADD_T add;
  // CAUTION: Care should be taken when using mod() and com().
  //          Usually you should use modEx() and compEx() instead.
  MOD_T mod;
  COMP_T comp;
  T unitT;
  S unitS;

  // modEx and compEx: Function mod and comp with handling of unitS
  T modEx(int k, S f, T x) { return f == unitS ? x : mod(k, f, x); }
  S compEx(S f, S g) { return f == unitS ? g : g == unitS ? f : comp(f, g); }

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
  int binsch(BINSCH_T pred) {
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
      T lval1 = add(lval, t1);
      bool b = pred(lval1);
      // DLOG("sub1 n", n, "lo,hi", lo, hi, "lval", lval,
      //      "t1,t2", t1, t2, "lval1", lval1, "b", (b?"True":"False"));
      if (b) {
	return recF(recF, 2*n + 1, lo, mi, lval);
      }else {
	return recF(recF, 2*n + 2, mi, hi, lval1);
      }
    };
    // DLOG("binsch IN st = ", st);
    // DLOG("binsch IN lz = ", st);
    int ret = sub1(sub1, 0, 0, size, unitT);
    // DLOG("binsch OUT = ", ret);
    return ret;
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
		    bool with_binsch, BINSCH_T pred) {
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
	  // cout << "i = " << i << ", cVec = " << cVec << endl;
	}else {
	  auto errRep = [&]() -> void {
	    cout << "vecData = " << vecData << endl;
	    cout << "vecL = " << vecL << endl;
	    cout << "vecR = " << vecR << endl;
	    cout << "vecUpd = " << vecUpd << endl;
	    cout << "i = " << i << endl;
	  };
	  if (!with_binsch || i % 4 == 1) {
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
	      cout << "cVec = " << cVec << endl;
	      T naive = unitT;
	      for (int ii = 0; ii < vecSize + 1; ii++) {
		cout << "i = " << ii << ", naive = " << naive
		     << ", valSegTree = " << query(0, ii) << endl;
		if (ii < vecSize) naive = add(naive, cVec.at(ii));
	      }
	      cout << "p = " << p << ", q = " << q << endl;
	      assert(false);
	    }
	  }
	}
      }
    }
  };

};

// ---- end segTree.cc
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  MOD = 998244353;
  ll N; cin >> N;
  vector<pair<ll,ll>> XD(N);
  for (ll i = 0; i < N; i++) {
    ll x, d; cin >> x >> d;
    XD.at(i) = make_pair(x, d);
  }
  sort(XD.begin(), XD.end());
  vector<ll> hull(N);
  for (ll i = N-1; i >= 0; i--) {
    auto check = [&](ll z) -> bool {
      return XD.at(z).first < XD.at(i).first + XD.at(i).second;
    };
    hull.at(i) = binsearch<ll>(check, i, N);
  }
  DLOG("hull", hull);

  using DAT = ll;
  using OP = ll;
  auto xAdd = [](DAT x, DAT y) -> DAT { return max(x, y); };
  auto xMod = [](int k, OP f, DAT x) -> DAT { return f; };
  auto xComp = [](OP h, OP g) -> OP { return h; };
  DAT unit1 = LLONG_MIN;
  OP unit2 = -1; // assigned number is non-negative
  vector<DAT> init_vec(N);
  SegTree<DAT, OP, decltype(xAdd), decltype(xMod), decltype(xComp)>
    st(init_vec, xAdd, xMod, xComp, unit1, unit2);

  for (ll i = N-1; i >= 0; i--) {
    if (hull.at(i) == i) {
      st.update(i, i+1, i);
    }else {
      ll m = st.query(i+1, hull.at(i) + 1);
      st.update(i, i+1, m);
    }
  }

  vector<Fp> cnt(N + 1);
  cnt.at(N) = 1;
  for (ll i = N-1; i >= 0; i--) {
    cnt.at(i) = cnt.at(i+1) + cnt.at(st.query(i,i+1) + 1);
  }
  DLOG("cnt", cnt);
  cout << cnt.at(0) << endl;

  return 0;
}

