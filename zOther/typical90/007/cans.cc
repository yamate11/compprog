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
  A.push_back(ll(-1e10));
  A.push_back(ll(1e10));
  sort(A.begin(), A.end());
  ll Q; cin >> Q;
  for (ll q = 0; q < Q; q++) {
    ll b; cin >> b;
    ll i = lower_bound(A.begin(), A.end(), b) - A.begin();
    cout << min(A[i] - b, b - A[i-1]) << "\n";
  }

  return 0;
}

