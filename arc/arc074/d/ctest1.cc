#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main() {
  int i1 = INT_MAX;
  int i2 = INT_MIN;
  long long l1 = LLONG_MAX;
  long long l2 = LLONG_MIN;

  assert(- (i2 + 1) == i1);
  assert(- (l2 + 1) == l1);
  assert(i1 == 2 * ((1 << 30) - 1) + 1);
  assert(l1 == 2 * ((1LL << 62) - 1) + 1);
  assert(i2 = -i1 - 1);
  assert(l2 = -l1 - 1);
}
