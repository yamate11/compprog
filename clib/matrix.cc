#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Matrix

  *  Most convenient usage:
    Matrix<T> mat0(M, N);  // You always need two values even if M == N
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) { 
        cin >> mat0.at(i, j); }}  // Note: at() has two arguments 
                                  //       and 0-indexed.

  *  Constructors

    // initializer
    Matrix<double> mat1({{0.5, -sqrt(3)/2}, {sqrt(3)/2, 0.5}});
          
    // dimensions, fill with 0 or def value
    Matrix<Fp> mat2(4,2);

    // copy, move constructors exist:
    Matrix<Fp> mat1(mat0);
    Matrix<Fp> mat2(move(mat0));

    // c * identity matrix, where c \in T.
    Matrix<ll>::defDimIJ = 3;
    Matrix<ll> mat3(7);   // mat3 == 7 * I, where I is the identity matrix.
                          // for this construction, you need to define defDimIJ
         // for defDimIJ, see "Note on the power function" below

  *  Construct n x 1 or 1 x m matrix from a vector

    static Matrix fromVec(const vector<T>& svec, bool isColVect = true)
         // if isColVect == false, then returns a row vector.

  *  Row vector and Column vector

    vector<T> vec = mat1.rowVec(size_t row);
    vector<T> vec = mat1.colVec(size_t row);

  *  Partial substitutions

    mat1.partial_subst(mat2);
        // Let dim of mat1 and mat2 are (m1, n1) and (m2, n2)
        // They should be m1 >= m2 and n1 >= n2
        // The left-upper corner of mat1 is substituted by mat2.

    mat1.partial_subst(mat2, 1, 2, 3, 4, 5, 6);
        // the left-upper point of the target is (1, 2)
        // the left-upper point of the source is (3, 4)
        // the right-lower point of the source is (5 - 1, 6 - 1)

    // Fills the ith row or the jth column, possibly from an intermediate point.
    mat1.fill_row(vec1, i);
    mat1.fill_row(vec1, i, start);
    mat1.fill_col(vec2, j);
    mat1.fill_col(vec2, j, start);

  *  Operations + / - / *

    Matrix<Fp> mat4(2, 3);
    cout << mat2 + mat2 << mat2 - mat2 << mat2 * mat4;
    mat4 += Matrix<Fp>(2, 3);


  *  Power

    cout << mat1.matpower(10); 

    Matrix<ll>::defDimIJ = 2;
    cout << power(mat1, 10)  // same as above   


  *  Transpose

    cout << mat2.transpose();


  *  Rank, Determinant, Inverse, ... using Sweep-out

    ** Warning: for these methods, T must be a FIELD. **

    auto [rank, dummy] = mat1.self_sweepout();     
         // Makes mat1 over-triangle.  Returns the rank.

    auto [rank, dummy] = mat1.sweepout
         // Same as above, but mat1 is not modified.

    mat1.determinant()
         // Returns the determinant

    mat1.inverse()
         // Returns the inverse matrix.

  *  Solves linear equation   A x = b

    optional<pair<vector<T>, vector<vector<T>>>>
    linSolution(const vector<T>& bs, bool ret_kernel = true);

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



  *  Note on the power function

    It is basically ok to use the general power() function defined in
    util.cc.  One problem is that, then Matrix<T> should support:
        Matrix<T> mat = 1;
    for the initial value.  But we cannot determine the dimension in
    general.  Matrix<T, dim> could be an option, but it is not convenient
    in cases where queries with different dimensions exist.  Thus, we
    introduce a static field defDimIJ, and use it as the default dimension.
    Various methods, including constructors for square matrices
    change the value of the field silently.  Thus, in most cases it should
    be OK:
        Matrix<Fp> mat(n, n);   // This set Matrix<Fp>::defDimIJ := n
        cout << power(mat, 10);
    You can also use an alternative method matpower(), which also changes
    the field value silently.    
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN(f:power)

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

// @@ !! END ---- matrix.cc

