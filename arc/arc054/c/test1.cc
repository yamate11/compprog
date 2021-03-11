#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(mod matrix)
// --> f:gcd mod f:power matrix
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

  Fp(ll t = 0) :
    val(t < 0 ? MOD + t % MOD : t >= MOD ? t % MOD : t) {}

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
  T rv = 1;
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
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  MOD = 998244353;

  ll N; cin >> N;
  Matrix<Fp> mat(N, N);
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      ll x; cin >> x; mat.at(i,j) = x;
    }
  }
  cout << (int)(mat.determinant()) << endl;

  return 0;
}

