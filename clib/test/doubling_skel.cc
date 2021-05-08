#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(doubling)

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  { // ABC179-E  

    auto func = [&](ll N, ll X, ll M) -> ll {
      vector<int> nxt(M);
      using T = ll;
      vector<T> alpha(M);
      for (ll i = 0; i < M; i++) {
	nxt[i] = i * i % M;
	alpha[i] = i;
      }
      auto op = [](T x, T y) { return x + y; };
      auto dbl = make_doubling(N, move(nxt), move(alpha), 0LL, op);
      return dbl.calc(X, N);
    };
    auto naive = [&](ll N, ll X, ll M) -> ll {
      ll sum = 0;
      ll cur = X;
      for (ll i = 1; i <= N; i++) {
	sum += cur;
	cur = cur * cur % M;
      }
      return sum;
    };

    assert(func(6, 2, 1001) == 1369);
    assert(func(1000, 2, 16) == 6);
    assert(func(10000, 418, 725) == 11140);
    for (ll n = 1; n <= 20; n++) {
      for (ll m = 1; m < 20; m++) {
	for (ll x = 0; x < m; x++) {
	  assert(func(n, x, m) == naive(n, x, m));
	}
      }
    }

  }
  return 0;
}

