#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/* Square Matrix */
template <class T>
class SMatrix {
private:
  size_t dimI;
  size_t dimJ;
  vector<T> mem;

public:

  static SMatrix<T> diagConst(size_t n, T d) {
    SMatrix result = SMatrix(n, n);
    for (size_t i = 0; i < n; i++)  result.at(i,i) = d;
    return result;
  }

  static SMatrix<ll> unit(size_t n) { return diagConst(n, 1); }

  SMatrix(size_t m, size_t n) : dimI(m), dimJ(n), mem(dimI*dimJ) {}

  SMatrix(initializer_list<vector<T>> il) {
    vector<vector<ll>> v(il);
    dimI = v.size();
    dimJ = v.at(0).size();
    mem.resize(dimI*dimJ);
    for (size_t i = 0; i < dimI; i++) {
      assert(v.at(i).size() == dimJ);
      for (size_t j = 0; j < dimJ; j++) {
	mem.at(i*dimJ + j) = v.at(i).at(j);
      }
    }
  }

  SMatrix(const SMatrix<T>& mat)
    : dimI(mat.dimI), dimJ(mat.dimJ), mem(mat.mem) {}

  SMatrix<T>& operator =(const SMatrix<T>& r) {
    dimI = r.dimI;
    dimJ = r.dimJ;
    mem = r.mem;
    return *this;
  }

  T& at(size_t i, size_t j) { return mem.at(i*dimJ + j); }
  const T& at(size_t i, size_t j) const { return mem.at(i*dimJ + j); }
  
  SMatrix<T>& operator +=(const SMatrix<T>& r) {
    assert(dimI == r.dimI && dimJ == r.dimJ);
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimJ; j++) at(i,j) += r.at(i,j);
    }
    return *this;
  }

  SMatrix<T>& operator -=(const SMatrix<T>& r) {
    assert(dimI == r.dimI && dimJ == r.dimJ);
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < dimJ; j++) at(i,j) -= r.at(i,j);
    }
    return *this;
  }

  SMatrix<T> operator +(const SMatrix<T>& r) const {
    return SMatrix<T>(*this) += r;
  }

  SMatrix<T> operator -(const SMatrix<T>& r) const {
    return SMatrix<T>(*this) -= r;
  }

  SMatrix<T> operator *(const SMatrix<T>& r) const {
    assert(dimJ == r.dimI);
    SMatrix<T> result(dimI, r.dimJ);
    for (size_t i = 0; i < dimI; i++) {
      for (size_t j = 0; j < r.dimJ; j++) {
	T s = 0;
	for (size_t k = 0; k < dimJ; k++)  s += at(i,k) * r.at(k,j);
	result.at(i,j) = s;
      }
    }
    return result;
  }

  SMatrix<T>& operator *=(const SMatrix<T>& r) {
    return *this = *this * r;
  }

  bool operator ==(const SMatrix<T>& r) const {
    return dimI == r.dimI && dimJ == r.dimJ && mem == r.mem;
  }
  bool operator !=(const SMatrix<T>& r) const { return !(*this == r); }

  SMatrix<T> power(ll k) {
    assert(dimI == dimJ);
    SMatrix<T> result = SMatrix<T>::unit(dimI);
    SMatrix<T> cur = *this;
    while (k > 0) {
      if (k & 1) result *= cur;
      cur *= cur;
      k >>= 1;
    }
    return result;
  }
};



vector<vector<ll>> foo(initializer_list<vector<ll>> xs) {
  vector<vector<ll>> v(xs);
  return v;
}

int main() {
  SMatrix<ll> mat0 = {{0,1,0},{2,0,-1}};
  SMatrix<ll> mat1 = SMatrix<ll>(2,3);
  mat1.at(0,1) = 1;
  mat1.at(1,0) = 2;
  mat1.at(1,2) = -1;
  assert(mat0 == mat1);
  assert(!(mat0 != mat1));
  SMatrix<ll> mat2 = {{1,0,0}, {0,0,1}};
  SMatrix<ll> mat3 = {{4}, {5}, {6}};
  SMatrix<ll> mat4 = {{5}, {2}};
  SMatrix<ll> mat5 = {{1,1,0},{2,0,0}};
  assert(mat2 + mat0 == mat5);
  SMatrix<ll> mat6 = mat2;
  mat2 += mat0;
  assert(mat2 == mat5);
  assert(mat5 - mat0 == mat6);
  mat5 -= mat0;
  assert(mat5 == mat6);
  assert(mat0 * mat3 == mat4);
  mat0 *= mat3;
  assert(mat0 == mat4);
  SMatrix<ll> mat7 = {{1, 3}, {0, 1}};
  assert(mat7.power(5) == mat7*mat7*mat7*mat7*mat7);
  assert(mat7.power(11) == mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7);
  cerr << "ok" << endl;
  
  return 0;
}
