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

  ll A, B, K; cin >> A >> B >> K;
  
  vector<vector<ll>> memo(A + B + 1, vector<ll>(A + B + 1, -1));
  auto binom = [&](auto rF, ll x, ll y) -> ll {
    ll& ret = memo[x][y];
    if (ret < 0) {
      if (y == 0) ret = 1;
      else if (y == x) ret = 1;
      else {
        ret = rF(rF, x - 1, y - 1) + rF(rF, x - 1, y);
      }
    }
    return ret;
  };

  auto func = [&](auto rF, string s, ll a, ll b, ll prep) -> void {
    if (a == 0 && b == 0) {
      cout << s << endl;
    }else if (a == 0) {
      rF(rF, s + 'b', a, b - 1, 0);
    }else if (b == 0) {
      rF(rF, s + 'a', a - 1, b, 0);
    }else {
      ll fst = binom(binom, a + b - 1, a - 1);
      if (fst <= prep) {
        rF(rF, s + 'b', a, b - 1, prep - fst);
      }else {
        rF(rF, s + 'a', a - 1, b, prep);
      }
    }
  };

  func(func, "", A, B, K - 1);

  return 0;
}

