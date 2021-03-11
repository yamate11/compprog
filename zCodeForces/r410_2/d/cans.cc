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
  vector<ll> A(n), B(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  for (ll i = 0; i < n; i++) cin >> B[i];
  using sta = tuple<ll, ll, ll>;
  vector<sta> vec;
  for (ll i = 0; i < n; i++) vec.emplace_back(A[i], B[i], i);
  sort(vec.begin(), vec.end(), greater<sta>());
  vector<ll> ans;
  {
    auto [a, b, i] = vec[0];
    ans.push_back(i);
  }
  for (ll i = 0; i < (n - 1) / 2; i++) {
    auto [a0, b0, i0] = vec[2 * i + 1];
    auto [a1, b1, i1] = vec[2 * i + 2];
    ans.push_back(b0 >= b1 ? i0 : i1);
  }
  if (n % 2 == 0) {
    auto [a, b, i] = vec[n - 1];
    ans.push_back(i);
  }
  cout << n / 2 + 1 << endl;
  for (ll i = 0; i < n / 2 + 1; i++) {
    if (i > 0) cout << " ";
    cout << ans[i] + 1;
  }
  cout << endl;

  return 0;
}

