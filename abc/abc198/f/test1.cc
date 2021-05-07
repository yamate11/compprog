#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
#include <atcoder/convolution>

int main() {

  {
    vector<ll> vecA({1, 2, 3, 4});
    vector<ll> vecB({-1, 0, 1, 2});
    auto res1 = convolution_ll(vecA, vecB);
    auto res2 = naive_convolution(vecA, vecB);
    if (res1 != res2) {
      DLOGK(res1);
      DLOGK(res2);
      assert(res1 == res2);
    }
  }

  return 0;
}
