#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(mod matrix)

// ---- inserted function f:gcd from util.cc

tuple<ll, ll, ll> mut_div(ll a, ll b, ll c, bool eff_c = true) {
  // auto [g, s, t] = mut_div(a, b, c, eff_c)
  //    If eff_c is true (default),
  //        g == gcd(|a|, |b|) and as + bt == c, if such s,t exists
  //        (g, s, t) == (-1, -1, -1)            otherwise
  //    If eff_c is false,                                 
  //        g == gcd(|a|, |b|) and as + bt == g           
  //    N.b.  gcd(0, t) == gcd(t, 0) == t.
  if (a == 0) {
    if (eff_c) {
      if (c % b != 0) return {-1, -1, -1};
      else            return {abs(b), 0, c / b};
    }else {
      if (b < 0) return {-b, 0, -1};
      else       return { b, 0,  1};
    }
  }else {
    auto [g, t, u] = mut_div(b % a, a, c, eff_c);
    // DLOGK(b%a, a, c, g, t, u);
    if (g == -1) return {-1, -1, -1};
    return {g, u - (b / a) * t, t};
  }
}

// auto [g, s, t] = eGCD(a, b)  --->  sa + tb == g == gcd(|a|, |b|)
//    N.b.  gcd(0, t) == gcd(t, 0) == t.
tuple<ll, ll, ll> eGCD(ll a, ll b) { return mut_div(a, b, 0, false); }

pair<ll, ll> crt_sub(ll a1, ll x1, ll a2, ll x2) {
  // DLOGKL("crt_sub", a1, x1, a2, x2);
  a1 = a1 % x1;
  a2 = a2 % x2;
  auto [g, s, t] = mut_div(x1, -x2, a2 - a1);
  // DLOGK(g, s, t);
  if (g == -1) return {-1, -1};
  ll z = x1 / g * x2;
  // DLOGK(z);
  s = s % (x2 / g);
  ll r = (x1 * s + a1) % z;
  // DLOGK(r);
  if (r < 0) r += z;
  // DLOGK(r);
  return {r, z};
};

// Chinese Remainder Theorem
//
//    r = crt(a1, x1, a2, x2)
//    ==>   r = a1 (mod x1);  r = a2 (mod x2);  0 <= r < lcm(x1, x2)
//    If no such r exists, returns -1
//    Note: x1 and x2 should >= 1.  a1 and a2 can be negative or zero.
//
//    r = crt(as, xs)
//    ==>   for all i. r = as[i] (mod xs[i]); 0 <= r < lcm(xs)
//    If no such r exists, returns -1
//    Note: xs[i] should >= 1.  as[i] can be negative or zero.
//          It should hold: len(xs) == len(as) > 0

ll crt(ll a1, ll x1, ll a2, ll x2) { return crt_sub(a1, x1, a2, x2).first; }

ll crt(vector<ll> as, vector<ll> xs) {
  // DLOGKL("crt", as, xs);
  assert(xs.size() == as.size() && xs.size() > 0);
  ll r = as[0];
  ll z = xs[0];
  for (size_t i = 1; i < xs.size(); i++) {
    // DLOGK(i, r, z, as[i], xs[i]);
    tie(r, z) = crt_sub(r, z, as[i], xs[i]);
    // DLOGK(r, z);
    if (r == -1) return -1;
  }
  return r;
}

// ---- end f:gcd

// ---- inserted library file mod.cc

template<int mod=0>
struct FpG {   // G for General
  static ll dyn_mod;

  static ll getMod() {
    if (mod == 0) return dyn_mod;
    else          return mod;
  }

  static void setMod(ll _mod) {  // effective only when mod == 0
    dyn_mod = _mod;
  }

  static ll _conv(ll x) {
    if (x >= getMod())  return x % getMod();
    if (x >= 0)         return x;
    if (x >= -getMod()) return x + getMod();
    ll y = x % getMod();
    if (y == 0) return 0;
    return y + getMod();
  }

  ll val;

  FpG(int t = 0) : val(_conv(t)) {}
  FpG(ll t) : val(_conv(t)) {}
  FpG(const FpG& t) : val(t.val) {}
  FpG& operator =(const FpG& t) { val = t.val; return *this; }
  FpG& operator =(ll t) { val = _conv(t); return *this; }
  FpG& operator =(int t) { val = _conv(t); return *this; }

  FpG& operator +=(const FpG& t) {
    val += t.val;
    if (val >= getMod()) val -= getMod();
    return *this;
  }

  FpG& operator -=(const FpG& t) {
    val -= t.val;
    if (val < 0) val += getMod();
    return *this;
  }

  FpG& operator *=(const FpG& t) {
    val = (val * t.val) % getMod();
    return *this;
  }

  FpG inv() const {
    if (val == 0) {
      throw runtime_error("FpG::inv(): called for zero.");
    }
    auto [g, u, v] = eGCD(val, getMod());
    return FpG(u);
  }

  FpG& operator /=(const FpG& t) {
    return (*this) *= t.inv();
  }

  FpG operator +(const FpG& t) const { return FpG(val) += t; }
  FpG operator -(const FpG& t) const { return FpG(val) -= t; }
  FpG operator *(const FpG& t) const { return FpG(val) *= t; }
  FpG operator /(const FpG& t) const { return FpG(val) /= t; }
  FpG operator -() const { return FpG(-val); }

  bool operator ==(const FpG& t) const { return val == t.val; }
  bool operator !=(const FpG& t) const { return val != t.val; }
  
  operator ll() const { return val; }

  friend FpG operator +(int x, const FpG& y) { return FpG(x) + y; }
  friend FpG operator -(int x, const FpG& y) { return FpG(x) - y; }
  friend FpG operator *(int x, const FpG& y) { return FpG(x) * y; }
  friend FpG operator /(int x, const FpG& y) { return FpG(x) / y; }
  friend bool operator ==(int x, const FpG& y) { return FpG(x) == y; }
  friend bool operator !=(int x, const FpG& y) { return FpG(x) != y; }
  friend FpG operator +(ll x, const FpG& y) { return FpG(x) + y; }
  friend FpG operator -(ll x, const FpG& y) { return FpG(x) - y; }
  friend FpG operator *(ll x, const FpG& y) { return FpG(x) * y; }
  friend FpG operator /(ll x, const FpG& y) { return FpG(x) / y; }
  friend bool operator ==(ll x, const FpG& y) { return FpG(x) == y; }
  friend bool operator !=(ll x, const FpG& y) { return FpG(x) != y; }
  friend FpG operator +(const FpG& x, int y) { return x + FpG(y); }
  friend FpG operator -(const FpG& x, int y) { return x - FpG(y); }
  friend FpG operator *(const FpG& x, int y) { return x * FpG(y); }
  friend FpG operator /(const FpG& x, int y) { return x / FpG(y); }
  friend bool operator ==(const FpG& x, int y) { return x == FpG(y); }
  friend bool operator !=(const FpG& x, int y) { return x != FpG(y); }
  friend FpG operator +(const FpG& x, ll y) { return x + FpG(y); }
  friend FpG operator -(const FpG& x, ll y) { return x - FpG(y); }
  friend FpG operator *(const FpG& x, ll y) { return x * FpG(y); }
  friend FpG operator /(const FpG& x, ll y) { return x / FpG(y); }
  friend bool operator ==(const FpG& x, ll y) { return x == FpG(y); }
  friend bool operator !=(const FpG& x, ll y) { return x != FpG(y); }

  friend istream& operator>> (istream& is, FpG& t) {
    ll x; is >> x;
    t = x;
    return is;
  }

  friend ostream& operator<< (ostream& os, const FpG& t) {
    os << t.val;
    return os;
  }

};
template<int mod>
ll FpG<mod>::dyn_mod;

template<int mod=0>
class CombG {
  int nMax;
  vector<FpG<mod>> vFact;
  vector<FpG<mod>> vInvFact;
public:
  CombG(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact.at(0) = 1;
    for (int i = 1; i <= nMax; i++) vFact.at(i) = i * vFact.at(i-1);
    vInvFact.at(nMax) = vFact.at(nMax).inv();
    for (int i = nMax; i >= 1; i--) vInvFact.at(i-1) = i * vInvFact.at(i);
  }
  FpG<mod> fact(int n) { return vFact.at(n); }
  FpG<mod> comb(int n, int r) {
    if (r < 0 || r > n) return 0;
    return vFact.at(n) * vInvFact.at(r) * vInvFact.at(n-r);
  }
  // The number of permutation extracting r from n.
  FpG<mod> perm(int n, int r) {
    return vFact.at(n) * vInvFact.at(n-r);
  }
};

constexpr int primeA = 1'000'000'007;
constexpr int primeB = 998'244'353;          // '
using FpA = FpG<primeA>;
using FpB = FpG<primeB>;
using CombA = CombG<primeA>;
using CombB = CombG<primeB>;

// ---- end mod.cc

// ---- inserted function f:power from util.cc
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

// ad-hoc power function
template<typename T, typename Op>
T ah_power(T a, ll b, const T& unit_t, Op op) {
  T two_pow = a;
  T ret = unit_t;
  while (b > 0) {
    if (b & 1LL) ret = op(ret, two_pow);
    two_pow = op(two_pow, two_pow);
    b >>= 1;
  }
  return ret;
}
// ---- end f:power

// ---- inserted library file matrix.cc

#if ! defined(DLOG_LIB)
  #define DLOG_LIB(...)
  #define DLOGK_LIB(...)
  #define DLOGKL_LIB(lab, ...)
#endif

struct MyExc : exception {};

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
    mem.resize(dimI*dimJ, (T)0);
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

  static Matrix fromVec(const vector<T>& svec, bool isColVect = true) {
    vector<vector<T>> vec;
    vec.push_back(svec);
    Matrix ret = Matrix(vec);
    if (isColVect) return ret.transpose();
    else           return ret;
  }

  vector<T> rowVec(size_t row) const {
    vector<T> result(dimJ);
    for (size_t i = 0; i < dimJ; i++) result[i] = at(row, i);
    return result;
  }

  vector<T> colVec(size_t col) const {
    vector<T> result(dimI);
    for (size_t i = 0; i < dimI; i++) result[i] = at(i, col);
    return result;
  }

  void partial_subst(const Matrix<T>& r, size_t i0, size_t j0,
		     size_t i1, size_t j1, size_t i2, size_t j2) {
    for (size_t i = i1; i < i2; i++) {
      for (size_t j = j1; j < j2; j++) at(i0 + i, j0 + j) = r.at(i, j);
    }
  }

  void partial_subst(const Matrix<T>& r) {
    return partial_subst(r, 0, 0, 0, 0, r.dimI, r.dimJ);
  }

  void fill_row(const auto& vec, size_t i, size_t j0 = 0) {
    for (size_t j = 0; j < vec.size(); j++) at(i, j0 + j) = vec[j];
  }

  void fill_col(const auto& vec, size_t j, size_t i0 = 0) {
    for (size_t i = 0; i < vec.size(); i++) at(i0 + i, j) = vec[i];
  }

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

  /* aux functions for sweepout */

  void basic_mult(int i, T t) {
    for (size_t j = 0; j < dimJ; j++) at(i, j) *= t;
  }

  void basic_xchg(int i1, int i2) {
    for (size_t j = 0; j < dimJ; j++) swap(at(i1, j), at(i2, j));
  }

  void basic_mult_add(int i1, T t, int i2) {
    for (size_t j = 0; j < dimJ; j++) at(i2, j) += at(i1, j) * t;
  }

  bool is_zero(T t) const { return t == (T)0; }

  pair<size_t, size_t> find_nz(size_t i0, size_t j0) {
    for ( ; j0 < dimJ; j0++) {
      size_t i = i0;
      for ( ; i < dimI && is_zero(at(i, j0)); i++);
      if (i < dimI) return {i, j0};
    }
    return {dimI, dimJ};
  }

  /*
    Sweepout for the vertical direction.
    Returns a pair (rank, det)
      rank: the rank of the matrix
      det: internally used for determinant calculation
    WARNNIG: T should be a field.
   */
  pair<size_t, T> self_sweepout() {
    T det = (T)1;
    size_t j0 = 0;
    size_t i0 = 0;
    // DLOGKL("  ", *this);
    for ( ; i0 < dimI; i0++, j0++) {
      auto [i1, j1] = find_nz(i0, j0);
      if (i1 == dimI) break;
      j0 = j1;
      if (i1 != i0) {
	det = -det;
	basic_xchg(i0, i1);
      }
      det *= at(i0, j0);
      basic_mult(i0, (T)1 / at(i0, j0));
      for (size_t i = 0; i < dimI; i++) {
	if (i == i0) continue;
	basic_mult_add(i0, -at(i, j0), i);
      }
      // DLOGKL("  ", *this);
    }
    return {i0, det};
  }
  
  pair<size_t, T> sweepout() const { 
    Matrix<T> res1(*this);
    return res1.self_sweepout();
  }

  /* WARNING: T should be a field. */
  T determinant() const {
    precond((defDimIJ = dimI) == dimJ, "only for square matrix");
    auto [rank, det] = sweepout();
    return (rank == dimI) ? det : (T)0;
  }

  /* WARNING: T should be a field. */
  Matrix<T> inverse() const {
    precond((defDimIJ = dimI) == dimJ, "only for square matrix");
    Matrix<T> work(dimI, dimI * 2);
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimI; j++) {
	work.at(i, j) = at(i, j);
	work.at(i, j + dimI) = (i == j) ? (T)1 : (T)0;
      }
    }
    work.self_sweepout();
    if (!is_zero(work.at(dimI-1, dimI-1) - (T)1)) {
      cerr << "inverse() for non-regular matrix." << endl;
      throw MyExc();
    }
    Matrix<T> ret(dimI, dimI);
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimI; j++) ret.at(i, j) = work.at(i, j + dimI);
    }
    return ret;
  }

  /* WARNING: T should be a field. */
  // Solves linear euqation "(*this) x = bs".
  //        dimI and dimJ can be different.
  // arguments:
  //    bs ... vector<T>.  bs.size() == dimI should hold.
  //    ret_kernel ... if false, returned kernel is an empty vector.
  // return value: optional<pair<vector<T>, vector<vector<T>>>
  //    If there is no solution, nullopt is returned.
  //    Otherwise, ret.value() is a pair [sol, kernel].
  //      sol ... a solution.  sol.size() is dimJ.
  //      kernel ... A basis of the space { x | (*this) x = 0 }.
  // Typical usage:
  //    auto ret = mat.linSolution(bs);
  //    if (!ret.has_value()) cout << "No solution\n";
  //    else {
  //      [sol, _dummy] = ret.value();
  //      cout << "Solution is: " << sol << "\n";
  //    }
  optional<pair<vector<T>, vector<vector<T>>>>
  linSolution(const vector<T>& bs, bool ret_kernel = true) const {
    Matrix<T> work(dimI, dimJ + 1);
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimJ; j++) { work.at(i, j) = at(i, j); }
      work.at(i, dimJ) = bs[i];
    }
    auto [rank, _] = work.self_sweepout();
    // DLOGK(rank, work);
    if (rank > 0) {
      bool succ = false;
      for (size_t j = 0; j < dimJ; j++) {
        if (work.at(rank - 1, j) != (T)0) { succ = true; break; }
      }
      if (!succ) { return nullopt; }
    }
    vector<T> sol(dimJ, (T)0);
    {
      size_t j = 0;
      for (size_t i = 0; i < rank; i++, j++) {
        for ( ; work.at(i, j) == (T)0; j++);
        sol[j] = work.at(i, dimJ);
      }
    }
    vector<vector<T>> kernel;
    if (ret_kernel) {
      vector<bool> cor(dimJ, false);
      size_t i = 0;
      for (size_t j = 0 ; j < dimJ; j++) {
        if (i == dimI || work.at(i, j) == (T)0) {
          vector<T> kv(dimJ);
          kv[j] = (T)1;
          for (size_t p = 0, q = 0; p < i; p++, q++) {
            while (!cor[q]) q++;
            kv[q] = -work.at(p, j);
          }
          kernel.push_back(move(kv));
        }else {
          cor[j] = true;
          if (i < dimI) i++;
        }
      }
    }
    return make_optional(make_pair(move(sol), move(kernel)));
  }


};

template<typename T> size_t Matrix<T>::defDimIJ = 0;

template<typename T>
ostream& operator<< (ostream& os, const Matrix<T>& mat) {
  return mat.ostr_out(os);
}

// ---- end matrix.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<string> S(N);
  ll lmax = 0;
  for (ll i = 0; i < N; i++) {
    cin >> S[i];
    lmax = max(lmax, S[i].size());
  }
  using sta = pair<ll, ll>;
  vector<string> suff;
  suff.push_back("");
  for (ll i = 0; i < N; i++) {
    for (size_t j = 0; j <= S[i].size(); j++) {
      suff.push_back(S[i].substr(j, S[i].size() - j));
    }
  }
  sort(suff.begin(), suff.end());
  suff.erase(unique(suff.begin(), suff.end()), suff.end());
  vector cf(sz, vector(sz, vector(6, Fp(0))));
  ll sz = suff.size();
  for (ll i = 0; i < sz; i++) {
    string& sj = S[j];
    ll sjz = sj.size();
    for (ll j = 0; j < N; j++) {
      string& si = suff[i];
      ll siz = si.size();
      if (sj == si.substr(0, sjz)) {
        ll p = find(suff.begin(), suff.end(), si.subst(sjz, siz - sjz))
          - suff.begin();
        if (p < sz) {
          cf[i][p][sjz]++;
        }
      }else if (si == sj.substr(0, siz)) {
        ll p = find(suff.begin(), suff.end(), sj.subst(siz, sjz - siz))
          - suff.begin();
        if (p < sz) {
          cf[i][p][siz]++;
        }
      }
    }
  }
  ll dim = sz * lmax;
  matrix mat(dim, dim);
  for (ll i = 0; i < sz; i++) {
    for (ll j = 0; j < lmax
    mat.at(i, 
  }

  


  return 0;
}

