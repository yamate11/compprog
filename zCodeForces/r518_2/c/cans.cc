#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  vector<ll> A(m), B(m);
  for (ll i = 0; i < m; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    A[i] = a;
    B[i] = b;
  }
  using sta = pair<ll, ll>;
  vector<vector<sta>> ans(n);
  for (ll i = 0; i < n; i++) ans[i].emplace_back(i, i);
  for (ll i = 0; i < m; i++) {
    ll a = A[i];
    ll b = B[i];
    ans[a].emplace_back(n + i, a);
    ans[b].emplace_back(n + i, b);
  }
  for (ll i = 0; i < n; i++) {
    cout << ans[i].size() << "\n";
    for (auto [a, b] : ans[i]) {
      cout << a + 1 << " " << b + 1 << "\n";
    }
  }

  return 0;
}

