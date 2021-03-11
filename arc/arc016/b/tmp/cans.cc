#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/math/special_functions/gamma.hpp>


using namespace boost::multiprecision;

typedef number<backends::cpp_bin_float<237, backends::digit_base_2, void, boost::int32_t, -262142, 262143>, et_off>  cpp_bin_float_oct;


// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cpp_bin_float_100 x = 1.0;
  ll n = 2000010;
  for (ll i = 1; i < n; i++) {
    x *= i;
  }
  cout << x << endl;

  return 0;
}

