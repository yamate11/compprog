#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Matrix

  https://yamate11.github.io/blog/posts/2024/03-30-matrix/

  Needs AO (Algebra Operations) as template parameter.

  Mat<AO> ... basic usage
  Matrix<T> == Mat<AO_def<T>> ... Using T's natural operations. 

  In the following, let T be the underlying Type of AO  (T == ult_t<AO>)

  *  Constructors

     Mat(int dimI_, int dimJ_);
     Mat(int dimI_, int dimJ_, T t);
     Mat(int dimI_, int dimJ_, const vector<T>& vec);  
         // from one-dim vector
         // If one of dimI_, dimJ_ is non-positive, it is calculated from the other and vec.size().
     Mat(int dimI_, int dimJ_, vector<T>&&      vec);
     Mat(initializer_list<initializer_list<T>> il);
     Mat(const Part& cs);     // see below for struct Part
    
    Note: to make (n,1) matrix from a vector, Mat(0, 1, vec) is handy.

  * Other builders

     Mat from_vvec(const vector<vector<T>>& vvec);      // from two-dim vector
     Mat zero() const;      // zero matrix.  dimI may be different from dimJ.  
                            // This is a NON-STATIC member.  Dimensions are taken from (*this).
     Mat unit() const;      // unit matrix.  dimI == dimJ should hold.
     Mat rowVec(int i) const;
     Mat colVec(int j) const;
     
  * struct Part

    * constructor:  Part(const Mat& mat_, int i_size_ = -1, int j_size_ = -1, int i_0_ = 0, int j_0_ = 0);
         Small matrix of mat_.  Top-Left corner is (i_0_, j_0_).  Sizes are i_size_ and j_size_.
    * member functions of Mat:   
         part(int, int, int, int)  ... small matrix of (*this).
         memcopy(const Part& part, int i_1 = 0, int j_1 = 0)  
            ... copy part into the block of (*this), whose top-left corner is (i_1, j_1)

  * operations ... +, -, *, +=, -=, *=, matpower(ll)

  * self_transpose(), transpose() 

  * sweepout, inverse, linSolution, ...

      * [rank, det] = mat.self_sweepout();   // vertical direction
      * [rank, det] = mat.sweepout();        // The resulting swept-out matrix is discarded.
      * omat = mat.inverse();                // omat is of type optional<Mat>
      * oo = mat.linSolution<flag>(bs);    
             // Solves linear equation mat * X = bs.
             // oo is of type optional<pair<Mat, vector<Mat>>>
             // If there is no solution, oo is nullopt.
             // Otherwise, let [sol, kernel] = oo;    sol: Mat,  kernel: vector<Mat>;
             //    sol is a solution: mat * sol == bs.
             // if flag is true, then kenel is a basis of space { x | mat * x = 0 }
             // if flag is false, then kernel is an empty vector.
          // Note: sometimes you need to add ".template" when calling it
          //       to teach the compiler that "<" after linSolution is not a "less than" symbol.
          //    e.g.   auto opt1 = mat.template linSolution<true>(bs);

 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN(power algOp)

template <typename T>
struct Matrix {

  struct Part {
    const Matrix& mat;
    int i_size;
    int j_size;
    int i_0;
    int j_0;
    Part(const Matrix& mat_, int i_size_ = -1, int j_size_ = -1, int i_0_ = 0, int j_0_ = 0)
      : mat(mat_), i_size(i_size_ >= 0 ? i_size_ : mat.dimI),
        j_size(j_size_ >= 0 ? j_size_ : mat.dimJ), i_0(i_0_), j_0(j_0_) {
      if (i_0 + i_size > mat.dimI or j_0 + j_size > mat.dimJ) throw domain_error("part");
    }
  };

  int dimI;
  int dimJ;
  bool rev_rc = false; // if true, the order in mem is column->row
  vector<T> mem;

  T&       at(int i, int j)       { return rev_rc ? mem[j*dimI + i] : mem[i*dimJ + j]; }
  const T& at(int i, int j) const { return rev_rc ? mem[j*dimI + i] : mem[i*dimJ + j]; }
  
  Matrix() : dimI(1), dimJ(1), mem(1) {}
  Matrix(int dimI_, int dimJ_) : dimI(dimI_), dimJ(dimJ_), mem(dimI*dimJ) {}
  Matrix(int dimI_, int dimJ_, const T& t) : dimI(dimI_), dimJ(dimJ_), mem(dimI*dimJ, t) {}

  template<typename Z>
  void _from_vec(int dimI_, int dimJ_, Z&& vec) {
    int sz = vec.size();
    dimI = dimI_ <= 0 ? sz / dimJ_ : dimI_;
    dimJ = dimJ_ <= 0 ? sz / dimI_ : dimJ_;
    if (dimI * dimJ != sz) throw domain_error("_from_vec: inconsistent sizes");
    mem = forward<Z>(vec);
  }
  Matrix(int dimI_, int dimJ_, const vector<T>& vec) { _from_vec(dimI_, dimJ_, vec); }
  Matrix(int dimI_, int dimJ_, vector<T>&&      vec) { _from_vec(dimI_, dimJ_, move(vec)); }

  Matrix(initializer_list<initializer_list<T>> il) {
    dimI = il.size();
    if (dimI == 0) throw domain_error("from_il: zero rows");
    dimJ = (*il.begin()).size();
    if (dimJ == 0) throw domain_error("from_il: zero columns");
    mem.resize(dimI * dimJ);
    int i = 0;
    for (auto it : il) {
      if ((int)it.size() != dimJ) throw domain_error("from_il: not in rectangular shape");
      int j = 0;
      for (const T& t : it) mem[i * dimJ + (j++)] = t;
      i++;
    }
  }

  Matrix(const Part& cs) : dimI(cs.i_size), dimJ(cs.j_size), mem(dimI*dimJ) {
    for (int i = 0; i < dimI; i++) for (int j = 0; j < dimJ; j++) at(i, j) = cs.mat.at(cs.i_0 + i, cs.j_0 + j);
  }

  bool operator ==(const Matrix& r) const {
    if (dimI != r.dimI or dimJ != r.dimJ) return false;
    if (rev_rc == r.rev_rc) return mem == r.mem;
    for (int i = 0; i < dimI; i++) for (int j = 0; j < dimJ; j++) if (at(i, j) != r.at(i, j)) return false;
    return true;
  }
  bool operator !=(const Matrix& r) const { return !(*this == r); }

  T _zero_T() const { return ::zero<T>(at(0, 0)); }
  T _one_T() const { return ::one<T>(at(0, 0)); }

  template<int sign>
  Matrix& _add_subt(const Matrix& r) {
    if (dimI != r.dimI or dimJ != r.dimJ) throw domain_error("_add_subt: dimension mismatch");
    for (int i = 0; i < dimI; i++) for (int j = 0; j < dimJ; j++) {
        if constexpr (sign > 0) at(i, j) += r.at(i, j);
        else                    at(i, j) -= r.at(i, j);
      }
    return *this;
  }
  Matrix& operator +=(const Matrix& r) { return _add_subt<1>(r); }
  Matrix& operator -=(const Matrix& r) { return _add_subt<-1>(r); }
  Matrix operator +(const Matrix& r) const { return Matrix(*this) += r; }
  Matrix operator -(const Matrix& r) const { return Matrix(*this) -= r; }

  Matrix operator *(const Matrix& r) const {
    if (dimJ != r.dimI) throw domain_error("mult: dimension mismatch");
    Matrix result(dimI, r.dimJ, _zero_T());
    for (int i = 0; i < dimI; i++) for (int j = 0; j < r.dimJ; j++) {
	for (int k = 0; k < dimJ; k++) result.at(i, j) += at(i, k) * r.at(k, j);
      }
    return result;
  }
  Matrix& operator *=(const Matrix& r) { return *this = *this * r; }

  Matrix& operator *=(const T& t) {
    for (int p = 0; p < dimI * dimJ; p++) mem[p] *= t;
    return *this;
  }
  friend Matrix operator *(const Matrix& mat, const T& t) { return Matrix(mat) *= t; }
  friend Matrix operator *(const T& t, const Matrix& mat) { // Mult of T might be non-commutative
    Matrix ret(mat);
    for (int p = 0; p < mat.dimI * mat.dimJ; p++) ret.mem[p] = t * ret.mem[p];
    return ret;
  }

  vector<T> operator *(const vector<T>& vec) const {
    auto m = (*this) * Matrix(0, 1, vec);
    return m.mem;
  }

  vector<T> operator *(vector<T>&& vec) const {
    auto m = (*this) * Matrix(0, 1, move(vec));
    return m.mem;
  }

  static Matrix from_vvec(const vector<vector<T>>& vvec) {
    int dimI_ = vvec.size();
    if (dimI_ == 0) throw domain_error("from_vvec: zero rows");
    int dimJ_ = vvec[0].size();
    if (dimJ_ == 0) throw domain_error("from_vvec: zero columns");
    Matrix ret(dimI_, dimJ_);
    for (int i = 0; i < dimI_; i++) {
      if ((int)vvec[i].size() != dimJ_) throw domain_error("from_vvec: not in rectangular shape");
      for (int j = 0; j < dimJ_; j++) ret.mem[i*dimJ_ + j] = vvec[i][j];
    }
    return ret;
  }

  Matrix zero() const { return Matrix(dimI, dimJ, _zero_T()); }
  Matrix unit() const {
    if (dimI != dimJ) throw domain_error("unit: dimension mismatch");
    Matrix ret(dimI, dimI, _zero_T());
    for (int i = 0; i < dimI; i++) ret.at(i, i) = _one_T();
    return ret;
  }
  Matrix one() const { return unit(); }  // for general operation Ring

  Part part(int i_size_ = -1, int j_size_ = -1, int i_0_ = 0, int j_0_ = 0) const {
    return Part(*this, i_size_, j_size_, i_0_, j_0_);
  }

  Matrix rowVec(int i) const { return Matrix(part(1, -1, i, 0)); }
  Matrix colVec(int j) const { return Matrix(part(-1, 1, 0, j)); }

  void memcopy(const Part& cs, int i_1 = 0, int j_1 = 0) {
    for (int i = 0; i < cs.i_size; i++) for (int j = 0; j < cs.j_size; j++) {
        at(i_1 + i, j_1 + j) = cs.mat.at(cs.i_0 + i, cs.j_0 + j);
      }
  }

  Matrix matpower(ll x) const { return power<Matrix>(*this, x); }

  Matrix& self_transpose() {
    rev_rc = not rev_rc;
    swap(dimI, dimJ);
    return *this;
  }
  Matrix transpose() { return Matrix(*this).self_transpose(); }

  /* aux functions for sweepout */

  void basic_mult(int i, T t) {               // multiplies i-th row by t
    for (int j = 0; j < dimJ; j++) at(i, j) *= t;
  }
  void basic_xchg(int i1, int i2) {           // exchanges i1-th and i2-th rows
    for (int j = 0; j < dimJ; j++) swap(at(i1, j), at(i2, j));
  }
  void basic_mult_add(int i1, T t, int i2) {  // adds t times of i1-th row to i2-th row
    for (int j = 0; j < dimJ; j++) at(i2, j) += t * at(i1, j);
  }

  pair<int, int> _find_nz(int i0, int j0) const {
    for ( ; j0 < dimJ; j0++) {
      int i = i0;
      for ( ; i < dimI && at(i, j0) == _zero_T(); i++);
      if (i < dimI) return {i, j0};
    }
    return {dimI, dimJ};
  }

  pair<int, T> self_sweepout() {
    T det = _one_T();
    int j0 = 0;
    int i0 = 0;
    for ( ; i0 < dimI; i0++, j0++) {
      auto [i1, j1] = _find_nz(i0, j0);
      if (i1 == dimI) break;
      j0 = j1;
      if (i1 != i0) {
        det = -det;
	basic_xchg(i0, i1);
      }
      det *= at(i0, j0);
      basic_mult(i0, ::inverse<T>(at(i0, j0)));
      for (int i = 0; i < dimI; i++) {
	if (i == i0) continue;
        basic_mult_add(i0, -at(i, j0), i);
      }
    }
    return {i0, move(det)};
  }
  
  pair<int, T> sweepout() const { 
    Matrix res1(*this);
    return res1.self_sweepout();
  }

  T determinant() const {
    auto [rank, det] = sweepout();
    return (rank == dimI) ? det : _zero_T();
  }

  optional<Matrix> inv() const {
    if (dimI != dimJ) throw domain_error("inv: not square");
    Matrix work(dimI, dimI * 2);
    work.memcopy(part());
    work.memcopy(unit().part(), 0, dimI);
    work.self_sweepout();
    if (work.at(dimI - 1, dimI - 1) != _one_T()) return {};
    Matrix ret(dimI, dimI);
    ret.memcopy(work.part(dimI, dimI, 0, dimI));
    return ret;
  }

  Matrix inverse() const { return inv().value(); } // for general operation of Ring / Semi Ring

  template<bool ret_kernel = false>
  optional<pair<Matrix, vector<Matrix>>> linSolution(const Matrix& bs) const {
    if (dimI != bs.dimI or bs.dimJ != 1) throw domain_error("linSolution: invalid bs");
    Matrix work(dimI, dimJ + 1);
    work.memcopy(part());
    work.memcopy(bs.part(), 0, dimJ);
    auto [rank, _] = work.self_sweepout();
    Matrix sol(dimJ, 1);
    vector<Matrix> kernel;
    if (rank == 0) {
      if constexpr (not ret_kernel) return make_pair(move(sol), move(kernel));
      for (int j = 0; j < dimJ; j++) {
        Matrix m(dimJ, 1);
        m.at(j, 0) = _one_T();
        kernel.push_back(m);
      }
      return make_pair(move(sol), move(kernel));
    }
    if (not ([&]() -> bool {
      for (int j = 0; j < dimJ; j++) if (work.at(rank - 1, j) != _zero_T()) return true;
      return false;
    })()) return nullopt;
    for (int i = 0, j = 0; i < rank; i++, j++) {
      for ( ; work.at(i, j) == _zero_T(); j++);
      sol.at(j, 0) = work.at(i, dimJ);
    }
    if constexpr (not ret_kernel) return make_pair(move(sol), move(kernel));
    vector<bool> cor(dimJ, false);
    int i = 0;
    for (int j = 0 ; j < dimJ; j++) {
      if (i == dimI || work.at(i, j) == _zero_T()) {
        Matrix vec(dimJ, 1);
        vec.at(j, 0) = _one_T();
        for (int p = 0, q = 0; p < i; p++, q++) {
          while (!cor[q]) q++;
          vec.at(q, 0) = -work.at(p, j);
        }
        kernel.push_back(move(vec));
      }else {
        cor[j] = true;
        if (i < dimI) i++;
      }
    }
    return make_pair(move(sol), move(kernel));
  }

  friend istream& operator >>(istream& is, Matrix& mat) {
    is >> mat.dimI >> mat.dimJ;
    mat.rev_rc = false;
    mat.mem.resize(mat.dimI * mat.dimJ);
    for (int i = 0; i < mat.dimI; i++) for (int j = 0; j < mat.dimJ; j++) is >> mat.at(i, j);
    return is;
  }

  friend ostream& operator <<(ostream& os, const Matrix& mat) {
    for (int i = 0; i < mat.dimI; i++) {
      for (int j = 0; j < mat.dimJ; j++) {
        if (j > 0) os << ", ";
        os << mat.at(i, j);
      }
      os << "\n";
    }
    return os;
  }

};

// @@ !! END ---- matrix.cc

