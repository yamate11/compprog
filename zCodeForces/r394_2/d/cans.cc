#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, l, r; cin >> n >> l >> r;
  vector<ll> A(n);
  using sta = pair<ll, ll>;
  vector<sta> P;
  for (ll i = 0; i < n; i++) cin >> A[i];
  for (ll i = 0; i < n; i++) {
    ll p; cin >> p;
    P.emplace_back(p, i);
  }
  sort(P.begin(), P.end());
  vector<ll> B(n);
  ll cur = -1e10;
  for (auto [p, idx] : P) {
    ll b = A[idx] + cur + 1;
    if (b < l) b = l;
    if (b > r) {
      cout << -1 << endl;
      return 0;
    }
    B[idx] = b;
    cur = b - A[idx];
  }
  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << B[i];
  }
  cout << endl;


  return 0;
}

