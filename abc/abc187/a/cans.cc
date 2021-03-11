#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto func = [&](ll x) -> ll {
                ll ret = 0;
                while (x > 0) {
                  ret += x % 10;
                  x /= 10;
                }
                return ret;
              };
  ll A, B; cin >> A >> B;
  cout << max(func(A), func(B)) << endl;

  return 0;
}

