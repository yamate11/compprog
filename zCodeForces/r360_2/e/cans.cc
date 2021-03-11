#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  vector<ll> C(n);
  for (ll i = 0; i < n; i++) cin >> C[i];
  vector<vector<bool>> cur(k + 1, vector<bool>(k + 1));
  cur[0][0] = true;
  for (ll i = 0; i < n; i++) {
    auto prev = cur;
    for (ll t = 0; t + C[i] <= k; t++) {
      for (ll j = 0; j <= t; j++) {
	if (prev[t][j]) {
	  cur[t + C[i]][j] = true;
	  if (j + C[i] <= k) cur[t + C[i]][j + C[i]] = true;
	}
      }
    }
  }
  ll cnt = 0;
  for (ll i = 0; i <= k; i++) if (cur[k][i]) cnt++;
  cout << cnt << endl;
  bool first = true;
  for (ll i = 0; i <= k; i++) {
    if (cur[k][i]) {
      if (first) first = false;
      else cout << " ";
      cout << i;
    }
  }
  cout << endl;


  return 0;
}

