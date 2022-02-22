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

template <
  typename Opdef,
  typename En = enable_if_t< std::is_same_v< decay_t<decltype( Opdef::subst_add



template <typename Opdef>
struct FromOP {
  using T = typename Opdef::value_type;
  using value_type = T;
  T v;
  FromOP() {}
  FromOP(T v_) : v(v_) {}
  bool operator==(FromOP o) const { return v == o.v; }
  bool operator!=(FromOP o) const { return v != o.v; }
  operator T() const { return v; }
  FromOP zero() const { return Opdef::zero(*this); }
  FromOP one() const { return Opdef::one(*this); }
  FromOP inverse() const { return FromOP(Opdef::inverse(v)); }
  // FromOP& operator+=(const FromOP& o) { Opdef::subst_add(v, o.v);  return *this; }
  FromOP& operator-=(const FromOP& o) { Opdef::subst_subt(v, o.v);  return *this; }
  FromOP& operator*=(const FromOP& o) { Opdef::subst_mult(v, o.v); return *this; }
  FromOP operator/=(const FromOP& o) { Opdef::subst_mult(v, Opdef::inverse(o.v)); return *this; }
  FromOP operator+(const FromOP& o) const { return FromOP(*this) += o; }
  FromOP operator-(const FromOP& o) const { return FromOP(*this) -= o; }
  FromOP operator*(const FromOP& o) const { return FromOP(*this) *= o; }
  FromOP operator/(const FromOP& o) const { return (*this) * inverse(); }
  FromOP operator-() const { return zero() - *this; }

  template <typename = enable_if_t< std::is_same_v< decay_t<decltype( Opdef::subst_add(v, v) )>, FromOP>>>
  FromOP& operator +=(const FromOP& o) { Opdef::subst_add(v, o.v); return *this; }


};


ostream& operator <<(ostream& os, const vector<ll>& vec) {
  os << "[";
  for (size_t i = 0; i < vec.size(); i++) {
    os << vec[i];
    if (i < vec.size() - 1) os << ", ";
    else os << "]\n";
  }
  return os;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    struct V {
      using T = vector<ll>;
      using value_type = T;
      static T zero(const T& v) { return T(v.size(), 0); }
      static void subst_add(T& v, const T& w) { for (size_t i = 0; i < v.size(); i++) v[i] += w[i]; }
      static T one(const T& v) { return T(v.size(), 1); }
      static void subst_mult(T& v, const T& w) { for (size_t i = 0; i < v.size(); i++) v[i] *= w[i]; }
    };

    FromOP<V> f1(vector<ll>({1,2,3}));
    FromOP<V> f2(vector<ll>({4,5,6}));
    assert(f1 + f2 == FromOP<V>(vector<ll>({5, 7, 9})));
  }
  
  {
    struct OpM2R {
      using T = vector<vector<double>>;
      using value_type = T;
      static T zero(const T& v) { return T({{0,0}, {0,0}}); }
      static T one(const T& v) { return T({{1,0}, {0,1}}); }
      static void subst_add(T& v, const T& w) {
        for (size_t i = 0; i < 2; i++) for (size_t j = 0; j < 2; j++) v[i][j] += w[i][j];
      }
      static void subst_subt(T& v, const T& w) {
        for (size_t i = 0; i < 2; i++) for (size_t j = 0; j < 2; j++) v[i][j] -= w[i][j];
      }
      static T mult(const T& v, const T& w) {
        auto z = T(2, vector(2));
        z[0][0] = v[0][0] * w[0][0] + v[0][1] * w[1][0];
        z[0][1] = v[0][0] * w[0][1] + v[0][1] * w[1][1];
        z[1][0] = v[1][0] * w[0][0] + v[1][1] * w[1][0];
        z[1][1] = v[1][0] * w[0][1] + v[1][1] * w[1][1];
        return z;
      }
    };
  }

  return 0;
}

