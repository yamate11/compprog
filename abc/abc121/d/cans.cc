#include <bits/stdc++.h>
using namespace std;

long long g(long long x) {
  int r = x % 4;
  if (r == 0)  return x;
  if (r == 1)  return 1;
  if (r == 2)  return x+1;
  /* r == 3 */ return 0;
}

int main() {
  long long a, b;
  cin >> a >> b;
  cout << (g(a-1) ^ g(b)) << endl;
  return 0;
}
