#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

struct Matrix {
  
};

template <typename T>
struct StdOp {
  StdOp(T x) {}
};

template <>
struct StdOp<Matrix> {
  StdOp(Matrix m) {}
};
  

template<typename T, typename Op=StdOp<T>>
T power(T x, ll y, optional<Op> op = nullopt) {
  if (not op) op = Op(x);
  T ret = op.one();
  for (ll i = 0; i < y; i++) {
    op.subst_mult(ret, x);
  }
  return ret;
}
  
template<typename T>
vector<T>& _subst_add(vector<T>& v, const vector<T>& o, auto f) {
  for (size_t i = 0; i < v.size(); i++) f(v[i], o[i]); // v[i] += o[i];
  return v;
}

template<typename T>
T& t_subst_add(T& x, const T& y) { return x += y; }

template<typename T>
vector<T>& operator +=(vector<T>& v, const vector<T>& o) { return _subst_add(v, o, t_subst_add<T>); }
template<typename T>
vector<T> operator +(const vector<T>& v1, const vector<T>& v2) {
  vector<T> ret(v1);
  return ret += v2;
}

template<typename T>
ostream& operator <<(ostream& os, const vector<T>& v) {
  os << "[";
  for (size_t i = 0; i < v.size(); i++) {
    if (i > 0) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

/*
template<typename T>
struct myvector : public vector<T> {

  myvector() : vector<T>() {}
  myvector(const vector<T>& v) : vector<T>(v) {}
  myvector(const vector<T>&& v) : vector<T>(move(v)) {}
  myvector(size_t n) : vector<T>(n) {}
  myvector(size_t n, const T& t) : vector<T>(n, t) {}
  myvector(size_t n, T&& t) : vector<T>(n, t) {}
  

  myvector& _subst_add(myvector& v, const vector<T>& o) {
    for (size_t i = 0; i < v.size(); i++) v[i] += o[i];
    return v;
  }
  myvector& operator +=(const vector<T>& o) { return _subst_add(*this, o); }
  myvector operator +(const vector<T>& o) const { return _subst_add(myvector(*this), o); }
  friend myvector operator +(const vector<T>& o, const myvector& v) { return _subst_add(myvector(o), v); }

  myvector& _subst_subt(myvector& v, const vector<T>& o) {
    for (size_t i = 0; i < v.size(); i++) v[i] -= o[i];
    return v;
  }
  myvector& operator -=(const vector<T>& o) { return _subst_subt(*this, o); }
  myvector operator -(const vector<T>& o) const { return _subst_subt(myvector(*this), o); }
  friend myvector operator -(const vector<T>& o, const myvector& v) { return _subst_subt(myvector(o), v); }
  myvector operator -() const { return myvector((*this).size()) -= *this; }
    
  friend ostream& operator <<(ostream& os, const myvector v) {
    os << "[";
    for (size_t i = 0; i < v.size(); i++) {
      if (i > 0) os << ", ";
      os << v[i];
    }
    os << "]";
    return os;
  }

};
*/
  

int main() {

  vector<int> v1(10), v2(10);
  v1[5] = 3;
  v2[4] = 4;
  auto v = v1 + v2;
  cout << v << endl;


}
