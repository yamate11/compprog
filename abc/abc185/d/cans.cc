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

  ll N, M; cin >> N >> M;
  vector<ll> A(M+2);
  for (ll i = 1; i <= M; i++) {
    ll a; cin >> a;
    A[i] = a;
  }
  A[0] = 0;
  A[M + 1] = N + 1;
  sort(A.begin(), A.end());
  ll big = N * 2;
  ll vmin = big;
  for (ll i = 1; i <= M + 1; i++) {
    ll x = A[i] - A[i - 1] - 1;
    if (x > 0) {
      vmin = min(vmin, x);
    }
  }
  if (vmin == big) {
    cout << 0 << endl;
    return 0;
  }
  ll cnt = 0;
  for (ll i = 1; i <= M + 1; i++) {
    ll x = A[i] - A[i - 1] - 1;
    cnt += (x + vmin - 1) / vmin;
  }
  cout << cnt << endl;

  return 0;
}

