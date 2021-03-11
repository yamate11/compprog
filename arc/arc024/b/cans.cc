#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> col(N);
  for (ll i = 0; i < N; i++) cin >> col.at(i);
  ll smax = 0;
  for (ll i = 0; i < N; ) {
    ll k = 1;
    while (k < N && col.at(i) == col.at((i+k) % N)) k++;
    smax = max(smax, k);
    i += k;
  }
  ll ans;
  if (smax == N) ans = -1;
  else if (smax <= 2) ans = 1;
  else ans = 1 + (smax - 1) / 2;
  cout << ans << endl;

  return 0;
}

