#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// Library Insertion Mark
// @@ !! LIM(debug f:power mod matrix)

int main() {
  Fp::MOD = 1e9 + 7;

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
  
  cerr << "ok" << endl;
  return 0;
}
