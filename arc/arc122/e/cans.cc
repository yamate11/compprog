#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];

  vector<ll> ans;
  for (ll k = N - 1; k >= 0; k--) {
    bool succ = false;
    for (ll i = k; i >= 0; i--) {
      ll x = 1;
      for (ll j = 0; j <= k; j++) {
        if (i == j) continue;
        ll g = gcd(A[i], A[j]);
        ll m = gcd(x, g);
        x *= g / m;
      }
      if (x < A[i]) {
        ans.push_back(A[i]);
        A[i] = A[k];
        succ = true;
        break;
      }
    }
    if (!succ) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  reverse(ans.begin(), ans.end());
  for (ll a : ans) { cout << a << " "; }
  cout << endl;
  return 0;
}

