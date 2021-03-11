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
  vector<ll> X(N);
  for (ll i = 0; i < N; i++) cin >> X.at(i);
  ll vmin = LLONG_MAX;
  for (ll p = 1; p <= 100; p++) {
    ll tot = 0;
    for (ll i = 0; i < N; i++) {
      ll dist = X.at(i) - p;
      tot += dist * dist;
    }
    if (tot < vmin) vmin = tot;
  }
  cout << vmin << endl;

  return 0;
}

