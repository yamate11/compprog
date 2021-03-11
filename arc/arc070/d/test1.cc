#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main() {
  //             0  1  2  3  4  5
  vector<int> v({2, 4, 6, 6, 6, 8});
  auto b = v.begin();
  auto e = v.end();
  
  assert(lower_bound(b, e, 6) == b + 2);
  assert(upper_bound(b, e, 6) == b + 5);

  assert(lower_bound(b, e, 5) == b + 2);
  assert(upper_bound(b, e, 5) == b + 2);

  assert(lower_bound(b, e, 9) == e);
  assert(upper_bound(b, e, 9) == e);

}
