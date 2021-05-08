#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(coordCompr)


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> orig_values({0, -3000, 0, 9, 9, 10, 3, -1234567890123});
  CoordCompr cc(move(orig_values));
  assert(cc.c(-3000) == 1);
  assert(cc.c(-1234567890123) == 0);
  assert(cc.c(9) == 4);
  assert(cc.d(0) == -1234567890123);
  assert(cc.d(2) == 0);
  assert(cc.d(5) == 10);
  assert(cc.size == 6);

  cout << "Test done." << endl;

}
  
