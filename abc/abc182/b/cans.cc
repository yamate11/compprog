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

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  ll arg = -1;
  ll vmax = -1;
  for (ll x = 2; x <= 1000; x++) {
    ll cnt = 0;
    for (ll i = 0; i < N; i++) {
      if (A[i] % x == 0) cnt++;
    }
    if (cnt > vmax) {
      vmax = cnt;
      arg = x;
    }
  }
  cout << arg << endl;

  return 0;
}

