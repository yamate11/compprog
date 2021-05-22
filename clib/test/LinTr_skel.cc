#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(LinTr mod f:power matrix)


int main() {

  LinTr<ll> f1(2, 1);
  LinTr<ll> f2(-3, 4);
  LinTr<ll> f3(1, -2);
  assert((f1*f2*f3)(4) == f1(f2(f3(4))));
  assert((f3*f2*f1)(-5) == f3(f2(f1(-5))));

  using Fp = FpA;
  LinTr<Fp> f4(5, 7);
  Fp x1 = 10;
  for (ll i = 0; i < 100; i++) { x1 = f4(x1); }
  assert(power(f4, 100)(10) == x1);
  Matrix<Fp> mat1({{1,2}, {3,4}});
  Matrix<Fp> mat2({{5,6}, {7,8}});
  Matrix<Fp> mat3({{9,10}, {11,12}});
  Matrix<Fp> mat4(mat3);
  LinTr<Matrix<Fp>> fm1(mat1, mat2);
  for (ll i = 0; i < 100; i++) { mat4 = fm1(mat4); }
  assert(power(fm1, 100)(mat3) == mat4);
  cout << "Test done." << endl;

}
