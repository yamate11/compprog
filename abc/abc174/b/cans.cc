#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, D; cin >> N >> D;
  ll cnt = 0;
  for (ll i = 0; i < N; i++) {
    ll x, y; cin >> x >> y;
    if (x*x + y*y <= D*D) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

