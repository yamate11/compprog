#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector<ll> acc(N+1);
  for (ll i = 0; i < N; i++) {
    ll p; cin >> p;
    acc.at(i+1) = acc.at(i) + p;
  }
  ll vm = 0;
  for (ll i = K; i <= N; i++) {
    vm = max(vm, acc.at(i) - acc.at(i - K));
  }
  double ans = ((double)vm + K) / 2.0;
  cout << ans << endl;

  return 0;
}

