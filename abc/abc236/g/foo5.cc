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
  AO クラス が zero() や one() を持っているけれど，
  正方行列のように，dimension を与えないと決まらない場合もある．
  そうすると，やはり，AOクラスのインスタンスフィールドに そのようなパラメタを持たせるのが自然．
  となると，power 関数とか Matrix クラスとか SegTree クラスのように，AOクラスを使う方では，
  テンプレートのクラスパラメタとして AO クラスを指定するだけではなくて，AO オブジェクトを
  もらうようにしないといけないだろう．

    template<typename AO> ult_t<AO> power(ult_t<AO> a, size_t b, const AO& ao);
    template<typename AO> Mat(size_t dimI, size_t dimJ, const AO& ao)

  でも，dimension 情報みたいなものがいらないときには，かったるい．
  そこで，AO が引数のないコンストラクタを持つときには，以下のように使えるようにしたい．

    template<typename AO> ult_t<AO> power(ult_t<AO> a, size_t b);
    template<typename AO> Mat(size_t dimI, size_t dimJ);

 */

template<typename AO>
using ult_t = typename AO::ult;

// ao_is_no_arg<AO>::value is true iff AO().zero() is valid (instead of AO().zero(const ult_t<AO>& t))
template<typename AO>
struct ao_is_no_arg {
  template<typename T>
  static auto check(int) -> typename std::is_same< decltype( declval<T>().zero() ), ult_t<T> >::type;
  template<typename>
  static false_type check(...);
  using _type = decltype(check<AO>(0));
  static const bool value = _type::value;
};

template<typename T>
struct AO_basic { // Algebra Operations -- default operations
  using ult = T;
  ult zero() const { return (T)0; }
  ult one() const { return (T)1; }
  void subst_add(T& v, const T& w) const { v += w; }
  void subst_subt(T& v, const T& w) const { v -= w; }
  void subst_mult(T& v, const T& w) const { v *= w; }
};

template<typename T>
struct AO_def : AO_basic<T> {
  using typename AO_basic<T>::ult;
};

template<>
struct AO_def<double> : AO_basic<double> {
  using typename AO_basic<double>::ult;
  ult inverse(const ult& w) const { return 1.0 / w; }
};

template<typename T>
struct AO_vec {
  using ult = vector<T>;
  ult zero(const ult& v) const { return vector<T>(v.size()); }
  ult one(const ult& v) const { return vector<T>(v.size(), (T)1); }
  void subst_add(vector<T>& v, const vector<T>& w) const { for(size_t i = 0; i < v.size(); i++) v[i] += w[i]; }
  void subst_subt(vector<T>& v, const vector<T>& w) const { for(size_t i = 0; i < v.size(); i++) v[i] -= w[i]; }
  void subst_mult(vector<T>& v, const vector<T>& w) const { for(size_t i = 0; i < v.size(); i++) v[i] *= w[i]; }
};

template<typename AO> ult_t<AO> get_zero(const ult_t<AO>& t) {
  if constexpr(ao_is_no_arg<AO>::value) return AO().zero(); else return AO().zero(t);
}
template<typename AO> ult_t<AO> get_one(const ult_t<AO>& t) {
  if constexpr(ao_is_no_arg<AO>::value) return AO().one(); else return AO().one(t);
}

template<typename AO>
ult_t<AO> power(const ult_t<AO>& a, ll b) {
  auto two_pow = a;
  auto ret = get_one<AO>(a);
  while (b > 0) {
    if (b & 1LL) AO().subst_mult(ret, two_pow);
    AO().subst_mult(two_pow, two_pow);
    b >>= 1;
  }
  return ret;
}

template<typename T>
T power(const T& a, ll b) { return power<AO_def<T>>(a, b); }

int main() {
  int x = power(2, 3);
  cout << x << endl;
  double y = power(0.5, 4);
  cout << y << endl;
  vector<int> z(5);
  iota(ALL(z), 0);
  auto zz = power<AO_vec<int>>(z, 3);
  for (size_t i = 0; i < 5; i++) cout << zz[i] << " ";
  cout << endl;
}
