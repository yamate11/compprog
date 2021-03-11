#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

#include <boost/multiprecision/cpp_int.hpp>           // 整数を使う時
#include <boost/multiprecision/cpp_bin_float.hpp>     // 実数を使う時
using namespace boost::multiprecision;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll L; cin >> L;
  cpp_int ans = 1;
  for (ll i = 0; i < 11; i++) {
    ans *= (cpp_int)(L - 1 - i);
  }
  for (ll i = 0; i < 11; i++) {
    ans /= (cpp_int)(11 - i);
  }
  cout << ans << endl;

  return 0;
}

