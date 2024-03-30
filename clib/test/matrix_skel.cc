#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// Library Insertion Mark
// @@ !! LIM(algOp power mod matrix)

int main() {
  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  {
    using Fp = FpA;

    cerr << "start" << endl;
    cerr << "equation" << endl;
    Matrix<ll> mat0({{0,1,0},{2,0,-1}});
    Matrix<ll> mat1 = Matrix<ll>(2,3);
    mat1.at(0,1) = 1;
    mat1.at(1,0) = 2;
    mat1.at(1,2) = -1;
    assert(mat0 == mat1);
    assert(!(mat0 != mat1));

    cerr << "addition" << endl;
    Matrix<ll> mat2({{1,0,0}, {0,0,1}});
    Matrix<ll> mat3({{4}, {5}, {6}});
    Matrix<ll> mat4({{5}, {2}});
    Matrix<ll> mat5({{1,1,0},{2,0,0}});
    Matrix<ll> tmp = mat2 + mat0;
    bool tmp2 = tmp == mat5;
    assert(tmp2);
    assert(mat2 + mat0 == mat5);
    Matrix<ll> mat6 = mat2;
    mat2 += mat0;
    assert(mat2 == mat5);

    cerr << "subtraction" << endl;
    assert(mat5 - mat0 == mat6);
    mat5 -= mat0;
    assert(mat5 == mat6);

    cerr << "multiplication" << endl;
    assert(mat0 * mat3 == mat4);
    mat0 *= mat3;
    assert(mat0 == mat4);
    Matrix<ll> mat7 = {{1, 3}, {0, 1}};

    cerr << "power" << endl;
    assert(mat7.matpower(5) == mat7*mat7*mat7*mat7*mat7);
    assert(power(mat7, 5) == mat7*mat7*mat7*mat7*mat7);
    assert(mat7.matpower(11) == mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7*mat7);
    Matrix<double> mat8 = {{1.0, 2.0}, {3.0, 4.0}};
    Matrix<double> mat9 = {{7.0, 10.0}, {15.0, 22.0}};
    assert(mat9 == mat8 * mat8);
    Matrix<Fp> mat9a = {{1,2,3}, {5,5,5}, {-3,-1,0}};
    assert(power(mat9a, 5) == mat9a*mat9a*mat9a*mat9a*mat9a);
    assert(mat9a.matpower(3) == mat9a*mat9a*mat9a);

    cerr << "at" << endl;
    vector<vector<ll>> vec10 = {{3,2,0}, {5,4,1}};
    Matrix<ll> mat10 = Matrix<ll>::from_vvec(vec10);
    Matrix<ll> mat11(2, 3);
    for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++) {
        mat11.at(i,j) = vec10.at(i).at(j);
      }
    assert(mat10 == mat11);

    cerr << "transpose" << endl;
    Matrix<ll> mat12a = {{0,1,0}, {2,0,-1}};
    Matrix<ll> mat12 = {{0,2}, {1,0}, {0,-1}};
    assert(mat12a == mat12.transpose());
    assert(mat12a.transpose() == mat12);
    assert(mat12a == mat12a.transpose().transpose());

    Matrix<ll> mat13({{1,2,-1}, {3,0,-2}});
    Matrix<ll> mat14({{0,1}, {-1,2}, {3,1}});
    Matrix<ll> mat14b({{0,-1,3}, {1,2,1}});
    mat14.self_transpose();
    assert(mat14 == mat14b);
    assert(mat13 + mat14 == Matrix<ll>({{1,1,2}, {4,2,-1}}));
    assert(mat13 - mat14 == Matrix<ll>({{1,3,-4}, {2,-2,-3}}));
    Matrix<ll> mat15({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
    assert(mat14 * mat15 == mat14b * mat15);
    Matrix<FpB> mat16({{2,3,4},{-1,0,-2},{1,-1,3}});
    Matrix<FpB> mat16a({{2,-1,1},{3,0,-1},{4,-2,3}});
    mat16a.self_transpose();
    assert(mat16 == mat16a);
    assert(mat16a.determinant() != 0);
    assert(mat16.inverse() == mat16a.inverse());
  }

  {
    struct MinMax {
      ll v;
      MinMax(ll v_ = LLONG_MAX) : v(v_) {}
      bool operator ==(const MinMax& o) const { return v == o.v; }
      bool operator !=(const MinMax& o) const { return v != o.v; }
      MinMax zero() const { return LLONG_MAX; }
      MinMax one() const { return LLONG_MIN; }
      MinMax operator +=(const MinMax& o) { if (v > o.v) v = o.v; return *this;}
      MinMax operator *=(const MinMax& o) { if (v < o.v) v = o.v; return *this;}
      MinMax operator +(const MinMax& o) const { return MinMax(v) += o; }
      MinMax operator *(const MinMax& o) const { return MinMax(v) *= o; }
    };
    MinMax x10(10), x2(2), x5(5), x4(4), x6(6);
    Matrix<MinMax> mat1({{x2, x5}, {x10, x2}});
    Matrix<MinMax> mat2({{x5, x5}, {x4,  x6}});
    assert(mat1 + mat2 == Matrix<MinMax>({{x2, x5}, {x4, x2}}));
    assert(mat1 * x6 == Matrix<MinMax>({{x6, x6}, {x10, x6}}));
    assert(mat1 * mat2 == Matrix<MinMax>({{x5, x5}, {x4, x6}}));
  }

  {
    using MyMat = Matrix<ll>;
    MyMat mat1{{2, -4, 1}, {3, 5, 0}, {-1, 2, -3}};
    vector<ll> vec1{3, 1, -2};
    vector<ll> vec2{0, -2, 1};
    auto vec3 = mat1 * vec1;
    assert(vec3 == (vector<ll>{0, 14, 5}));
    auto vec4 = mat1 * move(vec2);
    assert(vec4 == (vector<ll>{9, -10, -7}));
    assert(vec1 == (vector<ll>{3, 1, -2}));
  }


  {
    using Fp = FpA;

    cerr << "sweepout, determinant, inverse" << endl;
    Matrix<Fp> mat13  = {{2,5,7}, {4,-2,20}, {4, 6, 42}, {8,-7,7}};
    Matrix<Fp> mat13a = {{2,5,7}, {0,-12,6}, {0, 0, 26}, {0,0,0}};
    Matrix<Fp> mat13b = {{2,0,0}, {4,-12,0}, {4,-4,26}, {8,-27,0}};
    mat13b.at(3,2) = Fp(-69) / Fp(2);
    auto [rank13, det13] = mat13.sweepout();
    assert(rank13 == 3 && det13 == Fp(2) * Fp(-12) * Fp(26));
    auto [rank13x, det13x] = mat13.self_transpose().sweepout();
    assert(rank13x == rank13 && det13x == det13);
    Matrix<Fp> mat13c = {{2,5,7}, {4,-2,20}, {4, 6, 42}};
    assert(mat13c.determinant() == Fp(2) * Fp(-12) * Fp(26));
    Matrix<Fp> mat14  = {{1,1,1}, {2,2,3}, {1,2,3}, {3,3,2}};
    Matrix<Fp> mat14a = {{1,1,1}, {0,1,2}, {0,0,1}, {0,0,0}};
    assert(mat14.sweepout().first == 3);
    Matrix<Fp> mat14b = {{1,1,1}, {2,2,3}, {1,2,3}};
    assert(mat14b.determinant() == Fp(-1));
    Matrix<Fp> mat14c = {{1,1,1}, {2,2,3}, {-1,-1,-2}};
    assert(mat14c.determinant() == Fp(0));
    Matrix<Fp> mat15 = {{0,1}, {1,0}};
    assert(mat15.determinant() == Fp(-1));
    Matrix<Fp> mat16 = {{1,1,0,0},{0,0,1,0},{0,0,1,0}};
    Matrix<Fp> mat17 = {{1,1,0,0},{0,0,1,0},{0,0,0,0}};
    assert(mat16.sweepout().first == 2);
    Matrix<Fp> matUnit3 = {{1,0,0}, {0,1,0}, {0,0,1}};
    assert(mat13c * mat13c.inv().value() == matUnit3);
    Matrix<Fp> mat18 = {{2,3,5}, {1,4,-2}, {2+1,3+4,5-2}};
    assert(not mat18.inv().has_value());
  }
  
  {
    using Fp = FpB;
    Matrix<Fp> mat1a(3, 5);
    for (int i = 0; i < 3; i++) for (int j = 0; j < 5; j++) mat1a.at(i, j) = 42;
    assert(mat1a == Matrix<Fp>(3, 5, 42));
    Matrix<Fp> mat2a(2, 3, {1,2,3,4,5,6});
    Matrix<Fp> mat2b(0, 3, {1,2,3,4,5,6});
    Matrix<Fp> mat2c(2, 0, {1,2,3,4,5,6});
    vector<Fp> vec2d({1,2,3,4,5,6});
    Matrix<Fp> mat2d(2, 3, vec2d);
    Matrix<Fp> mat2e({{1,2,3},{4,5,6}});
    assert(mat2a == mat2b);
    assert(mat2a == mat2c);
    assert(mat2a == mat2d);
    assert(mat2a == mat2e);
    assert(Matrix<Fp>(mat2a.part(1, 2, 1, 1)) == Matrix<Fp>({{5,6}}));
    assert(Matrix<Fp>(mat2a.part(2, 2)) == Matrix<Fp>({{1,2},{4,5}}));
    assert(Matrix<Fp>(mat2a.part()) == mat2a);
    assert(mat1a != mat2a);
    vector<vector<Fp>> vvec2f({{1,2,3},{4,5,6}});
    assert(Matrix<Fp>::from_vvec(vvec2f) == mat2a);
    Matrix<Fp> mat3a({{1,2,3},{4,5,6},{7,8,9}});
    assert(mat3a.zero() == Matrix<Fp>({{0,0,0},{0,0,0},{0,0,0}}));
    assert(mat3a.unit() == Matrix<Fp>({{1,0,0},{0,1,0},{0,0,1}}));
    assert(mat3a.rowVec(1) == Matrix<Fp>({{4,5,6}}));
    assert(mat3a.colVec(1) == Matrix<Fp>(0, 1, {2,5,8}));
    Matrix<Fp> mat3b(mat3a);
    mat3b.memcopy(mat2a.part(1,2,1,1), 2, 1);
    assert(mat3b == Matrix<Fp>({{1,2,3},{4,5,6},{7,5,6}}));
    auto mat3c = mat3a.zero();
    mat3c.memcopy(mat2a.part(1,2,1,1));
    assert(mat3c == Matrix<Fp>({{5,6,0},{0,0,0},{0,0,0}}));
    stringstream ss("2 3 11 12 13 -14 -15 -16 1000");
    int x;
    Matrix<int> mat4a;
    ss >> mat4a >> x;
    assert(mat4a == Matrix<int>({{11,12,13},{-14,-15,-16}}));
    assert(x == 1000);
    stringstream ss2;
    ss2 << mat4a << "foo\n";
    assert(ss2.str() == "11, 12, 13\n-14, -15, -16\nfoo\n");
  }

  {
    using Fp = FpA;

    cerr << "linear equation" << endl;
    Matrix<Fp> mat1({{1,2,3}, {4,5,6}, {3,1,2}});
    Matrix<Fp> vec1({{14,26,11}});
    vec1.self_transpose();
    auto optsol1 = mat1.linSolution<true>(vec1);
    assert(optsol1.has_value());
    auto [sol1, kernel1] = optsol1.value();
    assert(kernel1.size() == 0);
    assert(mat1 * sol1 == vec1);
    
    Matrix<Fp> vv1(1, 0, {2,3,1,1,2,1});
    Matrix<Fp> vv2(1, 0, {0,0,0,2,0,1});
    // vector<Fp> vv3 = {0,0,0,2,1,-1};
    auto vv4 = vv1 + vv2 + Fp(2) * vv1;
    auto vv5 = vv1 + Fp(3) * vv1;
    auto vv6 = Fp(4) * vv1 + Fp(2) * vv5;
    Matrix<Fp> mat2(4, 6);
    mat2.memcopy(vv1.part(), 0, 0);
    mat2.memcopy(vv4.part(), 1, 0);
    mat2.memcopy(vv5.part(), 2, 0);
    mat2.memcopy(vv6.part(), 3, 0);
    Matrix<Fp> vv7(0, 1, {1,2,3,4,5,6});
    auto vec2 = mat2 * vv7;
    auto optsol2 = mat2.linSolution<true>(vec2);
    assert(optsol2.has_value());
    auto [sol2, kernel2] = optsol2.value();
    assert(kernel2.size() == 4);
    assert(mat2 * sol2 == vec2);
    for (const auto& m : kernel2) assert(mat2 * m == Matrix<Fp>(4, 1));

    Matrix<Fp> vec3(0, 1, {1,2,3,4});
    auto optsol3 = mat2.linSolution(vec3);
    assert(!optsol3.has_value());

    ll rep = 1000;
    for (ll i = 0; i < rep; i++) {
      ll n = randrange(1, 10);
      ll m = randrange(1, 10);
      ll rank = randrange(1, min(n, m) + 1);
      // DLOGKL("decided rank is", rank);
      vector<int8_t> dt(n, 0);
      for (ll j = 0; j < rank; j++) dt[j] = 1;
      for (ll j = n; j >= 2; j--) {
          ll p = randrange(0, j);
          if (p != j - 1) swap(dt[p], dt[j-1]);
      }
      ll cur_rank = 0;
      Matrix<Fp> A(n, m);
      for (ll j = 0; j < n; j++) {
        if (dt[j]) {
          cur_rank++;
          while (true) {
            for (ll k = 0; k < m; k++) A.at(j, k) = Fp(randrange(-6, 7));
            auto [chk, _] = A.sweepout();
            if ((ll)chk == cur_rank) break;
          }
        }else {
          for (ll p = 0; p < j; p++) {
            Fp c = Fp(randrange(-6, 7));
            for (ll k = 0; k < m; k++) { A.at(j, k) += c * A.at(p, k); }
          }
        }
      }
      Matrix<Fp> z(n, 1);
      for (ll p = 0; p < m; p++) {
        z = z + Fp(randrange(-6, 7)) * A.colVec(p);
      }
      auto optsol10 = A.linSolution(z);
      assert(optsol10.has_value());
      auto [sol10, kernel10] = optsol10.value();
      assert(A * sol10 == z);
      auto zero_mat = Matrix<Fp>(n, 1);
      for (const auto& kk : kernel10) {
        assert(A * kk == zero_mat);
      }
      if (rank < min(n, m)) {
        Matrix<Fp> B(n, m + 1);
        B.memcopy(A.part());
        while (true) {
          for (ll k = 0; k < n; k++) B.at(k, m) = Fp(randrange(-10, 10));
          auto [chk, _] = B.sweepout();
          // DLOGK(B);
          // DLOGK(chk);
          if ((ll)chk == rank + 1) break;
        }
        auto z2 = B.colVec(m);
        auto optsol11 = A.linSolution(z2);
        // DLOGK(A);
        // DLOGK(z2);
        assert(!optsol11.has_value());
      }
    }

  }
  
  {
    using Fp = FpG<2>;
    
    auto check = [&](const Matrix<Fp>& mat, ll m, ll n) -> void {
      Matrix<Fp> bs(m, 1);
      auto optsol = mat.linSolution<true>(bs);
      assert(optsol);
      auto [_, kernel] = *optsol;
      ll sz = kernel.size();
      Matrix<Fp> zero_m(m, 1);
      ll cnt = 0;
      for (ll x = 0; x < (1LL << n); x++) {
        Matrix<Fp> v(n, 1);
        for (ll i = 0; i < n; i++) v.at(i, 0) = (x >> i) & 1;
        if (mat * v == zero_m) cnt++;
      }
      assert((1LL << sz) == cnt);
    };
      
    ll rep = 1000;
    for (ll _r = 0; _r < rep; _r++) {
      ll m = randrange(1, 9);
      ll n = randrange(1, 9);
      Matrix<Fp> mat(m, n);
      for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) mat.at(i, j) = randrange(0, 2);
      }
      check(mat, m, n);
    }
    ll m = 4, n = 3;
    for (ll xx = 0; xx < (1LL << (m*n)); xx++) {
      Matrix<Fp> mat(m, n);
      for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
          ll t = i * n + j;
          mat.at(i, j) = (xx >> t) & 1;
        }
      }
      check(mat, m, n);
      check(mat.transpose(), n, m);
    }
  }

  cerr << "ok" << endl;
  return 0;
}
