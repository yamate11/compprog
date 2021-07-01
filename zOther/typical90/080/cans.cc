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

  ll N, D; cin >> N >> D;
  vector<ll> A(N);
  vector<ll> B(D);
  for (ll i = 0; i < N; i++) cin >> A[i];
  for (ll i = 0; i < D; i++) {
    for (ll j = 0; j < N; j++) {
      if ((A[j] >> i) & 1) B[i] |= (1LL << j);
    }
  }
  auto memo = vector(D + 1, vector(1LL << N, -1LL));
  auto func = [&](auto rF, ll d, ll x) -> ll {
    ll& ret = memo[d][x];
    if (ret < 0) {
      if (x == 0) ret = (1LL << d);
      else if (d == 0) ret = 0;
      else {
        ll low = rF(rF, d - 1, x);
        ll hi = rF(rF, d - 1, x & ~B[d - 1]);
        ret = low + hi;
      }
    }
    return ret;
  };
  ll ans = func(func, D, (1LL << N) - 1);
  cout << ans << endl;

  return 0;
}

