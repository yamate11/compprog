#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
#include <atcoder/convolution>

using mint = atcoder::modint998244353;

int main() {
  cout << std::is_integral<int>::value << endl;
  cout << std::is_integral<mint>::value << endl;
  cout << atcoder::internal::is_integral<mint>::value << endl;

#ifdef TEST_FOO
  cout << "test_foo" << endl;
#else
  cout << "test_bar" << endl;
#endif

  return 0;
}
