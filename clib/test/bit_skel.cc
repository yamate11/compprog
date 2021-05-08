#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(bit)

int main() {
  BIT<long long> t(10); // a_1 = a_2 = ... = a_10 = 0
  for (int i = 1; i <= 10; i++)  t.add(i, i);  // a_i = i
  t.add(1, 300);           // a_1 <- a_1 + 300 = 301
  long long x = t.sum(3);  // x <- a_1 + a_2 + a_3 = 301 + 2 + 3 = 306
  assert(x == 306);
}
