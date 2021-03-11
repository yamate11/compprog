#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// See debug.cc for usage etc
#define DEBUG 0

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#if DEBUG
  #define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DCALL(func, ...)
#endif

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

ll MOD;

struct Fp {
  ll val;

  Fp(ll t = 0) :
    val(t < 0 ? MOD + t % MOD : t >= MOD ? t % MOD : t) {}

  Fp& operator +=(const Fp& t) {
    val += t.val;
    if (val > MOD) val -= MOD;
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

  static SMatrix<T> unit(size_t n) { return diagConst(n, 1); }

  SMatrix(size_t m, size_t n) : dimI(m), dimJ(n), mem(dimI*dimJ) {}

  SMatrix(initializer_list<vector<T>> il) {
    vector<vector<T>> v(il);
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




int main() {
  MOD = 7;

  SMatrix<Fp> m({{1, -1}, {1, 1}});
  if (m * m == m) {
    cout << "true" << endl;
  }else {
    cout << "false" << endl;
  }
  
  return 0;
}
