#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // using sta = pair<ll, ll>;
  // vector<sta> xy;
  vector<ll> rx(N), ux(N), vy(N), wx(N);
  for (ll i = 0; i < N; i++) {
    ll x, y; cin >> x >> y; x--; y--;
    ux[i] = x;
    rx[x] = i;
    vy[x] = y;
    wx[y] = x;
  }
  ll start = 0;
  ll p = 0;
  ll q = N - 1;
  vector<ll> ans(N);
  for (; p < N; p++) {
    if (vy[p] < q) {
      q = vy[p];
    }else if (p + q == N - 1) {
      ll m = p - start + 1;
      for (ll i = start; i <= p; i++) ans[rx[i]] = m;
      start = p + 1;
      q--;
    }
  }
  for (ll i = 0; i < N; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}

