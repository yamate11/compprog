#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// #include <boost/multiprecision/cpp_int.hpp>           // 整数を使う時
#include <boost/multiprecision/cpp_bin_float.hpp>     // 浮動小数点数を使う時
using namespace boost::multiprecision;

// @@ !! LIM()

int main() {
  cpp_bin_float_100 X, Y, R;
  cin >> X >> Y >> R;
  ll ans = 0;
  REP(x, llround(ceil(X - R)), llround(floor(X + R)) + 1) {
    cpp_bin_float_100 h = sqrt(R * R - (x - X) * (x - X));
    ll hiY = llround(floor(Y + h));
    ll loY = llround(ceil( Y - h));
    ans += hiY - loY + 1;
  }
  cout << ans << endl;
  return 0;
}

