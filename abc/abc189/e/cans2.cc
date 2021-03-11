#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(matrix)
// --> f:power matrix
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
// ---- end power
// ---- inserted library file matrix.cc

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
    for ( ; i0 < dimI; i0++) {
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

};

template<typename T> size_t Matrix<T>::defDimIJ = 0;

template<typename T>
ostream& operator<< (ostream& os, const Matrix<T>& mat) {
  return mat.ostr_out(os);
}

// ---- end matrix.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> X(N), Y(N);
  for (ll i = 0; i < N; i++) cin >> X[i] >> Y[i];
  ll M; cin >> M;
  vector<Matrix<ll>> mats;
  Matrix<ll> curm({{1,0,0}, {0,1,0}, {0,0,1}});
  mats.push_back(curm);
  for (ll i = 0; i < M; i++) {
    ll tp; cin >> tp;
    Matrix<ll> opm(3, 3);
    if (tp == 1) {
      opm = Matrix<ll>({{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}});
    }else if (tp == 2) {
      opm = Matrix<ll>({{0, -1, 0}, {1, 0, 0}, {0, 0, 1}});
    }else {
      ll p; cin >> p;
      if (tp == 3) {
        opm = Matrix<ll>({{-1, 0, 2*p}, {0, 1, 0}, {0, 0, 1}});
      }else if (tp == 4) {
        opm = Matrix<ll>({{1, 0, 0}, {0, -1, 2*p}, {0, 0, 1}});
      }
    }
    curm = opm * curm;
    mats.push_back(curm);
  }
  ll Q; cin >> Q;
  for (ll i = 0; i < Q; i++) {
    ll a, b; cin >> a >> b; b--;
    const Matrix<ll>& mat = mats[a];
    Matrix<ll> pt({{X[b]}, {Y[b]}, {1}});
    Matrix<ll> tr = mat * pt;
    cout << tr.at(0, 0) << " " << tr.at(1, 0) << "\n";
  }

  return 0;
}

