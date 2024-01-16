#include <cmath>

double foo(int n) {
  double x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    x += (double)(2756 * i);
    y += sqrt((double)(1538 * i));
  }
  return x;
}

int bar() {
  int z = foo(10);
  return z;
}
