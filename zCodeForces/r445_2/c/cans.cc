#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<ll> T(n + 1);
  vector<ll> rev(n + 1, -1);
  for (ll i = 1; i <= n; i++) {
    ll t; cin >> t;
    T[i] = t;
    if (rev[t] == -1) rev[t] = i;
  }
  // const ll big = 1e9;
  vector<bool> mark(n + 1, false);
  ll cnt = 0;
  for (ll i = 0; i <= n; i++) {
    if (!mark[i]) cnt++;
    if (rev[i] >= 0) mark[rev[i]] = true;
  }
  cout << cnt << endl;

  return 0;
}

