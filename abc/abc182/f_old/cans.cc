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

  ll N, X; cin >> N >> X;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  
  map<ll, ll> mp;
  auto func = [&](auto rF, ll x, ll i) -> ll {
    while (i < N && x % A[i] == 0) i++;
    if (i == N) return 1;
    ll& ret = mp[x];
    if (ret == 0) {
      ll y = x % A[i];
      ret = rF(rF, x - y, i + 1) + rF(rF, x + (A[i] - y), i + 1);
    }
    return ret;
  };
  cout << func(func, X, 1) << endl;

  return 0;
}
