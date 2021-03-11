#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll m; cin >> m;
  vector<ll> S(m);
  const ll lim = 1e6;
  vector<bool> vec(lim + 1);
  for (ll i = 0; i < m; i++) {
    ll s; cin >> s;
    S[i] = s;
    vec[s] = true;
  }
  ll g = S[0];
  for (ll i = 1; i < m; i++) {
    g = gcd(g, S[i]);
  }
  if (!vec[g]) {
    cout << -1 << endl;
    return 0;
  }
  cout << 2 * m << endl;
  for (ll i = 0; i < m; i++) {
    if (i > 0) cout << " ";
    cout << S[0] << " " << S[i];
  }
  cout << endl;

  return 0;
}

