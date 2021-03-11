#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main() {
  int i1 = INT_MAX;
  int i2 = INT_MIN;
  long long l1 = LLONG_MAX;
  long long l2 = LLONG_MIN;
  double d1 = DBL_MAX;
  double d2 = DBL_MIN;

  // 自分の普段の環境では:
  assert(i1 == (((1 << 30) - 1) << 1) + 1);
  assert(l1 == (2 * ((1LL << 62) - 1) + 1));
  assert(i2 == -i1 - 1);
  assert(l2 == -l1 - 1);
  assert(1e308 < d1);
  assert(0 < d2 && d2 < 3e-308);
}
