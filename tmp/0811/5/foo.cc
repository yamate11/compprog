#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll x = 1;
  bool a = (bool)x;
  x++;
  bool b = (bool)x;
  cout << a << " " << b << endl;
  ll y = 1LL << 32;
  bool c = (bool)y;
  int d = (int)y;
  cout << c << " " << d << endl;
  return 0;
}
