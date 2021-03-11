#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<ll> L(N);
  for (ll i = 0; i < N; i++) cin >> L[i];
  sort(L.begin(), L.end());
  ll cnt = 0;
  for (ll i = 0; i < N; i++) {
    ll a = L[i];
    for (ll j = i + 1; j < N; j++) {
      ll b = L[j];
      if (a == b) continue;
      for (ll k = j + 1; k < N; k++) {
	ll c = L[k];
	if (b == c) continue;
	if (a + b <= c) continue;
	cnt++;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}

