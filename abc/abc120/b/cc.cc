#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  int g = __gcd(a, b);
  int m = 0;
  int x = g;
  while (1) {
    if (g % x == 0) {
      m++;
      if (m == k) {
	cout << x << endl;
	return 0;
      }
    }
    x--;
  }
  return 0;
}

