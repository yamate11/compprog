#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int x = min(c, int(b / a));
  cout << x << endl;
  return 0;
}
