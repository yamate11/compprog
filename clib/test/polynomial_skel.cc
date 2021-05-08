#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:<< mod debug polynomial)

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    Polynomial p1({-2, 0, 1});
    Polynomial p2({2, -1, 3, 2});

    assert(p1 == p1);
    assert(p1 != p2);

    assert(p1.degree() == 2 && p2.degree() == 3);
    assert(p1.coef[0] == -2 && p1.coef[1] == 0 && p1.coef[2] == 1);

    assert(p1 + p2 == Polynomial({0, -1, 4, 2}));
    assert(p2 + p1 == Polynomial({0, -1, 4, 2}));
    assert(p1 - p2 == Polynomial({-4, 1, -2, -2}));
    assert(p2 - p1 == Polynomial({4, -1, 2, 2}));
    assert(-p1 == Polynomial({2, 0, -1}));
    assert(Polynomial(12.3) == Polynomial({12.3, 1.0}) - Polynomial({0.0, 1.0}));
    Polynomial p3({1, 2, 3});
    Polynomial p4(p3);
    p3 *= Polynomial({0, 0, 0, 1});
    p4 += p3;
    assert(p4 == Polynomial({1, 2, 3, 1, 2, 3}));
    
    Polynomial p5({-4, 2, -4, -5, 3, 2});
    assert(p1 * p2 == p5);
    assert(p2 * p1 == p5);

    assert(10 + p1 == Polynomial({8, 0, 1}));
    assert(p1 + 10 == Polynomial({8, 0, 1}));
    assert(10 - p1 == Polynomial({12, 0, -1}));
    assert(p1 - 10 == Polynomial({-12, 0, 1}));
    assert(10 * p1 == Polynomial({-20, 0, 10}));
    assert(p1 * 10 == Polynomial({-20, 0, 10}));

    Polynomial X = Polynomial<int>::get_X();
    assert((X - 1) * (X - 1) == (X * X) - 2 * X + 1);

    Fp::MOD = 2;
    Polynomial Y = Polynomial<Fp>::get_X();
    assert((Y - Fp(1)) * (Y - Fp(1)) == (Y * Y) + Fp(1));

  }
  {
    Fp::MOD = 1e9 + 7;
    using Pol = Polynomial<Fp>;
    Pol p1;
    assert(p1.degree() == 0 && p1.coef[0] == Fp(0));
    Pol p2(Fp(10));
    assert(p2.degree() == 0 && p2.coef[0] == Fp(10));
    vector<Fp> v1({2, 3, 4});
    auto v2(v1);
    Pol p3(v1);
    Pol p4(move(v2));
    Pol p5({2, 3, 4});
    assert(p3 == p4 && p3 == p5 && !(p4 != p5));
    Pol p6(p3);
    Pol p7(move(p5));
    Pol p8; p8 = p3;
    Pol p9; p9 = move(p4);
    assert(p6 == p7 && p6 == p8 && p6 == p9);
    Pol p10; p10 = Fp(10);
    assert(p10 == p2);

    vector<Fp> v3({1, 2, 3, 4, 5});
    Pol p11(v3);
    Pol p11cp(p11);
    Pol p12({6, 7});
    p11 = p11cp; p11 += p12; assert(p11 == p11cp + p12);
    p11 = p11cp; p11 -= p12; assert(p11 == p11cp - p12);
    p11 = p11cp; p11 *= p12; assert(p11 == p11cp * p12);
    p11 = p11cp; p11 += Fp(10); assert(p11 == p11cp + Fp(10));
    p11 = p11cp; p11 -= Fp(10); assert(p11 == p11cp - Fp(10));
    p11 = p11cp; p11 *= Fp(10); assert(p11 == p11cp * Fp(10));
    p11 = p11cp; 
    assert(p11 + Fp(10) == Fp(10) + p11);
    assert(p11 - Fp(10) == -(Fp(10) - p11));
    assert(p11 * Fp(10) == Fp(10) * p11);

    stringstream ss;
    ss << p11;
    assert(ss.str() == "[1, 2, 3, 4, 5]");
    
  }
  {
    using Pol = Polynomial<double>;
    Pol X = Pol::get_X();
    using Tup = tuple<Pol, Pol, Pol>;
    vector<Tup> tests({
        {X*X + 4.0*X - 3.0, 2.0*X*X*X, -3.0*X + 1.0},
        {2.0*X*X*X, X*X + 4.0*X - 3.0, -3.0*X + 1.0},
        {2.0*X*X*X, X*X + 4.0*X - 3.0, 0.0},
        {0.0, 1.0*X*X*X - 2.0*X, -3.0*X + 1.0},
        {5.0, 2.0, 0.0},
        {X*X*X - X*X + 4.0, 3.0, 0.0}
      });
    for (auto [d, q, m] : tests) {
      auto p = d * q + m;
      auto [dd, mm] = p.divmod(q);
      // DLOGK(p, q, d, m, dd, mm);
      assert(d == dd && m == mm);
    }
    vector<pair<Pol, Pol>> tests2({
        {Pol({1, 2, 3, 4}), Pol({2, 1})},
        {Pol({2, 1}), Pol({1, 2, 3, 4})},
        {Pol({0, 0, 0, 4}), Pol({2, 1})},
        {Pol({2, 1}), Pol({10, 0, 0, 0})},
        {Pol({4, 3, 2, 1}), Pol({1, 2, 3, 4})},
        {Pol({4}), Pol({1, 2, 3, 4})},
        {Pol({0}), Pol({1, 2, 3, 4})},
        {Pol({4, 3, 2, 1}), Pol({4})},
      });
    for (auto [p, q] : tests2) {
      auto [d, m] = p.divmod(q);
      assert(p == q * d + m &&
             (m.degree() < q.degree() || (q.degree() == 0 && m == Pol(0.0))));
    }
    Fp::MOD = 1e9 + 7;
    using PolFp = Polynomial<Fp>;
    vector<pair<PolFp, PolFp>> tests3({
        {PolFp({1, 2, 3, 4}), PolFp({2, 1})},
        {PolFp({2, 1}), PolFp({1, 2, 3, 4})},
        {PolFp({0, 0, 0, 4}), PolFp({2, 1})},
        {PolFp({2, 1}), PolFp({10, 0, 0, 0})},
        {PolFp({4, 3, 2, 1}), PolFp({1, 2, 3, 4})},
        {PolFp({4}), PolFp({1, 2, 3, 4})},
        {PolFp({0}), PolFp({1, 2, 3, 4})},
        {PolFp({4, 3, 2, 1}), PolFp({4})},
      });
    for (auto [p, q] : tests3) {
      auto [d, m] = p.divmod(q);
      assert(p == q * d + m &&
             (m.degree() < q.degree() || (q.degree() == 0 && m == PolFp(0.0))));
    }

  }

  cout << "test done." << endl;

  return 0;
}

