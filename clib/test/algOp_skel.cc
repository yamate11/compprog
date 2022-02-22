#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(algOp)


int main() {
  
  {
    struct MinPlusLL {
      using value_type = ll;
      static ll add(const ll& u, const ll& v) { return min(u, v); }
      static void subst_mult(ll& u, const ll& v) { u += v; }
      static ll zero(const ll& u) { return LLONG_MAX; }
      static ll one(const ll& u) { return 0; }
    };
    using MMP = MyAlg<MinPlusLL>;
    MMP a2(2), a5(5), a7(7), a10(10);
    assert(a7 == a7 + a10);
    assert(a7 == a2 * a5);
    MMP sum1 = a2.zero();
    sum1 += a10;
    sum1 += a5 + a7;
    sum1 = sum1 + a2;
    assert(sum1.v == 2);
    MMP prod1 = a2.one();
    prod1 *= a10;
    prod1 *= a5 * a7;
    prod1 = prod1 * a2;
    assert(prod1.v = 24);
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
    MM m1(VT({{2, 3}, {1, 1}}));
    MM m2(VT({{1, 2}, {-3, -5}}));
    MM m3(VT({{1, 0}, {2, -1}}));
    assert((m1 + m2).v == VT({{3, 5}, {-2, -4}}));
    assert((m2 * m3).v == VT({{5,-2}, {-13, 5}}));
    assert(m1 * (m2 + m3) == m1 * m2 + m1 * m3);
    assert((m1 - m2) * m3 == m1 * m3 - m2 * m3);
    assert(m1 * m1.one() == m1);
    assert(m2 + m2.zero() == m2);
    MM m2i = m2.inverse();
    assert(m2 * m2i == m2.one());
    assert(m2i * m2 == m2.one());
    assert((m2 / m3) * m3 == m2);
    MM m4(m1);
    m4 += m2;
    assert(m4 == m1 + m2);
    MM m5(m2);
    m5 *= m3;
    assert(m5 == m2 * m3);
    MM m6(m3);
    m6 -= m1;
    assert(m6 == m3 - m1);
    MM m7 = -m2;
    assert(m1 - m2 == m1 + m7);

    

  }

  return 0;
}
