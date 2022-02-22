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

/*
  AO クラスを定義したときに，それを自然に演算定義したクラスが作れるはず....

 */

template<typename T>
struct AO_basic { // Algebra Operations -- default operations
  using ult = T;
  AO_basic(const ult& _dummy) {}
  ult zero() const { return (T)0; }
  ult one() const { return (T)1; }
  void subst_add(ult& v, const ult& w) const { v += w; }
  void subst_subt(ult& v, const ult& w) const { v -= w; }
  void subst_mult(ult& v, const ult& w) const { v *= w; }
};

template<typename T>
struct AO_def : AO_basic<T> {
  using typename AO_basic<T>::ult;
  AO_def(const ult& t) : AO_basic<T>(t) {}
};

template<>
struct AO_def<double> : AO_basic<double> {
  using typename AO_basic<double>::ult;
  AO_def<double>(const ult& t) : AO_basic<double>(t) {}
  ult inverse(const ult& w) const { return 1.0 / w; }
};

template<typename AO>
using ult_t = typename AO::ult;

template<typename T>
struct AO_vec {
  using ult = vector<T>;
  size_t len;
  AO_vec(size_t len_) : len(len_) {}
  AO_vec(const ult& v) : len(v.size()) {}
  ult zero() const { return vector<T>(len); }
  ult one() const { return vector<T>(len, (T)1); }
  void subst_add(vector<T>& v, const vector<T>& w) const { for(size_t i = 0; i < len; i++) v[i] += w[i]; }
  void subst_subt(vector<T>& v, const vector<T>& w) const { for(size_t i = 0; i < len; i++) v[i] -= w[i]; }
  void subst_mult(vector<T>& v, const vector<T>& w) const { for(size_t i = 0; i < len; i++) v[i] *= w[i]; }
};

struct AO_ll_minmax {
  using ult = ll;
  AO_ll_minmax(const ult& _dummy) {}
  ult zero() const { return LLONG_MAX; }
  ult one() const { return LLONG_MIN; }
  void subst_add(ult& v, const ult& w) const { if (v > w) v = w; }
  void subst_mult(ult& v, const ult& w) const { if (v < w) v = w; }
};

template<typename AO>
struct BwAO { // body with AO
  using T = typename AO::ult;
  T v;  // value
  BwAO(const T& v_) : v(v_) {}
  BwAO(T&& v_) : v(move(v_)) {}
  BwAO& operator =(const T& v_) { v = v_; return *this; }
  BwAO& operator =(T&& v_) { v = move(v_); return *this; }
  operator T() const { return v; }
  bool operator ==(const BwAO& o) { return v == o.v; }
  bool operator !=(const BwAO& o) { return v != o.v; }
  BwAO& operator +=(const BwAO& o) { AO(v).subst_add(v, o.v); return *this; }
  BwAO& operator -=(const BwAO& o) { AO(v).subst_subt(v, o.v); return *this; }
  BwAO& operator *=(const BwAO& o) { AO(v).subst_mult(v, o.v); return *this; }
  BwAO inverse() const { return BwAO(AO(v).inverse(v)); }
  BwAO& operator /=(const BwAO& o) { AO(v).subst_mult(v, AO(v).inverse(o.v)); return *this; }
  BwAO operator +(const BwAO& o) const { return BwAO(v) += o; }
  BwAO operator -(const BwAO& o) const { return BwAO(v) -= o; }
  BwAO operator *(const BwAO& o) const { return BwAO(v) *= o; }
  BwAO operator /(const BwAO& o) const { return (*this) * o.inverse(); }
};
  
int main() {
  BwAO<AO_ll_minmax> z1(5), z2(9);
  cout << z1 + z2 << endl;
  cout << z1 * z2 << endl;
  BwAO<AO_def<ll>> y1(5), y2(9);
  cout << y1 + y2 << endl;
  cout << y1 - y2 << endl;
  cout << y1 * y2 << endl;
  BwAO<AO_def<double>> x1(5), x2(9);
  cout << x1 + x2 << endl;
  cout << x1 - x2 << endl;
  cout << x1 * x2 << endl;
  cout << x1 / x2 << endl;
}
