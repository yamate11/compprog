#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main() {
  int x = 12 & 10 == 8;
  int y = (12 & 10) == 8;
  int z = 12 & (10 == 8);
  cout << x << " " << y << " " << z << endl;
  return 0;
}
