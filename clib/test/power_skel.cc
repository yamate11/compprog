#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(power mod)

int main() {

  assert(power(2,3) == 8);
  assert(power(10LL, 12) == llround(1e12));
  assert(power(0.5, 4) * 16 == 1.0);
  
  {
    using Fp = FpB;
    Fp x7(7);
    assert(power(x7, 6) == x7*x7*x7*x7*x7*x7);
    assert(power(1 / x7, 5) * x7 * x7 * x7 * x7 * x7 == Fp(1));
  }
  {
    using VEC = vector<ll>;
    struct OV {
      using value_type = VEC;
      static value_type one(const value_type& u) {
        vector<ll> ret(u.size());
        for (size_t i = 0; i < u.size(); i++) ret[i] = 1LL;
        return ret;
      }
      static void       subst_mult(      value_type& u, const value_type& v) {
        for (size_t i = 0; i < u.size(); i++) u[i] *= v[i];
      }
    };
    using MOV = MyAlg<OV>;
    MOV m1(VEC({2, 3, 4}));
    assert(power(m1, 3) == VEC({8, 27, 64}));

  }

  {
    using VT = vector<vector<double>>;
    struct OpMatrix2 {
      using value_type = VT;
      static value_type zero(const value_type& dummy) { return VT(2, vector(2, 0.0)); }
      static value_type one(const value_type& dummy) {
        VT ret(2, vector(2, 0.0));
        ret[0][0] = ret[1][1] = 1.0;
        return ret;
      }
      static void subst_add(value_type& u, const value_type& v) {
        for (size_t i = 0; i < 2; i++) for (size_t j = 0; j < 2; j++) u[i][j] += v[i][j];
      }
      static void subst_subt(value_type& u, const value_type& v) {
        for (size_t i = 0; i < 2; i++) for (size_t j = 0; j < 2; j++) u[i][j] -= v[i][j];
      }
      static value_type mult(const value_type& u, const value_type& v) {
        value_type ret(2, vector(2, 0.0));
        for (size_t i = 0; i < 2; i++) for (size_t j = 0; j < 2; j++) for (size_t k = 0; k < 2; k++) {
              ret[i][j] += u[i][k] * v[k][j];
            }
        return ret;
      }
      static value_type inverse(const value_type& u) {
        double d = u[0][0] * u[1][1] - u[0][1] * u[1][0];
        return value_type({{u[1][1] / d, -u[0][1] / d}, {-u[1][0] / d, u[0][0] / d}});
      }
    };
    using MM = MyAlg<OpMatrix2>;
    MM m1(VT{{cos(1), -sin(1)}, {sin(1), cos(1)}});
    MM m2 = power(m1, 10);
    auto near = [&](const MM& mm1, const MM& mm2) -> bool {
      VT diff = (mm1 - mm2).v;
      double err = 0.0;
      for (size_t i = 0; i < 2; i++) for (size_t j = 0; j < 2; j++) err += diff[i][j] * diff[i][j];
      return err < 1e-6;
    };
    assert(near(power(m1, 10), MM(VT({{cos(10), -sin(10)}, {sin(10), cos(10)}}))));
  }
  return 0;

}
