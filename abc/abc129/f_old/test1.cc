#include <iostream>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace ublas = boost::numeric::ublas;

int main()
{
  // double型を要素とする3次元ベクトル
  ublas::vector<double> v(3);

  // 各要素の参照と代入
  v[0] = 3.0; // x
  v[1] = 0.0; // y
  v[2] = 4.0; // z

  // 出力ストリーム
  std::cout << v << std::endl;
}
