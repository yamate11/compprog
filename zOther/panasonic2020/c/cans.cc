#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#include <boost/multiprecision/cpp_bin_float.hpp>     // 浮動小数点数を使う時
using namespace boost::multiprecision;

// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

using Real = cpp_bin_float_100;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(100);

  Real a, b, c; cin >> a >> b >> c;
  Real err = 1e-90;
  cout << (sqrt(a) + sqrt(b) + err < sqrt(c) ? "Yes\n" : "No\n");

  return 0;
}

