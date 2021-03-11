#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    ll n; cin >> n;
    vector<ll> vec_a(n);
    for (ll i = 0; i < n; i++) cin >> vec_a[i];
    ll vmin = 1e10;
    for (ll i = 0; i < n; i++) vmin = min(vmin, vec_a[i]);
    vector<ll> mults;
    for (ll i = 0; i < n; i++) {
      if (vec_a[i] % vmin == 0) mults.push_back(vec_a[i]);
    }
    sort(mults.begin(), mults.end());
    ll k = 0;
    for (ll i = 0; i < n; i++) {
      if (vec_a[i] % vmin == 0) {
	vec_a[i] = mults[k];
	k++;
      }
    }
    for (ll i = 0; i < n - 1; i++) {
      if (vec_a[i] > vec_a[i+1]) return false;
    }
    return true;
    
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

