#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// Library Insertion Mark
// @@ !! LIM(debug f:power mod matrix)

template<typename T>
vector<T> operator+(const vector<T>& v1,
                    const vector<T>& v2) {
  if (v1.size() != v2.size()) { throw runtime_error("different size"); }
  vector<T> result(v1.size());
  for (size_t i = 0; i < v1.size(); i++) result[i] = v1[i] + v2[i];
  return result;
}

template<typename T>
vector<T> operator-(const vector<T>& v1,
                    const vector<T>& v2) {
  if (v1.size() != v2.size()) { throw runtime_error("different size"); }
  vector<T> result(v1.size());
  for (size_t i = 0; i < v1.size(); i++) result[i] = v1[i] - v2[i];
  return result;
}

template<typename T>
vector<T> operator*(T c1, const vector<T>& v2) {
  vector<T> result(v2.size());
  for (size_t i = 0; i < v2.size(); i++) result[i] = c1 * v2[i];
  return result;
}

template<typename T>
vector<T> operator*(const vector<T>& v1, T c2) {
  vector<T> result(v1.size());
  for (size_t i = 0; i < v1.size(); i++) result[i] = v1[i] * c2;
  return result;
}

template<typename T>
vector<T> operator/(const vector<T>& v1, T c2) {
  vector<T> result(v1.size());
  for (size_t i = 0; i < v1.size(); i++) result[i] = v1[i] / c2;
  return result;
}

template<typename T>
T dotProd(const vector<T>& v1, const vector<T>& v2) {
  if (v1.size() != v2.size()) { throw runtime_error("different size"); }
  T result = (T)0;
  for (size_t i = 0; i < v1.size(); i++) result += v1[i] * v2[i];
  return result;
}

int main() {
  using Fp = FpA;
  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  {
    cerr << "start" << endl;
    cerr << "equation" << endl;
    Matrix<ll> mat0 = {{0,1,0},{2,0,-1}};
    Matrix<ll> mat1 = Matrix<ll>(2,3);
    mat1.at(0,1) = 1;
    mat1.at(1,0) = 2;
    mat1.at(1,2) = -1;
    assert(mat0 == mat1);
    assert(!(mat0 != mat1));

    cerr << "addition" << endl;
    Matrix<ll> mat2 = {{1,0,0}, {0,0,1}};
    Matrix<ll> mat3 = {{4}, {5}, {6}};
    Matrix<ll> mat4 = {{5}, {2}};
    Matrix<ll> mat5 = {{1,1,0},{2,0,0}};
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
    Matrix<ll> mat10(vec10);
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
  }

  {
    cerr << "sweepout, determinant, inverse" << endl;
    Matrix<Fp> mat13  = {{2,5,7}, {4,-2,20}, {4, 6, 42}, {8,-7,7}};
    Matrix<Fp> mat13a = {{2,5,7}, {0,-12,6}, {0, 0, 26}, {0,0,0}};
    Matrix<Fp> mat13b = {{2,0,0}, {4,-12,0}, {4,-4,26}, {8,-27,0}};
    mat13b.at(3,2) = Fp(-69) / Fp(2);
    auto [rank13, det13] = mat13.sweepout();
    assert(rank13 == 3 && det13 == Fp(2) * Fp(-12) * Fp(26));
    auto [rank13x, det13x] = mat13.transpose().sweepout();
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
    assert(mat13c * mat13c.inverse() == matUnit3);
    Matrix<Fp> mat18 = {{2,3,5}, {1,4,-2}, {2+1,3+4,5-2}};
    try {
      Matrix<Fp> mat19 = mat18.inverse();
      assert(0);
    }catch(const MyExc& e) {
    }
  }
  
  {
    auto from_vec = [&](const auto& v) {
      return Matrix<Fp>::fromVec(v, true);
    };

    cerr << "linear equation" << endl;
    Matrix<Fp> mat1 = {{1,2,3}, {4,5,6}, {3,1,2}};
    vector<Fp> vec1 = {14,26,11};
    auto optsol1 = mat1.linSolution(vec1);
    assert(optsol1.has_value());
    auto [sol1, kernel1] = optsol1.value();
    assert(kernel1.size() == 0);
    Matrix<Fp> vec1a = from_vec(sol1);
    assert(mat1 * from_vec(sol1) == from_vec(vec1));
    
    vector<Fp> vv1 = {2,3,1,1,2,1};
    vector<Fp> vv2 = {0,0,0,2,0,1};
    // vector<Fp> vv3 = {0,0,0,2,1,-1};
    auto vv4 = vv1 + vv2 + Fp(2) * vv1;
    auto vv5 = vv1 + Fp(3) * vv1;
    auto vv6 = Fp(4) * vv1 + Fp(2) * vv5;
    vector<Fp> vv7 = {1,2,3,4,5,6};
    Fp t1 = dotProd(vv1, vv7);
    Fp t4 = dotProd(vv4, vv7);
    Fp t5 = dotProd(vv5, vv7);
    Fp t6 = dotProd(vv6, vv7);
    vector<Fp> vec2({t1, t4, t5, t6});
    Matrix<Fp> mat2 = {vv1, vv4, vv5, vv6};
    auto optsol2 = mat2.linSolution(vec2);
    assert(optsol2.has_value());
    auto [sol2, kernel2] = optsol2.value();
    assert(kernel2.size() == 2);
    assert(mat2 * from_vec(sol2) == from_vec(vec2));
    Matrix<Fp> mat_zero_4 = from_vec(vector<Fp>({0,0,0,0}));
    assert(mat2 * from_vec(kernel2[0]) == mat_zero_4);
    assert(mat2 * from_vec(kernel2[1]) == mat_zero_4);

    vector<Fp> vec3 = {1,2,3,4};
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
      vector<Fp> z(n);
      for (ll p = 0; p < m; p++) {
        z = z + Fp(randrange(-6, 7)) * A.colVec(p);
      }
      auto optsol10 = A.linSolution(z);
      assert(optsol10.has_value());
      auto [sol10, kernel10] = optsol10.value();
      assert(A * from_vec(sol10) == from_vec(z));
      auto zero_mat = from_vec(vector<Fp>(n));
      for (const auto& kk : kernel10) {
        assert(A * from_vec(kk) == zero_mat);
      }
      if (rank < min(n, m)) {
        Matrix<Fp> B(n, m + 1);
        B.partial_subst(A);
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

  cerr << "ok" << endl;
  return 0;
}
