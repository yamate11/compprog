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

#include <boost/multiprecision/cpp_int.hpp>           // 整数を使う時
#include <boost/multiprecision/cpp_bin_float.hpp>     // 浮動小数点数を使う時
using namespace boost::multiprecision;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  using sta = pair<cpp_int, cpp_int>;
  vector<sta> AB(N);
  REP(i, 0, N) {
    cpp_int a, b; cin >> a >> b;
    AB[i] = sta(a, b);
  }
  ranges::sort(AB, [&](sta p, sta q) -> bool {
    return p.first * q.second < p.second * q.first;
  });
  for (auto [a, b] : AB) {
    cout << a << " " << b << "\n";
  }

  return 0;
}

