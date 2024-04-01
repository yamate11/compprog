#include <iostream>

const int n = 50000000;

/*
int op(int n) {
    if(n == 0) return 0;
    return n ^ op(n-1);
}
*/

int main() {
  auto op = [&](auto rF, int m) -> int {
    if (m == 0) return 0;
    return m ^ rF(rF, m - 1);
  };

  std::cout << op(op, n) << '\n';
}
