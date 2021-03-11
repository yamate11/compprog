#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(40);

  int x = 10;
  int y = 20;
  int& rx = x;
  int& ry = y;
  swap(rx, ry);
  cout << rx << endl;
  cout << x << endl;

  return 0;
}
