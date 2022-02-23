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

  ll N, K; cin >> N >> K;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end(), greater<ll>());
  auto tbl = vector(N + 1, vector(40, -1LL));
  auto func = [&](auto rF, ll i, ll j) -> ll {
    ll& ret = tbl[i][j];
    if (ret < 0) {
      if (i == N) ret = 0;
      else {
        ll q = rF(rF, i + 1, j) + 1;
        if (j > 0) {
          ll idx = lower_bound(A.begin(), A.end(), A[i] / 2, greater<ll>())
            - A.begin();
          ll p = rF(rF, idx, j - 1);
          ret = min(p, q);
        }else {
          ret = q;
        }
      }
    }
    return ret;
  };
  for (ll j = 0; j < 40; j++) {
    ll t = func(func, 0, j);
    if (t <= K) {
      cout << j << " " << t << endl;
      return 0;
    }
  }
  
  return 0;
}

