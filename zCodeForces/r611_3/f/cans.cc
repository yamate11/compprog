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
  vector<ll> a(n-1);
  for (ll i = 0; i < n-1; i++) cin >> a[i];

  vector app(n+1, 0LL);
  vector parent(n+1, -1LL);
  parent[a[0]] = 0;
  ll t = 0;
  for (ll i = n; i >= 1; i--) {
    if (parent[i] >= 0) continue;
    while (t + 1 < n - 1 && a[t + 1] != i && parent[a[t + 1]] == -1) {
      parent[a[t + 1]] = a[t];
      t++;
    }
    parent[i] = a[t];
    t++;
  }
  cout << a[0] << "\n";
  for (ll i = 1; i <= n; i++) {
    if (parent[i] == 0) continue;
    cout << i << " " << parent[i] << "\n";
  }

  return 0;
}

