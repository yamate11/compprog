#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, f; cin >> n >> f;
  ll base = 0;
  vector<ll> poss(n);
  for (ll i = 0; i < n; i++) {
    ll k, l; cin >> k >> l;
    base += min(k, l);
    poss[i] = min(2 * k, l) - min(k, l);
  }
  sort(poss.begin(), poss.end(), greater<ll>());
  ll add = 0;
  for (ll i = 0; i < f; i++) add += poss[i];
  cout << base + add << endl;


  return 0;
}

