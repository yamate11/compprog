#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(matrix debug)
// --> f:power matrix f:<< debug
// ---- inserted function power from util.cc
/* *** WARNING ***  
      ll x = power(10, 12) 
   does not work since it is interpreted as 
      ll x = power<int>((int)10, 12)
   Use power<ll>(10, 12) or power(10LL, 12).
 */
template<typename T>
T power(T a, ll b) {
  T twoPow = a;
  T rv(1);
  while (b > 0) {
    if (b & 1LL) rv *= twoPow;
    twoPow *= twoPow;
    b >>= 1;
  }
  return rv;
}
// ---- end power
// ---- inserted library file matrix.cc

template <typename T>
struct Matrix {
// private:
  size_t dimI;
  size_t dimJ;
  vector<T> mem;
  static size_t defDimIJ;

  void init_from_vv(const vector<vector<T>>& vec) {
    dimI = vec.size();
    dimJ = vec.at(0).size();
    if (dimI == dimJ) defDimIJ = dimI;
    mem.resize(dimI*dimJ);
    for (size_t i = 0; i < dimI; i++) {
      assert(vec.at(i).size() == dimJ);
      for (size_t j = 0; j < dimJ; j++) at(i,j) = vec.at(i).at(j);
    }
  }

// public:

  void precond(bool b, string msg) const {
    if (!b) {
      cerr << "**FATAL** " << msg << endl;
      exit(1);
    }
  }

  T&       at(size_t i, size_t j)       { return mem.at(i*dimJ + j); }
  const T& at(size_t i, size_t j) const { return mem.at(i*dimJ + j); }
  
  Matrix(size_t m, size_t n) : dimI(m), dimJ(n), mem(dimI*dimJ) {
    if (dimI == dimJ) defDimIJ = dimI;
  }

  Matrix(const vector<vector<T>>& vec) { init_from_vv(vec); }
  Matrix(initializer_list<vector<T>> il) {
    init_from_vv(vector<vector<T>>(il)); 
  }

  /*  They will be constructed as implicitly-defined constructors???
  Matrix(const Matrix<T>& mat)
    : dimI(mat.dimI), dimJ(mat.dimJ), mem(mat.mem) {}
  Matrix(Matrix<T>&& mat)
    : dimI(mat.dimI), dimJ(mat.dimJ), mem(move(mat.mem)) {}
  */

  Matrix(const T& t) {
    precond(defDimIJ != 0, "defDimIJ not set Matrix(T)");
    dimI = dimJ = defDimIJ;
    mem.resize(dimI*dimJ);
    for (size_t i = 0; i < dimI; i++) at(i,i) = t;
  }

  /*
  Matrix<T>& operator =(const Matrix<T>& r) {
    dimI = r.dimI;
    dimJ = r.dimJ;
    mem = r.mem;
    return *this;
  }
  */

  Matrix<T>& operator +=(const Matrix<T>& r) {
    precond(dimI == r.dimI && dimJ == r.dimJ, "dimension mismatch");
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimJ; j++) at(i,j) += r.at(i,j);
    }
    return *this;
  }

  Matrix<T>& operator -=(const Matrix<T>& r) {
    precond(dimI == r.dimI && dimJ == r.dimJ, "dimension mismatch");
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimJ; j++) at(i,j) -= r.at(i,j);
    }
    return *this;
  }

  Matrix<T> operator +(const Matrix<T>& r) const {
    return Matrix<T>(*this) += r;
  }

  Matrix<T> operator -(const Matrix<T>& r) const {
    return Matrix<T>(*this) -= r;
  }

  // Unlike + and -, we anyway need a new object for multiplication.
  // Thus, we first define operator *, and then define operator *=
  // using operator *.
  Matrix<T> operator *(const Matrix<T>& r) const {
    precond(dimJ == r.dimI, "dimension mismatch");
    Matrix<T> result(dimI, r.dimJ);
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < r.dimJ; j++) {
	T s = 0;
	for (size_t k = 0; k < dimJ; k++)  s += at(i,k) * r.at(k,j);
	result.at(i,j) = s;
      }
    }
    return result;
  }

  Matrix<T>& operator *=(const Matrix<T>& r) {
    return *this = *this * r;
  }

  bool operator ==(const Matrix<T>& r) const {
    return dimI == r.dimI && dimJ == r.dimJ && mem == r.mem;
  }
  bool operator !=(const Matrix<T>& r) const { return !(*this == r); }

  ostream& ostr_out(ostream& os) const {
    vector<vector<T>> vec(dimI, vector<T>(dimJ));
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimJ; j++) vec.at(i).at(j) = at(i,j);
    }
    return os << vec;
  }

  Matrix<T> matpower(ll x) const {
    precond((defDimIJ = dimI) == dimJ, "only for square matrix");
    return power(*this, x);
  }

  Matrix<T> transpose() const {
    Matrix<T> res(dimJ, dimI);
    for (size_t i = 0; i < dimI; i++) for (size_t j = 0; j < dimJ; j++) {
	res.at(j,i) = at(i,j);
      }
    return res;
  }

  /*
    Sweepout for the vertical direction.
    Returning vector is the history of the exchange operations.
   */
  vector<pair<int, int>> self_sweepout() {
    vector<pair<int, int>> xchg;
    for (size_t i = 0; i < min(dimI, dimJ); i++) {
      size_t ii = i; 
      for ( ; ii < dimI && at(ii, i) == (T)0; ii++);
      if (ii == dimI) continue;
      if (i != ii) {
	for (size_t j = i; j < dimJ; j++) swap(at(i, j), at(ii, j));
	xchg.emplace_back(i, ii);
      }
      for (size_t k = ii + 1; k < dimI; k++) {
	T x = at(k, i) / at(i, i);
	at(k, i) = 0;
	for (size_t j = i + 1; j < dimJ; j++) at(k, j) -= x * at(i, j);
      }
      // DLOG("i", i);
      // DLOG("*this", *this);
    }
    return xchg;
  }
  
  pair<Matrix<T>, vector<pair<int, int>>> sweepout() const { 
    Matrix<T> res1(*this);
    auto res2 = res1.self_sweepout();
    return make_pair(res1, res2);
  }

  T determinant() const {
    precond((defDimIJ = dimI) == dimJ, "only for square matrix");
    auto pr = sweepout();
    auto m = pr.first;
    auto hist = pr.second;
    T ret = pr.second.size() % 2 == 0 ? 1 : -1;
    for (size_t i = 0; i < dimI; i++) ret *= m.at(i, i);
    return ret;
  }

};

template<typename T> size_t Matrix<T>::defDimIJ = 0;

template<typename T>
ostream& operator<< (ostream& os, const Matrix<T>& mat) {
  return mat.ostr_out(os);
}

// ---- end matrix.cc
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
// @@ !! LIM  -- end mark --

using ull = unsigned long long;

struct logint {
  unsigned long long v;
  logint operator +=(logint o) { v = (v ^ (o.v)); return v; }
  logint operator *=(logint o) { v = (v & (o.v)); return v; }
  logint operator +(logint o) const { return logint(v) += o; }
  logint operator *(logint o) const { return logint(v) *= o; }
  logint(unsigned long long v_ = 0) : v(v_) {}
  operator ll() const { return v; }
};

template<typename T>
T mypower(T a, ll b, T unit) {
  T twoPow = a;
  T rv = unit;
  while (b > 0) {
    if (b & 1LL) rv *= twoPow;
    twoPow *= twoPow;
    b >>= 1;
  }
  return rv;
}

constexpr unsigned long long unit = 0xFFFFFFFFFFFFFFFF;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K, M; cin >> K >> M; M--;
  vector<ll> A(K), C(K);
  for (ll i = 0; i < K; i++) cin >> A.at(i);
  for (ll i = 0; i < K; i++) cin >> C.at(i);
  Matrix<logint> mat(K, K);
  Matrix<logint> matUnit(K, K);
  for (ll i = 0; i < K; i++) matUnit.at(i,i) = unit;
  for (ll i = 0; i < K-1; i++) mat.at(i, i+1) = unit;
  for (ll i = 0; i < K; i++) mat.at(K-1, i) = C.at(K-1 - i);
  Matrix<logint> mA(K, 1);
  for (ll i = 0; i < K; i++) mA.at(i, 0) = A.at(i);
  Matrix<logint> ppp = mypower(mat, M, matUnit);
  DLOG("mat", mat, "matUnit", matUnit);
  DLOG("ppp", ppp);
  unsigned long long ans = (ppp * mA).at(0, 0);
  cout << ans << endl;

  return 0;
}

