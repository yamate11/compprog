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
  vector<ll> pile(N, LLONG_MAX);
  ll jmax = -1;
  for (ll i = 0; i < N; i++) {
    ll w; cin >> w;
    for (ll j = 0; j < N; j++) {
      if (pile.at(j) >= w) {
	pile.at(j) = w;
	jmax = max(jmax, j);
	break;
      }
    }
  }
  cout << jmax + 1 << endl;

  return 0;
}

